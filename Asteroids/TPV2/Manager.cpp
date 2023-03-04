#include "Manager.h"

template<typename T, typename Ts>
inline T* Manager<T, Ts>:: addSystem(Ts && args) {
	constexpr sysId_type sId = T::id;
	removeSystem<T>();
	System* s = new T(std::forward<Ts>(args)...);
	s->setContext(this);
	s->initSystem();
	sys_[sId] = s;
	return static_cast<T*>(s);
}

template<typename T, typename Ts>
inline T* Manager<T, Ts>:: getSystem() {
	constexpr sysId_type sId = T::id;
	return static_cast<T*>(sys_[sId]);
}

template<typename T, typename Ts>
inline void Manager<T, Ts>:: removeSystem() {
	constexpr sysId_type sId = T::id;
	if (sys_[sId] != nullptr) {
		delete sys_[sId];
		sys_[sId] = nullptr;
	}
}

template<typename T, typename Ts>
inline T* Manager<T, Ts>::addComponent(Entity* e, Ts&& args){
	T* c = new T(std::forward<Ts>(args));
	constexpr cmpId_type cId = T::id;
	removeComponent<T>()
		e->currCmps_.push_back(c);
	e->cmps_[cId] = c;
	e->setContext(e, this);
	e->initComponent();
	return c;
}

template<typename T, typename Ts>
inline void Manager<T, Ts>::removeComponent(Entity* e) {
	constexpr cmpId_type cId = T::id;
	if (e->cmps_[cId] != nullptr) {
		auto iter = std::find(e->currCmps_.begin(),
			e->currCmps_.end(),
			e->cmps_[cId]);
		e->currCmps_.erase(iter);
		delete e->cmps_[cId];
		e->cmps_[cId] = nullptr;
	}
}

template<typename T, typename Ts>
inline bool Manager<T, Ts>:: hasComponent(Entity* e) {
	constexpr cmpId_type cId = T::id;
	return e->cmps_[cId] != nullptr;
}
template<typename T, typename Ts>
inline T* Manager<T, Ts>::getComponent(Entity* e) {
	constexpr cmpId_type cId = T::id;
	return static_cast<T*>(e->cmps_[cId]);
}
template<typename T, typename Ts>
inline void Manager<T, Ts>::setAlive(Entity* e, bool alive) {
	e->alive_ = alive;
}
template<typename T, typename Ts>
inline bool Manager<T, Ts>::isAlive(Entity* e) {
	return e->alive_;
}
template<typename T, typename Ts>
inline grpId_type Manager<T, Ts>::groupId(Entity* e) {
	return e->gId_;
}

template<typename T, typename Ts>
inline void Manager<T, Ts>::send(const Message& m, bool delay = false) {
	if (!delay) {
		for (System* s : sys_) {
			if (s != nullptr)
				s->recieve(m);
		}
	}
	else {
		msgs_.emplace_back(m);
	}
}

template<typename T, typename Ts>
inline void Manager<T, Ts>:: flushMessages() {
	std::swap(msgs_, aux_msgs_);
	for (auto& m : aux_msgs_) {
		for (System* s : sys_) {
			if (s != nullptr)
				s->recieve(m);
		}
	}
	aux_msgs_.clear();
}
