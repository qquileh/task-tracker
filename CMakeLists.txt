cmake_minimum_required (VERSION 3.8)

# Включение горячей перезагрузки для компиляторов MSVC, если поддерживается.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("task-tracker")

add_executable (task-tracker "src/main.cpp"  "include/CommandRepository.h"  "include/CommandLineArguments.h" "src/CommandLineArguments.cpp" "include/CommandDispatcher.h" "src/CommandDispatcher.cpp" "src/CommandRepository.cpp"  "include/DatabaseConnectionConfig.h" "src/DatabaseConnectionConfig.cpp")

find_package(libpqxx REQUIRED)
target_link_libraries(task-tracker PRIVATE libpqxx::pqxx)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET task-tracker PROPERTY CXX_STANDARD 20)
endif()
