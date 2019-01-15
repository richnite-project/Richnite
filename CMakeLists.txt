cmake_minimum_required(VERSION 2.8.6)

#Set build version
set(VERSION_MAJOR "5")
set(VERSION_MINOR "0.0 ${CMAKE_BUILD_TYPE}")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CONFIGURATION_TYPES Debug Release CACHE TYPE INTERNAL)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_SKIP_PACKAGE_ALL_DEPENDENCY ON)
set(CMAKE_SUPPRESS_REGENERATION ON)
set(STATIC ON CACHE BOOL "Link libraries statically")
set(BUILD_TESTS OFF CACHE BOOL "build tests")

set(FAIL_ON_WARNINGS "Treat compile warnings as errors" OFF)

if(BUILD_TESTS)
    enable_testing()
else()
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/CTestCustom.cmake ${CMAKE_CURRENT_BINARY_DIR})
endif()

project(iridium)

include_directories(include
  src
  external
  "${CMAKE_CURRENT_BINARY_DIR}/version"
)

if(APPLE)
  include_directories(SYSTEM /usr/include/malloc)
  enable_language(ASM)
endif()

if(MSVC)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Windows)
elseif(APPLE)
  set(CMAKE_OSX_DEPLOYMENT_TARGET 10.10)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/OSX)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)
else()
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Linux)
  include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src/Platform/Posix)
endif()

set(STATIC ${MSVC} CACHE BOOL "Link libraries statically")

if(MSVC)
  add_definitions("/bigobj /MP /W3 /GS- /D_CRT_SECURE_NO_WARNINGS /wd4996 /wd4345 /D_WIN32_WINNT=0x0600 /DWIN32_LEAN_AND_MEAN /DGTEST_HAS_TR1_TUPLE=0 /D_VARIADIC_MAX=8 /D__SSE4_1__")
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /STACK:10485760")
  if(STATIC)
    foreach(VAR CMAKE_C_FLAGS_DEBUG CMAKE_CXX_FLAGS_DEBUG CMAKE_C_FLAGS_RELWITHDEBINFO CMAKE_CXX_FLAGS_RELWITHDEBINFO CMAKE_C_FLAGS_RELEASE CMAKE_CXX_FLAGS_RELEASE)
      string(REPLACE "/MD" "/MT" ${VAR} "${${VAR}}")
    endforeach()
  endif()
  include_directories(SYSTEM ${CMAKE_CURRENT_SOURCE_DIR}/src/platform/msc)
