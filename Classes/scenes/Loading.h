#ifndef __LOADING_H__
#define __LOADING_H__

class Loading : public Scene
{
private:
    DrawNode* background;

public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(Loading);
};

#endif 
