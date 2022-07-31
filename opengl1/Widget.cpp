#include"Widget.h"
Widget::Widget()
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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}
