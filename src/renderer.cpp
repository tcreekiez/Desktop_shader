#include"renderer.h"
//采用vao绘制图元
void Renderer::Draw(const VAO& vao, const Shader& program) const
{
	vao.bind();
	glDrawElements(GL_TRIANGLES, vao.count, GL_UNSIGNED_SHORT, 0);
}
//采用vbo和ibo绘制图元
void Renderer::Draw(const VBO& vbo, const IBO& ibo, const Shader& program) const
{
	vbo.bind();
	ibo.bind();
	glDrawElements(GL_TRIANGLES, ibo.count, GL_UNSIGNED_SHORT, 0);
}
