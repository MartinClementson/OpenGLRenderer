#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "ShaderHandler.h"
//#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Triangle.h"
#include "Texture.h"
#include "Camera.h"
#include "SOIL2\SOIL2.h"


// Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

//void KeyCallback(GLFWwindow *window, int key, int scanCode, int action, int mode);
//void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
//void MouseCallback(GLFWwindow* window, double xPos, double yPos);
//void DoMovement();
//
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//GLfloat lastX = WIDTH  / 2.0f;
//GLfloat lastY = HEIGHT / 2.0f;
bool SetupWindow(GLFWwindow*& window)
{
	glfwInit(); //Initialize

	// Set GLFW options
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Try to set it to openGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Else fall back to an older version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); //Set Reziable to False


	// Create the window object
	window = glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL",nullptr,nullptr);


	
	glfwGetFramebufferSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT); // Get the proper size relative to the screen pixel density

	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	//glfwSetKeyCallback(window, KeyCallback);
	//glfwSetCursorPosCallback(window, MouseCallback);
	//glfwSetScrollCallback(window, ScrollCallback);
	//glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	glewExperimental = GL_TRUE; // tell Glew to use a modern approach to retrieve function pointers and extensions

	if (GLEW_OK != glewInit()) 
	{
		std::cout << "Failed to initalize GLEW" << std::endl;
		return false;
	}

	glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

	return true;

}

int main()
{

	// Set up Window
	GLFWwindow *window = nullptr;
	if (!SetupWindow(window))
		return 0;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// Set up shaders
	ShaderHandler shaderHandler;
	if (!shaderHandler.Init())
	{
		//Add Messagebox here
		glfwTerminate();
		return 0;
	}

	GEO::Triangle* tri = new GEO::Triangle();
	
	Texture tex("images/tex.png");
	shaderHandler.UseShader(Shaders::COLOR);
	tex.SetActive(glGetUniformLocation(shaderHandler.GetActiveShader()->Program,"Diffuse"));

	
	
	while (!glfwWindowShouldClose(window)) //while window is open
	{
		glfwPollEvents();

		// Render
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
		
		////TEMP
		glm::mat4 projection;
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 1000.0f);
		
		glm::mat4 model = glm::mat4();
		glm::mat4 view = glm::mat4();
		
		model = glm::rotate(model, (GLfloat)glfwGetTime()* 0.2f, glm::vec3(0.5f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

		GLint modelLoc = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "model");
		GLint viewLoc  = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "view");
		GLint projLoc  = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "proj");


		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		////END TEMP
		
		
		
		// Draw OpenGL
		GLuint loc = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "transform");
		//tri->GetTransform()->Rotate(glm::vec3(0.0f, 0.0f, 1.0f), (GLfloat)glfwGetTime() * -0.0005f);
		tri->Draw();

		glfwSwapBuffers(window);
	}

	delete tri;
	glfwTerminate();

	return EXIT_SUCCESS;
}




