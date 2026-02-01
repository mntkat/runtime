#include "ScriptContext.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void ScriptContext::_bind_methods() {
    // Binding methods can be added here if needed

    ClassDB::bind_method(D_METHOD("eval", "code"), &ScriptContext::eval);
    ClassDB::bind_method(D_METHOD("bind_variant"), &ScriptContext::bind_variant);
    ClassDB::bind_method(D_METHOD("bind_array"), &ScriptContext::bind_array);
    ClassDB::bind_method(D_METHOD("bind_dictionary"), &ScriptContext::bind_dictionary);
    ClassDB::bind_method(D_METHOD("bind_vector2"), &ScriptContext::bind_vector2);
    ClassDB::bind_method(D_METHOD("bind_rect2"), &ScriptContext::bind_rect2);
    ClassDB::bind_method(D_METHOD("bind_vector2i"), &ScriptContext::bind_vector2i);
    ClassDB::bind_method(D_METHOD("bind_rect2i"), &ScriptContext::bind_rect2i);
    ClassDB::bind_method(D_METHOD("bind_vector3"), &ScriptContext::bind_vector3);
    ClassDB::bind_method(D_METHOD("bind_vector3i"), &ScriptContext::bind_vector3i);
    ClassDB::bind_method(D_METHOD("bind_vector4"), &ScriptContext::bind_vector4);
    ClassDB::bind_method(D_METHOD("bind_vector4i"), &ScriptContext::bind_vector4i);
    ClassDB::bind_method(D_METHOD("bind_quaternion"), &ScriptContext::bind_quaternion);
    ClassDB::bind_method(D_METHOD("bind_basis"), &ScriptContext::bind_basis);
    ClassDB::bind_method(D_METHOD("bind_transform3d"), &ScriptContext::bind_transform3d);
    ClassDB::bind_method(D_METHOD("bind_transform2d"), &ScriptContext::bind_transform2d);
    ClassDB::bind_method(D_METHOD("bind_aabb"), &ScriptContext::bind_aabb);
    ClassDB::bind_method(D_METHOD("bind_color"), &ScriptContext::bind_color);
}
