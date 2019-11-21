#add_library(queue queue.h queue.cpp)
add_executable(test_queue test_queue.cpp)
target_link_libraries(test_queue queue)
set_property(TARGET test_queue PROPERTY CXX_STANDARD 17)
