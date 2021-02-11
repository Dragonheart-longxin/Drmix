//cocos2d
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "AppDelegate.h"
#include "AudioEngine.h"

//GameManager
#ifndef _GAMEMANAGER_H_
	#define _GAMEMANAGER_H_
	#include "base/GameManager.h"
#endif
//Scenes
#ifndef _SCENES_
	#define _SCENES_
	#include "scenes/EnterGame/EnterGame.h"
	#include "scenes/Game/Game.h"
	#include "scenes/Levels/Levels.h"
	#include "scenes/Loading/Loading.h"
	#include "scenes/Menu/Menu.h"
	#include "scenes/Settings/Settings.h"
	#include "scenes/Stop/Stop.h"
#endif
//Scripts