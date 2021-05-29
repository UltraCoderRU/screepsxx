#ifndef SCREEPS_STRUCTURE_HPP
#define SCREEPS_STRUCTURE_HPP

#include "Constants.hpp"
#include "RoomObject.hpp"

namespace Screeps {

class Structure : public RoomObject
{
public:
	explicit Structure(JS::Value value);

	int hits() const;

	int hitsMax() const;

	std::string id() const;

	std::string structureType() const;

	int destroy();

	bool isActive();

	int notifyWhenAttacked(bool enabled);

	const static int findConstant = Screeps::FIND_STRUCTURES;
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_HPP
