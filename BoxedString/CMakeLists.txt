cmake_minimum_required(VERSION 3.10)

# list of source files
set(libBoxedStringPlot BoxedString_plot.c)

# set the project name
project(BoxedString VERSION 1.0)

# Force verbosity
set(CMAKE_VERBOSE_MAKEFILE ON CACHE BOOL "ON" FORCE)

# Specify command line parameters for the build toolkit
if ("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
    message("Microsoft C/C++ Optimizing Compiler found.")
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ${BUILD_SHARED_LIBS})
    add_compile_options(/W4)
    set(CMAKE_C_FLAGS_RELEASE "/WX")
    #set (CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
else()
    message(${CMAKE_C_COMPILER_ID} " found.")
    add_compile_options(-Wall -Wextra -pedantic)
    set(CMAKE_C_FLAGS_RELEASE "-O3 -Werror")
    set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)
    set(CMAKE_EXE_LINKER_FLAGS "-fuse-ld=gold -Wl,-z,relro -Wl,-z,now")
endif()

################################################################################
# this is the "BoxedStringPlot library"                                        #
################################################################################
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)
add_library(libBoxedStringPlot ${libBoxedStringPlot})
set_target_properties(
    libBoxedStringPlot PROPERTIES
    POSITION_INDEPENDENT_CODE ${BUILD_SHARED_LIBS}
    OUTPUT_NAME BoxedStringPlot
)

################################################################################
# this is the "BoxedString executable"                                         #
################################################################################
add_executable(exeBoxedString BoxedString.c)
target_link_libraries(exeBoxedString libBoxedStringPlot)
set_target_properties(
    exeBoxedString PROPERTIES
    OUTPUT_NAME BoxedString
)