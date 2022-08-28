
#include<iostream>
#include"src/Widget.h"
#include<filesystem>
int main()
{

    std::shared_ptr<MyShader>shader = std::make_shared<MyShader>("../src/GLSL/texture.vs",
        "../src/GLSL/texture.fs");
    std::shared_ptr<BufferData>buffer = std::make_shared<BufferData>();
    Widget w(shader, buffer);
    w.SetWindowTitle("Opengl");
    w.CreateWidget(800, 600);
    w.Show();
}
