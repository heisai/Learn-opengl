#include"Shader.h"

// 顶点着色器源码
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 1) in vec3 aPos;\n"
"layout(location = 2) in vec3 aColor;\n" // 颜色变量的属性位置值为 1
"out vec3 ourColor;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"	ourColor = aColor;\n"
"}\0";
// 片段着色器源码
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(ourColor, 1.0f);\n"
"}\n\0";
void Shader::CreatShader()
{
	//顶点着色器对象
	vertecShader = glCreateShader(GL_VERTEX_SHADER);
	//将源码添加到对象上
	glShaderSource(vertecShader, 1, &vertexShaderSource, NULL);
	//编译着色器对象
	glCompileShader(vertecShader);

	//片段着色器对象
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//将源码添加到对象上
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	//编译着色器对象
	glCompileShader(fragmentShader);

	
}
void Shader::BindShader()
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

void Shader::InitShader()
{
	 this->CreatShader();
	 this->BindShader();
}

unsigned  int Shader::GetPromger()
{
	return ShaderPromger;
}

MyShader::MyShader(const std::string& vertexPath, const std::string& fragmentPath)
{
	vShaderCode = ReadShaderCode(vertexPath);
	gShaderCode = ReadShaderCode(fragmentPath);
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
	glShaderSource(vertecShader, 1, &vertexShaderSource, NULL);
	//编译着色器对象
	glCompileShader(vertecShader);

	//片段着色器对象
	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	//将源码添加到对象上
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
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

const char* MyShader::ReadShaderCode(const std::string &filePath)
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
	return texCode.c_str();
}
