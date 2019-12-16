#pragma once
#include "Action.h"
class DeleteGameObjectAction :public Action
{
	CellPosition objPos;
public:
	DeleteGameObjectAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~DeleteGameObjectAction();
};

