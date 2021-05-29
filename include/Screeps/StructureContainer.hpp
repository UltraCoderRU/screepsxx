#ifndef SCREEPS_STRUCTURE_CONTAINER_HPP
#define SCREEPS_STRUCTURE_CONTAINER_HPP

#include "Structure.hpp"

namespace Screeps {

class Store;

class StructureContainer : public Structure
{
public:
	explicit StructureContainer(JS::Value value);

	Store store() const;

	int ticksToDecay() const;
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_CONTAINER_HPP
