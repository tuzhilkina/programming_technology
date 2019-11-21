#add_library(matrixa matrixa.h matrixa.cpp)
add_executable(test_matrixa test_matrixa.cpp)
target_link_libraries(test_matrixa matrixa)
set_property(TARGET test_matrixa PROPERTY CXX_STANDARD 17)
