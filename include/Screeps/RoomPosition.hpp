#ifndef SCREEPS_ROOM_POSITION_HPP
#define SCREEPS_ROOM_POSITION_HPP

#include "Object.hpp"

#include <optional>

namespace Screeps {

class RoomObject;

class RoomPosition : public Object
{
public:
	explicit RoomPosition(JS::Value value);
	RoomPosition(const std::string& roomName, int x, int y);

	std::string roomName() const;
	void setRoomName(const std::string& name);

	int x() const;
	void setX(int x);

	int y() const;
	void setY(int y);

	std::unique_ptr<RoomObject>
	findClosestByPath(const std::vector<std::unique_ptr<RoomObject>>& objects);
	std::optional<JS::Value> findClosestByPath(const std::vector<JS::Value>& objects);
};

} // namespace Screeps

#endif // SCREEPS_ROOM_POSITION_HPP
