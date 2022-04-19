#ifndef SCREEPS_ROOM_HPP
#define SCREEPS_ROOM_HPP

#include "Constants.hpp"
#include "Object.hpp"

namespace Screeps {

class RoomObject;
class RoomPosition;
class StructureController;
class StructureStorage;

class Room : public Object
{
public:
	explicit Room(JS::Value value);

	std::optional<StructureController> controller() const;

	int energyAvailable() const;

	int energyCapacityAvailable() const;

	JSON memory() const;
	void setMemory(const JSON&);

	std::string name() const;

	std::optional<StructureStorage> storage() const;

	// StructureTerminal terminal() const;

	// RoomVisual visual() const;

	// std::string serializePath(...)

	// ... deserializePath(const std::string& path);

	int createConstructionSite(int x,
	                           int y,
	                           const std::string& structureType,
	                           const std::optional<std::string>& name = std::nullopt);
	int createConstructionSite(const RoomPosition& pos,
	                           const std::string& structureType,
	                           const std::optional<std::string>& name = std::nullopt);

	int createFlag(int x,
	               int y,
	               const std::optional<std::string>& name = std::nullopt,
	               const std::optional<std::string>& color = std::nullopt,
	               const std::optional<std::string>& secondaryColor = std::nullopt);
	int createFlag(const RoomPosition& pos,
	               const std::optional<std::string>& name = std::nullopt,
	               const std::optional<std::string>& color = std::nullopt,
	               const std::optional<std::string>& secondaryColor = std::nullopt);

	std::vector<std::unique_ptr<RoomObject>>
	find(int type, std::function<bool(const JS::Value&)> predicate = {}) const;

	template <class T>
	std::vector<std::unique_ptr<RoomObject>> find(std::function<bool(const T&)> predicate = {}) const
	{
		if (predicate)
		{
			auto p = [&](const JS::Value& value)
			{
				return predicate(T(value));
			};
			return find(T::findConstant, p);
		}
		else
			return find(T::findConstant);
	}

	int findExitTo(const std::string& room);
	int findExitTo(const Room& room);

	// ... findPath(const RoomPosition& fromPos, const RoomPosition& toPos, JSON options);

	// ... getEventLog(bool raw);

	std::optional<RoomPosition> getPositionAt(int x, int y);

	// RoomTerrain getTerrain();

	// ... lookAt(int x, int y);
	// ... lookAt(const RoomPosition& target);

	// ... lookAtArea(int top, int left, int bottom, int right, const std::optional<bool>& asArray = std::nullopt);

	// ... lookForAt(const std::string& type, int x, int y);
	// ... lookForAt(const std::string& type, const RoomPosition& target);

	// ... lookAtArea(const std::string& type,
	//                int top,
	//                int left,
	//                int bottom,
	//                int right,
	//                const std::optional<bool>& asArray = std::nullopt);
};

} // namespace Screeps

#endif // SCREEPS_ROOM_HPP
