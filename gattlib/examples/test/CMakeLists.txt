

cmake_minimum_required(VERSION 2.6)

find_package(PkgConfig REQUIRED)

pkg_search_module(GATTLIB REQUIRED gattlib)
pkg_search_module(PCRE REQUIRED libpcre)


set(SOURCE_FILES conversions.h conversions.c)
set(MAIN_FILE test.c)


add_executable(test ${SOURCE_FILES} ${MAIN_FILE} )
target_link_libraries(test ${GATTLIB_LIBRARIES} ${GATTLIB_LDFLAGS} ${PCRE_LIBRARIES} pthread)
