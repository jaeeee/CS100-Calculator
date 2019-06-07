CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

ADD_SUBDIRECTORY(googletest)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE(test
    unit_test.cpp
    sort.cpp
    container.cpp
    Iterator.cpp
)

ADD_EXECUTABLE(calculator
    calculator.cpp
    sort.cpp
    container.cpp
    Iterator.cpp
    )

TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
