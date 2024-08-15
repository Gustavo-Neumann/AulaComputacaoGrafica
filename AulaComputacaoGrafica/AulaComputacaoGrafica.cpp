#include <iostream>
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <stdio.h>

const GLint WIDTH = 800, HEITH = 600;

int main()
{
    if (!glfwInit()) {
        printf("NAO FUNCIONOU");
        return 1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEITH, "COMPUTACAO GRAFICA", NULL, NULL);

    if (!window)
    {
        printf("NAO ABRIU A JANELA");
        glfwTerminate();
        return 1;
    }

    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) 
    {
        printf("DEU RUIM NO GLEW");
        glfwDestroyWindow(window);
        glfwTerminate();
        return 1; 
    }

    glViewport(0, 0, bufferWidth, bufferHeight);
    while (!glfwWindowShouldClose(window))
    {
        //cria um evento
        glfwPollEvents();
        //define a cor do fundo
        glClearColor(0.0f, 100.0f,03.0f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

    }
    
}
