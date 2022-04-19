#include "RoomObject.hpp"

#include "ConstructionSite.hpp"
#include "Creep.hpp"
#include "Deposit.hpp"
#include "Effect.hpp"
#include "Flag.hpp"
#include "Resource.hpp"
#include "Room.hpp"
#include "RoomPosition.hpp"
#include "Ruin.hpp"
#include "Source.hpp"
#include "StructureContainer.hpp"
#include "StructureController.hpp"
#include "StructureExtension.hpp"
#include "StructureExtractor.hpp"
#include "StructureLink.hpp"
#include "StructureRampart.hpp"
#include "StructureRoad.hpp"
#include "StructureSpawn.hpp"
#include "StructureStorage.hpp"
#include "StructureTerminal.hpp"
#include "StructureTower.hpp"
#include "StructureWall.hpp"

namespace Screeps {

RoomObject::RoomObject(JS::Value value) : Object(std::move(value))
{
}

RoomObject::~RoomObject() = default;

std::vector<Effect> RoomObject::effects() const
{
	std::vector<Effect> list;
	for (const auto& elem : JS::jsArrayToVector(value()["effects"]))
	{
		Effect effect;
		effect.effect = elem["effect"].as<int>();
		if (!elem["level"].isUndefined())
			effect.level = elem["level"].as<int>();
		effect.ticksRemaining = elem["ticksRemaining"].as<int>();
		list.push_back(std::move(effect));
	}
	return list;
}

RoomPosition RoomObject::pos() const
{
	return RoomPosition(value()["pos"]);
}

Room RoomObject::room() const
{
	return Room(value()["room"]);
}

std::unique_ptr<RoomObject> createRoomObject(JS::Value object)
{
	auto is = [&](const char* type)
	{
		return JS::isInstanceOf(object, type);
	};

	// FIXME: sort by rarity
	if (is("Structure"))
	{
		std::string type = object["structureType"].as<std::string>();
		if (type == Screeps::STRUCTURE_ROAD)
			return std::make_unique<StructureRoad>(std::move(object));
		else if (type == Screeps::STRUCTURE_WALL)
			return std::make_unique<StructureWall>(std::move(object));
		else if (type == Screeps::STRUCTURE_RAMPART)
			return std::make_unique<StructureRampart>(std::move(object));
		else if (type == Screeps::STRUCTURE_EXTENSION)
			return std::make_unique<StructureExtension>(std::move(object));
		else if (type == Screeps::STRUCTURE_CONTAINER)
			return std::make_unique<StructureContainer>(std::move(object));
		else if (type == Screeps::STRUCTURE_TOWER)
			return std::make_unique<StructureTower>(std::move(object));
		else if (type == Screeps::STRUCTURE_LINK)
			return std::make_unique<StructureLink>(std::move(object));
		else if (type == Screeps::STRUCTURE_SPAWN)
			return std::make_unique<StructureSpawn>(std::move(object));
		else if (type == Screeps::STRUCTURE_CONTROLLER)
			return std::make_unique<StructureController>(std::move(object));
		else if (type == Screeps::STRUCTURE_STORAGE)
			return std::make_unique<StructureStorage>(std::move(object));
		else if (type == Screeps::STRUCTURE_EXTRACTOR)
			return std::make_unique<StructureExtractor>(std::move(object));
		else if (type == Screeps::STRUCTURE_TERMINAL)
			return std::make_unique<StructureTerminal>(std::move(object));
		else
			return nullptr;
	}
	else if (is("Creep"))
		return std::make_unique<Creep>(std::move(object));
	else if (is("Source"))
		return std::make_unique<Source>(std::move(object));
	else if (is("ConstructionSite"))
		return std::make_unique<ConstructionSite>(std::move(object));
	else if (is("Ruin"))
		return std::make_unique<Ruin>(std::move(object));
	else if (is("Deposit"))
		return std::make_unique<Deposit>(std::move(object));
	else if (is("Flag"))
		return std::make_unique<Flag>(std::move(object));
	else if (is("Resource"))
		return std::make_unique<Resource>(std::move(object));
	else
		return nullptr;
}

} // namespace Screeps
