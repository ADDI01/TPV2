#include "Entity.h"
#include "Message.h"

template<typename T, typename Ts>
class Manager {
public:
	Manager(){}
	virtual ~Manager(){}
	inline Entity* addEntity(grpId_type gId);
	inline const auto& getEntitiesByGroup(grpId_type gId);
	inline void setHandler(hdlrId_type hId, Entity* e);
	inline Entity* getHandler(hdlrId_type hId);
	inline T* addSystem(Ts&& args);
	inline T* getSystem();
	inline void removeSystem();
	void update();
	void render();
	void refresh();

	inline T* addComponent(Entity* e, Ts&& args);
	inline void removeComponent(Entity* e);
	inline bool hasComponent(Entity* e);
	inline T* getComponent(Entity* e);
	inline void setAlive(Entity* e, bool alive);
	inline bool isAlive(Entity* e);
	inline grpId_type groupId(Entity* e);

	inline void send(const Message& m, bool delay = false);
	inline void flushMessages();
private:
	std::array<Entity*, maxHandlerId> hdlrs_;
	std::array<std::vector<Entity*>, maxGroupId> entsByGroup_;
	std::array<System*, maxSystemId> sys_;
	std::vector<Message> msgs_;
	std::vector<Message> aux_msgs_;
};

