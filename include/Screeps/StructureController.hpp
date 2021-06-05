#ifndef SCREEPS_STRUCTURE_CONTROLLER_HPP
#define SCREEPS_STRUCTURE_CONTROLLER_HPP

#include "OwnedStructure.hpp"

#include <ctime>
#include <optional>

namespace Screeps {

class StructureController : public OwnedStructure
{
public:
	struct Reservation
	{
		std::string username;
		int ticksToEnd;
	};

	struct Sign
	{
		std::string username;
		std::string text;
		int time;
		std::int64_t datetime; // ms since epoch (UTC)
	};

	explicit StructureController(JS::Value value);

	bool isPowerEnabled() const;

	int level() const;

	int progress() const;

	int progressTotal() const;

	std::optional<Reservation> reservation() const;

	std::optional<int> safeMode() const;

	int safeModeAvailable() const;

	std::optional<int> safeModeCooldown() const;

	std::optional<Sign> sign() const;

	int ticksToDowngrade() const;

	int upgradeBlocked() const;

	int activateSafeMode();

	int unclaim();
};

} // namespace Screeps

#endif // SCREEPS_STRUCTURE_CONTROLLER_HPP
