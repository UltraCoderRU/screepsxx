#include "Deposit.hpp"

namespace Screeps {

Deposit::Deposit(JS::Value value) : RoomObject(std::move(value))
{
}

int Deposit::cooldown() const
{
	return value()["cooldown"].as<int>();
}

std::string Deposit::depositType() const
{
	return value()["depositType"].as<std::string>();
}

std::string Deposit::id() const
{
	return value()["id"].as<std::string>();
}

int Deposit::lastCooldown() const
{
	return value()["lastCooldown"].as<int>();
}

int Deposit::ticksToDecay() const
{
	return value()["ticksToDecay"].as<int>();
}

} // namespace Screeps
