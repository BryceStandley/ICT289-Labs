find_library(FREEGLUT_LIBRARY
        NAMES freeglut.lib
        PATHS
            ${PROJECT_SOURCE_DIR}/vender/
        PATH_SUFFIXES lib src
        NO_DEFAULT_PATH
        )



if(FREEGLUT_LIBRARY)
    message("Library: FreeGlut found! Located at: ${FREEGLUT_LIBRARY}")
else()
    message("Library: FreeGlut NOT found! Located at: ${FREEGLUT_LIBRARY}")
endif(FREEGLUT_LIBRARY)