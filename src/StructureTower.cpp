#include "StructureTower.hpp"

#include "Creep.hpp"
#include "Store.hpp"
#include "Structure.hpp"

namespace Screeps {

StructureTower::StructureTower(JS::Value value) : OwnedStructure(std::move(value))
{
}

Store StructureTower::store() const
{
	return Store(value()["store"]);
}

int StructureTower::attack(const Creep& target)
{
	return value().call<int>("attack", target.value());
}

int StructureTower::attack(const Structure& target)
{
	return value().call<int>("attack", target.value());
}

int StructureTower::heal(const Creep& target)
{
	return value().call<int>("heal", target.value());
}

int StructureTower::repair(const Structure& target)
{
	return value().call<int>("repair", target.value());
}

} // namespace Screeps
