#include <vector>

class Component;
class Entity {
public:
	Entity(ecs::grpId_type gId);
	Entity(const Entity&) = delete;
	Entity& operator=(const Entity&) = delete;
	virtual ~Entity();
	void update();
	void render();
private:
	friend Manager;
	std::vector<Component*> currCmps_;
	std::array<Component*, maxComponentId> cmps_;
	bool alive_;
	ecs::grpId_type gId_;
};

