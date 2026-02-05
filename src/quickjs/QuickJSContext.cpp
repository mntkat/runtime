#include "QuickJSContext.h"
#include <godot_cpp/variant/utility_functions.hpp>
#include <stdint.h>
#include <string.h>

#ifndef countof
#define countof(x) (sizeof(x) / sizeof((x)[0]))
#endif

using namespace godot;

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

static Variant unwrapVariant(JSContext* ctx, JSValueConst val) {
	return (static_cast<Variant>(JS_GetOpaque(val, QuickJSContext::getFromContext(ctx)->VariantClassID)));
}
static ObjectHandle* unwrapObjectHandle(JSContext* ctx, JSValueConst val) {
	// Use the ObjectHandle class id when unwrapping an ObjectHandle
	return static_cast<ObjectHandle*>(JS_GetOpaque(val, QuickJSContext::getFromContext(ctx)->ObjectHandleClassID));
}
static ReferenceHandle* unwrapReferenceHandle(JSContext* ctx, JSValueConst val) {
	// Use the ReferenceHandle class id when unwrapping a ReferenceHandle
	return static_cast<ReferenceHandle*>(JS_GetOpaque(val, QuickJSContext::getFromContext(ctx)->ReferenceHandleClassID));
}

static void finalizerVariant(JSRuntime* rt, JSValue val) {
}
static void finalizerObjectHandle(JSRuntime* rt, JSValue val) {
	// finalizer does not receive a JSContext*, so avoid using one; retrieve the opaque pointer directly
	JSClassID cid;
	void* p = JS_GetAnyOpaque(val, &cid);
	ObjectHandle* instance = static_cast<ObjectHandle*>(p);
	if (instance) {
		delete instance;
	}
}
static void finalizerReferenceHandle(JSRuntime* rt, JSValue val) {
	// finalizer does not receive a JSContext*, so avoid using one; retrieve the opaque pointer directly
	JSClassID cid;
	void* p = JS_GetAnyOpaque(val, &cid);
	ReferenceHandle* instance = static_cast<ReferenceHandle*>(p);
	if (instance) {
		delete instance;
	}
}


static JSValue ctorVariant(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst* argv) {
	if (argc > 0) {
		return JS_EXCEPTION;
	}

	Variant variant;

	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue strToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	const String str = JS_ToCString(ctx, argv[0]);
	if (!str) return JS_EXCEPTION;

	Variant variant = str;

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue intToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	double tmp;
	int ret = JS_ToFloat64(ctx, &tmp, argv[0]);
	if (ret < 0) return JS_EXCEPTION;
	int i = static_cast<int>(tmp);

	Variant variant = i;

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue float32ToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	double tmp;
	int ret = JS_ToFloat64(ctx, &tmp, argv[0]);
	if (ret < 0) return JS_EXCEPTION;
	int i = static_cast<int>(tmp);

	Variant variant = static_cast<float>(tmp);

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue float64ToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	double tmp;
	int ret = JS_ToFloat64(ctx, &tmp, argv[0]);
	if (ret < 0) return JS_EXCEPTION;
	int i = static_cast<int>(tmp);

	Variant variant = tmp;

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue booToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	const bool b = JS_ToBool(ctx, argv[0]);
	if (!b) return JS_EXCEPTION;

	Variant variant = b;

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue objHandleToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	ObjectHandle* handle = unwrapObjectHandle(ctx, argv[0]);
	if (!handle) return JS_EXCEPTION;

	Variant variant = handle->getNative();

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue refHandleToVariant(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc != 1) {
		return JS_EXCEPTION;
	}

	ReferenceHandle* handle = unwrapReferenceHandle(ctx, argv[0]);
	if (!handle) return JS_EXCEPTION;

	Variant variant = handle->getNative();

	JSValue proto = JS_GetPropertyStr(ctx, this_val, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, variant);

	return obj;
}

static JSValue jsVariantType(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	int type = variant.get_type();
	return JS_NewInt32(ctx, type);
}

static JSValue variantToStr(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	String str = variant;
	return JS_NewString(ctx, str.utf8().get_data());
}

