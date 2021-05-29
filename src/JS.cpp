#include "JS.hpp"

#include "JSON.hpp"

#include <emscripten/bind.h>

#include <string>

namespace JS {

Value getGlobal(char const* name)
{
	return Value::global(name);
}

Value getGlobal(std::string const& name)
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

std::vector<Value> jsArrayToVector(const Value& array)
{
	std::vector<Value> result;

	int size = array["length"].as<int>();
	result.reserve(size);

	for (int i = 0; i < size; ++i)
		result.emplace_back(array[i]);

	return result;
}

std::map<std::string, Value> jsObjectToMap(const Value& object)
{
	std::map<std::string, Value> result;

	Value keys = gObject.call<Value>("keys", object);
	int size = keys["length"].as<int>();

	for (int i = 0; i < size; ++i)
	{
		auto key = keys[i].as<std::string>();
		result.emplace_hint(result.end(), key, object[key]);
	}

	return result;
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
