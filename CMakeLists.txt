cmake_minimum_required(VERSION 3.15)
project(interviewer)
set(CMAKE_CXX_STANDARD 20)


#file(GLOB SRC_LIST "*.cpp" "protocol/*.cpp")
#自定义搜索规矩
#aux_source_directory(src DIR_SRC)
#aux_source_directory(include DIR_INC) #发现一个目录下所有的源代码文件并将列表存储在一个变量中。

add_subdirectory(offer)
add_subdirectory(leetcode)
add_subdirectory(datastruct)

#add_library(lib ${DIR_SRCS})
ADD_EXECUTABLE(interview main.cpp)
target_link_libraries(interview offer leetcode)
