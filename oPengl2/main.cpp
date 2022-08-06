
#include"Widget.h"
int main()
{
	std::shared_ptr<Shader>shader = std::make_shared<Shader>();
	std::shared_ptr<BufferData>buffer = std::make_shared<BufferData>();
	Widget w(shader, buffer);
	w.CreateWidget(800, 600);
	w.SetPolygonMode(GL_LINE);
	w.Show();
}