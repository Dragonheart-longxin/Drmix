#include "Drmix.h"

cocos2d::Scene* EnterGame::createScene() {

	return EnterGame::create();

}

bool EnterGame::init() {

	_initBg();
	_initSeq();
	_initText();
	_initStartButton();

	return true;
}

void EnterGame::_initBg() {

	_bg = cocos2d::DrawNode::create();

	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Vec2 winSize = cocos2d::Director::getInstance()->getWinSize();

	_bg->drawSolidRect(origin, winSize, cocos2d::Color4F(0.24, 0.24, 0.24, 1));
	this->addChild(_bg);

}

void EnterGame::_initSeq() {

	_seq = cocos2d::Sequence::create(nullptr);

}
// Bug can't display text
void EnterGame::_initText() {

	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Vec2 winSize = cocos2d::Director::getInstance()->getWinSize();

	_text = cocos2d::ui::Text::create("Drmix", "Arial", 20);
	_text->setColor(cocos2d::Color3B(1, 1, 1));
	_text->setPosition(cocos2d::Vec2(origin.x + winSize.x / 2, origin.y + winSize.y / 2));
	_text->setTextColor(cocos2d::Color4B(1, 1, 1,1));

	this->addChild(_text);
	
}

void EnterGame::_initStartButton() {

	cocos2d::Vec2 winSize = cocos2d::Director::getInstance()->getWinSize();

	_bt = cocos2d::ui::Button::create();
	_bt->setTitleText("Start Game");
	_bt->setZoomScale(0.2);
	_bt->setPosition(cocos2d::Vec2(winSize.x / 2, winSize.y / 2));
	_bt->addTouchEventListener(
		[&](cocos2d::Ref*, cocos2d::ui::Widget::TouchEventType type) {
			switch (type)
			{
			case cocos2d::ui::Widget::TouchEventType::BEGAN:
				break;
			case cocos2d::ui::Widget::TouchEventType::MOVED:
				break;
			case cocos2d::ui::Widget::TouchEventType::ENDED:
				_buttonRef();
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

void EnterGame::_buttonRef() {

	_bt->setTitleText("Clicked");

}

void EnterGame::onEnter() {

	cocos2d::Node::onEnter();

}

void EnterGame::onExit() {

	cocos2d::Node::onExit();

}
