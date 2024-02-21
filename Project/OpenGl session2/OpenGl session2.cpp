#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"
#include "Camera.h"
#include "Cube.h"
#include "LSM.h"
#include "PrintFunction.h"
#include "GenGraph.h"
#include "GenDots.h"


void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);


// Window Dimensions
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 800;



int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);



    // GLFW window initialization
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Load Glad stuff
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Build and compile shader program
    ShaderClass shaderProgram("VertexShader.vert", "FragmentShader.frag");


    // Cube Code
    //Cube cube(0.5f);
    //std::vector<GLfloat> vertices = cube.mCubeVertecies;



    // Creating LSM object
    std::vector<double> Points = { -0.5, 0.8, -0.2, 0.3, -0.9, 0.6, -0.4, 0.1, 0.7, -0.6, -1, -0.8, 0.2, 1, 1, 1 };
    //std::vector<double> Points = { 0.7, -0.6, -1, -0.8, 0.2, 1, 1, 1 };

    LSM regression(Points, Points.size()/2);
    regression.printCoefficients();
    std::cout << "Polynomial Equation: " << regression.polynomialString() << std::endl;
    PrintFunction printer(regression.polynomialString());
    
    
    printer.generateCoordinates(100, "coordinates.txt");
    GenGraph GraphGen;
    std::string filename = "coordinates.txt";
    GraphGen.readPointsFromFile(filename);


    GenDots DotGen;
    DotGen.GenDotCords(Points);


    std::vector<GLfloat> GraphVertices = GraphGen.mGraphVertices;
    std::vector<GLfloat> DotVertices = DotGen.mDotsVertices;


    VAO VAO1;
    VAO VAO2;
    VAO1.Bind();
    VAO2.Bind();

    VBO VBO1(GraphVertices.data(), GraphVertices.size() * sizeof(GLfloat));
    VBO VBO2(DotVertices.data(), DotVertices.size() * sizeof(GLfloat));

    // EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // For position
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); // For color

    VAO2.LinkAttrib(VBO2, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0); // For position
    VAO2.LinkAttrib(VBO2, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float))); // For color
   
    VAO1.Unbind();
    VBO1.Unbind();

    VAO2.Unbind();
    VBO2.Unbind();




    // Setting up camera
    Camera camera(SCR_WIDTH, SCR_HEIGHT, glm::vec3(0.0f, 0.0f, 2.0f));


    glEnable(GL_DEPTH_TEST);


    // Wireframe toggle vv                                                                                 keybind for this could be set up
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Render loop
    while (!glfwWindowShouldClose(window))
    {
        // Input
        processInput(window);


        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shaderProgram.Activate();

        // Camera stuff
        camera.inputs(window);
        camera.matrix(45.f, 0.1f, 100.0f, shaderProgram, "camMatrix");


        glUniform4f(0, 0.0f, 1, 0.0f, 1.0f);
        VAO1.Bind();
        glDrawArrays(GL_LINE_STRIP, 0, 100);
        VAO1.Unbind();

        VAO2.Bind();
        glPointSize(10);
        glDrawArrays(GL_POINTS, 0, sizeof(DotVertices));
        VAO2.Unbind();


        // Swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Delete stuff no longer needed.
    VAO1.Delete();
    VAO2.Delete();
    VBO1.Delete();
    VBO2.Delete();
    // EBO1.Unbind();
    // EBO1.Delete();
    shaderProgram.DeleteShader();

    // Terminate GLFW before closing the window
    glfwTerminate();
    return 0;
}

// Do input stuff
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// Executes on window size change
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // Resize viewport to window dimensions
    glViewport(0, 0, width, height);
    std::cout << " windows resized with " << width << " Height " << height << std::endl;
}



