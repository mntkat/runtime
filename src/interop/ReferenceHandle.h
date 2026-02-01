#pragma once

#include <godot_cpp/classes/ref_counted.hpp>
#include <godot_cpp/variant/variant.hpp>
#include <godot_cpp/classes/class_db_singleton.hpp>
#include <godot_cpp/classes/gd_script.hpp>
#include <godot_cpp/classes/resource_loader.hpp>

using namespace godot;

class ReferenceHandle {
private:
        Ref<RefCounted> native;
    public:
        ReferenceHandle(std::string name, const Array& args = Array(), int scriptType = 0)
        {
            if (scriptType == 0)
            {
                native = ClassDB::instantiate( name.c_str() );
            }
            else if (scriptType == 1)
            {
                Ref<godot::Resource> res = ResourceLoader::get_singleton()->load(
                    name.c_str()
                );

                Ref<GDScript> script = res;
                if (script.is_valid() && !script.is_null())
                {
                    native = script->callv( "new",  args);
                }
            }
        	else if (scriptType == 2) {
        		Ref<godot::Resource> res = ResourceLoader::get_singleton()->load(
					"res://Engine/CSharpScriptLoader.gd"
				);

        		Ref<GDScript> script = res;
        		Object* loader = script->callv( "new",  Array() );
        		native = loader->call( "load_script", name.c_str(), args );
        	}
        }

        ReferenceHandle(Ref<RefCounted> ref)
        {
            native = ref;
        }

        Ref<RefCounted> getNative()
        {
            return native;
        }

        Variant call(std::string funcname, const Array& args)
        {
        	if (isNull() || !isValid()) return Variant();
            return native->callv( funcname.c_str(), args );
        }

        Variant get(std::string propname)
        {
        	if (isNull() || !isValid()) return Variant();
            return native->get( propname.c_str() );
        }

        void set(std::string propname, Variant value)
        {
        	if (isNull() || !isValid()) return;
            native->set( propname.c_str(), value );
        }

        std::string getClass()
        {
        	if (isNull() || !isValid()) return "";
            return native->get_class().utf8().get_data();
        }

        bool isClass(std::string classname)
        {
        	if (isNull() || !isValid()) return false;
            return native->is_class( classname.c_str() );
        }

        Variant getMeta(std::string name, Variant _default = Variant())
        {
        	if (isNull() || !isValid()) return Variant();
            return native->get_meta( name.c_str(), _default );
        }

        Array getMetaList()
        {
        	if (isNull() || !isValid()) return Array();
            return native->get_property_list();
        }

        int getMethodArgumentCount(std::string method)
        {
        	if (isNull() || !isValid()) return -1;
            return native->get_method_argument_count( method.c_str() );
        }

        Array getMethodList()
        {
        	if (isNull() || !isValid()) return Array();
            return native->get_method_list();
        }

        Array getPropertyList()
        {
        	if (isNull() || !isValid()) return Array();
            return native->get_property_list();
        }

        bool hasMeta(std::string name)
        {
        	if (isNull() || !isValid()) return false;
            return native->has_meta( name.c_str() );
        }

        bool hasMethod(std::string method)
        {
        	if (isNull() || !isValid()) return false;
            return native->has_method( method.c_str() );
        }

        void setMeta(std::string name, Variant value)
        {
        	if (isNull() || !isValid()) return;
            native->set_meta( name.c_str(), value );
        }

		bool isValid()
        {
        	return native.is_valid();
        }

		bool isNull()
        {
        	return native.is_null();
        }
};
