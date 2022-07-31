#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>

#include"Shader.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Widget
{
public:
	Widget(std::shared_ptr<Shader>shader = nullptr,std::shared_ptr<BufferData>buffer = nullptr);
	
	int  CreateWidget(int width, int height);
	void SetColor();
	void Show();
	void SetWindowTitle(const std::string& title);
private:
	void InitWidget();
	int  ManagePoint();
	void processInput();
	void DrawArrary();

private:
	std::string title_text;
	GLFWwindow* window;

	std::shared_ptr<Shader>m_Shader;
	std::shared_ptr<BufferData>m_Buffer;

};