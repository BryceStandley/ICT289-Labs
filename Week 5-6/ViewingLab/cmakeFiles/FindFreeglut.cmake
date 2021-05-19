find_library(FREEGLUT_LIBRARY
       NAMES libglut.3.11.0.dylib
       HINTS "${PROJECT_SOURCE_DIR}/ViewingLab"
       PATHS ${PROJECT_SOURCE_DIR}/ViewingLab
       PATH_SUFFIXES lib
       NO_DEFAULT_PATH
       )

if(FREEGLUT_LIBRARY)
   message("Library: FREEGLUT found! Located at: ${FREEGLUT_LIBRARY}")
else()
   message("Library: FREEGLUT NOT found! Located at: ${FREEGLUT_LIBRARY}")
endif(FREEGLUT_LIBRARY)

find_library(GLUT_LIBRARY
        NAMES libglut.a
        HINTS "${PROJECT_SOURCE_DIR}/ViewingLab"
        PATHS ${PROJECT_SOURCE_DIR}/ViewingLab
        PATH_SUFFIXES lib
        NO_DEFAULT_PATH
        )

if(GLUT_LIBRARY)
   message("Library: GLUT found! Located at: ${GLUT_LIBRARY}")
else()
   message("Library: GLUT NOT found! Located at: ${GLUT_LIBRARY}")
endif(GLUT_LIBRARY)