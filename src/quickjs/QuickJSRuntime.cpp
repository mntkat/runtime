#include "QuickJSRuntime.h"
#include <godot_cpp/core/error_macros.hpp>

// Define the singleton instance
QuickJSRuntime* QuickJSRuntime::singleton = nullptr;

QuickJSRuntime::QuickJSRuntime(/* args */)
{
	contexts = godot::Array();

    rt = JS_NewRuntime();
    if (!rt) {
        ERR_PRINT("Failed to create QuickJS runtime");
        return;
    }
}

QuickJSRuntime::~QuickJSRuntime()
{
    if (rt) {
        JS_FreeRuntime(rt);
    }
}
