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

    virtual void eval(const String &code) override;
};
