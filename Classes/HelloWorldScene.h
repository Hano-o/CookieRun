﻿#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#pragma execution_character_set("utf-8")
#endif

#include "cocos2d.h"
#include "HomeScene.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(HelloWorld);

	float _soundVolume;

	int audioId1;

	void doStart(Ref* pSender);
	void Audio_start();
	void preloadAll();
	~HelloWorld();

};

#endif // __HELLOWORLD_SCENE_H__
