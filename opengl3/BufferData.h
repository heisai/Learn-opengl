#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
class BufferData
{
public:
	void BindBufferData();
	
	unsigned int  GetVAO();
	
private:
	unsigned int VBO, VAO, EBO;
	
};