#!/usr/bin/env python
import os
import sys

from methods import print_error


libname = "runtime"
projectdir = "demo"

localEnv = Environment(tools=["default"], PLATFORM="")

# Build profiles can be used to decrease compile times.
# You can either specify "disabled_classes", OR
# explicitly specify "enabled_classes" which disables all other classes.
# Modify the example file as needed and uncomment the line below or
# manually specify the build_profile parameter when running SCons.

# localEnv["build_profile"] = "build_profile.json"

customs = ["custom.py"]
customs = [os.path.abspath(path) for path in customs]

opts = Variables(customs, ARGUMENTS)
opts.Update(localEnv)

Help(opts.GenerateHelpText(localEnv))

env = localEnv.Clone()

if not (os.path.isdir("godot-cpp") and os.listdir("godot-cpp")):
    print_error("""godot-cpp is not available within this folder, as Git submodules haven't been initialized.
Run the following command to download godot-cpp:

    git submodule update --init --recursive""")
    sys.exit(1)

env = SConscript("godot-cpp/SConstruct", {"env": env, "customs": customs})

env.Append(CPPPATH=["src/"])
env.Append(CPPPATH=["src/interop/"])
env.Append(CPPPATH=["src/io/"])
env.Append(CPPPATH=["src/quickjs/"])
sources = Glob("src/*.cpp")
sources.extend(Glob("src/interop/*.cpp"))
sources.extend(Glob("src/io/*.cpp"))
sources.extend(Glob("src/quickjs/*.cpp"))

### > QUICKJS STUFF

quickjs_sources = [
    'quickjs/quickjs-amalgam.c'
]

quickjs_env = env.Clone()
if quickjs_env['CC'] == 'cl':
    quickjs_env.Append(CCFLAGS=['/std:c11', '/experimental:c11atomics'])
    quickjs_env.Append(CPPDEFINES=['WIN32_LEAN_AND_MEAN', 'QJS_BUILD_LIBC'])
else:
    quickjs_env.Append(CCFLAGS=['-std=c11'])
    quickjs_env.Append(CPPDEFINES=['_GNU_SOURCE', 'QJS_BUILD_LIBC'])

# Build QuickJS as a static library using the separate environment
quickjs_lib = quickjs_env.Library('quickjs', quickjs_sources)

env.Prepend(LIBS=[quickjs_lib])

env.Append(CPPPATH=[ "quickjs/"])
if env['CC'] == 'cl':
    env.Append(CPPFLAGS=['/std:c++20'])
else:
    env.Append(CPPFLAGS=['-std=c++20'])

### < QUICKJS STUFF

if env["target"] in ["editor", "template_debug"]:
    try:
        doc_data = env.GodotCPPDocData("src/gen/doc_data.gen.cpp", source=Glob("doc_classes/*.xml"))
        sources.append(doc_data)
    except AttributeError:
        print("Not including class reference as we're targeting a pre-4.3 baseline.")

# .dev doesn't inhibit compatibility, so we don't need to key it.
# .universal just means "compatible with all relevant arches" so we don't need to key it.
suffix = env['suffix'].replace(".dev", "").replace(".universal", "")

lib_filename = "{}{}{}{}".format(env.subst('$SHLIBPREFIX'), libname, suffix, env.subst('$SHLIBSUFFIX'))

library = env.SharedLibrary(
    "bin/{}/{}".format(env['platform'], lib_filename),
    source=sources,
)

copy = env.Install("{}/bin/{}/".format(projectdir, env["platform"]), library)

default_args = [library, copy]
Default(*default_args)
