cmake_minimum_required(VERSION 3.10)
project(SensorTagApp)

set(CMAKE_CXX_STANDARD 11)

add_executable(SensorTagApp main.cpp conversions.cpp rw.cpp objects.cpp config_st.cpp watki.cpp )


target_link_libraries(SensorTagApp "${CMAKE_SOURCE_DIR}/gattlib/build/bluez/libgattlib.so" pthread)