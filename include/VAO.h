#pragma once
#include"VBO.h"
#include"IBO.h"
#include"glAPI.h"

class VAO {
	unsigned int id;
	unsigned int count;
public:
	VAO();
	~VAO();

	friend class Renderer;
	void AttachVBO(const VBO& vbo) const;
	inline void AttachIBO(const IBO& ibo)
	{
		bind();
		ibo.bind();
		count = ibo.count;
	}

	inline void bind() const
	{
		glBindVertexArray(id);
	}
	inline void unbind() const
	{
		glBindVertexArray(0);
	}
};
