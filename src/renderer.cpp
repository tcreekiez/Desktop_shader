#include"renderer.h"

void Renderer::Draw(const VAO& vao, const Shader& program) const
{
	vao.bind();
	glDrawElements(GL_TRIANGLES, vao.count, GL_UNSIGNED_SHORT, 0);
}

void Renderer::Draw(const VBO& vbo, const IBO& ibo, const Shader& program) const
{
	vbo.bind();
	ibo.bind();
	glDrawElements(GL_TRIANGLES, ibo.count, GL_UNSIGNED_SHORT, 0);
}
