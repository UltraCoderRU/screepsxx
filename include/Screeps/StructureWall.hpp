#ifndef SCREEPS_STRUCTURE_WALL_HPP
#define SCREEPS_STRUCTURE_WALL_HPP

#include "Structure.hpp"

namespace Screeps {

class StructureWall : public Structure
{
public:
	explicit StructureWall(JS::Value value);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_WALL_HPP
