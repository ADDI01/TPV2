
using msgId_type = uint8_t;
enum msgId : msgId_type {
	_m_STAR_EATEN, //
	_m_ADD_STARS
};
struct Message {
	msgId_type id;
};
