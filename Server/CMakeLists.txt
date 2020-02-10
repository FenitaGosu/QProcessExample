set(SRC_LIST
	${CMAKE_CURRENT_LIST_DIR}/main.cpp
	)

add_executable(Server ${SRC_LIST})

find_package(Qt5Core REQUIRED)

set(QT_MODULES_LIST
	Core
	)

qt5_use_modules(Server LINK_PRIVATE ${QT_MODULES_LIST})
set_target_properties(Server PROPERTIES AUTOMOC ON AUTORCC ON)
