file(GLOB_RECURSE src_list "**.cpp")
add_executable(tic-tac-toe ${src_list})
target_include_directories(tic-tac-toe PRIVATE ../include)
target_link_libraries(tic-tac-toe PRIVATE project_options project_warnings)
