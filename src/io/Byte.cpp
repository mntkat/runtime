#include "Byte.h"

void io ::luaopen_Byte(sol::state& lua) {
	lua.new_usertype<Byte>("Byte",
		//sol::constructors<Byte(), Byte(double), Byte(int)>(),
		"new", sol::factories(
			[]() { return new Byte(); },
			[](double value) { return new Byte(value); },
			[](int value) { return new Byte(value); }
		),
		"getInt", &Byte::getInt,
		"getInt64", [](Byte* byte) {
			int i = byte->getInt();
			int64_t i64 = i;
			return i64;
		},
		"getFloat", &Byte::getDouble,
		"setInt", &Byte::setInt,
		"setInt64", [](Byte* byte, int64_t i64) {
			int i = i64;
			byte->setInt(i64);
		},
		"setFloat", &Byte::setDouble
	);
}