else()
  if (${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
      # This option has no effect in glibc version less than 2.20.
      # Since glibc 2.20 _BSD_SOURCE is deprecated, this macro is recomended instead
      add_definitions("-D_DEFAULT_SOURCE -D_GNU_SOURCE")
  endif()
  set(ARCH default CACHE STRING "CPU to build for: -march value or default")
  if("${ARCH}" STREQUAL "default")
    set(ARCH_FLAG "")
  else()
    set(ARCH_FLAG "-march=${ARCH}")
  endif()

  # globals warnings
  #set(WARNINGS "-Wall -Wextra -Wpointer-arith -Wvla -Wwrite-strings -Werror -Wno-error=extra -Wno-error=unused-function -Wno-error=deprecated-declarations -Wno-error=sign-compare -Wno-error=strict-aliasing -Wno-error=type-limits -Wno-unused-parameter -Wno-error=unused-variable -Wno-error=uninitialized -Wno-error=unused-result")
  set(WARNINGS "-Wall -Wextra")

  # Debug warnings
  set(DEBUG_WARNINGS "-Wpointer-arith -Wvla -Wwrite-strings")

  # Release warnings
  set(RELEASE_WARNINGS "-Wno-unused-parameter -Wno-reorder -Wno-missing-field-initializers -Wno-unused-variable  -Wno-sign-compare -Wno-unused-function")

#  # per compiler warnings
#  if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
#    # set(WARNINGS "${WARNINGS} -Wno-error=mismatched-tags -Wno-error=null-conversion -Wno-overloaded-shift-op-parentheses -Wno-error=shift-count-overflow -Wno-error=tautological-constant-out-of-range-compare -Wno-error=unused-private-field -Wno-error=unneeded-internal-declaration -Wno-error=unused-function -Wno-error=missing-braces -Wno-unused-lambda-capture -Wno-exceptions -Wno-unknown-pragmas")
#    set(WARNINGS "${WARNINGS}")
#  else()
#    # set(WARNINGS "${WARNINGS} -Wlogical-op -Wno-error=maybe-uninitialized -Wno-error=clobbered -Wno-error=unused-but-set-variable")
#    set(WARNINGS "${WARNINGS}")
#  endif()

  if(MINGW)
    set(WARNINGS "${WARNINGS} -Wno-error=unused-value -Wno-error=unused-but-set-variable")
    set(MINGW_FLAG "-DWIN32_LEAN_AND_MEAN")
    include_directories(SYSTEM src/platform/mingw)
  else()
    set(MINGW_FLAG "")
  endif()

#  if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS 5.1))
#    # set(WARNINGS "${WARNINGS} -Wno-error=odr")
#    set(WARNINGS "${WARNINGS}")
#  endif()

#  if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND (CMAKE_C_COMPILER_VERSION VERSION_GREATER 6))
#    # set(WARNINGS "${WARNINGS} -Wno-logical-op -Wno-error=terminate -Wno-error=init-self")
#    set(WARNINGS "${WARNINGS}")
#  endif()

#  if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND (CMAKE_C_COMPILER_VERSION VERSION_GREATER 7))
#    # set(WARNINGS "${WARNINGS} -Wno-format-truncation -Wno-implicit-fallthrough -Wno-error=stringop-overflow")
#    set(WARNINGS "${WARNINGS}")
#  endif()

  # C Warnings
  #    set(C_WARNINGS "-Waggregate-return -Wnested-externs -Wold-style-definition -Wstrict-prototypes")
  # set(C_WARNINGS "")

  # CXX warnings
  #    set(CXX_WARNINGS "-Wno-reorder -Wno-missing-field-initializers")
  # set(CXX_WARNINGS "")

  # C Flags
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 ${MINGW_FLAG} ${WARNINGS} ${C_WARNINGS} ${ARCH_FLAG} -maes")


  # CXX Flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ${MINGW_FLAG} ${WARNINGS} ${CXX_WARNINGS} ${ARCH_FLAG} -maes")

  if(NOT APPLE)
  #       set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  endif()

  if(APPLE)
  #        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DGTEST_HAS_TR1_TUPLE=0")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
  endif()


  # debug flags
  set(DEBUG_FLAGS "")
  # gcc < 4.8
#  if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS 4.8))
#    # set(DEBUG_FLAGS "-g3 -Og -gdwarf-4 -fvar-tracking -fvar-tracking-assignments -fno-inline -fno-omit-frame-pointer")
#    set(DEBUG_FLAGS "")
#  endif()

  # clang
#  if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
##    set(DEBUG_FLAGS "${DEBUG_FLAGS} -Wno-delete-non-virtual-dtor")
#    set(DEBUG_FLAGS "${DEBUG_FLAGS}")
#  endif()

  # release flags
  # set(RELEASE_FLAGS "-Ofast -DNDEBUG -Wno-unused-variable -Wno-uninitialized -Wno-sign-compare -Wno-unused-function"
  set(RELEASE_FLAGS "-Ofast")

  # gcc < 4.8
  if(CMAKE_C_COMPILER_ID STREQUAL "GNU" AND NOT (CMAKE_C_COMPILER_VERSION VERSION_LESS 4.8))
    # set(RELEASE_FLAGS "${RELEASE_FLAGS} -Wno-strict-aliasing -Wno-unused-but-set-variable -Wno-maybe-uninitialized -Winit-self -Wno-sign-compare")
    set(RELEASE_FLAGS "${RELEASE_FLAGS}")
  endif()

  # clang
  if(CMAKE_C_COMPILER_ID STREQUAL "Clang")
    # set(RELEASE_FLAGS "${RELEASE_FLAGS} -Wno-delete-non-virtual-dtor -Wno-unused-private-field -Wno-unused-lambda-capture -Wno-exceptions")
    set(RELEASE_FLAGS "${RELEASE_FLAGS}")
  endif()

  if(NOT APPLE)
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_SYSTEM_NAME STREQUAL "Linux" AND CMAKE_BUILD_TYPE STREQUAL "Release" AND ((CMAKE_C_COMPILER_VERSION VERSION_GREATER 4.9) OR (CMAKE_C_COMPILER_VERSION VERSION_EQUAL 4.9)))
      set(CMAKE_AR gcc-ar)
      set(CMAKE_RANLIB gcc-ranlib)
    endif()
  else() # remove ranlib complaining for no symbols
    set(CMAKE_C_ARCHIVE_CREATE   "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
    set(CMAKE_CXX_ARCHIVE_CREATE "<CMAKE_AR> Scr <TARGET> <LINK_FLAGS> <OBJECTS>")
    set(CMAKE_C_ARCHIVE_FINISH   "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
    set(CMAKE_CXX_ARCHIVE_FINISH "<CMAKE_RANLIB> -no_warning_for_no_symbols -c <TARGET>")
  endif()

  if(STATIC AND NOT APPLE)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++")
    endif()
  endif()

  set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS} ${DEBUG_WARNINGS}")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS} ${DEBUG_WARNINGS}")
  set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} ${RELEASE_FLAGS} ${RELEASE_WARNINGS}")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} ${RELEASE_FLAGS} ${RELEASE_WARNINGS}")

