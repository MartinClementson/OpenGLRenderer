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
#include "Cube.h"


// Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

void KeyCallback(GLFWwindow *window, int key, int scanCode, int action, int mode);
void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset);
void MouseCallback(GLFWwindow* window, double xPos, double yPos);
void DoMovement();

Camera camera(glm::vec3(-10.0f, 0.0f, 5.0f),glm::vec3(0.0f, 1.0f, 0.0f), -20.0f , 0.0f);
GLfloat lastX = WIDTH  / 2.0f;
GLfloat lastY = HEIGHT / 2.0f;
GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;
bool keys[1024];
bool firstMouse = true;
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

	glfwSetKeyCallback(window, KeyCallback);
	glfwSetCursorPosCallback(window, MouseCallback);
	glfwSetScrollCallback(window, ScrollCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

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

	//TEMP
	std::vector<glm::vec3> meshPositions =
	{
		glm::vec3(0.0f,0.0f,0.0f),
		glm::vec3(2.0f,5.0f,-15.0f),
		glm::vec3(-1.5f,-2.2f,-2.5f),
		glm::vec3(-3.8f,-2.0f,-12.3f),
		glm::vec3(2.4f,-0.4f,-3.5f),
		glm::vec3(-1.7f,3.0f,-7.5f),
		glm::vec3(1.3f,-2.0f,-2.5f),
		glm::vec3(1.5f,2.0f,-2.5f),
		glm::vec3(1.5f,0.2f,-1.5f),
		glm::vec3(-1.3f,1.0f,-1.5f)
	};

	std::vector<GEO::Mesh*> meshes(meshPositions.size());

	for (size_t i = 0; i < meshPositions.size(); i++)
	{
		meshes.at(i) = new GEO::Triangle();
		meshes.at(i)->GetTransform()->SetPos(meshPositions.at(i));
		
	}
	//GEO::Cube* cube	   = new GEO::Cube();
	Texture tex("images/tex.png");
	shaderHandler.UseShader(Shaders::COLOR);
	tex.SetActive(glGetUniformLocation(shaderHandler.GetActiveShader()->Program,"Diffuse"));

	
	
	while (!glfwWindowShouldClose(window)) //while window is open
	{
		GLfloat currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		glfwPollEvents();
		DoMovement();


		// Render
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		
		
		
		////TEMP
		glm::mat4 projection;
		projection = glm::perspective(camera.GetZoom(), (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f, 1000.0f);
		
		glm::mat4 model = glm::mat4();
		glm::mat4 view = glm::mat4();
		
		model = glm::rotate(model, (GLfloat)glfwGetTime()* 0.2f, glm::vec3(0.5f, 1.0f, 0.0f));
		view = camera.GetViewMatrix();

		GLint modelLoc = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "model");
		GLint viewLoc  = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "view");
		GLint projLoc  = glGetUniformLocation(shaderHandler.GetActiveShader()->Program, "proj");


		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));

		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		////END TEMP
		
		// Draw OpenGL
		
		for (size_t i = 0; i < meshes.size(); i++)
		{
			glm::mat4 model;
			model = glm::translate(model, meshes.at(i)->GetTransform()->GetPos());
			GLfloat angle = 20.0f * i;
			model = glm::rotate(model, angle, glm::vec3(1.0f, 0.3f, 0.5f));

			glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

			meshes.at(i)->Draw();
		}

		glfwSwapBuffers(window);
	}

	//delete tri;
	//delete cube;
	for (size_t i = 0; i < meshes.size(); i++)
	{
		delete meshes.at(i);
	}

	glfwTerminate();

	return EXIT_SUCCESS;
}


void DoMovement()
{
	if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
	{
		camera.ProcessKeyboard(Camera::Cam_Movement::FORWARD, deltaTime);
	}
	if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
	{
		camera.ProcessKeyboard(Camera::Cam_Movement::BACKWARD, deltaTime);
	}
	if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
	{
		camera.ProcessKeyboard(Camera::Cam_Movement::LEFT, deltaTime);
	}
	if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
	{
		camera.ProcessKeyboard(Camera::Cam_Movement::RIGHT, deltaTime);
	}
}

void KeyCallback(GLFWwindow *window,int key, int scancode,int action,int mode)
{
	if (key == GLFW_KEY_ESCAPE  && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	if (key >= 0 && key < 1024)
	{
		if (action == GLFW_PRESS)
		{
			keys[key] = true;
		}
		else if (GLFW_RELEASE == action)
		{
			keys[key] = false;
		}
	}
}

void MouseCallback(GLFWwindow* window, double xPos, double yPos)
{
	if (firstMouse)
	{
		lastX = xPos;
		lastY = yPos;
		firstMouse = false;
	}
	GLfloat xOffset = xPos - lastX;
	GLfloat yOffset = lastY - yPos;

	lastX = xPos;
	lastY = yPos;

	camera.ProcessMouseMovement(xOffset, yOffset, true);
}
void ScrollCallback(GLFWwindow* window, double xOffset, double yOffset)
{
	camera.ProcessMouseScroll(yOffset);
}




