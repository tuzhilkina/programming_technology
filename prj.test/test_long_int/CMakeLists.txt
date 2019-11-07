#add_library(long_int long_int.h long_int.cpp)
add_executable(test_long_int test_long_int.cpp)
target_link_libraries(test_long_int long_int)
set_property(TARGET test_long_int PROPERTY CXX_STANDARD 17)
