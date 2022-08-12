#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <functional>

#include"Shader.h"
#include"BufferData.h"
void framebuffer_size_callback(GLFWwindow* window, int width, int height);

class Widget
{
public:
	Widget(std::shared_ptr<MyShader>shader = nullptr,std::shared_ptr<BufferData>buffer = nullptr);
	
	int  CreateWidget(int width, int height);
	void SetColor();
	void Show();
	void SetWindowTitle(const std::string& title);
	void SetPolygonMode(int);
private:
	void InitWidget();
	int  ManagePoint();
	void processInput();
	void DrawArrary();

private:
	std::string title_text;
	GLFWwindow* window;

	std::shared_ptr<MyShader>m_Shader;
	std::shared_ptr<BufferData>m_Buffer;

};