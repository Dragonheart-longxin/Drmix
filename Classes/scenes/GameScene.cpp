#include "GameScene.h"

Scene* GameScene::createScene() {
	return GameScene::create();
}

bool GameScene::init() {
	initBackGround();

	return true;
}

void GameScene::initBackGround() {
	_background = DrawNode::create();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Vec2 winSize = Director::getInstance()->getWinSize();

	_background->drawSolidRect(origin, winSize, Color4F(0.12, 0.56, 1, 1));
	this->addChild(_background);
}

void GameScene::update() {

}