static JSValue variantToInt(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	double i = variant;
	return JS_NewFloat64(ctx, i);
}

static JSValue variantToFloat32(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	float f = variant;
	double d = f;
	return JS_NewFloat64(ctx, d);
}

static JSValue variantToFloat64(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	double d = variant;
	return JS_NewFloat64(ctx, d);
}

static JSValue variantToBool(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	bool b = variant;
	return JS_NewBool(ctx, b);
}

static JSValue variantToObjectHandle(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	auto* handle = new ObjectHandle(variant);

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue handle_ctor = JS_GetPropertyStr(ctx, global, "ObjectHandle");
	JSValue handle_proto = JS_GetPropertyStr(ctx, handle_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, handle_ctor);

	if (JS_IsException(handle_proto)) {
		delete handle;
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, handle_proto, QuickJSContext::getFromContext(ctx)->ObjectHandleClassID);
	JS_FreeValue(ctx, handle_proto);

	if (JS_IsException(js_handle_obj)) {
		delete handle;
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, handle);

	return js_handle_obj;
}

static JSValue variantToReferenceHandle(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	Variant variant = unwrapVariant(ctx, this_val);
	if (!variant) return JS_EXCEPTION;

	auto* handle = new ReferenceHandle(variant);

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue handle_ctor = JS_GetPropertyStr(ctx, global, "ReferenceHandle");
	JSValue handle_proto = JS_GetPropertyStr(ctx, handle_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, handle_ctor);

	if (JS_IsException(handle_proto)) {
		delete handle;
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, handle_proto, QuickJSContext::getFromContext(ctx)->ReferenceHandleClassID);
	JS_FreeValue(ctx, handle_proto);

	if (JS_IsException(js_handle_obj)) {
		delete handle;
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, handle);

	return js_handle_obj;
}

static const JSCFunctionListEntry jsVariantFuncs[] = {
	JS_CFUNC_DEF("fromString", 0, strToVariant),
	JS_CFUNC_DEF("fromInt", 0, intToVariant),
	JS_CFUNC_DEF("fromFloat32", 0, float32ToVariant),
	JS_CFUNC_DEF("fromFloat364", 0, float64ToVariant),
	JS_CFUNC_DEF("fromBool", 0, booToVariant),
	JS_CFUNC_DEF("fromObjHandle", 0, objHandleToVariant),
	JS_CFUNC_DEF("fromRefHandle", 0, refHandleToVariant),
	JS_CFUNC_DEF("type", 0, jsVariantType),
	JS_CFUNC_DEF("toString", 0, variantToStr),
	JS_CFUNC_DEF("toInt", 0, variantToInt),
	JS_CFUNC_DEF("toFloat32", 0, variantToFloat32),
	JS_CFUNC_DEF("toFloat64", 0, variantToFloat64),
	JS_CFUNC_DEF("toBool", 0, variantToBool),
	JS_CFUNC_DEF("toObjHandle", 0, variantToObjectHandle),
	JS_CFUNC_DEF("toRefHandle", 0, variantToReferenceHandle)
};

static JSValue ctorObjectHandle(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst* argv) {
	if (argc <= 0 || argc > 2) {
		return JS_EXCEPTION;
	}

	const char* className = JS_ToCString(ctx, argv[0]);
	Array args;
	int scriptType = 0;
	if (argc == 2) {
		double tmp;
		int ret = JS_ToFloat64(ctx, &tmp, argv[0]);
		if (ret < 0) return JS_EXCEPTION;
		int i = static_cast<int>(tmp);
		scriptType = i;
	}

	ObjectHandle* handle = new ObjectHandle(className, scriptType);

	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->ObjectHandleClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, handle);

	return obj;
}

static JSValue obHandleCallStatic(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc < 2) {
		return JS_EXCEPTION;
	}

	const char* className = JS_ToCString(ctx, argv[0]);
	const char* methodName = JS_ToCString(ctx, argv[1]);
	Array args;
	for (int i = 2; i < argc; i++) {
		Variant v = unwrapVariant(ctx, argv[i]);
		if (!v) continue;
		args.append(v);
	}

	Variant res = ObjectHandle::callStatic(className, methodName, args);

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue variant_ctor = JS_GetPropertyStr(ctx, global, "VariantObject");
	JSValue variant_proto = JS_GetPropertyStr(ctx, variant_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, variant_ctor);

	if (JS_IsException(variant_proto)) {
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, variant_proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, variant_proto);

	if (JS_IsException(js_handle_obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, res);

	return js_handle_obj;
}

