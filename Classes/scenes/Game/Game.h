//Game

class Game : public cocos2d::Scene {

private:
	cocos2d::DrawNode* _bg;
	cocos2d::DrawNode* _player;
	cocos2d::DrawNode* _enemy;
	cocos2d::EventListenerKeyboard* _keyBoard;
	cocos2d::EventListenerPhysicsContact* _phy;
	cocos2d::PhysicsBody* _phyBody;

	cocos2d::Vec2 _playerPosition;
	cocos2d::Vec2 _enemyPosition;
	bool _playerDirection[4] = {false};
	double _speed = 10;

	void _initBg();
	void _initPlayer();
	void _initEnemy();
	void _initKbListener();
	void _initPhy();

	void _onKeyPressed(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	void _onKeyReleased(cocos2d::EventKeyboard::KeyCode, cocos2d::Event*);
	bool _onContactBegin(cocos2d::PhysicsContact&);
	void _playerMove();
	void _drawPlayer();
	void _drawEnemy();
public:
	CREATE_FUNC(Game);
	static cocos2d::Scene* createScene();
	virtual bool initWithPhysics();
	virtual void update();

	cocos2d::Vec2 winOrigin;
	cocos2d::Vec2 winSize;
};