//Game

class Game : public cocos2d::Scene {

private:
	cocos2d::Vec2 _player_position;
	cocos2d::DrawNode* _player;
	cocos2d::EventListenerKeyboard* _keyBoard;
	bool _playerDirection[4] = {false};

	double _speed = 10;

	void _initPlayer();
	void _initKbListener();

	void _onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	void _onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	void _playerMove();
	void _drawPlayer();
public:
	CREATE_FUNC(Game);
	static cocos2d::Scene* createScene();
	virtual bool init();
	virtual void update();

};