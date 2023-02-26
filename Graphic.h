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
int temp = 0;
int h_word = 10;
int screen_width = 1460;
int screen_height = 750;
int w_option = 140;
int w_frame_main = 10;
int dis_frame_main = 15;
int w_subframe = 5;
int frame_left = 230;
int frame_top = 20;
int frame_right = 1245;
int frame_bottom = 700;
int w_hdsd = 400;
int h_hdsd = 400;
int x_hdsd = (frame_right + frame_left )/2 - w_hdsd/2;
int y_hdsd = (frame_bottom+frame_top+dis_frame_main*4)/2-h_hdsd/2;
int w_btn_x = 30;
int x_btn_x_hdsd = x_hdsd + w_hdsd - w_btn_x - w_subframe;
int y_btn_x_hdsd = y_hdsd + 4 ;
bool hdsd = false;
bool thoat = false;
//-------------------------------------------//
void straight_line(int left,int top,int right,int bottom, int color){
	setfillstyle(1,color);
	bar(left,top,right,bottom);
}
void button_x(int x, int y){
	setcolor(0);
	rectangle(x,y+w_subframe,x+w_btn_x,y+w_btn_x+w_subframe);
	setbkcolor(cllightred);
	setfillstyle(1,cllightred);
	bar(x+1,y+w_subframe+1,x+w_btn_x,y+w_btn_x+w_subframe);
	string s = "X";
	setusercharsize(1,2,1,2);   // response font-size text UI
	settextstyle(8,0,0);
	int length = textwidth(s.c_str());
	outtextxy(x+w_btn_x/2-length/2,y+w_subframe+w_btn_x/2-h_word+1,s.c_str());
}
void screen_logo(){
//	setusercharsize(1,1,1,1); 
//	settextstyle(0,0,0);
	setbkcolor(cllightwhite);
	setcolor(cllightred);
	int length = textwidth(logo[0].c_str());
	// screen logo
	FOR(i,0,27){
		outtextxy((frame_left+frame_right)/2 - length/2,frame_top*8+i*15,logo[i].c_str()); // 15 la` chieu cao(y) cua chu
	}
}
void table_hdsd(){
	straight_line(x_hdsd , y_hdsd,x_hdsd+w_hdsd+w_subframe , y_hdsd+h_hdsd+w_subframe,cllightwhite);
	// thanh ngang
	straight_line(x_hdsd , y_hdsd , x_hdsd+w_hdsd , y_hdsd+w_subframe , clred);
	straight_line(x_hdsd , y_hdsd+h_hdsd , x_hdsd+w_hdsd , y_hdsd+h_hdsd+w_subframe , clred);
	// thanh doc
	straight_line(x_hdsd , y_hdsd , x_hdsd+w_subframe , y_hdsd+h_hdsd+w_subframe , clred);
	straight_line(x_hdsd+w_hdsd , y_hdsd , x_hdsd+w_hdsd+w_subframe , y_hdsd+h_hdsd+w_subframe , clred);
	// button X
	button_x(x_btn_x_hdsd,y_btn_x_hdsd);
	// content 
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5, "- Dung chuot de thao tac" );
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*2 , "- Khi nhap khong the thao tac voi menu");
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*4 , "  chinh");
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*6 , "- Khi tat bang HDSD se tu dong ve trang 1");
}
void create_frame(){
	setusercharsize(1,2,1,2);   // font-size text UI
	settextstyle(8,0,0);
  // main frame
    // thanh ngang
  straight_line(frame_left , frame_top , frame_right , frame_top + w_frame_main ,clblue);
  straight_line(frame_left , frame_bottom , frame_right , frame_bottom + w_frame_main ,clblue);
    // thanh doc
  straight_line(frame_left ,frame_top , frame_left + w_frame_main , frame_bottom ,clblue);
  straight_line(frame_right - w_frame_main , frame_top , frame_right , frame_bottom ,clblue);
  
  // subframe
    // thanh ngang
  straight_line(frame_left+dis_frame_main, frame_top+dis_frame_main,frame_right-dis_frame_main, frame_top+w_subframe+dis_frame_main,clred);
  straight_line(frame_left+dis_frame_main,frame_bottom-w_subframe*2,frame_right-dis_frame_main,frame_bottom-w_subframe,clred);
    // thanh doc chinh
  straight_line(frame_left+dis_frame_main, frame_top+dis_frame_main,frame_left+ frame_top,frame_bottom-w_subframe,clred);
  straight_line(frame_right-dis_frame_main-w_subframe, frame_top+dis_frame_main,frame_right-dis_frame_main,frame_bottom-w_subframe,clred);
    // thanh doc phu
    // do rong cua option la dis_frame_main*3
  straight_line(frame_left + dis_frame_main,frame_top+dis_frame_main*4,frame_right-dis_frame_main,frame_top+dis_frame_main*4+w_subframe,clred);
  setcolor(clblack);
  int length = 0;
  FOR(i,1,8){
    // thanh doc
    straight_line(frame_left+dis_frame_main+w_option*i,frame_top+dis_frame_main,frame_left+dis_frame_main+w_subframe+w_option*i,frame_top+dis_frame_main*4,4);
    setfillstyle(1,clyellow);
    setbkcolor(clyellow);
    length = textwidth(s[i-1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+dis_frame_main+w_subframe+w_option*(i-1),frame_top+dis_frame_main+w_subframe,frame_left+dis_frame_main+w_option*(i),frame_top+dis_frame_main*4);
    outtextxy(frame_left+dis_frame_main+w_subframe+w_option*(i-1)+w_option/2-w_subframe-length/2,frame_top*2+h_word,s[i-1].c_str());
  }
}
void refresh_content(){
	straight_line(frame_left+dis_frame_main+w_subframe,frame_top+dis_frame_main*4+w_subframe,frame_right-dis_frame_main-w_subframe,frame_bottom-dis_frame_main-w_subframe,cllightwhite);
	button_x(frame_right-dis_frame_main-w_subframe*2-w_btn_x-1,frame_top+dis_frame_main*4+ w_subframe);
}
void background_option(int a){
	create_frame();
	setcolor(clblack);
	setfillstyle(1,cllightgreen);
    setbkcolor(cllightgreen);
    int length = textwidth(s[a-1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+dis_frame_main+w_subframe+w_option*(a-1),frame_top+dis_frame_main+w_subframe,frame_left+dis_frame_main+w_option*(a),frame_top+dis_frame_main*4);
    outtextxy(frame_left+dis_frame_main+w_subframe+w_option*(a-1)+w_option/2-w_subframe-length/2,frame_top*2+h_word,s[a-1].c_str());
}
void create_hcn(int a,int b,int c,int d,int e){
	setcolor(e);
	rectangle(a,b,c,d);
}
void test(){
	for(int j=0;j<10;j++){
		for(int i=2;i<5;i++)
			create_hcn(frame_left + dis_frame_main + w_subframe*2+50*(i-1),y_hdsd+30*(j-1),frame_left + dis_frame_main + w_subframe*2+50*i ,y_hdsd+30*j ,0);
			create_hcn(frame_left + dis_frame_main + w_subframe*2+50*4,y_hdsd+30*(j-1),frame_left + dis_frame_main + w_subframe*2+50*10 ,y_hdsd+30*j ,0);
		for(int i=10;i<18;i++)
			create_hcn(frame_left + dis_frame_main + w_subframe*2+50*(i-1),y_hdsd+30*(j-1),frame_left + dis_frame_main + w_subframe*2+50*i ,y_hdsd+30*j ,0);
	}
}
void animations(int x,int y){
	int i = 2; 
	// option 2
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(i-1) && y> frame_top+dis_frame_main+w_subframe && x < frame_left+dis_frame_main+w_option*i && y < frame_top+dis_frame_main*4){
		refresh_content();
		test();
		background_option(i);
		temp = i;
	} 
	// option 3
	i++;
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(i-1) && y> frame_top+dis_frame_main+w_subframe && x < frame_left+dis_frame_main+w_option*i && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(i);
		temp = i;
	} 
	// option 4
	i++;
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(i-1) && y> frame_top+dis_frame_main+w_subframe && x < frame_left+dis_frame_main+w_option*i && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(i);
		temp = i;
	}
	// option 5
	i++;
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(i-1) && y> frame_top+dis_frame_main+w_subframe && x < frame_left+dis_frame_main+w_option*i && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(i);
		temp = i;
	}
	// option 6
	i++;
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(i-1) && y> frame_top+dis_frame_main+w_subframe && x < frame_left+dis_frame_main+w_option*i && y < frame_top+dis_frame_main*4){
		background_option(i);
		hdsd = false ;
		table_hdsd();
	}
	// option 7
	i++;
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(i-1) && y> frame_top+dis_frame_main+w_subframe && x < frame_left+dis_frame_main+w_option*i && y < frame_top+dis_frame_main*4){
		int x = MessageBox(NULL,"Ban co muon thoat khong","Thong bao", MB_OKCANCEL| MB_ICONWARNING);
		if(x==1)	thoat = true;
	}
	// remove table hdsd
	if(x>x_btn_x_hdsd && y>y_btn_x_hdsd && x<x_btn_x_hdsd+w_btn_x && y< y_btn_x_hdsd+w_btn_x && hdsd == false){
    	create_frame();
		hdsd = true ;
        straight_line(x_hdsd , y_hdsd,x_hdsd+w_hdsd+w_subframe , y_hdsd+h_hdsd+w_subframe,cllightwhite);
        if(temp!=0)	{
			background_option(temp);							
			animations(x,y);
		}
        else	screen_logo();
	}
	// remove content -> screen_logo
	if(x>frame_right-dis_frame_main-w_subframe*2-w_btn_x-1 && y> frame_top+dis_frame_main*4+ w_subframe && x<frame_right-dis_frame_main-w_subframe*2-w_btn_x-1 + w_btn_x && y< frame_top+dis_frame_main*4+ w_subframe+ w_btn_x+w_subframe){
		create_frame();
		straight_line(frame_left+dis_frame_main+w_subframe,frame_top+dis_frame_main*4+w_subframe,frame_right-dis_frame_main-w_subframe,frame_bottom-dis_frame_main-w_subframe,cllightwhite);
		screen_logo();
		temp = 0;
	}
}
void click(){	
	if (!kbhit())
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            int x = mousex();
            int y = mousey();
			animations(x,y);      		
            clearmouseclick(WM_LBUTTONDOWN);
        }
    }
}
int main(int argc, char *argv[]){
	initwindow(screen_width, screen_height);
	setbkcolor(cllightwhite);
	cleardevice();
	screen_logo();
	table_hdsd();
	create_frame();
	background_option(6);
	while(1){
		click();
		if(thoat == true ) break;
		delay(100);
	}	
}
