#include<iostream>
#include"Widget.h"
int main()
{

	std::cout << "aaaaaaaa" <<std::endl;


	std::shared_ptr<Shader>shader = std::make_shared<Shader>();
	std::shared_ptr<BufferData>buffer = std::make_shared<BufferData>();
	Widget w(shader, buffer);
	w.SetWindowTitle("OPENGL444");
	w.CreateWidget(800, 600);

	w.Show();
}