static JSValue objHandleGetSingleton(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc <= 2) {
		return JS_EXCEPTION;
	}

	const char* className = JS_ToCString(ctx, argv[0]);

	auto* handle = ObjectHandle::getSingleton(className);

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue handle_ctor = JS_GetPropertyStr(ctx, global, "ObjectHandle");
	JSValue handle_proto = JS_GetPropertyStr(ctx, handle_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, handle_ctor);

	if (JS_IsException(handle_proto)) {
		delete handle;
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, handle_proto, QuickJSContext::getFromContext(ctx)->ReferenceHandleClassID);
	JS_FreeValue(ctx, handle_proto);

	if (JS_IsException(js_handle_obj)) {
		delete handle;
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, handle);

	return js_handle_obj;
}

static JSValue obHandleCall(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc < 1) {
		return JS_EXCEPTION;
	}

	const char* methodName = JS_ToCString(ctx, argv[0]);
	Array args;
	for (int i = 1; i < argc; i++) {
		Variant v = unwrapVariant(ctx, argv[i]);
		if (!v) continue;
		args.append(v);
	}

	ObjectHandle* handle = unwrapObjectHandle(ctx, this_val);
	if (!handle) {
		return JS_EXCEPTION;
	}

	Variant res = handle->call( methodName, args);

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue variant_ctor = JS_GetPropertyStr(ctx, global, "VariantObject");
	JSValue variant_proto = JS_GetPropertyStr(ctx, variant_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, variant_ctor);

	if (JS_IsException(variant_proto)) {
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, variant_proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, variant_proto);

	if (JS_IsException(js_handle_obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, res);

	return js_handle_obj;
}

static JSValue obHandleGet(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc <= 1) {
		return JS_EXCEPTION;
	}

	const char* propName = JS_ToCString(ctx, argv[0]);

	ObjectHandle* handle = unwrapObjectHandle(ctx, this_val);
	if (!handle) {
		return JS_EXCEPTION;
	}

	Variant res = handle->get( propName );

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue variant_ctor = JS_GetPropertyStr(ctx, global, "VariantObject");
	JSValue variant_proto = JS_GetPropertyStr(ctx, variant_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, variant_ctor);

	if (JS_IsException(variant_proto)) {
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, variant_proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, variant_proto);

	if (JS_IsException(js_handle_obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, res);

	return js_handle_obj;
}

static JSValue obHandleSet(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc <= 2) {
		return JS_EXCEPTION;
	}

	const char* propName = JS_ToCString(ctx, argv[0]);
	Variant value = unwrapVariant(ctx, argv[1]);

	ObjectHandle* handle = unwrapObjectHandle(ctx, this_val);
	if (!handle) {
		return JS_EXCEPTION;
	}

	handle->set( propName, value );

	return this_val;
}

static const JSCFunctionListEntry jsObjHandleFuncs[] = {
	JS_CFUNC_DEF("getSingleton", 0, objHandleGetSingleton),
	JS_CFUNC_DEF("callStatic", 0, obHandleCallStatic),
	JS_CFUNC_DEF("call", 0, obHandleCall),
	JS_CFUNC_DEF("get", 0, obHandleGet),
	JS_CFUNC_DEF("set", 0, obHandleSet)
};

