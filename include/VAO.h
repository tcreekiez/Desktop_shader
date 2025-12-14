#pragma once
#include"VBO.h"
#include"IBO.h"
#include"glAPI.h"
//顶点数组对象
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
	//绑定vao
	inline void bind() const
	{
		glBindVertexArray(id);
	}
	//取消绑定vao
	inline void unbind() const
	{
		glBindVertexArray(0);
	}
};
