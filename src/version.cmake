
    message(STATUS "Setting tag version and commit ID")
    message(STATUS "Version : ${VERSION}")
    message(STATUS "Revision : ${GIT_REVISION}")

    set(VERSION "${VERSION}")
    set(GIT_REVISION "${GIT_REVISION}")

    configure_file("${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in" "${TO}")

    
