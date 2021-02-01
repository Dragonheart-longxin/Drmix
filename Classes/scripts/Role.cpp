#include "Drmix.h"

DrawNode* Role::createRole() {
	return Role::create();
}

bool Role::init() {
	_role = DrawNode::create();
	_role->drawSolidCircle(Vec2(360, 360), 100, 360, 2, Color4F(0, 0, 0, 1));

	_role->setPosition(Vec2(640, 360));
	this->addChild(_role);

	auto action = Sequence::create(MoveBy::create(2,Vec2(100,100)), nullptr);
	this->runAction(action);

	return true;
}