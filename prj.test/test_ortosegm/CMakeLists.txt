add_executable(test_ortosegm test_ortosegm.cpp)
target_link_libraries(test_ortosegm ortosegm)
set_property(TARGET test_ortosegm PROPERTY CXX_STANDARD 17)
