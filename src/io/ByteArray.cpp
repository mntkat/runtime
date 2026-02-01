#include "ByteArray.h"

void io::luaopen_ByteArray(sol::state &lua) {
	lua.new_usertype<ByteArray>("BinaryData",
		//sol::constructors<ByteArray(), BinaryData(const sol::table)>(),
		"new", sol::factories(
			[]() { return new ByteArray(); },
			[](const sol::table& table) { return new ByteArray(table); }
		),
		"size", &ByteArray::size,
		"get", &ByteArray::get,
		"set", &ByteArray::set,
		"resize", &ByteArray::resize,
		"append", &ByteArray::append,
		"insert", &ByteArray::insert,
		"toTable", &ByteArray::toTable
	);
}
