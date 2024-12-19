# MainWindow/CMakeLists.txt

# 查找 Qt 的 Widgets 模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# 设置源文件
set (MAINWINDOW_SOURCES
    MainWindow.cpp
    MainWindow.h
    MainWindow.ui
)

# 如果是 Qt6，则使用 qt_add_executable 否则使用 add_executable
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_library(MainWindow STATIC
        ${MAINWINDOW_SOURCES}
        icon.qrc
    )
else()
    add_library(MainWindow STATIC
        ${MAINWINDOW_SOURCES}
    )
endif()

# 引用 Form/SideButton 库
add_subdirectory(../Form/SideButton ${CMAKE_BINARY_DIR}/Form/SideButton)

# 将 MainWindow 依赖于 QtWidgets
target_link_libraries(MainWindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# 让目标 MainWindow 的头文件对外部可见
target_include_directories(MainWindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
