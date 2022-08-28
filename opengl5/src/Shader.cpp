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
	//顶点着色器对象
	vertecShader = glCreateShader(GL_VERTEX_SHADER);
	//将源码添加到对象上
	glShaderSource(vertecShader, 1, &vShaderCode, NULL);
	//编译着色器对象
	glCompileShader(vertecShader);

	//片段着色器对象
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//将源码添加到对象上
	glShaderSource(fragmentShader, 1, &gShaderCode, NULL);
	//编译着色器对象
	glCompileShader(fragmentShader);
}

void MyShader::BindShader()
{
	// 创建着色器程序
	ShaderPromger = glCreateProgram();
	// 将着色器对象添加到着色器程序上
	glAttachShader(ShaderPromger, vertecShader);
	glAttachShader(ShaderPromger, fragmentShader);
	//编译着色器程序
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
