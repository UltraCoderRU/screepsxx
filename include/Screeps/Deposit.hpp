#ifndef SCREEPS_DEPOSIT_HPP
#define SCREEPS_DEPOSIT_HPP

#include "RoomObject.hpp"

namespace Screeps {

class Deposit : public RoomObject
{
public:
	explicit Deposit(JS::Value value);

	int cooldown() const;

	std::string depositType() const;

	std::string id() const;

	int lastCooldown() const;

	int ticksToDecay() const;
};

} // namespace Screeps

#endif // SCREEPS_DEPOSIT_HPP
