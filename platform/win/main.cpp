// System Headers
#include "gl.h"
#include <GLFW/glfw3.h>

// STL
#include <iostream>
#include <cstdlib>

#include "core/Perch.h"

int mWidth = 800;
int mHeight = 600;

int main(int argc, char * argv[]) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow* mWindow = glfwCreateWindow(mWidth, mHeight, "PerchRender", nullptr, nullptr);

    if (mWindow == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return EXIT_FAILURE;
    }

    glfwMakeContextCurrent(mWindow);

    // Load OpenGL Functions
    gladLoadGL();
    //std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

#ifdef WIN32
    perchInit("win");
#else
    perchInit("osx");
#endif

    // Viewport
    int width, height;
    glfwGetFramebufferSize(mWindow, &width, &height);
    glViewport(0, 0, width, height);
    perchResize(width, height);

    // Rendering Loop
    while (!glfwWindowShouldClose(mWindow)) {
        if (glfwGetKey(mWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(mWindow, true);

        // Background Fill Color
        //glClearColor(1.0f, 0.25f, 0.25f, 1.0f);
        //glClear(GL_COLOR_BUFFER_BIT);
        perchTick();

        // Flip Buffers and Draw
        glfwSwapBuffers(mWindow);
        glfwPollEvents();
    }   glfwTerminate();
    return EXIT_SUCCESS;
}

