#pragma once
#include "../ecs/Component.h"
#include "../ecs/Entity.h"
#include "Transform.h"
#include "../sdlutils/Texture.h"
#include "../sdlutils/SDLUtils.h"

class FIghterJ :	public Component{

public:
	FIghterJ(float speed, float thrust, float maxSpeed);
	virtual ~FIghterJ();
	virtual void init() override;
	virtual void update() override;

	void ShowAtOppositeSide();

	virtual void render() override;

	inline void setHealth(int h) { currHealth_ = h; }
	inline int getHealth() { return currHealth_; }
	inline void resetHealth() { currHealth_ = health_; }
	
private:

	Transform* tr_;
	float speed_, maxSpeed_,thrust_;
	int currHealth_, health_;
	Texture* tex_;

};

