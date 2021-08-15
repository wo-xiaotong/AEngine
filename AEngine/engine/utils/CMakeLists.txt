set(project_name "utils")

set(src
filereader.h
filereader.cpp
logtool.h
logtool.cpp
)

source_group("source" FILES ${src})

add_library(
    ${project_name}
    ${src}
)