#include "Game.h"

#include "sdlutils/SDLUtils.h"
#include "utils/Vector2D.h"

#include "sdlutils/InputHandler.h"

#include "ecs/Manager.h"
#include "components/Transform.h"
#include "components/Image.h"
#include "components/FighterCtrl.h"
#include "components/Health.h"
#include "components/Gun.h"
#include "components/ShowAtOppositeSide.h"

#include "GameManager/AsteroidsManager.h"
#include "GameManager/GameCtrl.h"
#include "GameManager/CollisionManager.h"
#include "GameManager/State.h"

Game::Game()
{
	//manager_.reset(new Manager());
}

Game::~Game()
{
	// Initialise the SDLGame singleton
	SDLUtils::init("Asteroids", 800, 600, "src / resources / config / sdlutilsdemo.resources.json");


	//manager_.reset();
}

void Game::init()
{



	//Generate the Player
	Entity* player = manager_->addEntity();
	player->addComponent<Transform>(Vector2D(sdlutils().width() / 2 - 25, sdlutils().height() / 2 - 25), Vector2D(), 50, 50, 0);

	player->addComponent<Image>(&sdlutils().images().at("fighter"));
	player->addComponent<FighterCtrl>(10.0f, 0.25f, 3);
	player->addComponent<Health>(3, &sdlutils().images().at("heart"));
	player->addComponent<Gun>(50);
	player->addComponent<ShowAtOppositeSide>();

	manager_->setHandler<Fighter>(player);

	start();
}
void Game::start() 
{
	bool exit = false;
	SDL_Event event;
	while (!exit)
	{

	}

}


void Game::update()
{

}

void Game::render()
{


}