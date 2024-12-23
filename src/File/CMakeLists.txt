# File/CMakeLists

# 查找 Qt 的 widgets 模块
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

# 设置源文件
set(FILE_SOURCES
    HomePage.h HomePage.cpp HomePage.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_library(File STATIC
        ${FILE_SOURCES}
        ../../resource/icon/icon.qrc
    )
endif()

# 链接 Qt 的 widgets 模块
target_link_libraries(File PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
