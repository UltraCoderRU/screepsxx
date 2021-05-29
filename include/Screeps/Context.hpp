#ifndef SCREEPS_CONTEXT_HPP
#define SCREEPS_CONTEXT_HPP

#include "Game.hpp"
#include "Memory.hpp"
#include "PathFinder.hpp"
#include "RawMemory.hpp"

namespace Screeps {

class Context
{
public:
	static Context& getInstance()
	{
		static Context context;
		return context;
	}

	static void update()
	{
		Game.setValue(JS::getGlobal("Game"));
		Memory.setValue(JS::getGlobal("Memory"));
		RawMemory.setValue(JS::getGlobal("RawMemory"));
		PathFinder.setValue(JS::getGlobal("PathFinder"));
	}

private:
	Context() = default;
};

} // namespace Screeps

#endif // SCREEPS_CONTEXT_HPP
