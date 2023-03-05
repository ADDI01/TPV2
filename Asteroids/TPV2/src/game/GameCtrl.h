#pragma once
#include "../ecs/Component.h"
#include "State.h"

class GameCtrl :public Component{

public:

	GameCtrl();
	virtual ~GameCtrl();

	virtual void init() override;
	virtual void update() override;

private:

	State* gameState_;
	
};

