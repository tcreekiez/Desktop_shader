#include "renderline.h"
#include<stdio.h>
#include<math.h>
//#include<mutex>
//#include"mygl.h"
#include<random>

//渲染线程函数
void renderline(SDL_Window* window)//, const renderdata& data, const position& camera)
{
    //srand(time(NULL));
    SDL_GLContext gl_context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, gl_context);
    SDL_GL_SetSwapInterval(1); //垂直同步，貌似会阻塞。

    //渲染相关
    gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress);

    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);//启用混合
    glEnable(GL_DEPTH_TEST);
    //glEnable(GL_CULL_FACE);
    //glPolygonMode(GL_FRONT, GL_LINE);//
    //glLineWidth(3);

    float ver[]=
    {
        1,1,
        1,-1,
        -1,-1,
        -1,1
    };//一个简单的矩形，不像旧工程那样用一整个大三角形是为了测试新的类
    unsigned short order[] =
    {
        2,1,0,
        0,3,2
    };
    Shader shader("vs.vert", "fs.frag");
    shader.use();
  
    Renderer ren;
    VBO vbo(ver, sizeof(ver));
    vbo.add<float>(2);
    EBO ibo(order, sizeof(order));
    VAO vao;
    vao.AttachVBO(vbo);
    vao.AttachIBO(ibo);

    shader.addUniform("r");//0
    shader.addUniform("it");//1
   
    shader.SetUniform(0, (float)WIN_W,(float)WIN_H);

    glClearColor(1.0f, 0.2f, 0.2f, 1.0f);
    
    float t = 0;
    
	printf("输入enter退出程序\n");
    while (!quit)
    {
        shader.SetUniform(1, t);
        t += 0.01;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ren.Draw(vao,shader);
        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DeleteContext(gl_context);
}