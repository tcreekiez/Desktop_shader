#pragma once
#include"glAPI.h"
#include<vector>
#include<stdio.h>

class Shader
{
	unsigned int id;
	std::vector<unsigned int> uni_id;
	//int* unif;
public:
	Shader(const char* vs, const char* fs);
	~Shader();

	void addUniform(const char* name)
	{
		uni_id.push_back(glGetUniformLocation(id, name));
	}

	void SetUniform(const short& location, const float& v0)
	{
		glUniform1f(uni_id[location], v0);
	}
	void SetUniform(const short& location, const float& v0, const float& v1)
	{
		glUniform2f(uni_id[location], v0, v1);
	}
	void SetUniform(const short& location, const float& v0, const float& v1, const float& v2)
	{
		glUniform3f(uni_id[location], v0, v1, v2);
	}	
	void SetUniform(const short& location, const float& v0, const float& v1, const float& v2, const float& v3)
	{
		glUniform4f(uni_id[location], v0, v1, v2, v3);
	}
	void SetUniform(const short& location, const int& v0)
	{
		glUniform1i(uni_id[location], v0);
	}
	void SetUniform(const short& location, const int& v0, const int& v1)
	{
		glUniform2i(uni_id[location], v0, v1);
	}
	void SetUniform(const short& location, const int& v0, const int& v1, const int& v2)
	{
		glUniform3i(uni_id[location], v0, v1, v2);
	}
	void SetUniform(const short& location, const int& v0, const int& v1, const int& v2, const int& v3)
	{
		glUniform4i(uni_id[location], v0, v1, v2, v3);
	}
	void SetUniform1i(const short& location, const unsigned int& count, const int* value)
	{
		glUniform1iv(uni_id[location], count, value);
	}
	void SetUniform1v(const short& location,const unsigned int& count, const float* value)
	{
		glUniform1fv(uni_id[location], count, value);
	}
	void SetUniform2v(const short& location, const unsigned int& count, const float* value)
	{
		glUniform2fv(uni_id[location], count, value);
	}
	void SetUniform3v(const short& location, const unsigned int& count, const float* value)
	{
		glUniform3fv(uni_id[location], count, value);
	}
	void SetUniform4v(const short& location, const unsigned int& count, const float* value)
	{
		glUniform4fv(uni_id[location], count, value);
	}
	void SetUniform3m(const short& location, const float* value)
	{
		glUniformMatrix3fv(uni_id[location], 1, GL_TRUE, value);
	}

	void use() const
	{
		glUseProgram(id);
	}

};