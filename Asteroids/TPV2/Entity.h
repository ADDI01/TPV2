#include <vector>
#include "Component.h"
class Entity
{
public:
	Entity();
	virtual ~Entity();
	//Method: Para pasarle el Manager, lo necesita para pasarle a sus componentes
	inline void setContext(Manager* mngr);
	//Method: Consultar y cambiar el estado(alive o dead).
	inline bool isAlive();
	inline void setAlive(bool alive);

private:
#pragma region References
	Manager* mngr_;
#pragma endregion
#pragma region Atributes
	bool alive_;
	vector<Component*> currCmps_;
	array<Component*, ecs::maxComponentId> cmps_;
#pragma endregion
};

