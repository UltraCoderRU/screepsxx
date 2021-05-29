#ifndef SCREEPS_CONSTRUCTION_SITE_HPP
#define SCREEPS_CONSTRUCTION_SITE_HPP

#include "Constants.hpp"
#include "RoomObject.hpp"

namespace Screeps {

class ConstructionSite : public RoomObject
{
public:
	explicit ConstructionSite(JS::Value value);

	std::string id() const;

	bool my() const;

	std::string owner() const;

	int progress() const;

	int progressTotal() const;

	std::string structureType() const;

	int remove();

	static const int findConstant = Screeps::FIND_CONSTRUCTION_SITES;
};

} // namespace Screeps

#endif // SCREEPS_CONSTRUCTION_SITE_HPP
