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
		// ��������
		float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		 0.5f, -0.5f, 0.0f, // right 
		 0.0f,  0.5f, 0.0f  // top   
		};

		// �����������
		glGenVertexArrays(1, &VAO);
		//���㻺�����
		glGenBuffers(1, &VBO);
		//��VAO
		glBindVertexArray(VAO);
		//�Ѷ������鸴�Ƶ������й�OpenGLʹ��
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		//���ö�������ָ��
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);

		//�󶨻������
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
