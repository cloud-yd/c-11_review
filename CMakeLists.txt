# cmake最低版本要求
cmake_minimum_required(VERSION 3.6)

# 工程名称
project(tutorial
		LANGUAGES C CXX)

# Enable C++11 (注意：这种方式只适用于cmake3.1之后)
#set(CMAKE_CXX_STANDARD 11)
# 版本低于cmake3.1的设置方法 -std=c++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")
#add_compile_options(-g -Wall -std=c++11) 

# 指定头文件路径，多个路径之间使用空格分隔
include_directories(${PROJECT_SOURCE_DIR}/include)

# 指定源文件路径，并将该路径下的所有源文件保存在变量中
#aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_LIST)
set(SRC_LIST
	learn_smart_pointer
	learn_smart_pointer2
	learn_template
	learn_auto_for)

foreach(bin_name ${SRC_LIST})
	add_executable(${bin_name} ${PROJECT_SOURCE_DIR}/src/${bin_name}.cpp)
	# target_link_libraries(${bin_name} ${WORKFLOW_LIB})
endforeach()

# 设置elf文件的生成路径 (PROJECT_SOURCE_DIR: 工程根目录)
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
