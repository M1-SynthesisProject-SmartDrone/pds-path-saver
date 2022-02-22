#########################################################################################################
###                                       GENERAL CONFIG                                               ##
#########################################################################################################

message("%%% SYNTHESIS PROJECT : PATH SAVER")
message("\n%% GENERAL CONFIGURATION")

# GENERAL SETTINGS
project(SmartDrone CXX)
cmake_minimum_required(VERSION 3.2)
set(VERSION 1.0.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)

set(APP_NAME pathSaver)

# OUTPUT DIR SETTINGS
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

# COMPILER OPTIONS
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS_DEBUG   " -g3 -DDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE " -O3")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}") # Warning : option are important for some lib


########################################################################################################
###                                       LIBRARY CONFIG                                              ##
########################################################################################################

message("\n%% EXTERNALS libs configuration")

message("- Checking : pkg")
find_package(PkgConfig REQUIRED)
if(PkgConfig_FOUND)
    message("-> succes " )
endif()

message("- Checking : Thread")
find_package(Threads)

######################################################################################################
###                                            LINKS                                                ##
######################################################################################################

add_subdirectory(lib)
include_directories(lib)
include_directories(include)


######################################################################################################
###                                         APPLICATION                                             ##
######################################################################################################

message("\n%% APPLICATION GENERATION")

file(GLOB_RECURSE drone_SRC 
    "lib/*.h"
    "include/*.h"
     "src/*.cpp"
)

# %% App files
add_executable(${APP_NAME} ${drone_SRC})

target_link_libraries(${APP_NAME} PUBLIC
    cxxopts
    -lpqxx -lpq
)