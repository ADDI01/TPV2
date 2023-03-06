#include "AsteroidsManager.h"
#pragma region sdlutilsIncludes
#include "../sdlutils/SDLUtils.h"
#pragma endregion
#pragma region ECSIncludes
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#pragma endregion
#pragma region GameIncludes
#include "../game/State.h"
#pragma endregion
#pragma region ComponentIncludes
#include "../component/Transform.h"
#include "../component/Image.h"
#include "../component/Follow.h"
#include "../component/Generations.h"
#include "../component/ShowAtOppositeSide.h"
#include "../component/FramedImage.h"
#pragma endregion

//Method: Determinates the position where the asteroid spawns.
void AsteroidsManager::spawnPointCoordinates(Vector2D& p) {

	//Coord -> Calculates each coordinate of the asteroid (x, y) to set it on 'p' variable
	//Random -> Determinates in which edge the asteroid spawns on (top, down, left, right)
	int coord, random = sdlutils().rand().nextInt(0, 2);
	if (random == 0) {
		coord = sdlutils().rand().nextInt(0, sdlutils().width() + 1);
		p.setX(coord);
		random = sdlutils().rand().nextInt(0, 2);
		if (random == 0) p.setY(sdlutils().rand().nextInt(0, sdlutils().height() / 10));
		else p.setY(sdlutils().height() - sdlutils().rand().nextInt(0, sdlutils().height() / 10));
	}
	else {
		coord = sdlutils().rand().nextInt(0, sdlutils().width() + 1);
		p.setY(coord);
		random = sdlutils().rand().nextInt(0, 2);
		if (random == 0) p.setX(sdlutils().rand().nextInt(0, sdlutils().width() / 9));
		else p.setX(sdlutils().width() - sdlutils().rand().nextInt(0, sdlutils().width() / 9));
	}
}

//Method: Add n asteroids (70% A type, 30% B type).
			//Param -> int n: number of asteroids to add
void AsteroidsManager:: createAsteroids(int n) {
	//Calcutes the type and generation of the asteroid to be created
	int type = sdlutils().rand().nextInt(0, 10);
	int gen = sdlutils().rand().nextInt(1, 4);

	//Point of direction and Spawn position of the asteroid
	Vector2D c = Vector2D(sdlutils().width() / 2 + sdlutils().rand().nextInt(-100, 100), 
		sdlutils().height() / 2 + sdlutils().rand().nextInt(-100, 100));
	Vector2D p = Vector2D();
	spawnPointCoordinates(p); //Coordinates of 'p'.

	//Set speed and velocity vector
	float speed = sdlutils().rand().nextInt(1, 10) / 10.0f;
	Vector2D v = Vector2D(c - p).normalize() * speed;

	//Creates asteroid entity, with its parameters set and Components
	Entity* asteroid = entity_->getMngr()->addEntity();
	asteroid->addComponent<Transform>(p, v, 10 + gen * 5, 10 + gen * 5, sdlutils().rand().nextInt(0, 360));
	asteroid->addComponent<ShowAtOppositeSide>();
	asteroid->addComponent<Generations>(gen);
	asteroid->setGroup<Asteroids>(true);

	if (type <= 3) { //Type B asteroid. It has the Follow component, in order to chase the Fighter
		asteroid->addComponent<FramedImage>(&(sdlutils().images().at("asteroid_gold")), 5, 6, 0, 0, 50.0f);
		asteroid->addComponent<Follow>();
	}
	//Type A asteroid. Just a regular asteroid with random direction vector
	else asteroid->addComponent<FramedImage>(&(sdlutils().images().at("asteroid")), 5, 6, 0, 0, 50.0f);

	nAsteroids++;
}
//Method: Generates an asteroid every 5 sec calling 'createAsteroids(1)'.
void addAsteroidsFrequently() {

}
//Method: Handles collisions bullet-asteroid. If a bullet collides, desactivates the asteroid and 
//generates 2 new ones (depending on the generation).
		//Param -> Entity *a: the asteroid about to be checked
bool onCollision(Entity* a) {

}
//Method: Desactivates all asteroids on the screen calling the 'setActive(false)' method of every one of them.
void destroyAllAsteroids() {
	for (auto a : _manager) {

	}
}