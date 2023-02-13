#pragma once
#include "src/utils/Vector2D.h"
#include <SDL_image.h>
#include "src/sdlutils/Texture.h"
#include "Objets.h"

class Fighter : public Objets
{
private:
	SDL_Rect rect;
	Vector2D position;
	Texture* texture = nullptr;

	int velocity = 1;

public:
	void Transform();
	void DeAcceleration();
	void Image();
	void Health();
	void FighterCtrl();
	void Gun();
	void FighShowAtOpposideSideterCtrl();
};

