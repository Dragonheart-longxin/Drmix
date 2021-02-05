//GameManager

class GameManager : public cocos2d::Ref {

private:
	static GameManager* _g;
public:
	GameManager();
	~GameManager();

	static GameManager* getinstance();

	cocos2d::Vec2 winOrigin;
	cocos2d::Vec2 winSize;

	//Change Scene
	void enterEnterGame();
	void enterGame();
	void enterLoading();
	void enterMenu();
	void enterSettings();
	void enterStop();

	//Background
	cocos2d::DrawNode* backGround;
};