#ifndef _ROLE_H_
#define _ROLE_H_


class Role :public DrawNode {
private:
	DrawNode* _role;
public:
	static DrawNode* createRole();
	virtual bool init();
	CREATE_FUNC(Role);
};
#endif