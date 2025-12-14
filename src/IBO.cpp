#include "IBO.h"

IBO::IBO(unsigned short int indices[], unsigned int&& size) :id(0), count(size / sizeof(unsigned short int))
{
	glGenBuffers(1, &id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STREAM_DRAW);
}

IBO::~IBO()
{
	glDeleteBuffers(1, &id);
}
//更新ibo数据
void IBO::update(unsigned short int indices[], unsigned int&& cou)
{
	count = cou;//注意VAO的count没有改变
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, cou * sizeof(unsigned short), indices, GL_STREAM_DRAW);
}
