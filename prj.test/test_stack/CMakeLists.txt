#add_library(stack stack.h stack.cpp)
add_executable(test_stack test_stack.cpp)
target_link_libraries(test_stack stack)
set_property(TARGET test_stack PROPERTY CXX_STANDARD 17)
