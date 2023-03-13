#include "FighterCtrl.h"

#include "../ecs/Manager.h"
#include "../GameManager/State.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"

FighterCtrl::FighterCtrl(float speed, float thrust, float maxSpeed)
	: Component(), speed_(speed), thrust_(thrust), maxSpeed_(maxSpeed) {
}

void FighterCtrl::init() {
	tr_ = entity_->getComponent<Transform>();
	assert(tr_ != nullptr);
}

void FighterCtrl::update() {
	auto* gameState = entity_->getMngr()->getHandler<GM>()->getComponent<State>();
	if (gameState->getGameState() != GameState::RUNNING) {
		return;
	}

	handleInput();

	auto dir = tr_->getDir();
	if (dir.magnitude() >= maxSpeed_) {
		dir = dir.normalize() * maxSpeed_;
	}

	tr_->setDir(dir);
}

void FighterCtrl::handleInput() {
	if (!ih().keyDownEvent()) {
		return;
	}

	auto dir = tr_->getDir();
	const auto rotation = tr_->getRotation();
	if (ih().isKeyDown(SDL_SCANCODE_UP)) {
		dir = dir + Vector2D(0, -1).rotate(rotation) * thrust_;
		sdlutils().soundEffects().at("thrust").play();
	}

	if (ih().isKeyDown(SDL_SCANCODE_LEFT)) {
		tr_->setRotation(rotation - 5);
	}

	if (ih().isKeyDown(SDL_SCANCODE_RIGHT)) {
		tr_->setRotation(rotation + 5);
	}

	tr_->setDir(dir);
}
