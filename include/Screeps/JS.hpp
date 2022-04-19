#ifndef JS_HPP
#define JS_HPP

#include <emscripten/val.h>
#include <nlohmann/json_fwd.hpp>

#include <map>
#include <string>
#include <vector>

using JSON = nlohmann::json;

namespace JS {

using Value = emscripten::val;

// Global JS scope
const static Value gGlobal = Value::global();

// Global JS Object
const static Value gObject = Value::global("Object");

Value getGlobal(char const* name);
Value getGlobal(const std::string& name);
Value getConstant(const std::string& name);

bool isInstanceOf(const Value& val, const char* name);

template <typename T = Value>
std::vector<T> jsArrayToVector(const Value& array)
{
	std::vector<T> result;
	int size = array["length"].as<int>();
	result.reserve(size);
	for (int i = 0; i < size; ++i)
		result.emplace_back(array[i].as<T>());
	return result;
}

template <typename T = Value>
std::map<std::string, T> jsObjectToMap(const Value& object)
{
	std::map<std::string, T> result;
	Value keys = gObject.call<Value>("keys", object);
	int size = keys["length"].as<int>();
	for (int i = 0; i < size; ++i)
	{
		auto key = keys[i].as<std::string>();
		result.emplace_hint(result.end(), key, object[key].as<T>());
	}
	return result;
}

template <typename T>
Value vectorToJSArray(const std::vector<T>& vector)
{
	Value array = Value::array();
	for (std::size_t i = 0; i < vector.size(); i++)
		array.set(i, static_cast<JS::Value>(vector[i]));
	return array;
}

template <typename K, typename T>
Value mapToJSObject(const std::map<K, T>& map)
{
	Value object = Value::object();
	for (const auto& pair : map)
		object.set(pair.first, pair.second);
	return object;
}

Value fromJSON(const JSON& json);
JSON toJSON(const Value& value);

class Console
{
public:
	Console();

	template <typename... Args>
	void log(Args&&... args)
	{
		object_.call<void>("log", std::forward<Args>(args)...);
	}

private:
	Value object_;
};

extern Console console;

} // namespace JS

#endif // JS_HPP
