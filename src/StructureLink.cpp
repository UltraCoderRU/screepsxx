#include "StructureLink.hpp"

#include "Store.hpp"

namespace Screeps {

StructureLink::StructureLink(JS::Value value) : OwnedStructure(std::move(value))
{
}

int StructureLink::cooldown() const
{
	return value()["cooldown"].as<int>();
}

Store StructureLink::store() const
{
	return Store(value()["store"]);
}

int StructureLink::transferEnergy(const StructureLink& target, const std::optional<int>& amount)
{
	if (amount)
		return value().call<int>("transferEnergy", target.value(), *amount);
	else
		return value().call<int>("transferEnergy", target.value());
}

} // namespace Screeps
