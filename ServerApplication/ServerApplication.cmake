add_executable(ServerApplication ServerApplication/main.cpp)

find_package(Qt5Core)

qt5_use_modules(ServerApplication LINK_PRIVATE Core)
set_target_properties(ServerApplication PROPERTIES AUTOMOC ON AUTORCC ON)
