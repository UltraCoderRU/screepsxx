#ifndef SCREEPS_STRUCTURE_CONTROLLER_HPP
#define SCREEPS_STRUCTURE_CONTROLLER_HPP

#include "OwnedStructure.hpp"

namespace Screeps {

class StructureController : public OwnedStructure
{
public:
	explicit StructureController(JS::Value value);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_CONTROLLER_HPP
