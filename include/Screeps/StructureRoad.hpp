#ifndef SCREEPS_STRUCTURE_ROAD_HPP
#define SCREEPS_STRUCTURE_ROAD_HPP

#include "Structure.hpp"

namespace Screeps {

class StructureRoad : public Structure
{
public:
	explicit StructureRoad(JS::Value value);

	int ticksToDecay() const;
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_ROAD_HPP
