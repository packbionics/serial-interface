cmake_minimum_required(VERSION 3.8)
project(serial_interface)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(PkgConfig REQUIRED)

pkg_check_modules(libserial REQUIRED)

# Source files which will be compiled as part of the library
set(
  SRC_FILES
  src/mcu_interface.cpp
)

add_library(${PROJECT_NAME} ${SRC_FILES})
target_include_directories(
  ${PROJECT_NAME} PRIVATE
  $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
)
ament_target_dependencies(
  ${PROJECT_NAME}
  sensor_msgs
)
target_link_libraries(${PROJECT_NAME} -lserial)

install(
  DIRECTORY include/${PROJECT_NAME}
  DESTINATION include/
)

install(
  TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  RUNTIME DESTINATION bin
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()

  find_package(ament_cmake_gtest REQUIRED)
  # ament_add_gtest(libserial_bridge_test test/test_libserial_bridge.cpp)
  # target_include_directories(libserial_bridge_test PUBLIC
  #   $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  #   $<INSTALL_INTERFACE:include>
  # )

  # target_link_libraries(libserial_bridge_test ${PROJECT_NAME})
endif()

ament_export_libraries(
  ${PROJECT_NAME}
)

ament_export_targets(
  export_${PROJECT_NAME}
)

ament_export_include_directories(
  include
)

ament_package()
