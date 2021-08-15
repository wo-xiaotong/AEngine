set(project_name "test")
AUX_SOURCE_DIRECTORY(. Src)
add_executable(${project_name} ${Src})