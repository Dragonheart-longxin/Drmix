#include "Drmix.h"

cocos2d::Scene* Game::createScene() {

	return Game::createWithPhysics();

}

bool Game::initWithPhysics() {

	winOrigin = cocos2d::Director::getInstance()->getVisibleOrigin();
	winSize = cocos2d::Director::getInstance()->getVisibleSize();

	_playerPosition = winOrigin + cocos2d::Vec2(10, 10);
	_enemyPosition = winOrigin + cocos2d::Vec2(cocos2d::random(winOrigin.x, winSize.x),
											   cocos2d::random(winOrigin.y, winSize.y)
											  );

	_initBg();
	_initPlayer();
	_initKbListener();
	_initPhy();

	schedule(CC_CALLBACK_0(Game::update, this), "GameUpdate");
	return true;
}


void Game::update() {

	_playerMove();
	_drawPlayer();
	_drawEnemy();

}

void Game::_initBg() {

	_bg = cocos2d::DrawNode::create();
	_bg->drawSolidRect(cocos2d::Director::getInstance()->getVisibleOrigin(),
					   cocos2d::Director::getInstance()->getVisibleSize(),
					   cocos2d::Color4F(0.24, 0.24, 0.24, 1)
	);

}

void Game::_initPlayer() {

	_player = cocos2d::DrawNode::create();
	this->addChild(_player);

}

void Game::_initEnemy() {

	_enemy = cocos2d::DrawNode::create();
	this->addChild(_enemy);

}

void Game::_initPhy() {

	_phyBody = cocos2d::PhysicsBody::createBox(cocos2d::Size(20, 20));
	_phyBody->setDynamic(false);

	_player->addComponent(_phyBody);
	_player->getPhysicsBody()->setCategoryBitmask(0x01);
	_player->getPhysicsBody()->setCollisionBitmask(0x01);

	_enemy->addComponent(_phyBody);
	_enemy->getPhysicsBody()->setCategoryBitmask(0x02);
	_enemy->getPhysicsBody()->setCollisionBitmask(0x02);

	_phy = cocos2d::EventListenerPhysicsContact::create();
	_phy->onContactBegin = CC_CALLBACK_1(Game::_onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_phy, this);
}

void Game::_initKbListener() {

	_keyBoard = cocos2d::EventListenerKeyboard::create();
	_keyBoard->onKeyPressed = CC_CALLBACK_2(Game::_onKeyPressed, this);
	_keyBoard->onKeyReleased = CC_CALLBACK_2(Game::_onKeyReleased, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(_keyBoard, this);

}

void Game::_onKeyPressed(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event) {

	switch (code)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
		_playerDirection[0] = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
		_playerDirection[1] = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
		_playerDirection[2] = true;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
		_playerDirection[3] = true;
		break;
	default:
		break;
	}

}

void Game::_onKeyReleased(cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event) {

	switch (code)
	{
	case cocos2d::EventKeyboard::KeyCode::KEY_W:
		_playerDirection[0] = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_A:
		_playerDirection[1] = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_S:
		_playerDirection[2] = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_D:
		_playerDirection[3] = false;
		break;
	case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
		cocos2d::Director::getInstance()->popToSceneStackLevel(0);
		break;
	default:
		break;
	}

}

void Game::_playerMove() {

	if (_playerDirection[0])
	{
		_playerPosition.y += _speed;
		if (_playerPosition.y > winSize.y -10)
		{
			_playerPosition.y -= winSize.y;
		}
	};

	if (_playerDirection[1])
	{
		_playerPosition.x -= _speed;
		if (_playerPosition.x < winOrigin.x +10)
		{
			_playerPosition.x += winSize.x;
		}
	};

	if (_playerDirection[2])
	{
		_playerPosition.y -= _speed;
		if (_playerPosition.y < winOrigin.y + 10)
		{
			_playerPosition.y += winSize.y;
		}
	};

	if (_playerDirection[3])
	{
		_playerPosition.x += _speed;
		if (_playerPosition.x > winSize.x - 10)
		{
			_playerPosition.x -= winSize.x;
		}
	};

}

void Game::_drawPlayer() {

	_player->clear();
	_player->drawSolidRect(
		_playerPosition - cocos2d::Vec2(10, 10),
		_playerPosition + cocos2d::Vec2(10, 10),
		cocos2d::Color4F::BLUE);
}

void Game::_drawEnemy() {

	_enemy->clear();
	_enemy->drawSolidRect(
		_enemyPosition - cocos2d::Vec2(10, 10),
		_enemyPosition + cocos2d::Vec2(10, 10),
		cocos2d::Color4F::RED);
}

bool Game::_onContactBegin(cocos2d::PhysicsContact& contact) {

	if (contact.getShapeA()->getCategoryBitmask() == 0x02 
		&& contact.getShapeA()->getCollisionBitmask() == 0x02)
	{
		_enemyPosition = winOrigin + cocos2d::Vec2(cocos2d::random(winOrigin.x, winSize.x),
												   cocos2d::random(winOrigin.y, winSize.y)
												  );
	}

	return true;
}