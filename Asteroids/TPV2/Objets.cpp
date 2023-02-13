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

//string Objets::loadFromFile(string str)
//{
//	//ifstream myfile(str);
//	//string level;
//	//if (myfile.is_open()) {
//	//	char mychar;
//	//	while (myfile) {
//	//		mychar = myfile.get();
//	//		level += mychar;
//	//	}
//	//	return level;
//	//}
//	//else throw std::string(" fichero de mapa de bloques no encontrado o no valido ");
//	return" ";
//}
//
//void Objets::saveToFile(string level)
//{
//	ofstream MyFile("../Mapas/saveFile.txt");
//	MyFile << level;
//	MyFile.close();
//}

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
