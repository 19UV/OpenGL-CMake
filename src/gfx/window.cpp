#include "window.hpp"

static std::size_t window_count = 0;

WindowException::WindowException(std::string reason) : reason(reason) {}

const char* WindowException::what() const throw() {
    return this->reason.c_str();
}

Window::Window(std::string title, unsigned int width, unsigned int height) {
    if((window_count++) == 0) {
        if(!glfwInit()) {
            throw WindowException("Failed to Initialize GLFW");
        }
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

    this->window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
    if(!this->window) {
        throw WindowException("Failed to Initialize Window");
    }
    glfwMakeContextCurrent(this->window);

    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw WindowException("Failed to Initialize OpenGL");
    }

    glfwSwapInterval(1);
    glEnable(GL_DEPTH_TEST);

    std::cout << "--------------- GLFW/OPENGL INFORMATION ---------------"  << std::endl;
	std::cout << "GLFW Version:            " << glfwGetVersionString()      << std::endl;
	std::cout << "OpenGL Version:          " << glGetString(GL_VERSION)     << std::endl;
	std::cout << "  OpenGL Vendor:         " << glGetString(GL_VENDOR)      << std::endl;
	std::cout << "  OpenGL Renderer:       " << glGetString(GL_RENDERER)    << std::endl;
	std::cout << "  GLSL Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
}

Window::~Window() {
    glfwDestroyWindow(this->window);

    if((--window_count) == 0) {
        glfwTerminate();
    }
}

void Window::set_current() {
    glfwMakeContextCurrent(this->window);
}

bool Window::should_close() {
    return glfwWindowShouldClose(this->window);
}

void Window::update_frame() {
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}