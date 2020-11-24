cmake_minimum_required(VERSION 3.10)

project(print_ip)

add_subdirectory(print_ip)
add_subdirectory(test)

find_package(Doxygen COMPONENTS dot)

if(DOXYGEN_FOUND)
  configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
    ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    @ONLY)
  add_custom_target(
    html
    ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/../
    COMMENT "Creating HTML documentation with Doxygen" VERBATIM)
endif()

enable_testing()