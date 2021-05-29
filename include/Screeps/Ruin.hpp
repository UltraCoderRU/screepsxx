#ifndef SCREEPS_RUIN_HPP
#define SCREEPS_RUIN_HPP

#include "RoomObject.hpp"

namespace Screeps {

class Ruin : public RoomObject
{
public:
	explicit Ruin(JS::Value value);
};

} // namespace Screeps

#endif // SCREEPS_RUIN_HPP
