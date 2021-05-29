#ifndef JS_HPP
#define JS_HPP

#include <emscripten/val.h>
#include <nlohmann/json_fwd.hpp>

#include <map>
#include <vector>

using JSON = nlohmann::json;

namespace JS {

using Value = emscripten::val;

// Global JS scope
const static Value gGlobal = Value::global();

// Global JS Object
const static Value gObject = Value::global("Object");

Value getGlobal(char const* name);
Value getGlobal(std::string const& name);
Value getConstant(const std::string& name);

bool isInstanceOf(const Value& val, const char* name);

std::vector<Value> jsArrayToVector(const Value& array);
std::map<std::string, Value> jsObjectToMap(const Value& object);

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
