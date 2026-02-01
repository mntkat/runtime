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

	void bind_Variant();
	void bind_Variant_sandboxed(const Array& classnames);
	void bind_ObjectHandle_sandboxed(const Array& classnames);
	void bind_ObjectHandle();
	void bind_ReferenceHandle();
	void bind_ReferenceHandle_sandboxed(const Array& classnames);
};
