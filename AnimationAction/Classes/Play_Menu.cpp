#include "AnimationAction.h"
#include "cocostudio/CocoStudio.h"
#include "Play_Menu.h"
#include "ui/CocosGUI.h"
#include "Final/C3SButton.h"

USING_NS_CC;

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;



Scene* Play_Menu::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = Play_Menu::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}




Play_Menu::~Play_Menu()
{
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("scene101/scene101.plist");
	SpriteFrameCache::getInstance()->removeSpriteFramesFromFile("scene101/scene101bg.plist");
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
}


bool Play_Menu::init()
{
	counter = 3;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	Size size;
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	auto rootNode = CSLoader::createNode("Menu.csb");
	addChild(rootNode);

	_listener1 = EventListenerTouchOneByOne::create();	//創建一個一對一的事件聆聽器
	_listener1->onTouchBegan = CC_CALLBACK_2(Play_Menu::onTouchBegan, this);		//加入觸碰開始事件
	_listener1->onTouchMoved = CC_CALLBACK_2(Play_Menu::onTouchMoved, this);		//加入觸碰移動事件
	_listener1->onTouchEnded = CC_CALLBACK_2(Play_Menu::onTouchEnded, this);		//加入觸碰離開事件

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//加入剛創建的事件聆聽器
	/*this->schedule(CC_SCHEDULE_SELECTOR(Play_Menu::doStep));*/

	auto emiterpos = (Sprite *)(rootNode->getChildByName("Button_2"));
	Point loc = emiterpos->getPosition();
	emiterpos->setVisible(false);
	_playbtn = C3SButton::create();
	_playbtn->setButtonInfo("cuberbtn1.png", "cuberbtn2.png", "cuberbtn3.png", loc);
	this->addChild(_playbtn,2);
	//Button *playbtn = dynamic_cast<Button*>(rootNode->getChildByName("Button_2"));
	//_playbtn->addTouchEventListener(CC_CALLBACK_2(Play_Menu::PlayBtnTouchEvent, this));

	strcpy(this->_cSceneNo, "3");
	Txttime = Label::createWithBMFont("fonts/couriernew32.fnt", _cSceneNo);
	size = Txttime->getContentSize();
	Txttime->setColor(Color3B::WHITE);
	Txttime->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - size.height));
	this->addChild(Txttime, 1);

	label = CCLabelTTF::create(" ", "arial", 48);
	label->setAnchorPoint(ccp(1, 1));
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height));
	this->addChild(label);

	return true;
}

void Play_Menu::doStep(float dt)
{
	this->counter -= dt;
	if (this->counter <= 0) {
		this->counter = 0;
		this->Txttime->setVisible(false);
		label->setString("Go");
	}
	this->Txttime->setString(CCString::createWithFormat("%d", counter)->getCString());
}

void Play_Menu::next(float dt) 
{
	auto scene = AnimationAction::createScene();
	Director::getInstance()->replaceScene(scene);
}

bool Play_Menu::onTouchBegan(cocos2d::Touch * pTouch, cocos2d::Event * pEvent)
{
	Point touchLoc = pTouch->getLocation();

	return true;
}

void Play_Menu::onTouchMoved(cocos2d::Touch * pTouch, cocos2d::Event * pEvent)
{
	Point touchLoc = pTouch->getLocation();
}

void Play_Menu::onTouchEnded(cocos2d::Touch * pTouch, cocos2d::Event * pEvent)
{
	Point touchLoc = pTouch->getLocation();
	if (_playbtn->touchesBegan(touchLoc)) {
		this->schedule(CC_SCHEDULE_SELECTOR(Play_Menu::doStep),1.0f);
		this->scheduleOnce(schedule_selector(Play_Menu::next), 4);
	}
}




void Play_Menu::PlayBtnTouchEvent(cocos2d::Ref * pSender, cocos2d::ui::Widget::TouchEventType type)
{
	/*auto scene = AnimationAction::createScene();
	Director::getInstance()->replaceScene(scene);*/

}

