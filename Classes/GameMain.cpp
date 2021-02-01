#include "Drmix.h"

GameMain* GameMain::_g = nullptr;

GameMain::GameMain() {

}

GameMain::~GameMain() {

}

bool GameMain::init() {

    return true;
}

GameMain* GameMain::getInstance() {
    if (_g == nullptr) {
        _g = new GameMain();
        _g->init();
    }
    return _g;
}

void GameMain::enterLoading() {
    Scene* sc = Loading::createScene();
    Director::getInstance()->replaceScene(sc);
}

void GameMain::enterGameScene() {
    /*
    Scene* sc = GameScene::createScene();
    Director::getInstance()->replaceScene(sc);
    */
}

