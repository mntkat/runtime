#include "ScriptContext.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void ScriptContext::_bind_methods() {
    // Binding methods can be added here if needed

    ClassDB::bind_method(D_METHOD("eval", "code"), &ScriptContext::eval);
    ClassDB::bind_method(D_METHOD("bind_Variant"), &ScriptContext::bind_Variant);
    ClassDB::bind_method(D_METHOD("bind_Variant_sandboxed"), &ScriptContext::bind_Variant_sandboxed);
    ClassDB::bind_method(D_METHOD("bind_ObjectHandle"), &ScriptContext::bind_ObjectHandle);
    ClassDB::bind_method(D_METHOD("bind_ObjectHandle_sandboxed"), &ScriptContext::bind_ObjectHandle_sandboxed);
    ClassDB::bind_method(D_METHOD("bind_ReferenceHandle"), &ScriptContext::bind_ReferenceHandle);
    ClassDB::bind_method(D_METHOD("bind_ReferenceHandle_sandboxed"), &ScriptContext::bind_ReferenceHandle_sandboxed);
}
