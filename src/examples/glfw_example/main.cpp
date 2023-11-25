#include <GLFW/glfw3.h>

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
    // Initialize GLFW
    if (!glfwInit())
        return -1;

    // Set GLFW to not create an OpenGL context
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "GLFW Example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Set the key callback function
    glfwSetKeyCallback(window, key_callback);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Poll for and process events
        glfwPollEvents();
    }

    // Destroy the window
    glfwDestroyWindow(window);

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
