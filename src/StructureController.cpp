#include "StructureController.hpp"

namespace Screeps {

StructureController::StructureController(JS::Value value) : OwnedStructure(std::move(value))
{
}

bool StructureController::isPowerEnabled() const
{
	return value()["isPowerEnabled"].as<bool>();
}

int StructureController::level() const
{
	return value()["level"].as<int>();
}

int StructureController::progress() const
{
	return value()["progress"].as<int>();
}

int StructureController::progressTotal() const
{
	return value()["progressTotal"].as<int>();
}

std::optional<StructureController::Reservation> StructureController::reservation() const
{
	auto obj = value()["reservation"];
	if (obj.isUndefined())
		return std::nullopt;
	else
	{
		Reservation result;
		result.username = obj["username"].as<std::string>();
		result.ticksToEnd = obj["ticksToEnd"].as<int>();
		return result;
	}
}

std::optional<int> StructureController::safeMode() const
{
	auto result = value()["safeMode"];
	if (result.isUndefined())
		return std::nullopt;
	return result.as<int>();
}

int StructureController::safeModeAvailable() const
{
	return value()["safeModeAvailable"].as<int>();
}

std::optional<int> StructureController::safeModeCooldown() const
{
	auto result = value()["safeModeCooldown"];
	if (result.isUndefined())
		return std::nullopt;
	return result.as<int>();
}

std::optional<StructureController::Sign> StructureController::sign() const
{
	auto obj = value()["sign"];
	if (obj.isUndefined())
		return std::nullopt;
	else
	{
		Sign result;
		result.username = obj["username"].as<std::string>();
		result.text = obj["text"].as<std::string>();
		result.time = obj["time"].as<int>();
		result.datetime = obj["datetime"].call<double>("valueOf");
		return result;
	}
}

int StructureController::ticksToDowngrade() const
{
	return value()["ticksToDowngrade"].as<int>();
}

int StructureController::upgradeBlocked() const
{
	return value()["upgradeBlocked"].as<int>();
}

int StructureController::activateSafeMode()
{
	return value().call<int>("activateSafeMode");
}

int StructureController::unclaim()
{
	return value().call<int>("unclaim");
}

} // namespace Screeps
