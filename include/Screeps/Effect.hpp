#ifndef SCREEPS_EFFECT_H
#define SCREEPS_EFFECT_H

#include <optional>

namespace Screeps {

struct Effect
{
	int effect;
	std::optional<int> level;
	int ticksRemaining;
};

} // namespace Screeps

#endif // SCREEPS_EFFECT_H
