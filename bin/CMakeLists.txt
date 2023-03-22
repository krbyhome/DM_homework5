add_executable(${PROJECT_NAME} "NAME OF CPP".cpp) //type cpp file name here

target_link_libraries(${PROJECT_NAME} PUBLIC Solver)
target_link_libraries(${PROJECT_NAME} PUBLIC SetOperations)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})