#ifndef SCREEPS_PATH_FINDER_HPP
#define SCREEPS_PATH_FINDER_HPP

#include "Object.hpp"

namespace Screeps {

class PathFinderObject : public Object
{
public:
	PathFinderObject();
};

extern PathFinderObject PathFinder;

} // namespace Screeps

#endif // SCREEPS_PATH_FINDER_HPP
