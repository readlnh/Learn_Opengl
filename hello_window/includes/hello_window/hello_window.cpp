#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);


int main() 
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "hello window", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLF window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    while(!glfwWindowShouldClose(window)) {
        processInput(window);
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    }
    
    
    
    glfwTerminate();
    return 0;
}


void processInput(GLFWwindow *window) 
{
    if(glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS) 
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    printf("%d %d\n", width, height);
    glViewport(0, 0, width, height);
}
