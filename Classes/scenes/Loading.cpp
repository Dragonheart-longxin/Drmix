#include "Drmix.h"

USING_NS_CC;

Scene* Loading::createScene()
{
    return Loading::create();
}


bool Loading::init()
{
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    Vec2 winSize = Director::getInstance()->getWinSize();

    Vec2 points[4] = {origin, Vec2(winSize.x,origin.y), winSize, Vec2(origin.x, winSize.y)};
    background = DrawNode::create();
    background->drawSolidPoly(points, 4, Color4F(1,1,1,0.8) );
    this->addChild(background);

    return true;
}
