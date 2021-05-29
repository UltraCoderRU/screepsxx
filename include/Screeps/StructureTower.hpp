#ifndef SCREEPS_STRUCTURE_TOWER_HPP
#define SCREEPS_STRUCTURE_TOWER_HPP

#include "OwnedStructure.hpp"

namespace Screeps {

class Creep;
class Store;
class Structure;

class StructureTower : public OwnedStructure
{
public:
	explicit StructureTower(JS::Value value);

	Store store() const;

	int attack(const Creep& target);
	int attack(const Structure& target);

	int heal(const Creep& target);

	int repair(const Structure& target);
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_TOWER_HPP
