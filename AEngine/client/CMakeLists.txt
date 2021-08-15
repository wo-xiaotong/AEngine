set(project_name "client")

include_directories("${AEngine_Build_Root}/deps/glfw/include")
include_directories("${AEngine_Build_Root}/deps/glew/include")
include_directories("${AEngine_Build_Root}/engine/render")

link_directories("${AEngine_Build_Root}/deps/glfw/lib-vc2015")
link_directories("${AEngine_Build_Root}/deps/glew/lib/Release/x64")
link_libraries("glfw3.lib")
link_libraries("glew32s.lib")
link_libraries("opengl32.lib")

AUX_SOURCE_DIRECTORY(. Src)

SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
add_executable(${project_name} ${Src})
target_link_libraries(${project_name} render)