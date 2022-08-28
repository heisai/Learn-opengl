#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

/*
�Զ��� Shader ��
*/
class MyShader
{
public:
	// ��������ȡ��������ɫ��
	MyShader(const std::string& vertexPath, const std::string& fragmentPath);
	void InitShader();
	const char* test()
	{
		std::string name = "1111111";
		return name.c_str();
	}
	
	// ʹ��/�������
	void use();
    unsigned int ID(){return ShaderPromger;}
protected:
	// uniform���ߺ���
	template<typename T>
	void SetUniform1i(const std::string& name, const T& value)
	{
		if (std::is_same<int,T>::value)
		{
			glUniform1i(glGetUniformLocation(ShaderPromger, name.c_str()), (int)value);
		}
		else if (std::is_same<int, T>::value)
		{
			glUniform1i(glGetUniformLocation(ShaderPromger, name.c_str()), value);
		}
		else if (std::is_same<float, T>::value)
		{
			glUniform1f(glGetUniformLocation(ShaderPromger, name.c_str()), value);
		}
		
	}
	void CreatShader();
	void BindShader();
	std::string ReadShaderCode(const std::string &filePath);
private:
	const char* vShaderCode;
	const char* gShaderCode;
	unsigned int vertecShader;
	unsigned int fragmentShader;
	unsigned int ShaderPromger;
	std::string strVShaderCode;
	std::string strGShaderCode;

};






