#include "Creep.hpp"

#include "ConstructionSite.hpp"
#include "JSON.hpp"
#include "RoomPosition.hpp"
#include "Source.hpp"
#include "Store.hpp"
#include "StructureController.hpp"

#include <Resource.hpp>

namespace Screeps {

Creep::Creep(JS::Value creep) : RoomObject(std::move(creep))
{
}

std::vector<Creep::Body> Creep::body() const
{
	std::vector<Creep::Body> list;
	for (const auto& part : JS::jsArrayToVector(value()["body"]))
	{
		Body body;
		if (!part["boost"].isUndefined())
			body.boost = part["boost"].as<std::string>();
		body.type = part["type"].as<std::string>();
		body.hits = part["hits"].as<int>();
		list.push_back(std::move(body));
	}
	return list;
}

int Creep::fatigue() const
{
	return value()["fatigue"].as<int>();
}

int Creep::hits() const
{
	return value()["hits"].as<int>();
}

int Creep::hitsMax() const
{
	return value()["hitsMax"].as<int>();
}

std::string Creep::id() const
{
	return value()["id"].as<std::string>();
}

JSON Creep::memory() const
{
	return JS::toJSON(value()["memory"]);
}

void Creep::setMemory(const JSON& memory)
{
	value().set("memory", JS::fromJSON(memory));
}

bool Creep::my() const
{
	return value()["my"].as<bool>();
}

std::string Creep::name() const
{
	return value()["name"].as<std::string>();
}

std::string Creep::owner() const
{
	return value()["owner"]["username"].as<std::string>();
}

std::string Creep::saying() const
{
	return value()["saying"].as<std::string>();
}

bool Creep::spawning() const
{
	return value()["spawning"].as<bool>();
}

Store Creep::store() const
{
	return Store(value()["store"]);
}

int Creep::ticksToLive() const
{
	return value()["ticksToLive"].as<int>();
}

int Creep::attack(const RoomObject& target)
{
	return value().call<int>("attack", target.value());
}

int Creep::attackController(const StructureController& target)
{
	return value().call<int>("attackController", target.value());
}

int Creep::build(const ConstructionSite& target)
{
	return value().call<int>("build", target.value());
}

int Creep::cancelOrder(const std::string& methodName)
{
	return value().call<int>("cancelOrder", methodName);
}

int Creep::claimController(const StructureController& target)
{
	return value().call<int>("claimController", target.value());
}

int Creep::dismantle(const Structure& target)
{
	return value().call<int>("dismantle", target.value());
}

int Creep::drop(const std::string& resourceType, std::optional<int> amount)
{
	if (amount)
		return value().call<int>("drop", resourceType, *amount);
	else
		return value().call<int>("drop", resourceType);
}

int Creep::generateSafeMode(const StructureController& target)
{
	return value().call<int>("generateSafeMode", target);
}

int Creep::getActiveBodyParts(const std::string& type)
{
	return value().call<int>("getActiveBodyParts", type);
}

int Creep::harvest(const Source& target)
{
	return value().call<int>("harvest", target.value());
}

int Creep::heal(const Creep& target)
{
	return value().call<int>("heal", target.value());
}

int Creep::move(const Creep& direction)
{
	return value().call<int>("move", direction.value());
}

int Creep::move(int direction)
{
	return value().call<int>("move", direction);
}

int Creep::moveTo(int x, int y, const std::optional<JSON>& options)
{
	if (options)
		return value().call<int>("moveTo", x, y, JS::fromJSON(*options));
	else
		return value().call<int>("moveTo", x, y);
}

int Creep::moveTo(const RoomPosition& target, const std::optional<JSON>& options)
{
	if (options)
		return value().call<int>("moveTo", target.value(), JS::fromJSON(*options));
	else
		return value().call<int>("moveTo", target.value());
}

int Creep::moveTo(const RoomObject& target, const std::optional<JSON>& options)
{
	if (options)
		return value().call<int>("moveTo", target.value(), JS::fromJSON(*options));
	else
		return value().call<int>("moveTo", target.value());
}

int Creep::notifyWhenAttacked(bool enabled)
{
	return value().call<int>("notifyWhenAttacked", enabled);
}

int Creep::pickup(const Resource& target)
{
	return value().call<int>("pickup", target.value());
}

int Creep::pull(const Creep& target)
{
	return value().call<int>("pull", target.value());
}

int Creep::rangedAttack(const Creep& target)
{
	return value().call<int>("rangedAttack", target.value());
}

int Creep::rangedAttack(const Structure& target)
{
	return value().call<int>("rangedAttack", target.value());
}

int Creep::rangedHeal(const Creep& target)
{
	return value().call<int>("rangedHeal", target.value());
}

int Creep::rangedMassAttack()
{
	return value().call<int>("rangedMassAttack");
}

int Creep::repair(const Structure& target)
{
	return value().call<int>("repair", target.value());
}

int Creep::reserveController(const StructureController& target)
{
	return value().call<int>("reserveController", target.value());
}

int Creep::say(const std::string& message, bool visibleToAll)
{
	return value().call<int>("say", message, visibleToAll);
}

int Creep::signController(const StructureController& target, const std::string& text)
{
	return value().call<int>("signController", target.value(), text);
}

int Creep::suicide()
{
	return value().call<int>("suicide");
}

int Creep::transfer(const Creep& target,
                    const std::string& resourceType,
                    const std::optional<int>& amount)
{
	if (amount)
		return value().call<int>("transfer", target.value(), resourceType, *amount);
	else
		return value().call<int>("transfer", target.value(), resourceType);
}

int Creep::transfer(const Structure& target,
                    const std::string& resourceType,
                    const std::optional<int>& amount)
{
	if (amount)
		return value().call<int>("transfer", target.value(), resourceType, *amount);
	else
		return value().call<int>("transfer", target.value(), resourceType);
}

int Creep::upgradeController(const StructureController& target)
{
	return value().call<int>("upgradeController", target.value());
}

int Creep::withdraw(const RoomObject& target,
                    const std::string& resourceType,
                    const std::optional<int>& amount)
{
	if (amount)
		return value().call<int>("withdraw", target.value(), resourceType, *amount);
	else
		return value().call<int>("withdraw", target.value(), resourceType);
}

} // namespace Screeps
