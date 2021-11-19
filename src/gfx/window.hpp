#pragma once

#include <iostream>
#include <string>
#include <exception>

#include <glad/glad.h>
#include <glfw/glfw3.h>

class WindowException : public std::exception {
public:
    WindowException(std::string reason);
    virtual const char* what() const throw();

private:
    std::string reason;
};

class Window {
public:
    Window(std::string title, unsigned int width, unsigned int height);
    ~Window();

    void set_current();
    bool should_close();
    void update_frame();

private:
    GLFWwindow* window;
};