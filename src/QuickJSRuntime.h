#pragma once

#include <quickjs.h>

class QuickJSRuntime
{
public:
    static QuickJSRuntime* singleton;

    JSRuntime *rt;

    QuickJSRuntime(/* args */);
    ~QuickJSRuntime();
};
