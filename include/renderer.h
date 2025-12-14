#pragma once
#include"VAO.h"
#include"shader.h"

class Renderer
{
	
public:
	Renderer(){}
	~Renderer(){}
	
	void Draw(const VAO& vao, const Shader& program) const;//用VAO和Shader绘制图元
	void Draw(const VBO& vbo, const IBO& ibo, const Shader& program) const;//用VBO，IBO和Shader绘制图元
};
