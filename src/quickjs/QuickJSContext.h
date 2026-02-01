#pragma once

#include "ScriptContext.h"
#include <quickjs.h>
#include "QuickJSRuntime.h"

using namespace godot;

class QuickJSContext : public ScriptContext {
    GDCLASS(QuickJSContext, ScriptContext)

protected:
    static void _bind_methods();

    JSContext *ctx;

    void setup_console();

public:
    QuickJSContext();
    ~QuickJSContext();

    void eval(const String &code) override;

	void bind_Variant() override;

	void bind_ObjectHandle() override;

	void bind_ReferenceHandle() override;
};
