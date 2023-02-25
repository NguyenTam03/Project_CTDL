//#pragma once
#include<winbgim.h>
#include<iostream>
#include<string>
#include"logo.h"
#define FOR(i,r,l)	for(int i=r;i<l;i++)
using namespace std;
string s[]={"MENU","LOP TIN CHI","SINH VIEN","MON HOC","DIEM","HDSD","THOAT"};
//--------------- COLORS --------------- // 
const int clblack = 0;
const int clblue = 1;
const int clgreen = 2;
const int claqua = 3;
const int clred = 4;
const int clpurple = 5;
const int clbrown = 6;
const int clwhite = 7;
const int clgray = 8;
const int cllightblue = 9;
const int cllightgreen = 10;
const int cllightaqua = 11;
const int cllightred = 12;
const int cllightpurple = 13;
const int clyellow = 14;
const int cllightwhite = 15;
//--------------- GRAPHICS --------------- // 
int height_word = 10;
int screen_width = 1460;
int screen_height = 750;
int width_option = 140;
int width_frame_main = 10;
int distance_frame_main = 15;
int width_subframe = 5;
int frame_left = 230;
int frame_top = 20;
int frame_right = 1245;
int frame_bottom = 700;
int width_hdsd = 400;
int height_hdsd = 400;
int x_hdsd = (frame_right + frame_left )/2 - width_hdsd/2;
int y_hdsd = (frame_bottom+frame_top+distance_frame_main*4)/2-height_hdsd/2;
//-------------------------------------------//
void straight_line(int left,int top,int right,int bottom, int color){
	setfillstyle(1,color);
	bar(left,top,right,bottom);
}
void screenlogo(){
	setcolor(cllightred);
	int length = textwidth(logo[0].c_str());
	// screen logo
	FOR(i,0,27){
		outtextxy((frame_left+frame_right)/2 - length/2,frame_top*8+i*15,logo[i].c_str()); // 15 la` chieu cao(y) cua chu
	}
}
void table_hdsd(){
	straight_line(x_hdsd,y_hdsd,x_hdsd+width_hdsd,y_hdsd+width_subframe,clred);
	
}
void creat_frame(){
	setusercharsize(1,2,1,2);   // response font-size text UI
	settextstyle(8,0,0);
  // main frame
    // thanh ngang
  straight_line(frame_left , frame_top , frame_right , frame_top + width_frame_main ,clblue);
  straight_line(frame_left , frame_bottom , frame_right , frame_bottom + width_frame_main ,clblue);
    // thanh doc
  straight_line(frame_left ,frame_top , frame_left + width_frame_main , frame_bottom ,clblue);
  straight_line(frame_right - width_frame_main , frame_top , frame_right , frame_bottom ,clblue);
  
  // subframe
    // thanh ngang
  straight_line(frame_left+distance_frame_main, frame_top+distance_frame_main,frame_right-distance_frame_main, frame_top+width_subframe+distance_frame_main,clred);
  straight_line(frame_left+distance_frame_main,frame_bottom-width_subframe*2,frame_right-distance_frame_main,frame_bottom-width_subframe,clred);
    // thanh doc chinh
  straight_line(frame_left+distance_frame_main, frame_top+distance_frame_main,frame_left+ frame_top,frame_bottom-width_subframe,clred);
  straight_line(frame_right-distance_frame_main-width_subframe, frame_top+distance_frame_main,frame_right-distance_frame_main,frame_bottom-width_subframe,clred);
    // thanh doc phu
    // do rong cua option la distance_frame_main*3
  straight_line(frame_left + distance_frame_main,frame_top+distance_frame_main*4,frame_right-distance_frame_main,frame_top+distance_frame_main*4+width_subframe,clred);
  setcolor(clblack);
  int length = 0;
  FOR(i,1,8){
    // thanh doc
    straight_line(frame_left+distance_frame_main+width_option*i,frame_top+distance_frame_main,frame_left+distance_frame_main+width_subframe+width_option*i,frame_top+distance_frame_main*4,4);
    setfillstyle(1,clyellow);
    setbkcolor(clyellow);
    length = textwidth(s[i-1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+distance_frame_main+width_subframe+width_option*(i-1),frame_top+distance_frame_main+width_subframe,frame_left+distance_frame_main+width_option*(i),frame_top+distance_frame_main*4);
    outtextxy(frame_left+distance_frame_main+width_subframe+width_option*(i-1)+width_option/2-width_subframe-length/2,frame_top*2+height_word,s[i-1].c_str());
  }
}
int main(int argc, char *argv[]){
	initwindow(screen_width, screen_height);
	setbkcolor(cllightwhite);
	cleardevice();
	screenlogo();
	table_hdsd();
	while(1){
		creat_frame();

		delay(100);
	}	
}
