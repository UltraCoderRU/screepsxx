#ifndef SCREEPS_CREEP_H
#define SCREEPS_CREEP_H

#include "JSON.hpp"
#include "RoomObject.hpp"

#include <optional>

namespace Screeps {

class ConstructionSite;
class Resource;
class Source;
class Store;
class Structure;
class StructureController;

class Creep : public RoomObject
{
public:
	struct Body
	{
		std::optional<std::string> boost;
		std::string type;
		int hits;
	};

	explicit Creep(JS::Value);

	std::vector<Body> body() const;

	int fatigue() const;

	int hits() const;

	int hitsMax() const;

	std::string id() const;

	JSON memory() const;
	void setMemory(const JSON& memory);

	bool my() const;

	std::string name() const;

	std::string owner() const;

	std::string saying() const;

	bool spawning() const;

	Store store() const;

	int ticksToLive() const;

	int attack(const RoomObject& target);

	int attackController(const StructureController& target);

	int build(const ConstructionSite& target);

	int cancelOrder(const std::string& methodName);

	int claimController(const StructureController& target);

	int dismantle(const Structure& target);

	int drop(const std::string& resourceType, std::optional<int> amount);

	int generateSafeMode(const StructureController& target);

	int getActiveBodyParts(const std::string& type);

	int harvest(const Source& target);

	int heal(const Creep& target);

	int move(const Creep& direction);
	int move(int direction);

	// int moveByPath(...);

	int moveTo(int x, int y, const std::optional<JSON>& options = std::nullopt);
	int moveTo(const RoomPosition& target, const std::optional<JSON>& options = std::nullopt);
	int moveTo(const RoomObject& target, const std::optional<JSON>& options = std::nullopt);

	int notifyWhenAttacked(bool enabled);

	int pickup(const Resource& target);

	int pull(const Creep& target);

	int rangedAttack(const Creep& target);
	int rangedAttack(const Structure& target);

	int rangedHeal(const Creep& target);

	int rangedMassAttack();

	int repair(const Structure& target);

	int reserveController(const StructureController& target);

	int say(const std::string& message, bool visibleToAll = false);

	int signController(const StructureController& target, const std::string& text);

	int suicide();

	int transfer(const Creep& target,
	             const std::string& resourceType,
	             const std::optional<int>& amount = std::nullopt);
	int transfer(const Structure& target,
	             const std::string& resourceType,
	             const std::optional<int>& amount = std::nullopt);

	int upgradeController(const StructureController& target);

	int withdraw(const RoomObject& target,
	             const std::string& resourceType,
	             const std::optional<int>& amount = std::nullopt);
};

} // namespace Screeps

#endif // SCREEPS_CREEP_H
