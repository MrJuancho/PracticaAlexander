# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\MrJua\Desktop\PracticaAlexander

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\PracticaAlexander.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\PracticaAlexander.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\PracticaAlexander.dir\flags.make

CMakeFiles\PracticaAlexander.dir\main.c.obj: CMakeFiles\PracticaAlexander.dir\flags.make
CMakeFiles\PracticaAlexander.dir\main.c.obj: ..\main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/PracticaAlexander.dir/main.c.obj"
	"D:\Visual Studio\VC\Tools\MSVC\14.16.27023\bin\Hostx86\x86\cl.exe" @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoCMakeFiles\PracticaAlexander.dir\main.c.obj /FdCMakeFiles\PracticaAlexander.dir\ /FS -c C:\Users\MrJua\Desktop\PracticaAlexander\main.c
<<

CMakeFiles\PracticaAlexander.dir\main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/PracticaAlexander.dir/main.c.i"
	"D:\Visual Studio\VC\Tools\MSVC\14.16.27023\bin\Hostx86\x86\cl.exe" > CMakeFiles\PracticaAlexander.dir\main.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\MrJua\Desktop\PracticaAlexander\main.c
<<

CMakeFiles\PracticaAlexander.dir\main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/PracticaAlexander.dir/main.c.s"
	"D:\Visual Studio\VC\Tools\MSVC\14.16.27023\bin\Hostx86\x86\cl.exe" @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\PracticaAlexander.dir\main.c.s /c C:\Users\MrJua\Desktop\PracticaAlexander\main.c
<<

# Object files for target PracticaAlexander
PracticaAlexander_OBJECTS = \
"CMakeFiles\PracticaAlexander.dir\main.c.obj"

# External object files for target PracticaAlexander
PracticaAlexander_EXTERNAL_OBJECTS =

PracticaAlexander.exe: CMakeFiles\PracticaAlexander.dir\main.c.obj
PracticaAlexander.exe: CMakeFiles\PracticaAlexander.dir\build.make
PracticaAlexander.exe: CMakeFiles\PracticaAlexander.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable PracticaAlexander.exe"
	"C:\Program Files\JetBrains\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\PracticaAlexander.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100177~1.0\x86\mt.exe --manifests  -- "D:\Visual Studio\VC\Tools\MSVC\14.16.27023\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\PracticaAlexander.dir\objects1.rsp @<<
 /out:PracticaAlexander.exe /implib:PracticaAlexander.lib /pdb:C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug\PracticaAlexander.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\PracticaAlexander.dir\build: PracticaAlexander.exe

.PHONY : CMakeFiles\PracticaAlexander.dir\build

CMakeFiles\PracticaAlexander.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PracticaAlexander.dir\cmake_clean.cmake
.PHONY : CMakeFiles\PracticaAlexander.dir\clean

CMakeFiles\PracticaAlexander.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\MrJua\Desktop\PracticaAlexander C:\Users\MrJua\Desktop\PracticaAlexander C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug C:\Users\MrJua\Desktop\PracticaAlexander\cmake-build-debug\CMakeFiles\PracticaAlexander.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\PracticaAlexander.dir\depend

