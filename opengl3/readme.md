## 来龙去脉

    着色器本身就是很好的小程序，但它们是整体的一部分，因此我们希望在单个着色器上具有输入和输出，以便我们可以移动东西。GLSL专门为此目的定义了inand关键字。out每个着色器都可以使用这些关键字指定输入和输出，以及输出变量与传递它们的下一个着色器阶段的输入变量匹配的任何位置。顶点和片段着色器虽然有点不同。

    顶点着色器应该接收某种形式的输入，否则它会非常无效。顶点着色器的输入不同，因为它直接从顶点数据接收输入。为了定义顶点数据的组织方式，我们使用位置元数据指定输入变量，以便我们可以在 CPU 上配置顶点​​属性。我们在上一章中已经将其视为layout (location = 0). 因此，顶点着色器需要对其输入进行额外的布局规范，以便我们可以将其与顶点数据链接起来。


    另一个例外是片段着色器需要vec4颜色输出变量，因为片段着色器需要生成最终输出颜色。如果您未能在片段着色器中指定输出颜色，则这些片段的颜色缓冲区输出将是未定义的（这通常意味着 OpenGL 会将它们渲染为黑色或白色）。

    因此，如果我们想将数据从一个着色器发送到另一个着色器，我们必须在发送着色器中声明一个输出，并在接收着色器中声明一个类似的输入。当双方的类型和名称相同时，OpenGL 会将这些变量链接在一起，然后可以在着色器之间发送数据（这在链接程序对象时完成）。为了向您展示这在实践中是如何工作的，我们将更改上一章中的着色器，让顶点着色器决定片段着色器的颜色。

### 改变图形颜色的三种方法：
__1： 直接修改着色器__
- 片段着色器源码

```cpp

    const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    // 1.0f, 0.5f, 0.2f 这就颜色的数值
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
```
- 修改 顶点着色器源码
  
  顶点的输出，作为片段的输入。
    
    // 顶点着色着色器
```cpp
    #version 330 core
    layout (location = 0) in vec3 aPos; // the position variable has attribute position 0
    
    out vec4 vertexColor; // specify a color output to the fragment shader

    void main()
    {
        gl_Position = vec4(aPos, 1.0); // see how we directly give a vec3 to vec4's constructor
        vertexColor = vec4(0.5, 0.0, 0.0, 1.0); // set the output variable to a dark-red color
    }
    // 片段着色器
    #version 330 core
    out vec4 FragColor;
    
    in vec4 vertexColor; // the input variable from the vertex shader (same name and same type)  

    void main()
    {
        FragColor = vertexColor;
    }
```

__2: 制服  （将颜色从我们的应用程序发送到片段着色器)__
    
        制服是另一种将数据从 CPU 上的应用程序传递到 GPU 上的着色器的方法。然而，与顶点属性相比，制服略有不同。首先，制服是全球的. 全局，这意味着每个着色器程序对象的统一变量是唯一的，并且可以在着色器程序的任何阶段从任何着色器访问。其次，无论您将制服值设置为什么，制服都会保留其值，直到它们被重置或更新。

        要在 GLSL 中声明统一，我们只需将uniform关键字添加到具有类型和名称的着色器中。从那时起，我们可以在着色器中使用新声明的制服。让我们看看这次我们是否可以通过制服设置三角形的颜色：
```cpp
float timeValue = glfwGetTime();
float greenValue = (sin(timeValue) / 2.0f) + 0.5f;
int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");
glUseProgram(shaderProgram);
glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f;
 ```      
__3: 修改顶点数据 （增加颜色属性)__
	

```cpp
float vertices[] = {
    // 位置              // 颜色
     0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
    -0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
     0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
};
```
由于顶点数据作为着色器的输入，数据的变动，着色器也会变动， 顶点着色器增加 颜色属性， 之前只有一个顶点属性。 代码如下:
```cpp
#version 330 core
layout (location = 0) in vec3 aPos;   // 位置变量的属性位置值为 0 
layout (location = 1) in vec3 aColor; // 颜色变量的属性位置值为 1

out vec3 ourColor; // 向片段着色器输出一个颜色

void main()
{
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor; // 将ourColor设置为我们从顶点数据那里得到的输入颜色
}
```
顶点着色器 变动后， 片段着色器也要变动，因为颜色的呈现 体现在片段着色器上。 
顶点着色器 颜色的输出 作为 片段着色器的输入。最后片段着色器在将颜色输出

代码如下：
```cpp
#version 330 core
out vec4 FragColor;  
in vec3 ourColor;

void main()
{
    FragColor = vec4(ourColor, 1.0);
}
```
顶点数据中增加了 一个属性颜色， 伴随着 着色器解析顶点数据的方式也会变化：

- 增加了一个属性
- 解析方式变化

代码如下：


```cpp
参数解释：
0 ： layout (location = 0) 

3 ： 每个属性是几个元素（坐标，颜色 都是由三个元素组成） 

6 * sizeof(float)：  顶点数据的步长（一个坐标（x,y,z）， 一个颜色(r,g,b)）

(void*)0): 属性的偏移量， 坐标是 从0 开始， 颜色是在颜色的后面 所以是3

// 位置属性
glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
glEnableVertexAttribArray(0);
// 颜色属性
glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3* sizeof(float)));
glEnableVertexAttribArray(1);
```
