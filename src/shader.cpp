#include "shader.h"
#include<stdio.h>
#include<stdlib.h>

char* GetCodeFrom(const char* file_position)
{
	FILE* file = NULL;
	fopen_s(&file, file_position, "r+");
	if (file != NULL)
	{
		fseek(file, 0, SEEK_END);
		long size = ftell(file);
		fseek(file, 0, SEEK_SET);
		char* code = (char*)malloc(size + 1);
		*code = fgetc(file);
		int i = 0;
		for (; *(code + i) != EOF; i++)
		{
			*(code + i + 1) = fgetc(file);
		}
		*(code + i) = '\0';
		fclose(file);
		return code;
	}
	return nullptr;
}

Shader::Shader(const char* vs, const char* fs) :id(0)//, unif(NULL)
{
	char* Vscode = GetCodeFrom(vs);
	
	//printf("%s", vscode);//检查着色器代码用的

	char* Fscode = GetCodeFrom(fs);

	unsigned int vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &Vscode, NULL);
	glCompileShader(vshader);
	unsigned int fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &Fscode, NULL);
	glCompileShader(fshader);

	free(Vscode);
	free(Fscode);//这里不设置NULL也可以吧，毕竟后面不用了。

	{
		int success = 0;
		char inform[512]={0};
		glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vshader, 512, NULL, inform);
			printf("%s", inform);
		}
		else
			printf("vsshader compile success\n");

		glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(fshader, 512, NULL, inform);
			printf("%s", inform);
		}
		else
			printf("fsshader compile success\n");
	}//检测是否编译错误

	id = glCreateProgram();
	glAttachShader(id, vshader);
	glAttachShader(id, fshader);
	glLinkProgram(id);

	glDeleteShader(vshader);
	glDeleteShader(fshader);

	//unif = (int*)malloc(uniform * sizeof(int));
	//glGetUniformLocation()

	//use();
}

Shader::~Shader()
{
	glDeleteProgram(id);
}
