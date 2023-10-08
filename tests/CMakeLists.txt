file(GLOB_RECURSE test_list "*_test.cpp")
file(GLOB_RECURSE src_list "../src/tic-tac-toe/*.cpp")
add_executable(tic-tac-toe-tests ${src_list} ${test_list} main.cpp)
target_link_libraries(tic-tac-toe-tests PRIVATE
  project_options
  project_warnings
  doctest::doctest
)
