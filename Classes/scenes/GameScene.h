#include "cocos2d.h"

#ifndef _GAMESCENE_H_
#define _GAMESCENE_H_

using namespace cocos2d;

class GameScene :public Scene {
private:
	DrawNode* _background;
	void initBackGround();
public:
	static Scene* createScene();
	virtual bool init();
	virtual void update();
	CREATE_FUNC(GameScene);


};

#endif