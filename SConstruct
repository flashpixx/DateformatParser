# -*- coding: utf-8 -*-
import platform, os

# script uses different parameters
#
# type = static|dynamic     : library build type (default: dynamic)
# debug = Yes|No            : debug version (default: False )
# arc   = x68|x64           : bit definition 32 or 64 bit version (default: x86)


# library name
def LibraryName() :
    return "dateformat"


# --- helper function ------------------------------------------------------------------------------------------------------------------------------------------------------

# read directory recursive
# @param start directory
# @param file extension
# @param execluded directoriy names
def GlobRekursiv(startdir, extensions=[], excludedir=[]) :
    if type(extensions) == type("") :
        extensions = [extensions]
    if type(excludedir) == type("") :
        excludedir = [excludedir]
    if type(extensions) <> type([]) :
        raise SCons.Errors.StopError("extensions parameter must be")
    if type(excludedir) <> type([]) :
        raise SCons.Errors.StopError("ExcludeDir Paramter muss eine Liste oder String sein")
    if not extensions :
        raise SCons.Errors.StopError("Extensions dürfen nicht leer sein")

    lst = []
    for root, dirs, filenames in os.walk(startdir) :
        if any([i in root for i in excludedir]) :
            continue
        for filename in filenames :
            if filename.startswith(".") :
                continue
            if any([filename.endswith(i) for i in extensions]) :
                lst.append( os.path.abspath(os.path.join(root, filename)) )
    return lst

# ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



# --- define build process ---------------------------------------------------------------------------------------------------------------------------------------------------

# defines parameter of the script and create build environment
vars = Variables()
vars.Add( EnumVariable( "type", "static or dynamic library type", "dynamic", allowed_values=("dynamic", "static"), ignorecase=True ) )
vars.Add( BoolVariable( "debug", "debugging flag", False ) )                            

env = Environment( ARCH_TYPE = ARGUMENTS.get("arch", "x86"), variables=vars )


# platform specific configuration (compiler, linker flags)
env.AppendUnique(CPPPATH = ["runtime/antlr4-runtime"])
env.AppendUnique(LIBPATH = ["runtime/lib"])
env.AppendUnique(LIBS = ["antlr4-runtime"])

if platform.system().lower() == "posix" or platform.system().lower() == "linux" :
    env.AppendUnique(CDEFINES = [])
    env.AppendUnique(CFLAGS   = ["-Wall", "-Wl,-soname" + env["LIBPREFIX"] + LibraryName() + env["SHLIBSUFFIX"], "-O2", "-std=c11"])
    env.AppendUnique(CPPFLAGS = ["-Wall", "-O2", "-std=c++11"])

elif platform.system().lower() == "darwin" :
    env.AppendUnique(CDEFINES  = [])
    env.AppendUnique(CFLAGS    = ["-Wall", "-O2", "-std=c11"])
    env.AppendUnique(CPPFLAGS  = ["-Wall", "-O2", "-std=c++11"])
    env.AppendUnique(LINKFLAGS = ["-Wl,-install_name," + env["LIBPREFIX"] + LibraryName() + env["SHLIBSUFFIX"]])

elif "windows" in platform.system().lower() :
    env.AppendUnique(CDEFINES = [])
    env.AppendUnique(CFLAGS   = ["/Wall", "/O2", "/GR", "/EHsc", "/nologo"])
   
if not env["debug"] :
    env.AppendUnique(CPPDEFINES = ["NDEBUG"])

print
print

# ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------



# --- build | packaging | clean execution ------------------------------------------------------------------------------------------------------------------------------------

# build library
if env["type"] == "dynamic" :
    lib = env.SharedLibrary( LibraryName(), GlobRekursiv("src", [".c", ".cpp"] ) )
if env["type"] == "static" :
    lib = env.StaticLibrary( LibraryName(), GlobRekursiv("src", [".c", ".cpp"] ) )

# build documentation
documentation = env.Command("documentation", "documentation.doxyfile", "doxygen $SOURCE")

# build package
zip = env.Zip( 
    "_".join( [ LibraryName(), platform.system(), env["ARCH_TYPE"], env["type"], "debug" if env["debug"] else "release" ] ).lower(), 
    lib + GlobRekursiv("include", [".h", ".hpp"] ) + documentation
)    

# define clean-up
env.Clean( zip, [ "documentation", ".sconsign.dblite" ] )

# ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


# --- test target ------------------------------------------------------------------------------------------------------------------------------------------------------------

env.Alias( "test", Program( "testparser", "test/testparser.c", LIBS=["dateformat"], LIBPATH=["."] ) );

