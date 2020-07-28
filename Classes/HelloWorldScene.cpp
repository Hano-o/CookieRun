#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

bool HelloWorld::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	////////////////////////////

	_soundVolume = 1.0f;

	auto background1 = Sprite::create("Images/MainScene.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));
	//background1->setScale(1);
	this->addChild(background1);

	auto pStart = MenuItemImage::create("Images/btn-play-normal.png", "Images/btn-play-selected.png", CC_CALLBACK_1(HelloWorld::doStart, this));
	pStart->setPosition(Vec2(640, 70));
	pStart->setAnchorPoint(Vec2(0.5, 0.5));
	pStart->setScale(1.5);

	auto pMenu = Menu::create(pStart, nullptr);
	pMenu->setPosition(Vec2::ZERO);

	this->preloadAll();
	this->addChild(pMenu);

    return true;
}
void HelloWorld::doStart(Ref* pSender) {

	this->Audio_start();
	log("log : btn click");
	//씬전환
	auto pScene = HomeScene::createScene();
	Director::getInstance()->pushScene(pScene);

}
void HelloWorld::preloadAll() {

	SimpleAudioEngine::getInstance()->preloadEffect("Sounds/start.mp3");
	log("log : preload");

}
void HelloWorld::Audio_start() {

	int soundID = SimpleAudioEngine::getInstance()->playEffect("Sounds/start.mp3");
	log("log : play audio");

}
HelloWorld::~HelloWorld() {

	//AudioEngine::end();
	log("log : Audio end");

}