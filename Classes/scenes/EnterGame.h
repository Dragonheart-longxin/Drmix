//EnterGame

class EnterGame : public cocos2d::Scene {

private:
	cocos2d::ui::Button* _bt;

	void _initStartButton();
	void _buttonRefEnded();
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(EnterGame);

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();
	
};