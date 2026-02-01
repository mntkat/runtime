#include "ScriptObject.h"

void ScriptObject::_bind_methods() {
	ClassDB::bind_method( D_METHOD( "get_var", "name" ), &ScriptObject::get_var );
	ClassDB::bind_method( D_METHOD( "set_var", "name", "variant" ), &ScriptObject::set_var );
	ClassDB::bind_method( D_METHOD( "has_var", "name" ), &ScriptObject::has_var );
	ClassDB::bind_method( D_METHOD( "has_function", "name" ), &ScriptObject::has_function );
	ClassDB::bind_method( D_METHOD( "call_function", "name", "args" ), &ScriptObject::call_function );
}
