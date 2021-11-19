#include <iostream>

#include <glad/glad.h>

#include "gfx/window.hpp"

int main(void) {
    Window window("OpenGL CMake Template", 192*5, 108*5);

    glClearColor(1, 0, 0, 1);
    while(!window.should_close()) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        window.update_frame();
    }

    return 0;
}