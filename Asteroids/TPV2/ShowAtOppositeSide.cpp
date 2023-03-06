#include "ShowAtOppositeSide.h"


void ShowAtOppositeSide::init()
{
	myTransform = entity_->getComponent<Transform>();
	assert(myTransform != nullptr); //Stops the program if myTransform isn't well initialize
}

//Method: Checks if the Entity is out of the limits of the screen. If so, updates the position to the other side
	//side of the screen to simulate a 'teleport'.
void ShowAtOppositeSide::update()
{
	//Its out of right or left edge
	if (myTransform->getPos().getX() > sdlutils().width())
		myTransform->setPos(myTransform->getW(), myTransform->getPos().getY());
	else if (myTransform->getPos().getX() < 0)
		myTransform->setPos(sdlutils().width() - myTransform->getW(), myTransform->getPos().getY());
	//its out of top or bot edge
	if (myTransform->getPos().getY() > sdlutils().height())
		myTransform->setPos(myTransform->getPos().getX(), myTransform->getH());
	else if (myTransform->getPos().getY() < 0)
		myTransform->setPos(myTransform->getPos().getX(), sdlutils().height() - myTransform->getH());
}
