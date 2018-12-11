#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

int main()
{
    
    // 初始化GLFW,设置主次版本号为3,即opengl3.3,设置模式为核心模式
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // 创建window对象
    GLFWwindow* window = glfwCreateWindow(800, 600, "Hello Window", NULL, NULL);
    if(window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    /* OpenGL渲染窗口的尺寸大小，即视口(Viewport)
    * glViewport函数前两个参数控制窗口左下角的位置。
    * 第三个和第四个参数控制渲染窗口的宽度和高度（像素）
    * 我们实际上也可以将视口的维度设置为比GLFW的维度小，
    * 这样子之后所有的OpenGL渲染将会在一个更小的窗口中显示，
    * 这样子的话我们也可以将一些其它元素显示在OpenGL视口之外。
    */
    //glViewport(0, 0, 80, 60);
    
    
    // 注册回调函数，视口大小随着窗口变化
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    /*
     * int gladLoadGLLoader(GLADloadproc load)：任何的OpenGL接口调用都必须在初始化GLAD库后才可以正常访问。如果成功的话，该接口将返回GL_TRUE，否则就会返回GL_FALSE。
     * 其中GLADloadproc函数声明如下：
     * void* (*GLADloadproc)(const char* name)
    */
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    while(!glfwWindowShouldClose(window)) {
        // input
        processInput(window);
        
        // render
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        // glfwSwapBuffers函数会交换颜色缓冲（它是一个储存着GLFW窗口每一个像素颜色值的大缓冲），
        // 它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上。
        glfwSwapBuffers(window);
        // glfwPollEvents函数检查有没有触发什么事件（比如键盘输入、鼠标移动等）、更新窗口状态，
        // 并调用对应的回调函数（可以通过回调方法手动设置）。
        glfwPollEvents();
    }
    
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    //std::cout << width << " " << height << std::endl;
}

void processInput(GLFWwindow *window) 
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}