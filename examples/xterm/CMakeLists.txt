STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
project(EXAMPLES-${CURRENT_FOLDER})

file(GLOB_RECURSE SOURCES  ./* )

# set(${PROJECT_NAME}_SOURCES
#     ${SOURCES}
# )

message(${SOURCES})

add_executable(${PROJECT_NAME}
    ${SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE obc_controlPanel_baselib
)
