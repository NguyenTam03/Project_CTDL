#pragma once
#include<winbgim.h>
#include"Const.h"
#include"Logo.h"
#define FOR(i,r,l)	for(int i=r;i<l;i++)
void draw_rectangle(int left,int top,int right,int bottom, int color){
	setfillstyle(1,color);
	bar(left,top,right,bottom);
}
void button_x(int x, int y){
	setcolor(clblack);
	rectangle(x,y+w_subframe,x+w_btn_x,y+w_btn_x+w_subframe);
	setbkcolor(cllightred);
	setfillstyle(1,cllightred);
	bar(x+1,y+w_subframe+1,x+w_btn_x,y+w_btn_x+w_subframe);
	string s = "X";
	int length = textwidth(s.c_str());
	outtextxy(x+w_btn_x/2-length/2,y+w_subframe+w_btn_x/2-h_word+1,s.c_str());
}
void refresh_content(){
	draw_rectangle(frame_left+dis_frame_main+w_subframe,
		frame_top+dis_frame_main*4+w_subframe,
		frame_right-dis_frame_main-w_subframe,
		frame_bottom-w_frame_main,cllightwhite);
	button_x(frame_right-dis_frame_main-w_subframe*2-w_btn_x-1,frame_top+dis_frame_main*4+ w_subframe);
}
void table(int x, int y, int width, int height){
	draw_rectangle(x , y,x+width+w_subframe , y+height+w_subframe,cllightwhite);
	// thanh ngang
	draw_rectangle(x , y , x+width , y+w_subframe , clred);
	draw_rectangle(x , y+height , x+width , y+height+w_subframe , clred);
	// thanh doc
	draw_rectangle(x , y , x+w_subframe , y+height+w_subframe , clred);
	draw_rectangle(x+width , y , x+width+w_subframe , y+height+w_subframe , clred);
	// button X
	button_x(x_btn_x_table,y_btn_x_table);
}

// --------------------
void table_hdsd(){
	table(x_hdsd,y_hdsd,w_table,h_hdsd);
	// content 
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5, "- Dung chuot de thao tac" );
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*2 , "- Khi nhap khong the thao tac voi menu");
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*4 , "  chinh");
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*6 , "- Khi tat bang HDSD se tu dong ve trang 1");
}

void button_page(){
	setbkcolor(clyellow);
	draw_rectangle(frame_left+307, 690 ,frame_left+407, 715,clyellow); //(1245-230)/2-200 = 307
	rectangle(frame_left+307, 690,frame_left+407, 715);
    outtextxy(frame_left+307+50-textwidth("<-")/2, 695, "<-"); // 50 = 100/2
    
    draw_rectangle(frame_left+607, 690,frame_left+707, 715,clyellow); // (1245-230)/2+100 = 607
    rectangle(frame_left+607, 690,frame_left+707, 715);
    outtextxy(frame_left+607+50-textwidth("->")/2, 695, "->");
}
void doichu(char &a){
		if(a>96&&a<123)
			a-=32;
}
void input(string &s ,int x,int y){
	char ch;
	while(kbhit()){
		ch = getch();
		if (ch == 8) { // Backspace key
            if (s.length() > 0) { //  xoa' ky' tu.
                s.erase(s.length() - 1);
            	outtextxy(x+textwidth(s.c_str()),y," ");
            }
        }else if( (ch>47 && ch<58) || (ch>96 && ch<123) || ch>63 && ch<91){
           		if(ch>96 && ch<123)	ch-=32;
            	s += ch;
            	outtextxy(x, y, s.c_str());
        	}
	}
}

void Nguyen_Tam(){
	setbkcolor(clyellow);
	setcolor(0);
	string s ="NGUYEN THANH TAM-NGUYEN TRUNG KHANH-LUONG HAI DANG";
	int length = textwidth(s.c_str());
	// screen logo
	outtextxy((frame_left+frame_right)/2 - length/2,frame_top*8+30*15,s.c_str()); // 15 la` chieu cao(y) cua chu
}

