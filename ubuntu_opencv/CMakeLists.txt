# 声明要求的 cmake 的最低版本
cmake_minimum_required( VERSION 2.8 )

# 声明一个cmake工程
set( PROJECT_NAME imageBasics )
project( ${PROJECT_NAME} )

# 添加C++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 寻找OpenCV库
find_package( OpenCV REQUIRED )
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable( imageBasics imageBasics.cpp )
# 链接OpenCV库
target_link_libraries( imageBasics ${OpenCV_LIBS} )
