#ifndef SCREEPS_SOURCE_HPP
#define SCREEPS_SOURCE_HPP

#include "Constants.hpp"
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

	static const int findConstant = Screeps::FIND_SOURCES;
};

} // namespace Screeps

#endif // SCREEPS_SOURCE_HPP
