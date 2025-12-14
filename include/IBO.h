#pragma once

#include"glAPI.h"

typedef class IBO
{
	unsigned int id;
	unsigned int count;
public:
	friend class VAO;
	friend class Renderer;

	IBO(unsigned short int indices[],unsigned int&& size);
	~IBO();
	void update(unsigned short int indices[], unsigned int&& count);
	void bind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
	}
	void unbind() const
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}EBO;