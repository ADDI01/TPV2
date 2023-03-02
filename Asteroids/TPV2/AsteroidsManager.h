/// <summary>
/// Handles the creation and destruction of asteroids
/// </summary>

#include "Entity.h"
#include "Manager.h"
class AsteroidsManager
{
public:
#pragma region Methods
	//Method: Add n asteroids (70% A type, 30% B type).
			//Param -> int n: number of asteroids to add
	void createAsteroids(int n);
	//Method: Generates an asteroid every 5 sec calling 'createAsteroids(1)'.
	void addAsteroidsFrequently();
	//Method: Handles collisions bullet-asteroid. If a bullet collides, desactivates the asteroid and 
	//generates 2 new ones (depending on the generation).
			//Param -> Entity *a: the asteroid about to be checked
	bool onCollision(Entity* a);
	//Method: Desactivates all asteroids on the screen calling the 'setActive(false)' method of every one of them.
	void destroyAllAsteroids();
#pragma endregion

private:
#pragma region References
	Manager _manager;
#pragma endregion
#pragma region Atributes
	const int MAX_ASTEROIDS; //Maximum astroids
	int currAsteroids; //Current number of asteroids
#pragma region
};

