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
	//�ж�GLFW �Ƿ��˳�
	while (!glfwWindowShouldClose(window))
	{
		//�����¼�
		processInput();
		//��Ⱦ
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

		//������ɫ����, ������һ�����б��������ƣ����ҽ�����Ϊ�����ʾ����Ļ��
		glfwSwapBuffers(window);
		//�����¼�����
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
//		�������汾
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//		���ô˰汾
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//		���������ļ�
//		 GLFW_OPENGL_CORE_PROFILE ����ģʽ
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
