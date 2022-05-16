project(splitlib)

set(SOURCE_FILES split_string.cpp)
set(HEADER_FILES split_string.h)

add_library(splitlib_lib  ${SOURCE_FILES} ${HEADER_FILES})