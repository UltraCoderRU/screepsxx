#include "JS.hpp"

#include "JSON.hpp"

namespace JS {

Value getGlobal(char const* name)
{
	return Value::global(name);
}

Value getGlobal(const std::string& name)
{
	return Value::global(name.c_str());
}

Value getConstant(const std::string& name)
{
	return getGlobal(name);
}

bool isInstanceOf(const Value& value, const char* name)
{
	return value.instanceof (JS::Value::global(name));
}

Value fromJSONArray(const JSON& array)
{
	Value value = Value::array();

	for (std::size_t i = 0; i < array.size(); i++)
		value.set(i, fromJSON(array[i]));

	return value;
}

Value fromJSONObject(const JSON& object)
{
	Value value = Value::object();

	for (auto iter = object.begin(); iter != object.end(); ++iter)
		value.set(iter.key(), fromJSON(iter.value()));

	return value;
}

Value fromJSON(const JSON& value)
{
	if (value.is_object())
		return fromJSONObject(value);
	else if (value.is_array())
		return fromJSONArray(value);
	else if (value.is_boolean())
		return JS::Value(value.get<bool>());
	else if (value.is_number_unsigned())
		return JS::Value(value.get<unsigned int>());
	else if (value.is_number_integer())
		return JS::Value(value.get<int>());
	else if (value.is_number_float())
		return JS::Value(value.get<double>());
	else if (value.is_string())
		return JS::Value(value.get<std::string>());
	else
		return JS::Value::null();
}

JSON toJSON(const JS::Value& value)
{
	return JSON::parse(JS::getGlobal("JSON").call<std::string>("stringify", value));
}

Console::Console() : object_(JS::Value::global()["console"])
{
}

Console console;

} // namespace JS
