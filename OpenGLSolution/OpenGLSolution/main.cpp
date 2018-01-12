#include <iostream>

#define GLEW_STATIC

#include <GL\glew.h>
#include <GLFW\glfw3.h>

const GLint WIDTH = 800, HEIGHT = 600;


bool SetupWindow(GLFWwindow*& window)
{
	glfwInit(); //Initialize

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Try to set it to openGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Else fall back to an older version
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE); //Set Reziable to False

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


int main()
{

	GLFWwindow *window = nullptr;
	if (!SetupWindow(window))
		return 0;
	
	while (!glfwWindowShouldClose(window)) //while window is open
	{
		glfwPollEvents();

		glClearColor(0.2f,0.3f,0.3f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
	}
	glfwTerminate();

	return EXIT_SUCCESS;
}




