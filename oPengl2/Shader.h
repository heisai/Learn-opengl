#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Shader
{
public:
	
	void InitShader();
	unsigned int GetPromger();
protected:
	void CreatShader();
	void BindShader();
private:
	unsigned int vertecShader;
	unsigned int fragmentShader;
	unsigned int ShaderPromger;


};



class BufferData
{
public:
	void BindBufferData()
	{
		// 顶点数据
		float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
		};

		// 顶点数组对象
		glGenVertexArrays(1, &VAO);
		//顶点缓冲对象
		glGenBuffers(1, &VBO);
		//绑定VAO
		glBindVertexArray(VAO);
		//把顶点数组复制到缓冲中供OpenGL使用
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		//设置顶点属性指针
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//绑定缓冲对象
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}
	unsigned int  GetVAO()
	{
		return VAO;
	}
private:
	unsigned int VBO, VAO;
};
