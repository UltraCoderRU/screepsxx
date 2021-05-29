#include "StructureContainer.hpp"

#include "Store.hpp"

namespace Screeps {

StructureContainer::StructureContainer(JS::Value value) : Structure(std::move(value))
{
}

Store StructureContainer::store() const
{
	return Store(value()["store"]);
}

int StructureContainer::ticksToDecay() const
{
	return value()["ticksToDecay"].as<int>();
}

} // namespace Screeps
