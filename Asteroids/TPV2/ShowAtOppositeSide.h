#pragma once
#include "src/ecs/Component.h"
#include "src/ecs/Entity.h"
#include "src/component/Transform.h"
#include "./src/sdlutils/SDLUtils.h"

class ShowAtOppositeSide : public Component
{
public:
	ShowAtOppositeSide() {};
	virtual ~ShowAtOppositeSide() {};

	virtual void init() override;
	virtual void update() override;

private:
	//Entity transform's pointer
	Transform* myTransform;
};