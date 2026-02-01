#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>

using namespace godot;

class ScriptFunction : public RefCounted {
	GDCLASS(ScriptFunction, RefCounted)
protected:
	static void _bind_methods();
public:
	ScriptFunction() {}

	virtual Variant call(Array args) {
		return Variant();
	}
};