static JSValue ctorReferenceHandle(JSContext* ctx, JSValueConst new_target, int argc, JSValueConst* argv) {
	if (argc <= 0 || argc > 2) {
		return JS_EXCEPTION;
	}

	const char* className = JS_ToCString(ctx, argv[0]);
	Array args;
	int scriptType = 0;
	if (argc == 2) {
		double tmp;
		int ret = JS_ToFloat64(ctx, &tmp, argv[0]);
		if (ret < 0) return JS_EXCEPTION;
		int i = static_cast<int>(tmp);
		scriptType = i;
	}

	ReferenceHandle* handle = new ReferenceHandle(className, scriptType);

	JSValue proto = JS_GetPropertyStr(ctx, new_target, "prototype");
	if (JS_IsException(proto)) {
		return JS_EXCEPTION;
	}

	JSValue obj = JS_NewObjectProtoClass(ctx, proto, QuickJSContext::getFromContext(ctx)->ObjectHandleClassID);
	JS_FreeValue(ctx, proto);

	if (JS_IsException(obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(obj, handle);

	return obj;
}

static JSValue refHandleCall(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc < 1) {
		return JS_EXCEPTION;
	}

	const char* methodName = JS_ToCString(ctx, argv[0]);
	Array args;
	for (int i = 1; i < argc; i++) {
		Variant v = unwrapVariant(ctx, argv[i]);
		if (!v) continue;
		args.append(v);
	}

	ReferenceHandle* handle = unwrapReferenceHandle(ctx, this_val);
	if (!handle) {
		return JS_EXCEPTION;
	}

	Variant res = handle->call( methodName, args);

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue variant_ctor = JS_GetPropertyStr(ctx, global, "VariantObject");
	JSValue variant_proto = JS_GetPropertyStr(ctx, variant_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, variant_ctor);

	if (JS_IsException(variant_proto)) {
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, variant_proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, variant_proto);

	if (JS_IsException(js_handle_obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, res);

	return js_handle_obj;
}

static JSValue refHandleGet(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc <= 1) {
		return JS_EXCEPTION;
	}

	const char* propName = JS_ToCString(ctx, argv[0]);

	ReferenceHandle* handle = unwrapReferenceHandle(ctx, this_val);
	if (!handle) {
		return JS_EXCEPTION;
	}

	Variant res = handle->get( propName );

	JSValue global = JS_GetGlobalObject(ctx);
	JSValue variant_ctor = JS_GetPropertyStr(ctx, global, "VariantObject");
	JSValue variant_proto = JS_GetPropertyStr(ctx, variant_ctor, "prototype");

	JS_FreeValue(ctx, global);
	JS_FreeValue(ctx, variant_ctor);

	if (JS_IsException(variant_proto)) {
		return JS_EXCEPTION;
	}

	JSValue js_handle_obj = JS_NewObjectProtoClass(ctx, variant_proto, QuickJSContext::getFromContext(ctx)->VariantClassID);
	JS_FreeValue(ctx, variant_proto);

	if (JS_IsException(js_handle_obj)) {
		return JS_EXCEPTION;
	}

	JS_SetOpaque(js_handle_obj, res);

	return js_handle_obj;
}

static JSValue refHandleSet(JSContext* ctx, JSValueConst this_val, int argc, JSValueConst* argv) {
	if (argc <= 2) {
		return JS_EXCEPTION;
	}

	const char* propName = JS_ToCString(ctx, argv[0]);
	Variant value = unwrapVariant(ctx, argv[1]);

	ReferenceHandle* handle = unwrapReferenceHandle(ctx, this_val);
	if (!handle) {
		return JS_EXCEPTION;
	}

	handle->set( propName, value );

	return this_val;
}

static const JSCFunctionListEntry jsRefHandleFuncs[] = {
	JS_CFUNC_DEF("call", 0, refHandleCall),
	JS_CFUNC_DEF("get", 0, refHandleGet),
	JS_CFUNC_DEF("set", 0, refHandleSet)
};


void QuickJSContext::_bind_methods() {
    // Binding methods can be added here if needed
}

QuickJSContext::QuickJSContext() {
	VariantClassID = 0;
	ObjectHandleClassID = 0;
	ReferenceHandleClassID = 0;

	VariantClassProto = JS_UNDEFINED;
	ObjectHandleClassProto = JS_UNDEFINED;
	ReferenceHandleClassProto = JS_UNDEFINED;

	VariantClassDef = nullptr;
	ObjectHandleClassDef = nullptr;
	ReferenceHandleClassDef = nullptr;

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

	QuickJSRuntime::singleton->contexts.append(this);

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
	return Ref<QuickJSContext>();
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

	JS_NewClassID(QuickJSRuntime::singleton->rt, &VariantClassID);

	VariantClassDef = new JSClassDef();

	VariantClassDef->class_name = "VariantObject";
	VariantClassDef->finalizer = finalizerVariant;

	if (JS_NewClass(QuickJSRuntime::singleton->rt, VariantClassID, VariantClassDef) != 0) {
		ERR_PRINT("Failed to create new class for Variant");
		return;
	}

	// Get the global object
	JSValue global = JS_GetGlobalObject(ctx);

	VariantClassProto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, VariantClassProto, jsVariantFuncs, countof(jsVariantFuncs));

	JSValue ctor = JS_NewCFunction2(ctx, ctorVariant, "VariantObject", 1, JS_CFUNC_constructor, 0);

	JS_SetConstructor(ctx, ctor, VariantClassProto);
	JS_SetClassProto(ctx, VariantClassID, VariantClassProto);

	JS_SetPropertyStr(ctx, global, "VariantObject", VariantClassProto);
	JS_SetPropertyStr(ctx, global, "Nil", ctor);
	JS_FreeValue(ctx, global);
}

