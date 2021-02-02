//EnterGame

class EnterGame : public cocos2d::Scene {

private:
	cocos2d::DrawNode* _bg;
	cocos2d::ui::Text* _text;
	cocos2d::Sequence* _seq;
	cocos2d::ui::Button* _bt;
	cocos2d::ui::Widget::ccWidgetClickCallback _bf;

	void _initBg();
	void _initSeq();
	void _initText();
	void _initStartButton();
	void _buttonRef();
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(EnterGame);
	virtual void onEnter();
	virtual void onExit();
	
};