#include "Objets.h"
#include "src/utils/Vector2D.h"

Objets::Objets(Vector2D _position, unsigned int h, unsigned int w, Texture* text)
{
	position = _position;
	rect.x = position.getX();
	rect.y = position.getY();
	rect.w = w;
	rect.h = h;

	texture = text;
}

Objets::~Objets()
{
	texture = nullptr;
}

void Objets::render()
{
	texture->render(rect);
}


SDL_Rect* Objets::getRect()
{

	return &rect;
}

Texture* Objets::getText()
{
	return texture;
}

Vector2D* Objets::getPos()
{

	return &position;
}

void Objets::setPos(Vector2D pos)
{
	position = pos;
	rect.x = pos.getX();
	rect.y = pos.getY();
}

void Objets::Size(int change)
{
	rect.w = change;
}

void Objets::MovingObject(Vector2D position, unsigned int h, unsigned int w, Texture* text, Vector2D dir_)
{
	dir = dir_;
}

void Objets::render()
{
	Objets::render();
}

void Objets::update()
{
	setPos(*getPos() + *getDir());
}

Vector2D* Objets::getDir()
{
	return &dir;
}

void Objets::setDir(Vector2D dir_)
{
	dir = dir_;
}