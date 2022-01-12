#include <iostream>
#include "Adder/adder.h"
#include <GLFW/glfw3.h>

/* float add(float a, float b); */

int main() {
    std::cout << "hello world!\n";

    std::cout << add(78.8111, 17.2) << "\n";

    GLFWwindow* window;
    int width, height;

    if( !glfwInit() )
    {
        fprintf( stderr, "Failed to initialize GLFW\n" );
        exit( EXIT_FAILURE );
    }

    /* glfwWindowHint(GLFW_DEPTH_BITS, 16); */
    /* glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, GLFW_TRUE); */

    window = glfwCreateWindow( 300, 300, "Gears", NULL, NULL );
    if (!window)
    {
        fprintf( stderr, "Failed to open GLFW window\n" );
        glfwTerminate();
        exit( EXIT_FAILURE );
    }

    /* // Set callback functions */
    /* glfwSetFramebufferSizeCallback(window, reshape); */
    /* glfwSetKeyCallback(window, key); */

    /* glfwMakeContextCurrent(window); */
    /* gladLoadGL(glfwGetProcAddress); */
    /* glfwSwapInterval( 1 ); */

    /* glfwGetFramebufferSize(window, &width, &height); */
    /* reshape(window, width, height); */

    // Parse command-line options
    /* init(); */

    // Main loop
    while( !glfwWindowShouldClose(window) )
    {
        // Draw gears
        /* draw(); */

        // Update animation
        /* animate(); */

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();

    return 0;
}
