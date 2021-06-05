#ifndef SCREEPS_OBJECT_HPP
#define SCREEPS_OBJECT_HPP

#include "JS.hpp"

namespace Screeps {

class Object
{
public:
	using Error = int;

	JS::Value& value();
	const JS::Value& value() const;
	void setValue(JS::Value value);

	operator JS::Value&();
	operator const JS::Value&() const;

protected:
	Object();
	explicit Object(JS::Value value);
	~Object();

private:
	JS::Value value_;
};

} // namespace Screeps

#endif // SCREEPS_OBJECT_HPP
