add_definitions(-DSERVER -DSTANDALONE)


set(EXTRA_LIBS ${EXTRA_LIBS} -shared -pthread -rdynamic -m64)

add_definitions("-I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/cares -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/http_parser -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/node -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/npm -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/openssl -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/uv -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/v8 -I/home/mapc/pr0j/sb/fork/code/src/platform_linux/linux64/include/zlib  '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION'  -fPIC -Wall -Wextra -Wno-unused-parameter -pthread -m64 -O2 -fno-strict-aliasing -fno-omit-frame-pointer -fno-rtti -fno-exceptions")

if(${BUILD_TARGET_WINDOWS})
    set(EXTRA_LIBS ${EXTRA_LIBS} opengl32 ws2_32 winmm)
elseif(${BUILD_TARGET_WINDOWS})
    set(EXTRA_LIBS ${EXTRA_LIBS} dl -pthread)
elseif(${BUILD_TARGET_WINDOWS})
    set(EXTRA_LIBS ${EXTRA_LIBS} socket nsl)
endif()


set(SERVER_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/../nodejs/bridge

    ${CMAKE_CURRENT_SOURCE_DIR}/../shared/crypto
    ${CMAKE_CURRENT_SOURCE_DIR}/../shared/geom
    ${CMAKE_CURRENT_SOURCE_DIR}/../shared/stream
    ${CMAKE_CURRENT_SOURCE_DIR}/../shared/tools
    ${CMAKE_CURRENT_SOURCE_DIR}/../shared/zip

    ${CMAKE_CURRENT_SOURCE_DIR}/../engine/server
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine/command
    ${CMAKE_CURRENT_SOURCE_DIR}/../engine/worldio

    ${CMAKE_CURRENT_SOURCE_DIR}/../fpsgame/server
    ${CMAKE_CURRENT_SOURCE_DIR}/../fpsgame/entities
)

set(SB_SERVER_LIBRARY server_${BUILD_PLATFORM_BIN}_${BUILD_TARGET_ARCH} CACHE INTERNAL "Server binary name.")
add_executable(${SB_SERVER_LIBRARY} ${SERVER_SOURCES})
target_link_libraries(${SB_SERVER_LIBRARY}
    ${TOMCRYPT_LIBRARIES}
    ${ENET_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${ZLIB_LIBRARIES}
    ${UV_LIBRARIES}
    ${SDL_LIBRARIES}
    ${LUVIT_LIBRARIES}
    ${LUAJIT_LIBRARIES}
    ${EXTRA_LIBS})

install(TARGETS
    ${SB_SERVER_LIBRARY}
    RUNTIME DESTINATION ${INSTALL_RUNTIME_DIR}
    LIBRARY DESTINATION ${INSTALL_LIBRARY_DIR}
    ARCHIVE DESTINATION ${INSTALL_ARCHIVE_DIR})
