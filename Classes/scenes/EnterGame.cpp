#include "Drmix.h"

cocos2d::Scene* EnterGame::createScene() {

	return EnterGame::create();

}

bool EnterGame::init() {

	//Listen Esc for exit
	cocos2d::EventListenerKeyboard* kbL = cocos2d::EventListenerKeyboard::create();
	kbL->onKeyReleased = [&](cocos2d::EventKeyboard::KeyCode code, cocos2d::Event* event) {
		switch (code)
		{
		case cocos2d::EventKeyboard::KeyCode::KEY_ESCAPE:
			cocos2d::Director::getInstance()->popToSceneStackLevel(0);
			break;
		default:
			break;
		}
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(kbL, this);

	this->addChild(GameManager::getinstance()->backGround);
	_initStartButton();

	return true;
}

void EnterGame::_initStartButton() {

	cocos2d::Vec2 winSize = cocos2d::Director::getInstance()->getWinSize();

	_bt = cocos2d::ui::Button::create();
	_bt->setTitleText("Start Game");
	_bt->setZoomScale(0.01);
	_bt->setPosition(cocos2d::Vec2(winSize.x / 2, winSize.y / 2));
	_bt->setTitleFontSize(20);
	_bt->addTouchEventListener(
		[&](cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type) {
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:

				break;
			case cocos2d::ui::Widget::TouchEventType::MOVED:

				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:

				_buttonRefEnded();

				break;
			case cocos2d::ui::Widget::TouchEventType::CANCELED:

				break;
			default:

				break;
			}
		}
	);
	
	
	this->addChild(_bt);

}

void EnterGame::_buttonRefEnded() {

	//GameManager::getinstance()->enterMenu();
	GameManager::getinstance()->enterGame();

}

void EnterGame::onEnter() {

	cocos2d::Node::onEnter();

}

void EnterGame::onExit() {

	cocos2d::Node::onExit();

}