set(BOOST_IGNORE_SYSTEM_PATHS_DEFAULT OFF)
option(BOOST_IGNORE_SYSTEM_PATHS "Ignore boost system paths for local boost installation" ${BOOST_IGNORE_SYSTEM_PATHS_DEFAULT})
if (${BOOST_IGNORE_SYSTEM_PATHS} STREQUAL "ON")
  set(Boost_NO_SYSTEM_PATHS TRUE)
endif()
if(STATIC)
    set(Boost_USE_STATIC_LIBS ON)
    set(Boost_USE_STATIC_RUNTIME ON)
endif()
find_package(Boost 1.55 REQUIRED COMPONENTS system filesystem thread date_time chrono regex serialization program_options)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
if(MINGW)
    set(Boost_LIBRARIES "${Boost_LIBRARIES};ws2_32;mswsock")
elseif(APPLE)
    set(Boost_LIBRARIES "${Boost_LIBRARIES}")
elseif(NOT MSVC)
    set(Boost_LIBRARIES "${Boost_LIBRARIES};rt")
endif()

set(COMMIT_ID_IN_VERSION ON CACHE BOOL "Include commit ID in version")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/version")

if (NOT COMMIT_ID_IN_VERSION)
    set(VERSION "${VERSION}-unknown")
    set(COMMIT_ID "unknown")
    message(STATUS "Version : ${VERSION}")
    message(STATUS "Revision : ${COMMIT_ID}")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/version/version.h")
    add_custom_target(version ALL)
elseif(DEFINED COMMIT_ID_IN_VERSION)
    find_package(Git QUIET)
    if(Git_FOUND OR GIT_FOUND)
        message(STATUS "Found Git: ${GIT_EXECUTABLE}")
        execute_process(
            COMMAND git rev-parse --abbrev-ref HEAD  # Get the current branch
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE GIT_BRANCH
            OUTPUT_STRIP_TRAILING_WHITESPACE
            )

        execute_process(
            COMMAND git log -1 --format=%h # Get latest commit hash
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            OUTPUT_VARIABLE COMMIT_ID
            OUTPUT_STRIP_TRAILING_WHITESPACE
            )
    else()
        message(STATUS "Git not found !")
        set(GIT_BRANCH "unknown")
        set(COMMIT_ID "unknown")
    endif()
    set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}")
    message(STATUS "--------------------- Iridium Core build details ----------------------------")
    message(STATUS "Build : ${CMAKE_BUILD_TYPE}")
    message(STATUS "Compiler : ${CMAKE_C_COMPILER_ID} version ${CMAKE_CXX_COMPILER_VERSION}")
    message(STATUS "Branch : ${GIT_BRANCH}")
    message(STATUS "Version : ${VERSION}")
    message(STATUS "Revision : ${COMMIT_ID}")
    message(STATUS "Boost version : ${Boost_LIB_VERSION}")
    message(STATUS "Link libraries statically : ${STATIC}" )
    message(STATUS "Portable : ${PORTABLE}" )
    message(STATUS "Compile tests : " ${BUILD_TESTS})
    message(STATUS "----------------------------------------------------------")
    message(STATUS "Warnings")
    message(STATUS ${WARNINGS})
    message(STATUS "----------------------------------------------------------")
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
      message(STATUS "C Flags")
      message(STATUS ${CMAKE_C_FLAGS_DEBUG})
      message(STATUS "CXX Flags")
      message(STATUS ${CMAKE_CXX_FLAGS_DEBUG})
    endif()
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
      message(STATUS "C Flags")
      message(STATUS ${CMAKE_C_FLAGS_RELEASE})
      message(STATUS "CXX Flags")
      message(STATUS ${CMAKE_CXX_FLAGS_RELEASE})
    endif()

    message(STATUS "----------------------------------------------------------")
    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in" "${CMAKE_CURRENT_BINARY_DIR}/version/version.h")
    add_custom_target(version ALL)
endif()

add_subdirectory(external)
add_subdirectory(src)
if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
