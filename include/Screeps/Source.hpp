#ifndef SCREEPS_SOURCE_HPP
#define SCREEPS_SOURCE_HPP

#include "RoomObject.hpp"

namespace Screeps {

class Source : public RoomObject
{
public:
	explicit Source(JS::Value value);

	int energy() const;

	int energyCapacity() const;

	std::string id() const;

	int ticksToLive() const;
};

} // namespace Screeps

#endif // SCREEPS_SOURCE_HPP
