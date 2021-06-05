#include "StructureRoad.hpp"

namespace Screeps {

StructureRoad::StructureRoad(JS::Value value) : Structure(std::move(value))
{
}

int StructureRoad::ticksToDecay() const
{
	return value()["ticksToDecay"].as<int>();
}

} // namespace Screeps
