# C++ Project Creator

using of cpp project creator is very easy:
it runs oly on **linux systems**.

cpproject  --path:project_name --project-normal
creates a C++ project with cmake configuration and C++ terminal command compilation for single file.

cpproject  --path:project_name --project-postgres
creates a C++ project with cmake configuration and C++ terminal command,
with Postgresql configuration both for cmake and terminal command compilation for single file.

cpproject  --path:project_name --project-qt-ui
creates a GUI Qt project with cmake configuration;

cpproject  --path:project_name --project-qt-console
creates a Console Qt project with cmake configuration;

for all cases it can be add these parameters:
[--git-init] [--author:name] [--email:email@mail.com]

for example:
cpproject  --path:project_name --project-normal --git-init --author:name --email:email@mail.com

## Files Explanation
![files.png](files.png)

    /bin  : contains binary file.
    /build: contains folder and files for cmake cmpilation.
    /data: for any data maybe developer using for test or any other porpuse.
    /scr: consist of C++ source files.
    cmake.sh: cmake compilation script.
    CMakeList.txt: cmake configuration.
    compiler.sh: C++ compile terminal command using by run.sh.
    new.sh: create new C++ source file.
    run.sh: compile and run the binary file.

## Using new.sh
    
    ./new.sh 001
    it make main_001.cpp file

## Using run.sh
    
    ./run.sh 001
    it compile and run main_001.cpp
