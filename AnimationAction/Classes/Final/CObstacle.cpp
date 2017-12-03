#include "CObstacle.h"

USING_NS_CC;
using namespace cocostudio::timeline;

CObstacle::CObstacle(const char *csbname, cocos2d::Layer &parent)
{
	//讀取障礙
	_obsRoot = CSLoader::createNode(csbname);
	//預設位置
	_obsRoot->setPosition(155, 330);
	//加到小孩
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
	
	_obsRoot->runAction(_triAction);//生成
	_triAction->gotoFrameAndPlay(0, 35, false);//生成的持續時間
	_obsRoot->runAction(_obsAction);//前進
}

void CObstacle::setPosition(const cocos2d::Point & pos)
{
	_obsRoot->setPosition(pos);
}

void CObstacle::setPosition(const float x, const float y)
{
	_obsRoot->setPosition(x,y);
}
