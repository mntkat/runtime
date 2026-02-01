#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class ScriptObject : public RefCounted{
	GDCLASS( ScriptObject, RefCounted )
protected:
	static void _bind_methods();
public:
	ScriptObject()
	{
	}

	~ScriptObject() {}

	virtual Variant get_var(const String& name)
	{
		return Variant();
	}

	virtual void set_var( const String &name, const Variant &var ) {}

	virtual bool has_var(const String& name)
	{
		return false;
	}

	virtual bool has_function(const String& name)
	{
		return false;
	}

	Variant call_function(const String& name, const Array& args)
	{
		return Variant();
	}
};
