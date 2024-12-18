#src/MainWindow/CMakeLists.txt

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
    )
else()
    add_library(MainWindow STATIC
        ${MAINWINDOW_SOURCES}
    )
endif()

# 将 MainWindow 依赖于 QtWidgets
target_link_libraries(MainWindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# 如果需要将这个模块与其他模块链接，可以在这里添加
# target_link_libraries(MainWindow PRIVATE other_libraries)
