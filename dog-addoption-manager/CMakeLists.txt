cmake_minimum_required(VERSION 3.30)
project(a10_BalaciSofia_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network)

add_executable(a10_BalaciSofia_1
        main.cpp
        ui/adddialog.cpp
        ui/adddialog.h
        ui/adminwindow.cpp
        ui/adminwindow.h
        ui/adoptdog.cpp
        ui/adoptdog.h
        ui/chart.cpp
        ui/chart.h
        controller/controller_admin.cpp
        controller/controller_admin.h
        controller/controller_user.cpp
        controller/controller_user.h
        ui/displaydogs.cpp
        ui/displaydogs.h
        domain/domain.h
        ui/htmlorcsv.cpp
        ui/htmlorcsv.h
        ui/mainwindow.cpp
        ui/mainwindow.h
        repo/repo.cpp
        ui/updatedialog.cpp
        repo/repo.h
        ui/userwindow.cpp
        ui/updatedialog.h
        ui/userwindow.h
        domain/domain.cpp
        repo/dog_table_model.cpp
        repo/dog_table_model.h
        domain/command.cpp
        domain/command.h
        repo/undo_redo.cpp
        repo/undo_redo.h
)
target_include_directories(a10_BalaciSofia_1 PRIVATE
        ${CMAKE_SOURCE_DIR}
)
target_link_libraries(a10_BalaciSofia_1 PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
        Qt6::Network
)

if (WIN32)
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            "${QT_INSTALL_PATH}/plugins/platforms/qwindows.dll"
            "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms"
    )

    foreach(QT_LIB Core Gui Widgets Network)
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy_if_different
                "${QT_INSTALL_PATH}/bin/Qt6${QT_LIB}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>"
        )
    endforeach()
endif()