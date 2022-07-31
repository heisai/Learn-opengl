#include"Shader.h"

// ������ɫ��Դ��
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
// Ƭ����ɫ��Դ��
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\n\0";
void Shader::CreatShader()
{
	//������ɫ������
	vertecShader = glCreateShader(GL_VERTEX_SHADER);
	//��Դ����ӵ�������
	glShaderSource(vertecShader, 1, &vertexShaderSource, NULL);
	//������ɫ������
	glCompileShader(vertecShader);

	//Ƭ����ɫ������
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//��Դ����ӵ�������
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//������ɫ������
	glCompileShader(fragmentShader);

	
}
void Shader::BindShader()
{
	// ������ɫ������
	ShaderPromger = glCreateProgram();
	// ����ɫ��������ӵ���ɫ��������
	glAttachShader(ShaderPromger, vertecShader);
	glAttachShader(ShaderPromger, fragmentShader);
	//������ɫ������
	glLinkProgram(ShaderPromger);

	glDeleteShader(vertecShader);
	glDeleteShader(fragmentShader);
}

void Shader::InitShader()
{
	 this->CreatShader();
	 this->BindShader();
}

unsigned  int Shader::GetPromger()
{
	return ShaderPromger;
}