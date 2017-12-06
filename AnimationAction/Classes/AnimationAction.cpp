#include "AnimationAction.h"
#include "cocostudio/CocoStudio.h"
#include "Final\CRunner.h"
#include "Final\CObstacle.h"
#include "Final\CScore.h"
#include"Final\C3SButton.h"

USING_NS_CC;

#define DOUBLEJUMP 1

using namespace cocostudio::timeline;
using namespace ui;
using namespace CocosDenshion;

Scene* AnimationAction::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = AnimationAction::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

AnimationAction::~AnimationAction()
{
	if( _myAction != nullptr ) _myAction->release();
	if (_myJump != nullptr) _myJump->release();
	if (_mycallback != nullptr) _mycallback->release();

	AnimationCache::destroyInstance();  // ���� AnimationCache ���o���귽
	SpriteFrameCache::getInstance()->removeUnusedSpriteFrames();
	Director::getInstance()->getTextureCache()->removeUnusedTextures();
	SimpleAudioEngine::getInstance()->unloadEffect("thinking cloud.mp3");
}

// on "init" you need to initialize your instance
bool AnimationAction::init()
{
	_myAction = nullptr;
	_myJump = nullptr;
	_mycallback = nullptr;

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("AnimationAction.csb");
    addChild(rootNode);

//�]�D�u�ʵe************************************************************
	auto runway = (cocos2d::Sprite *)rootNode->getChildByName("Sprite_1");
	auto action = (ActionTimeline *)CSLoader::createTimeline("AnimationAction.csb");
	rootNode->runAction(action);
	action->gotoFrameAndPlay(0, 11, true);

//�I������**************************************************************
	auto bgm = (cocostudio::ComAudio *)rootNode->getChildByName("BGM")->getComponent("BGM");
	bgm->playBackgroundMusic();

//�D��******************************************************************
	auto runner = CRunner("RunnerNode.csb", *this);
	runner.setPosition(1100,330);
	runner.setAnimation("cuberanim.plist");
	runner.go();
	SimpleAudioEngine::getInstance()->preloadEffect("thinking cloud.mp3");

#ifdef DOUBLEJUMP
	_NoJumps = 0;
	_myJump = JumpBy::create(0.65f, Point(0, 0), 150, 1);
	_myJump->retain();
	_runnerPt = Vec2(1100, 330);
	_mycallback = CallFunc::create(this, callfunc_selector(AnimationAction::actionFinished));
	_mycallback->retain();
#endif

//��ê������************************************************************
	auto obj1 = CObstacle("triangleNode.csb", *this);
	obj1.setPosition(155, 330);
	obj1.effectPlay();

	/*if (runner._rect1.intersectsRect(obj1._rect2)) {
		runner.happy();
	}
*/

// Action -----------------------------------------------------------------------------------------
	//auto actionBody = Sprite::createWithSpriteFrameName("cuber01.png");
	//actionBody->setPosition(visibleSize.width / 2.0f, visibleSize.height / 2.0f);
	//actionBody->setTag(101);	// �Ω���o�Ӫ���
	//actionBody->setColor(Color3B(82, 131, 151));
	//this->addChild(actionBody);
	// �����L���d�ҳ��ϥγo�� actionBody 
//-------------------------------------------------------------------------------------------------
	
	_listener1 = EventListenerTouchOneByOne::create();	//�Ыؤ@�Ӥ@��@���ƥ��ť��
	_listener1->onTouchBegan = CC_CALLBACK_2(AnimationAction::onTouchBegan, this);		//�[�JĲ�I�}�l�ƥ�
	_listener1->onTouchMoved = CC_CALLBACK_2(AnimationAction::onTouchMoved, this);		//�[�JĲ�I���ʨƥ�
	_listener1->onTouchEnded = CC_CALLBACK_2(AnimationAction::onTouchEnded, this);		//�[�JĲ�I���}�ƥ�

	this->_eventDispatcher->addEventListenerWithSceneGraphPriority(_listener1, this);	//�[�J��Ыت��ƥ��ť��
	this->schedule(CC_SCHEDULE_SELECTOR(AnimationAction::doStep));
    return true;
}

void AnimationAction::actionFinished()
{
	// do something on complete
	CCLOG("B %d\n", _NoJumps);

#ifdef DOUBLEJUMP
	_NoJumps--;
	if (_NoJumps == 1) {
		auto moveto = MoveTo::create(0.15f, _runnerPt);
		auto actionBody = this->getChildByTag(13);
		actionBody->runAction(moveto);
		_NoJumps--;
	}
#endif
}


void AnimationAction::doStep(float dt)
{

}

void AnimationAction::CuberBtnTouchEvent(Ref *pSender, Widget::TouchEventType type)
{
	switch (type)
	{
		case Widget::TouchEventType::BEGAN:
			log("Touch Down");
			break;
		case Widget::TouchEventType::MOVED:
			log("Touch Move");
			break;
		case Widget::TouchEventType::ENDED:
			log("Touch Up");
			break;
		case Widget::TouchEventType::CANCELED:
			log("Touch Cancelled");
			break;
		default:
			break;
	}
}
bool AnimationAction::onTouchBegan(cocos2d::Touch *pTouch, cocos2d::Event *pEvent)//Ĳ�I�}�l�ƥ�
{
	Point touchLoc = pTouch->getLocation();

#ifdef DOUBLEJUMP
	//auto actionBody = this->getChildByTag(101);
	auto actionBody = this->getChildByTag(13);
	if (_NoJumps == 0) {  // �Ĥ@���Q���U
		unsigned int eid = SimpleAudioEngine::getInstance()->playEffect("thinking cloud.mp3", false);// ���񭵮���
		actionBody->runAction(Sequence::create(_myJump, _mycallback, NULL)); 
		_NoJumps++;
	}
	else if(_NoJumps == 1 ){  // �ĤG���Q���U
		_NoJumps++;
		actionBody->stopAllActions();
		unsigned int eid = SimpleAudioEngine::getInstance()->playEffect("thinking cloud.mp3", false);// ���񭵮���
		actionBody->runAction(Sequence::create(_myJump, _mycallback, NULL)); 
	}
#endif
	
	return true;
}

void  AnimationAction::onTouchMoved(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //Ĳ�I���ʨƥ�
{
	Point touchLoc = pTouch->getLocation();

}

void  AnimationAction::onTouchEnded(cocos2d::Touch *pTouch, cocos2d::Event *pEvent) //Ĳ�I�����ƥ� 
{
	Point touchLoc = pTouch->getLocation();
}