cmake_minimum_required( VERSION 2.8 )
project(Library_Management)

include_directories(include)

file(GLOB SOURCES "src/*.cpp")
add_executable(testStudent ${SOURCES})

# add_executable(book src/book.cpp)
# add_executable(user src/user.cpp)