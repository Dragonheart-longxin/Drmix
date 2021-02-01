#ifndef _GAMEMAIN_H_
#define _GAMEMAIN_H_ 
using namespace cocos2d;

class GameMain {
private:
	static GameMain* _g;
public:
	
	GameMain();
	~GameMain();
	bool init();
	static GameMain* getInstance();
	void enterLoading();
	void enterGameScene();
};

#endif