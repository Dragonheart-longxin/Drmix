// Menu

class Menu : public cocos2d::Scene {

private:
	cocos2d::DrawNode* _bg;
	cocos2d::Menu* _menu;
	cocos2d::Vector<cocos2d::MenuItem*> _menuItem;
	cocos2d::MenuItemFont* _startMenu;

	void _initBg();
	void _initMenu();
	void _initmenuRef();
	void _menucallback(cocos2d::Ref*);
public:
	static cocos2d::Scene* createScene();
	CREATE_FUNC(Menu);

	virtual bool init();
	virtual void onEnter();
	virtual void onExit();

};