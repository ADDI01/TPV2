#include "Fighter.h"


void Fighter::Transform()
{
    Vector2D pos = *getPos() + *getDir();
    
}

void Fighter::DeAcceleration()
{

}

void Fighter::Image()
{

}

void Fighter::Health()
{

}

void Fighter::FighterCtrl()
{

}

void Fighter::Gun()
{

}

/*void Fighter::FighShowAtOpposideSideterCtrl()
{
    Vector2D pos = *getPos() + *getDir();

    if (pos.getX() < WALL_WIDTH)
    {
        pos = { WALL_WIDTH, pos.getY() };
    }
    else if (pos.getX() > WIN_WIDTH - WALL_WIDTH - getRect()->w)
    {
        pos = { WIN_WIDTH - (double)WALL_WIDTH - getRect()->w, pos.getY() };
    }
    setPos(pos);
}
*/
