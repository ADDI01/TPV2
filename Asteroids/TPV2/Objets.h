#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <SDL_image.h>
#include "src/sdlutils/Texture.h"
using namespace std;


class Objets
{
private:

	SDL_Rect rect;
	Vector2D position;
	Texture* texture = nullptr;
	Vector2D dir = { 0,0 };

public:
	//constructora
	Objets() {};
	Objets(Vector2D position, unsigned int h, unsigned int w, Texture* text);

	virtual ~Objets();

	//metodos de gameObject
	//virtual void render();// si se pone const es en todos los render
	//virtual void update(){};
	//virtual void handdleEvents(SDL_Event event){};

	virtual void render();
	//virtual void update() {};
	virtual void handdleEvents(SDL_Event event) {};

	//metodos de la propia clase
	virtual void loadFromFile() = 0;
	virtual string saveToFile() = 0;

	//quitar el virtual de estos??
	SDL_Rect* getRect();
	Texture* getText();
	Vector2D* getPos();
	void setPos(Vector2D pos);
	void update();
	Vector2D* getDir();
	void setDir(Vector2D dir_);
	virtual void Size(int change);
	void MovingObject(Vector2D position, unsigned int h, unsigned int w, Texture* text, Vector2D dir_);
	virtual bool eliminar() { return false; };

};
