# Desktop_shader
## 简介 
#### 本项目将片段着色器置于桌面图标下方运行，借此实现了动态壁纸效果。
## 主要功能
利用win api将sdl窗口置于图标下方，并采用opengl绘图，在桌面上运行glsl片段着色器。
## 目录结构

* `build`目录下是本项目通过cmake生成的中间文件。

<br>


* `dependencies`目录下是本项目使用到的第三方库或代码。


<br>


* `include`目录下是本项目所有的头文件。



<br>


* `out`目录下是本项目的生成结果。

<br>


* `shaders`目录下是顶点着色器和片段着色器，若输入格式相同，片段着色器可随意替换。

<br>

* `src`目录下是本项目所有的源文件。

## 构建及运行方式
    cd build
    cmake ..
    cmake --build .
    cd ../out/Debug
    ./Desktop_shader

