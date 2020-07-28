#include "HomeScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

Scene* HomeScene::createScene()
{
    return HomeScene::create();
}

bool HomeScene::init()
{
    if ( !Scene::init() )
    {
        return false;
    }

	auto wlayer = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(wlayer);

	////////////////////////////

	auto background1 = Sprite::create("Images/bg_loading_ovenbreak0002.png");
	background1->setAnchorPoint(Vec2(0, 0));
	background1->setPosition(Vec2(0, 0));
	//background1->setScale(1);
	this->addChild(background1);
	this->set_Homecookie();

    return true;
}
void HomeScene::set_Homecookie() { //Running...

	auto texture = Director::getInstance()->getTextureCache()->addImage("Images/Moonlight_MoveSheet.png");

	auto animation = Animation::create();
	animation->setDelayPerUnit(0.06f);

	for (int i = 0; i < 6; i++) {
		int column = i % 3;
		int row = i / 3;

		animation->addSpriteFrameWithTexture(texture, Rect(column * 380, row * 380, 380, 380));
	}

	auto Home_Cookie = Sprite::createWithTexture(texture, Rect(0, 0, 380, 380));
	Home_Cookie->setPosition(Vec2(640, 360));
	this->addChild(Home_Cookie);

	auto animate = Animate::create(animation);
	auto rep = RepeatForever::create(animate);
	Home_Cookie->runAction(rep);

}