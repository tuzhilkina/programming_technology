add_executable(test_ortorect test_ortorect.cpp)
target_link_libraries(test_ortorect ortorect)
set_property(TARGET test_ortorect PROPERTY CXX_STANDARD 17)
