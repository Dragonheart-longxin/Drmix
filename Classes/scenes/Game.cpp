#include "Drmix.h"

cocos2d::Scene* Game::createScene() {

	return Game::create();

}

bool Game::init() {

	this->addChild(GameManager::getinstance()->backGround);
	_initPlayer();
	_initKbListener();

	schedule(CC_CALLBACK_0(Game::update, this), "GameUpdate");
	return true;
}


void Game::update() {

	_playerMove();
	_drawPlayer();

}

void Game::_initPlayer() {

	_player_position = cocos2d::Vec2(100, 100);
	_player = cocos2d::DrawNode::create();
	this->addChild(_player);

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
		_player_position.y += _speed;
		if (_player_position.y > GameManager::getinstance()->winSize.y -10)
		{
			_player_position.y -= GameManager::getinstance()->winSize.y;
		}
	};

	if (_playerDirection[1])
	{
		_player_position.x -= _speed;
		if (_player_position.x < GameManager::getinstance()->winOrigin.x +10)
		{
			_player_position.x += GameManager::getinstance()->winSize.x;
		}
	};

	if (_playerDirection[2])
	{
		_player_position.y -= _speed;
		if (_player_position.y < GameManager::getinstance()->winOrigin.y + 10)
		{
			_player_position.y += GameManager::getinstance()->winSize.y;
		}
	};

	if (_playerDirection[3])
	{
		_player_position.x += _speed;
		if (_player_position.x > GameManager::getinstance()->winSize.x - 10)
		{
			_player_position.x -= GameManager::getinstance()->winSize.x;
		}
	};

}

void Game::_drawPlayer() {

	_player->clear();
	_player->drawSolidRect(
		_player_position - cocos2d::Vec2(10, 10),
		_player_position + cocos2d::Vec2(10, 10),
		cocos2d::Color4F::BLUE);
}