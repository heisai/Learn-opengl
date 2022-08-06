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
		// �������� ������
		//float vertices[] = {
		//-0.5f, -0.5f, 0.0f, // left  
		// 0.5f, -0.5f, 0.0f, // right 
		// 0.0f,  0.5f, 0.0f  // top   
		//};
		//����
		float vertices[] = {
		-0.5f, -0.5f, 0.0f, // left  
		-0.5f, 0.5f, 0.0f, // right 
		 0.5f,  0.5f, 0.0f, // top
		 0.5f,	-0.5f, 0.0f,
		 0.0f, 1.0f,0.0f
		};

		unsigned int indices[] = {
			// ע��������0��ʼ! 
			// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
			// �����������±��������ϳɾ���

			0, 1, 2, // ��һ��������
			2,3,0 , // �ڶ���������
			1,4,2 // �ڶ���������
		};

		// �����������
		glGenVertexArrays(1, &VAO);
		//���㻺�����
		glGenBuffers(1, &VBO);

		glGenBuffers(1, &EBO);
		//��VAO
		glBindVertexArray(VAO);
		//�Ѷ������鸴�Ƶ������й�OpenGLʹ��
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		

		
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);


		//���ö�������ָ��
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		//�󶨻������
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
