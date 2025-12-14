
#include<glad\glad.h>
#include "VAO.h"


VAO::VAO() //: id(0)
{
	
	glGenVertexArrays(1, &id);
	bind();
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &id);
}

void VAO::AttachVBO(const VBO& vbo) const
{
	bind();
	vbo.bind();
	const std::vector<layout>& lay = vbo.elements;
	unsigned int offset = 0;
	
	for (int i = 0; i < lay.size(); ++i)
	{
		const layout& lo = lay[i];
		unsigned int size = 0;
		switch (lo.type)
		{
		case GL_FLOAT:
			size = sizeof(float);
			break;
		default:
			_ASSERT(false);
		}
		glVertexAttribPointer(i, lo.count, lo.type, lo.normalized, vbo.stride, (void*)offset);//顶点属性位置值layout(location = 0),顶点属性大小（这里只有xy所以是二），数据类型，是否标准化（归到-1到1或0到1之间），步长（每组数据的间隔），偏置（记得类型强制转换）
		glEnableVertexAttribArray(i);//顶点属性位置值layout(location = 0)
		offset += size * lo.count;
	}
}


