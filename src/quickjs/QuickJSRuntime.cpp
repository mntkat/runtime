#include "QuickJSRuntime.h"
#include <godot_cpp/core/error_macros.hpp>

// Define the singleton instance
QuickJSRuntime* QuickJSRuntime::singleton = nullptr;

QuickJSRuntime::QuickJSRuntime(/* args */)
{
    rt = JS_NewRuntime();
    if (!rt) {
        ERR_PRINT("Failed to create QuickJS runtime");
        return;
    }

    // Set a reasonable memory limit (256 MB)
    JS_SetMemoryLimit(rt, 256 * 1024 * 1024);

    // Set maximum stack size (1 MB)
    JS_SetMaxStackSize(rt, 1024 * 1024);
}

QuickJSRuntime::~QuickJSRuntime()
{
    if (rt) {
        JS_FreeRuntime(rt);
    }
}
