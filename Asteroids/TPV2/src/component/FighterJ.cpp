#include "FIghterJ.h"
#include "../ecs/Manager.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../game/State.h"
#include "../game/ecs_defs.h"

FIghterJ::FIghterJ(float speed, float thrust, float maxSpeed) :
	Component(), speed_(speed), thrust_(thrust), maxSpeed_(maxSpeed)
{
}

FIghterJ::~FIghterJ()
{
}

void FIghterJ::init()
{
	tr_ = entity_->getComponent<Transform>();
	assert(tr_ != nullptr);
}

void FIghterJ::update()
{
	if (entity_->getMngr()->getHandler<GM>()->getComponent<State>()->getGameState() == GameState::RUNNING) {
		auto dir = tr_->getDir();

		if (ih().keyDownEvent()) {
			if (ih().isKeyDown(SDL_SCANCODE_UP)) {
				dir = dir + Vector2D(0, -1).rotate(tr_->getRotation()) * thrust_;
				sdlutils().soundEffects().at("thrust").play();
			}

			else if (ih().isKeyDown(SDL_SCANCODE_LEFT)) {

				tr_->setRotation(tr_->getRotation() - 5);
			}
			else if (ih().isKeyDown(SDL_SCANCODE_RIGHT)) {

				tr_->setRotation(tr_->getRotation() + 5);
			}
		}

		if (dir.magnitude() >= maxSpeed_) {
			dir = dir.normalize() * maxSpeed_;
		}

		ShowAtOppositeSide();


		tr_->setDir(dir);


		dir = tr_->getDir() * thrust_;

	}
}
void FIghterJ::ShowAtOppositeSide()
{
	if (tr_->getPos().getX() < 0) {
		tr_->setPos(sdlutils().width() - tr_->getW(), tr_->getPos().getY());
	}
	else if (tr_->getPos().getX() > sdlutils().width()) {

		tr_->setPos(tr_->getW(), tr_->getPos().getY());
	}

	if (tr_->getPos().getY() < 0) {

		tr_->setPos(tr_->getPos().getX(), sdlutils().height() - tr_->getH());
	}
	else if (tr_->getPos().getY() > sdlutils().height()) {

		tr_->setPos(tr_->getPos().getX(), tr_->getH());
	}

}


void FIghterJ::render()
{
	for (int i = 0; i < currHealth_; i++) {
		SDL_Rect dest;
		dest.x = sdlutils().width() / 2 - 120 + 35 * i;
		dest.y = 10;
		dest.w = 30;
		dest.h = 30;

		tex_->render(dest, 0.0f);

	}
}
