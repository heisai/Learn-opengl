#include"BufferData.h"

void BufferData::BindBufferData()
{
	

		float vertices[] = {
		-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // left  
		-0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // right 
		 0.5f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // top
		 0.5f,	-0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
		 0.0f, 1.0f,0.0f,  0.0f, 0.0f, 1.0f
		};

		unsigned int indices[] = {
			// ע��������0��ʼ! 
			// ����������(0,1,2,3)���Ƕ�������vertices���±꣬
			// �����������±��������ϳɾ���

			0, 1, 2, // ��һ��������
			2,3,0 , // �ڶ���������
			1,4,2 // ��san��������
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


		if (sizeof(indices))
		{
			glGenBuffers(1, &EBO);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
		}
		//���ö�������ָ��
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		//������ɫ����ָ��
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
	
}

unsigned int BufferData::GetVAO()
{
		return VAO;

}
