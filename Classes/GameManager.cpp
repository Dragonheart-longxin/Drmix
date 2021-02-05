#include "Drmix.h"

GameManager* GameManager::_g = nullptr;

GameManager::GameManager() {
	//Background
	winOrigin = cocos2d::Director::getInstance()->getVisibleOrigin();
	winSize = cocos2d::Director::getInstance()->getVisibleSize();

	backGround = cocos2d::DrawNode::create();
	backGround->drawSolidRect(winOrigin, winSize, cocos2d::Color4F(0.24, 0.24, 0.24, 1));

}

GameManager::~GameManager() {

	delete _g;

}

GameManager* GameManager::getinstance() {

	if (_g == nullptr)
	{
		_g = new GameManager();
	};
	return _g;
}

void GameManager::enterEnterGame() {

	cocos2d::Scene* sc = EnterGame::createScene();
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(1, sc, cocos2d::Color3B(0, 0, 0))
	);

}

void GameManager::enterGame() {
	
	cocos2d::Scene* sc = Game::createScene();
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(1, sc, cocos2d::Color3B(0, 0, 0))
	);
	
}

void GameManager::enterLoading() {
	/*
	cocos2d::Scene* sc = Loading::createScene();
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(1, sc, cocos2d::Color3B(0, 0, 0))
	);
	*/
}

void GameManager::enterMenu() {

	cocos2d::Scene* sc = Menu::createScene();
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(1, sc, cocos2d::Color3B(0, 0, 0))
	);
	
}

void GameManager::enterSettings() {
/*
	cocos2d::Scene* sc = Settings::createScene();
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(1, sc, cocos2d::Color3B(0, 0, 0))
	);
	*/
}

void GameManager::enterStop() {
/*
	cocos2d::Scene* sc = Stop::createScene();
	cocos2d::Director::getInstance()->replaceScene(
		cocos2d::TransitionFade::create(1, sc, cocos2d::Color3B(0, 0, 0))
	);
	*/
}