#include"Shader.h"

MyShader::MyShader(const std::string& vertexPath, const std::string& fragmentPath)
{
	strVShaderCode = ReadShaderCode(vertexPath);
	strGShaderCode = ReadShaderCode(fragmentPath);
	vShaderCode = strVShaderCode.c_str();
	gShaderCode = strGShaderCode.c_str();

}

void MyShader::InitShader()
{
	this->CreatShader();
	this->BindShader();
}

void MyShader::use()
{
	glUseProgram(ShaderPromger);
}

void MyShader::CreatShader()
{
	//������ɫ������
	vertecShader = glCreateShader(GL_VERTEX_SHADER);
	//��Դ����ӵ�������
	glShaderSource(vertecShader, 1, &vShaderCode, NULL);
	//������ɫ������
	glCompileShader(vertecShader);

	//Ƭ����ɫ������
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//��Դ����ӵ�������
	glShaderSource(fragmentShader, 1, &gShaderCode, NULL);
	//������ɫ������
	glCompileShader(fragmentShader);
}

void MyShader::BindShader()
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

std::string MyShader::ReadShaderCode(const std::string &filePath)
{
	std::string texCode;
	std::ifstream ShaderFile;
	ShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try
	{
		// open files
		ShaderFile.open(filePath);
		std::stringstream ShaderStream;
		// read file's buffer contents into streams
		ShaderStream << ShaderFile.rdbuf();
		// close file handlers
		ShaderFile.close();

		// convert stream into string
		texCode = ShaderStream.str();
	}
	catch (std::ifstream::failure& e)
	{
		std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ: " << e.what() << std::endl;
	}
	std::cout << "1111111111111111111111111111111111111111111111111" << std::endl;
	std::cout << texCode << std::endl;
	std::cout << "1111111111111111111111111111111111111111111111111" << std::endl;

	return texCode;
}
