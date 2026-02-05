#pragma once

#include "../ScriptContext.h"
#include <quickjs.h>
#include "QuickJSRuntime.h"
#include "../interop/ObjectHandle.h"
#include "../interop/ReferenceHandle.h"

using namespace godot;

class QuickJSContext : public ScriptContext {
    GDCLASS(QuickJSContext, ScriptContext)

protected:
    static void _bind_methods();

    JSContext *ctx;



	JSValue VariantClassProto;
	JSValue ObjectHandleClassProto;
	JSValue ReferenceHandleClassProto;

	JSClassDef* VariantClassDef;
	JSClassDef* ObjectHandleClassDef;
	JSClassDef* ReferenceHandleClassDef;

    void setup_console();

public:
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
