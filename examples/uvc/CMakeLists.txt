project(EXAMPLES-UVC)

file(GLOB_RECURSE SOURCES  ./* )

set(EXAMPLES_SOURCES
    ${SOURCES}
)

add_executable(${PROJECT_NAME}
    ${EXAMPLES_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE obc_controlPanel_baselib
)
