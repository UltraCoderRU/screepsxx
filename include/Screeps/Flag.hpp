#ifndef SCREEPS_FLAG_HPP
#define SCREEPS_FLAG_HPP

#include "RoomObject.hpp"

namespace Screeps {

class Flag : public RoomObject
{
public:
	explicit Flag(JS::Value value);

	int color() const;

	JSON memory() const;
	void setMemory(const JSON&);

	std::string name() const;

	int secondaryColor() const;

	void remove();

	int setColor(int color, const std::optional<int>& secondaryColor);

	int setPosition(int x, int y);
	int setPosition(const RoomPosition& pos);
	int setPosition(const RoomObject& pos);
};

} // namespace Screeps

#endif // SCREEPS_FLAG_HPP
