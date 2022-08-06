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
		// 顶点数据 三角形
		//float vertices[] = {
		//-0.5f, -0.5f, 0.0f, // left  
		// 0.5f, -0.5f, 0.0f, // right 
		// 0.0f,  0.5f, 0.0f  // top   
		//};
		//矩形
		float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		-0.5f, 0.5f, 0.0f, // right 
		 0.5f,  0.5f, 0.0f, // top
		 0.5f,	-0.5f, 0.0f,
		 0.0f, 1.0f,0.0f
		};

		unsigned int indices[] = {
			// 注意索引从0开始! 
			// 此例的索引(0,1,2,3)就是顶点数组vertices的下标，
			// 这样可以由下标代表顶点组合成矩形

			0, 1, 2, // 第一个三角形
			2,3,0 , // 第二个三角形
			1,4,2 // 第二个三角形
		};

		// 顶点数组对象
		glGenVertexArrays(1, &VAO);
		//顶点缓冲对象
		glGenBuffers(1, &VBO);

		glGenBuffers(1, &EBO);
		//绑定VAO
		glBindVertexArray(VAO);
		//把顶点数组复制到缓冲中供OpenGL使用
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		

		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		//设置顶点属性指针
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		//绑定缓冲对象
		//glBindBuffer(GL_ARRAY_BUFFER, 1);
		//glBindVertexArray(1);
	}
	unsigned int  GetVAO()
	{
		return VAO;
	}
private:
	unsigned int VBO, VAO, EBO;
};
