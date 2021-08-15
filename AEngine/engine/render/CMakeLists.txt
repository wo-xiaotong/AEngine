set(project_name "render")


include_directories("${AEngine_Build_Root}/deps/glfw/include")
include_directories("${AEngine_Build_Root}/deps/glew/include")
include_directories("${AEngine_Build_Root}/engine")

set(src
window.h
shader.h
shadermanager.h
shadermanager.cpp
window.cpp
shader.cpp
)

source_group("Source" FILES ${src})

add_library(
    ${project_name}
    ${src}
)
target_link_libraries(${project_name} utils)