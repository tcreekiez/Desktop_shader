#pragma once
//#include<stdlib.h>
//#include<stdio.h>
#include<vector>
#include"glAPI.h"
//储存顶点数据布局
struct layout
{
	unsigned int count;
	unsigned int type;
	bool normalized;
};
//顶点缓冲对象
class VBO {
	unsigned int id;
	unsigned int stride;//步长
	std::vector<layout> elements;//描述了顶点数据的结构布局，每一个element代表一种顶点数据（如顶点位置，颜色等）

	friend class VAO;
public:
	
	VBO(float vertices[], unsigned int&& size);
	~VBO();

	void update(float vertices[], unsigned int&& size);//更新顶点数据
	//添加新的顶点布局单元
	template<typename T>
	void add(unsigned int count)
	{
		printf("错误：%s line:%d",__FILE__,__LINE__);//static_assert(false);//为什么静态断言会失败啊？我没有实例化这个啊？！换成printf也没有输出
	}
	template<>
	void add<float>(unsigned int count)
	{
		elements.push_back({ count,GL_FLOAT,GL_FALSE });
		stride += sizeof(float) * count;
	}
	//绑定vbo
	inline void bind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, id);
	}
	//取消绑定vbo
	inline void unbind() const
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

};




