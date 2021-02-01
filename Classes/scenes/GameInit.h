#ifndef _GAMEINIT_H_
#define _GAMEINIT_H_

class GameInit :public Scene {
private:
	DrawNode* _background;
	Label* _text;
public:
	static Scene* createScene();
	virtual bool init();
	void changeScene();
	CREATE_FUNC(GameInit);
};

#endif
