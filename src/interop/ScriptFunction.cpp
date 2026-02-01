#include "ScriptFunction.h"

void ScriptFunction::_bind_methods() {
	ClassDB::bind_method(D_METHOD("call_func", "args"), &ScriptFunction::call);
}
