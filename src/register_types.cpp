#include "register_types.h"

#include <gdextension_interface.h>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include "example_class.h"

#include "ScriptContext.h"
#include "interop/ScriptObject.h"
#include "interop/ScriptFunction.h"
#include "quickjs/QuickJSRuntime.h"
#include "quickjs/QuickJSContext.h"

using namespace godot;

void initialize_gdextension_types(ModuleInitializationLevel p_level)
{
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
	GDREGISTER_CLASS(ExampleClass);
	GDREGISTER_ABSTRACT_CLASS(ScriptContext);
	GDREGISTER_ABSTRACT_CLASS(ScriptObject);
	GDREGISTER_ABSTRACT_CLASS(ScriptFunction);
	GDREGISTER_CLASS(QuickJSContext);
	QuickJSRuntime::singleton = new QuickJSRuntime();
}

void uninitialize_gdextension_types(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C"
{
	// Initialization
	GDExtensionBool GDE_EXPORT example_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization *r_initialization)
	{
		GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);
		init_obj.register_initializer(initialize_gdextension_types);
		init_obj.register_terminator(uninitialize_gdextension_types);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		return init_obj.init();
	}
}
