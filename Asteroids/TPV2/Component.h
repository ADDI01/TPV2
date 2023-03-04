#include "Manager.h"

class Entity;
class Component{
public:
	Component() : ent_(), mngr_() {}
	virtual ~Component() {}
	//Method: Para pasarle un puntero asu entidad y al manager
	inline void setContext(Entity* ent, Manager* mngr) {
		ent_ = ent;
		mngr_ = mngr;
	}
	//Method: Se invoca al añadir un componentea una entidad, para inicializar el componente si es necesario
	virtual void initComponent() {}
	virtual void update() {}
	virtual void render() {}
protected:
	Entity* ent_;
	Manager* mngr_;

};

