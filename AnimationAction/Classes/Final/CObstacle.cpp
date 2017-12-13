#include "CObstacle.h"

USING_NS_CC;
using namespace cocostudio::timeline;

CObstacle::CObstacle(const char *csbname, cocos2d::Layer &parent)
{
	//Ū����ê
	_obsRoot = CSLoader::createNode(csbname);
	//�w�]��m
	_obsRoot->setPosition(0,0);

	_body = (cocos2d::Sprite *)_obsRoot->getChildByName("triblock.png");

	_rect2 = _obsRoot->getBoundingBox();
	
	//�[��p��
	parent.addChild(_obsRoot);
}

CObstacle::~CObstacle()
{
}

void CObstacle::effectPlay()
{
	_triAction = (ActionTimeline *)CSLoader::createTimeline("triangleNode.csb");
	_triAction->setDuration(2.0f);
	_obsAction = MoveTo::create(2.0f, Point(1375, 330));
	
	_obsRoot->runAction(_triAction);//�ͦ�
	_triAction->gotoFrameAndPlay(0, 35, false);//�ͦ�������ɶ�
	_obsRoot->runAction(_obsAction);//�e�i
}

void CObstacle::setPosition(const cocos2d::Point & pos)
{
	_obsRoot->setPosition(pos);
}

void CObstacle::setPosition(const float x, const float y)
{
	_obsRoot->setPosition(x,y);
}

void CObstacle::setScale(float s)
{
	_obsRoot->setScale(s);
}
