cmake_minimum_required(VERSION 3.17)
project(AD_TP_Classes)

# Build the Google tests
set(GOOGLETEST_PATH lib/googletest-master)
add_subdirectory(${GOOGLETEST_PATH})

# Add the source files of each TP class
#file(GLOB TP1_FILES CONFIGURE_DEPENDS "TP1/*.cpp")
file(GLOB Parte1_FILES CONFIGURE_DEPENDS "Parte1/*.cpp")
#file(GLOB TP3_FILES CONFIGURE_DEPENDS "TP3/*.cpp")
#...

#add_executable(TP1 main.cpp ${TP1_FILES})
add_executable(Parte1 main.cpp ${Parte1_FILES}
        ex1.cpp
        ex2.cpp
        ex3.cpp
        ex4.cpp
        exercises.h)

#add_executable(TP3 main.cpp ${TP3_FILES})
#...

#target_link_libraries(TP1 gtest_main gmock_main)
target_link_libraries(Parte1 gtest_main gmock_main)
#target_link_libraries(TP3 gtest_main gmock_main)
#...