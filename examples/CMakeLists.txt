add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/test.c)
target_link_libraries(${PROJECT_NAME} linear_algebra)