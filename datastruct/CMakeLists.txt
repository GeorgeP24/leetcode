cmake_minimum_required(VERSION 3.15)
project(datastruct)
set(CMAKE_CXX_STANDARD 17)


#file(GLOB SRC_LIST "*.cpp" "protocol/*.cpp")
#自定义搜索规矩
aux_source_directory(. DIR_SRC)
#aux_source_directory(include DIR_INC) #发现一个目录下所有的源代码文件并将列表存储在一个变量中。
add_library(datastruct ${DIR_SRC})
