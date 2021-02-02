//GameManager

class GameManager : public cocos2d::Ref {

private:
	static GameManager* _g;
public:
	GameManager();
	~GameManager();

	GameManager* getinstance();

	//Change Scene
	void enterEnterGame();
	void enterGame();
	void enterLoading();
	void enterMenu();
	void enterSettings();
	void enterStop();
};