#add_library(dynarrayt dynarrayt.h dynarrayt.cpp)
add_executable(test_dynarrayt test_dynarrayt.cpp)
target_link_libraries(test_dynarrayt dynarrayt)
set_property(TARGET test_dynarrayt PROPERTY CXX_STANDARD 17)
