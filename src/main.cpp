#include<stdio.h>
#include<thread>
#include<vector>
#include"system.h"
#include"mygl.h"
#include"renderline.h"
int WIN_W;
int WIN_H;
char quit = 0;
//i_position win_pos = { sc_x,sc_y };
using namespace std;
int EnumWorkWin1(HWND hwnd, LPARAM lParam)
{
	HWND hw=FindWindowExW(hwnd,NULL,L"SHELLDLL_DefView",NULL);

	if (hw!= NULL&&hw!=hwnd)
	{
		
		((HWND*)lParam)[0]=hwnd;
		//printf("aa");
		return false;
	}
	//printf("bb");
	return true;
}


int main(int argc, char* argv[])
{
	WIN_W=GetSystemMetrics(SM_CXSCREEN);
	WIN_H=GetSystemMetrics(SM_CYSCREEN);
	SDL_Window* window = glwin_init();
	HWND win = FindWindowW(NULL, L"background_w");
	HWND desk_win = FindWindowW(L"Progman",L"Program Manager");
	SendMessageTimeoutW(desk_win, 0x052c, 0, 0, SMTO_NORMAL, 1000, NULL);
	//SetWindowPos(win, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE);
	HWND work_win[2] = { 0,0 };
	
	EnumWindows(EnumWorkWin1, (LPARAM)&work_win);
	work_win[1] = FindWindowExW(0,work_win[0],L"WorkerW",NULL);
	if (work_win[1] == NULL)
	{
		printf("新版win11\n");
		work_win[1] = FindWindowExW(work_win[0], NULL, L"WorkerW", NULL);
	}//在室友电脑上测试了有bug，显示不全，不知道原因
	ShowWindow(work_win[1], SW_SHOW);
	SetParent(win, work_win[1]);
	SDL_Event event;

	std::thread render_thread(renderline, window);//渲染线程
	
	getchar();
		
	quit = 1;
	render_thread.join();
	SDL_DestroyWindow(window);
	SDL_Quit();
	ShowWindow(work_win[1], SW_HIDE);//恢复窗口
	
	return 0;
}
