add_library(curves_library SHARED
        circle.cpp
        ellipsis.cpp
        helix.cpp)

set_target_properties(curves_library PROPERTIES
        CXX_STANDARD 17
)
target_include_directories(curves_library PUBLIC ../include)