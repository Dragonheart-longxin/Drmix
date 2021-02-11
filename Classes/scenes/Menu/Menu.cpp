#include "Drmix.h"

cocos2d::Scene* Menu::createScene() {

	return Menu::create();

}

bool Menu::init() {

	_initBg();
	_initmenuRef();
	_initMenu();

	return true;
}

void Menu::onEnter() {

	Node::onEnter();

}

void Menu::onExit() {

	Node;;onExit();

}

void Menu::_initBg() {

	_bg = cocos2d::DrawNode::create();

	cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();
	cocos2d::Vec2 winSize = cocos2d::Director::getInstance()->getVisibleSize();

	_bg->drawSolidRect(origin, winSize, cocos2d::Color4F(0.24, 0.24, 0.24, 1));
	this->addChild(_bg);
	

}

void Menu::_initMenu() {

	_menu = cocos2d::Menu::createWithArray(_menuItem);
	cocos2d::Vec2 winSize = cocos2d::Director::getInstance()->getVisibleSize();
	_menu->setPosition(winSize.x/2, winSize.y/2);
	this->addChild(_menu);

}

void Menu::_initmenuRef() {

	_startMenu = cocos2d::MenuItemFont::create("Menu Button", CC_CALLBACK_1(Menu::_menucallback, this));
	_startMenu->setFontSizeObj(20);
	_menuItem.pushBack(_startMenu);

}


void Menu::_menucallback(cocos2d::Ref* sender) {



}