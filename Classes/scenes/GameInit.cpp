#include "Drmix.h"

Scene* GameInit::createScene() {
	return GameInit::create();
}

bool GameInit::init() {
	_background = DrawNode::create();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 winSize = Director::getInstance()->getWinSize();

	_background->drawSolidRect(origin, winSize, Color4F(0.12, 0.56, 1, 1));
	this->addChild(_background);
	
	_text = Label::createWithSystemFont("Drmix", "Microsoft YaHai UI", 20);
	this->addChild(_text,2);

	auto func = CallFunc::create(CC_CALLBACK_0(GameInit::changeScene, this));
	auto fadeIn = FadeTo::create(1.0f, 255);
	auto fadeOut = FadeTo::create(1.0f, 0);

	this->runAction(Sequence::create(fadeIn, fadeOut,func, nullptr));

	return true;
}

void GameInit::changeScene() {
	GameMain::getInstance()->enterLoading();
}