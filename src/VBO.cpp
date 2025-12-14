#include"VBO.h"
#include<glad\glad.h>
#include <stdio.h>

VBO::VBO(float vertices[], unsigned int&& size) :id(0), stride(0)
{
	glGenBuffers(1, &id);
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STREAM_DRAW);
}

VBO::~VBO()
{
	glDeleteBuffers(1, &id);
}
//更新顶点数据
void VBO::update(float vertices[], unsigned int&& size)
{
	bind();
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STREAM_DRAW);
}


