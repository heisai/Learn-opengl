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




