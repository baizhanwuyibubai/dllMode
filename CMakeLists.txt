# 最小版本要求
cmake_minimum_required(VERSION 3.10)
project(MyExportDLL)

# 设置 C++ 标准（如果需要）
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# 定义构建目标为共享库（DLL）
add_library(MyDll SHARED src/MyDll.c src/MyDll.h)

# 配置导出符号
target_compile_definitions(MyDll PRIVATE BUILD_MY_DLL=1)

# 配置 DLL 输出路径
set_target_properties(MyDll PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

# 生成导入库（方便其他语言调用）
#add_custom_command(TARGET MyDll POST_BUILD
#    COMMAND ${CMAKE_COMMAND} -E copy_if_different
#    ${MyDll_DLL}
#    ${CMAKE_BINARY_DIR}/bin/
#)

# 添加测试文件（可选）
#enable_testing()
#add_test(NAME MyDllTest COMMAND $<TARGET_FILE:MyDllTest>)

# 生成 DLL 的导入库（Windows 特定）
#if (WIN32)
#    add_custom_command(
#        TARGET MyDll POST_BUILD
#        COMMAND ${CMAKE_C_COMPILER} -mlink -def:${CMAKE_CURRENT_SOURCE_DIR}/src/MyDll.def -libpath:.
#        COMMENT "Generating import library"
#    )
#endif ()

# 将 DLL 复制到 bin 目录（方便分发）
#install(TARGETS MyDll DESTINATION bin)
