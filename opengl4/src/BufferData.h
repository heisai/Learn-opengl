#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include<iostream>
#include<filesystem>
class BufferData
{
public:
	void BindBufferData();
	
	unsigned int  GetVAO();
	unsigned int Gettexture();

	void BindTexTure();

	
private:
	unsigned int VBO, VAO, EBO;
	unsigned int texture;
	
};