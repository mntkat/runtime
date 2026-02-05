#pragma once

#include "../ScriptContext.h"
#include <quickjs.h>
#include "QuickJSRuntime.h"
#include "../interop/ObjectHandle.h"
#include "../interop/ReferenceHandle.h"

#include <godot_cpp/godot.hpp>

using namespace godot;

class QuickJSContext : public ScriptContext {
    GDCLASS(QuickJSContext, ScriptContext)

protected:
    static void _bind_methods();

    JSContext *ctx;

	JSClassDef* VariantClassDef;
	JSClassDef* ObjectHandleClassDef;
	JSClassDef* ReferenceHandleClassDef;

    void setup_console();

public:
	JSValue VariantClassProto;
	JSValue ObjectHandleClassProto;
	JSValue ReferenceHandleClassProto;

	JSClassID VariantClassID;
	JSClassID ObjectHandleClassID;
	JSClassID ReferenceHandleClassID;

    QuickJSContext();
    ~QuickJSContext();

	static Ref<QuickJSContext> getFromContext(JSContext* p_ctx);

    void eval(const String &code) override;

	void bind_Variant() override;

	void bind_ObjectHandle() override;

	void bind_ReferenceHandle() override;
};

class  QuickJSVariantProxy {
public:
	godot::Variant variant;

	QuickJSVariantProxy(const godot::Variant& p_variant) : variant(p_variant) {}
	~QuickJSVariantProxy() {}
};
