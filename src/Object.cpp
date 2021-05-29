#include "Object.hpp"

namespace Screeps {

Object::Object() : value_(JS::Value::null())
{
}

Object::Object(JS::Value value) : value_(std::move(value))
{
}

Object::~Object() = default;

JS::Value& Object::value()
{
	return value_;
}

const JS::Value& Object::value() const
{
	return value_;
}

void Object::setValue(JS::Value value)
{
	value_ = std::move(value);
}

Object::operator JS::Value&()
{
	return value();
}

Object::operator const JS::Value&() const
{
	return value();
}

} // namespace Screeps
