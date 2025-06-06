#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1920, 1080, "ZCraft", nullptr, nullptr);

    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.1f, 0.4f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwPollEvents();

        glfwSwapBuffers(window);
    }

    glDrawArrays(GL_TRIANGLES, 0, 12 * 3);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
