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
	manager_.reset(new Manager());
}

Game::~Game()
{
	
	manager_.reset();
}

void Game::init()
{
	// Initialise the SDLGame singleton
	SDLUtils::init("Asteroids", 800, 600,"resources / config / sdlutilsdemo.resources.json");

	//Generate the GameManager
	Entity* gManager = manager_->addEntity();
	gManager->addComponent<State>();
	gManager->addComponent<AsteroidsManager>(5000,10);
	gManager->addComponent<GameCtrl>();
	gManager->addComponent<CollisionManager>();
	manager_->setHandler<GM>(gManager);

	//Generate the Player
	Entity* player = manager_->addEntity(); 
	player->addComponent<Transform>(Vector2D(sdlutils().width() / 2-25, sdlutils().height() / 2 -25), Vector2D(), 50, 50, 0);

	player->addComponent<Image>(&sdlutils().images().at("fighter"));
	player->addComponent<FighterCtrl>(10.0f,0.25f,3);
	player->addComponent<Health>(3, &sdlutils().images().at("heart"));
	player->addComponent<Gun>(50);
	player->addComponent<ShowAtOppositeSide>();

	manager_->setHandler<Fighter>(player);


}

void Game::start(){
	// reference to the input handler (we could use a pointer, I just . rather than ->).
	// you can also use the inline method ih() that is defined in InputHandler.h


	// a boolean to exit the loop
	bool exit_ = false;
	SDL_Event event;

	while (!exit_) {
		Uint32 startTime = sdlutils().currRealTime();

		// update the event handler
		ih().clearState();
		while (SDL_PollEvent(&event))
			ih().update(event);

		// exit when escape key is down
		if (ih().isKeyDown(SDLK_ESCAPE)) {
			exit_ = true;
		}
		manager_->refresh();
		manager_->update();

		// clear screen
		sdlutils().clearRenderer();

		manager_->render();
		manager_->getHandler<Fighter>()->render();


		// present new frame
		sdlutils().presentRenderer();

		Uint32 frameTime = sdlutils().currRealTime() - startTime;

		if (frameTime < 20)
			SDL_Delay(20 - frameTime);
	}

	// stop the music
	Music::haltMusic();
	
}

void Game::update()
{

}

void Game::render()
{


}