void QuickJSContext::bind_ObjectHandle() {
	if (!ctx) return;

	JS_NewClassID(QuickJSRuntime::singleton->rt, &ObjectHandleClassID);

	ObjectHandleClassDef = new JSClassDef();

	ObjectHandleClassDef->class_name = "ObjectHandle";
	ObjectHandleClassDef->finalizer = finalizerObjectHandle;

	if (JS_NewClass(QuickJSRuntime::singleton->rt, ObjectHandleClassID, ObjectHandleClassDef) != 0) {
		ERR_PRINT("Failed to create new class for ObjectHandle");
		return;
	}

	JSValue global = JS_GetGlobalObject(ctx);

	ObjectHandleClassProto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, ObjectHandleClassProto, jsObjHandleFuncs, countof(jsObjHandleFuncs));

	JSValue ctor = JS_NewCFunction2(ctx, ctorObjectHandle, "ObjectHandle", 1, JS_CFUNC_constructor, 0);

	JS_SetConstructor(ctx, ctor, ObjectHandleClassProto);
	JS_SetClassProto(ctx, ObjectHandleClassID, ObjectHandleClassProto);

	JS_SetPropertyStr(ctx, global, "ObjectHandle", ctor);
	JS_SetPropertyStr(ctx, global, "ObjectHandleGlobal", ObjectHandleClassProto);
}

void QuickJSContext::bind_ReferenceHandle() {
	if (!ctx) return;

	JS_NewClassID(QuickJSRuntime::singleton->rt, &ReferenceHandleClassID);

	ReferenceHandleClassDef = new JSClassDef();

	ReferenceHandleClassDef->class_name = "ReferenceHandle";
	ReferenceHandleClassDef->finalizer = finalizerReferenceHandle;

	if (JS_NewClass(QuickJSRuntime::singleton->rt, ReferenceHandleClassID, ReferenceHandleClassDef) != 0) {
		ERR_PRINT("Failed to create new class for ReferenceHandle");
		return;
	}

	JSValue global = JS_GetGlobalObject(ctx);

	ReferenceHandleClassProto = JS_NewObject(ctx);
	JS_SetPropertyFunctionList(ctx, ReferenceHandleClassProto, jsRefHandleFuncs, countof(jsRefHandleFuncs));

	JSValue cotr = JS_NewCFunction2(ctx, ctorReferenceHandle, "ReferenceHandle", 1, JS_CFUNC_constructor, 0);

	JS_SetConstructor(ctx, cotr, ReferenceHandleClassProto);
	JS_SetClassProto(ctx, ReferenceHandleClassID, ReferenceHandleClassProto);

	JS_SetPropertyStr(ctx, global, "ReferenceHandle",  cotr);
}

QuickJSContext::~QuickJSContext() {
    if (ctx) {
        JS_FreeContext(ctx);
    }
	if (QuickJSRuntime::singleton->contexts.has(this)) {
		QuickJSRuntime::singleton->contexts.erase(this);
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
