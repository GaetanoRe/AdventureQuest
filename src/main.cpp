#include<cstdlib>
#include<iostream>
#include<GLFW/glfw3.h>
#include<memory>

int main(){
	glfwInit();
	std::unique_ptr<GLFWwindow, decltype(&glfwDestroyWindow)> window(glfwCreateWindow(800,600, "My Window", nullptr, nullptr),
		glfwDestroyWindow
		);
	
	if(!window){
		std::cerr << "Cannot Create Window" << std::endl;
		glfwTerminate();
		return -1;
	}
	
	glfwMakeContextCurrent(window.get());
	
	while (!glfwWindowShouldClose(window.get())){
		glfwSwapBuffers(window.get());
		glfwPollEvents();
	}
	
	glfwTerminate();
	return 0;
	
}