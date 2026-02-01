#pragma once

#include <quickjs.h>

#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/typed_array.hpp>

class QuickJSRuntime
{
public:
    static QuickJSRuntime* singleton;

	godot::Array contexts;

    JSRuntime *rt;

    QuickJSRuntime(/* args */);
    ~QuickJSRuntime();
};
