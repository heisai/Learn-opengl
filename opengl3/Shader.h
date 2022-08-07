#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
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


/*
�Զ��� Shader ��
*/
class MyShader
{
public:
	// ��������ȡ��������ɫ��
	MyShader(const std::string& vertexPath, const std::string& fragmentPath);
	// ʹ��/�������
	void use();
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
	const char* ReadShaderCode(const std::string &filePath);
private:
	const char* vShaderCode;
	const char* gShaderCode;
	unsigned int vertecShader;
	unsigned int fragmentShader;
	unsigned int ShaderPromger;

};






