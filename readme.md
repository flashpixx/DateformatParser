# DateFormat Grammar

## Build

1. Download from [AntLR](http://www.antlr.org/download.html)
    * AntLR Java complete executable
    * AntLR Runtime _C++ target_ and copy folders into ```runtime``` directory 
2. Follow [AntLR tutorial](https://github.com/antlr/antlr4/blob/master/doc/cpp-target.md) and translate grammer file to C++ source code with

```bash
java -jar antlr-<your version>-complete.jar -Dlanguage=Cpp grammer/Dateformat.g4 -o src/
```
3. run ```scons``` for building
    * see ```SConstruct``` header for build targets and build parameter
    * if you want to prefere a (static) build-in AntLR runtime, remove the DLL library
from the directory ```runtime/lib```
