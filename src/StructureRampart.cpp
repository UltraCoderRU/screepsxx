#include "StructureRampart.hpp"

namespace Screeps {

StructureRampart::StructureRampart(JS::Value value) : Structure(std::move(value))
{
}

bool StructureRampart::isPublic() const
{
	return value()["isPublic"].as<bool>();
}

int StructureRampart::ticksToDecay() const
{
	return value()["ticksToDecay"].as<int>();
}

int StructureRampart::setPublic(bool isPublic)
{
	return value().call<int>("setPublic", isPublic);
}

} // namespace Screeps
