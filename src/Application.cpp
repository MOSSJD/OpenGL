#include <GLFW/glfw3.h>
#include "Utils.h"

int main()
{
	GLFWwindow* window = nullptr;

	if (glfwInit() == GLFW_FALSE)
		return -1;
	window = glfwCreateWindow(me::windowW, me::windowH, "Hello World", NULL, NULL);
	if (window == nullptr)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		me::drawTriangle(std::array<me::Point, 3>{ me::Point{ 0, 0 },
												   me::Point{ 400, 0 },
												   me::Point{ 1000, 900 } });
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}