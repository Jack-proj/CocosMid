#include "CObstacle.h"

USING_NS_CC;
using namespace cocostudio::timeline;

CObstacle::CObstacle(const char *csbname, cocos2d::Layer &parent)
{
	//Ū����ê
	_obsRoot = CSLoader::createNode(csbname);
	//�w�]��m
	_obsRoot->setPosition(155, 330);
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
	_obsAction = MoveTo::create(3.0f, Point(1375, 330));
	
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
