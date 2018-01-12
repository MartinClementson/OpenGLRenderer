#include <iostream>

//#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include "Triangle.h"

// Window Dimensions
const GLint WIDTH = 800, HEIGHT = 600;
const GLchar *vertexShaderSource = "#version 330 core\n" //Core shader language for 3.3
"layout (location = 0) in vec3 position;\n"
"void main()\n"
"{\n"
"gl_Position = vec4( position.x,position.y,position.z,1.0);\n"

"}";

const GLchar *fragmentShaderSource = "#version 330 core\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(1.0f,0.5f,0.2f,1.0f);\n"
"}";


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


	int screenWitdh, screenHeight;
	glfwGetFramebufferSize(window, &screenWitdh, &screenHeight); // Get the proper size relative to the screen pixel density

	if (nullptr == window)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE; // tell Glew to use a modern approach to retrieve function pointers and extensions

	if (GLEW_OK != glewInit()) 
	{
		std::cout << "Failed to initalize GLEW" << std::endl;
		return false;
	}

	glViewport(0, 0, screenWitdh, screenHeight);

	return true;

}


bool CompileShaders(GLuint& shaderProgram)
{
	GLint success;
	GLchar infoLog[512];

#pragma region Compile vertex shader

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}

#pragma endregion

#pragma region Compile Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		return false;
	}
#pragma endregion

#pragma region Link Shaders
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram,vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success)
	{
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		return false;
	}

	// Shaders are now a part of the program, so they can be deleted
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


#pragma endregion
	return true;
}


//GLfloat CreateTriangle()
//{
//	GLfloat vertices[] =
//	{
//		-0.5f,-0.5f, 0.0f, // Bottom left
//		0.5f, -0.5f, 0.0f, // Bottom right
//		0.0f,  0.5,  0.0f  // Top
//	};
//
//	GLuint VBO, VAO;
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	glBindVertexArray(VAO);
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,GL_STATIC_DRAW);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//}
int main()
{

	GLFWwindow *window = nullptr;
	if (!SetupWindow(window))
		return 0;
	
	GLuint shaderProgram = 0;
	if (!CompileShaders(shaderProgram))
		return 0;

	Triangle* tri = new Triangle();
	while (!glfwWindowShouldClose(window)) //while window is open
	{
		glfwPollEvents();

		// Render
		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		// Draw OpenGL
		glUseProgram(shaderProgram);
		tri->Draw();

		glfwSwapBuffers(window);
	}

	delete tri;
	glfwTerminate();

	return EXIT_SUCCESS;
}




