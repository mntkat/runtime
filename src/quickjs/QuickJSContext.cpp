#include "QuickJSContext.h"
#include <godot_cpp/variant/utility_functions.hpp>

// Console.log implementation
static JSValue js_console_log(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    for (int i = 0; i < argc; i++) {
        const char* str = JS_ToCString(ctx, argv[i]);
        if (str) {
            godot::UtilityFunctions::print(str);
            JS_FreeCString(ctx, str);
        }
    }
    return JS_UNDEFINED;
}

// Console.warn implementation
static JSValue js_console_warn(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    for (int i = 0; i < argc; i++) {
        const char* str = JS_ToCString(ctx, argv[i]);
        if (str) {
            godot::UtilityFunctions::push_warning(str);
            JS_FreeCString(ctx, str);
        }
    }
    return JS_UNDEFINED;
}

// Console.error implementation
static JSValue js_console_error(JSContext *ctx, JSValueConst this_val, int argc, JSValueConst *argv) {
    for (int i = 0; i < argc; i++) {
        const char* str = JS_ToCString(ctx, argv[i]);
        if (str) {
            godot::UtilityFunctions::push_error(str);
            JS_FreeCString(ctx, str);
        }
    }
    return JS_UNDEFINED;
}

void QuickJSContext::_bind_methods() {
    // Binding methods can be added here if needed
}

QuickJSContext::QuickJSContext() {
    // Check if singleton exists and runtime is valid
    if (!QuickJSRuntime::singleton) {
        ERR_PRINT("QuickJSRuntime singleton is not initialized");
        ctx = nullptr;
        return;
    }

    if (!QuickJSRuntime::singleton->rt) {
        ERR_PRINT("QuickJSRuntime rt is null");
        ctx = nullptr;
        return;
    }

    // Use JS_NewContextRaw to create a context without intrinsics
    // Then manually add the intrinsics we want
    ctx = JS_NewContext(QuickJSRuntime::singleton->rt);
    if (!ctx) {
        ERR_PRINT("Failed to create QuickJS context");
        return;
    }

    // Setup console object
    setup_console();
}

Ref<QuickJSContext> QuickJSContext::getFromContext(JSContext *p_ctx) {
	if (!QuickJSRuntime::singleton) {
		ERR_PRINT("QuickJSRuntime singleton is not initialized");
		return Ref<QuickJSContext>();
	}

	if (!QuickJSRuntime::singleton->rt) {
		ERR_PRINT("QuickJSRuntime rt is null");
		return Ref<QuickJSContext>();
	}

	for (int i = 0; i < QuickJSRuntime::singleton->contexts.size(); i++) {
		Variant v = QuickJSRuntime::singleton->contexts[i];
		Ref<QuickJSContext> context = v;
		if (context.is_valid()) {
			if (context->ctx == p_ctx) {
				return context;
			}
		}
	}
}

void QuickJSContext::setup_console() {
    if (!ctx) return;

    // Get the global object
    JSValue global = JS_GetGlobalObject(ctx);

    // Create console object
    JSValue console = JS_NewObject(ctx);

    // Add console.log
    JS_SetPropertyStr(ctx, console, "log",
        JS_NewCFunction(ctx, js_console_log, "log", 0));

    // Add console.warn
    JS_SetPropertyStr(ctx, console, "warn",
        JS_NewCFunction(ctx, js_console_warn, "warn", 0));

    // Add console.error
    JS_SetPropertyStr(ctx, console, "error",
        JS_NewCFunction(ctx, js_console_error, "error", 0));

    // Set console as global property
    JS_SetPropertyStr(ctx, global, "console", console);

    // Free the global object reference
    JS_FreeValue(ctx, global);
}

void QuickJSContext::bind_Variant() {
	if (!ctx) return;
}

void QuickJSContext::bind_ObjectHandle() {
	if (!ctx) return;
}

void QuickJSContext::bind_ReferenceHandle() {
	if (!ctx) return;
}

QuickJSContext::~QuickJSContext() {
    if (ctx) {
        JS_FreeContext(ctx);
    }
}

void QuickJSContext::eval(const godot::String &code) {
    if (!ctx) {
        ERR_PRINT("QuickJS context is not initialized");
        return;
    }

    // Convert Godot String to C string
    godot::CharString utf8_code = code.utf8();
    const char* c_code = utf8_code.get_data();

    // Evaluate the JavaScript code
    JSValue result = JS_Eval(ctx, c_code, strlen(c_code), "<eval>", JS_EVAL_TYPE_GLOBAL);

    // Check for errors
    if (JS_IsException(result)) {
        JSValue exception = JS_GetException(ctx);
        const char* error_str = JS_ToCString(ctx, exception);
        if (error_str) {
            ERR_PRINT("JavaScript error: " + String(error_str));
            JS_FreeCString(ctx, error_str);
        }
        JS_FreeValue(ctx, exception);
    }

    // Free the result
    JS_FreeValue(ctx, result);
}
