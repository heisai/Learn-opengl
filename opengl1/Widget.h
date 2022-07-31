#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Widget
{

public:
	Widget();
	
	int  CreateWidget(int width, int height);
	void SetColor();
	void Show();
	void SetWindowTitle(const std::string& title);
private:
	void InitWidget();
	int  ManagePoint();
	void processInput();

private:
	std::string title_text;
	GLFWwindow* window;
};