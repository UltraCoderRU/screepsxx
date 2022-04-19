#include "StructureTerminal.hpp"

namespace Screeps {

StructureTerminal::StructureTerminal(JS::Value value) : OwnedStructure(std::move(value))
{
}

int StructureTerminal::cooldown() const
{
	return value()["cooldown"].as<int>();
}

Store StructureTerminal::store() const
{
	return Store(value()["store"]);
}

int StructureTerminal::send(const std::string& resourceType,
                            int amount,
                            const std::string& destination,
                            const std::optional<std::string>& description)
{
	if (description)
		return value().call<int>("send", resourceType, amount, destination, description);
	else
		return value().call<int>("send", resourceType, amount, destination);
}

} // namespace Screeps
