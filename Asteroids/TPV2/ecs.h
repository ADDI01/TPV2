

using sysId_type = uint8_t;
enum sysId : sysId_type {
	_sys_ASTEROIDS = 0,
	_sys_COLLISIONS,

	// do not remove this
	_LAST_SYS_ID
};
constexpr sysId_type maxSystemId = _LAST_SYS_ID;

