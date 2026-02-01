#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace  godot;

class ScriptContext : public RefCounted {
	GDCLASS(ScriptContext, RefCounted)
protected:
	static void _bind_methods();

public:

	ScriptContext() {}
	~ScriptContext() {}

	virtual void eval(const String &code) {}

	virtual void bind_variant() {}
	virtual void bind_array() {}
	virtual void bind_dictionary() {}
	virtual void bind_vector2() {}
	virtual void bind_rect2() {}
	virtual void bind_vector2i() {}
	virtual void bind_rect2i() {}
	virtual void bind_vector3() {}
	virtual void bind_vector3i() {}
	virtual void bind_vector4() {}
	virtual void bind_vector4i() {}
	virtual void bind_quaternion() {}
	virtual void bind_basis() {}
	virtual void bind_transform3d() {}
	virtual void bind_transform2d() {}
	virtual void bind_aabb() {}
	virtual void bind_color() {}
};
