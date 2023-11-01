add_executable(cadex main.cpp random-number.cpp)

set_target_properties(cadex PROPERTIES
        CXX_STANDARD 17
)

find_package(OpenMP)
if (OpenMP_CXX_Found)
    target_link_libraries(cadex PUBLIC OpenMP::OpenMP_CXX)
endif ()

target_link_libraries(cadex PRIVATE fmt_header_only)
target_link_libraries(cadex PRIVATE curves_library)