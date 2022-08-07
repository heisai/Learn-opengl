#include"Widget.h"
Widget::Widget(std::shared_ptr<Shader>shader, std::shared_ptr<BufferData>buffer):
	m_Shader(shader),
	m_Buffer(buffer)
{
	InitWidget();
}

int Widget::CreateWidget(int width, int height)
{
	window = glfwCreateWindow(width, height, title_text.c_str(), NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	ManagePoint();

	if (m_Shader != nullptr && m_Buffer != nullptr)
	{
		m_Shader->InitShader();
		m_Buffer->BindBufferData();
	}

}

void Widget::SetColor()
{

}

void Widget::Show()
{
	//判断GLFW 是否退出
	while (!glfwWindowShouldClose(window))
	{
		//输入事件
		processInput();
		//渲染
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		DrawArrary();
		//交换颜色缓冲, 它在这一迭代中被用来绘制，并且将会作为输出显示在屏幕上
		glfwSwapBuffers(window);
		//监听事件输入
		glfwPollEvents();
	}
}

void Widget::SetWindowTitle(const std::string& title)
{
	title_text = title;
}

void Widget::SetPolygonMode(int Model)
{
	glPolygonMode(GL_FRONT_AND_BACK, Model);
}

void Widget::InitWidget()
{
		glfwInit();
//		设置主版本
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		设置此版本
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		设置配置文件
//		 GLFW_OPENGL_CORE_PROFILE 核心模式
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

int Widget::ManagePoint()
{
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}
}

void Widget::processInput()
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void Widget::DrawArrary()
{
	if (m_Shader != nullptr && m_Buffer != nullptr)
	{
		glUseProgram(m_Shader->GetPromger());
		glBindVertexArray(m_Buffer->GetVAO()); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		//glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
