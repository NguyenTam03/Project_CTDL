//#pragma once
#include<winbgim.h>
#include<iostream>
#include<string>
#include"logo.h"
#define FOR(i,r,l)	for(int i=r;i<l;i++)
using namespace std;
string option[]={"MENU" , "LOP TIN CHI" , "SINH VIEN" , "MON HOC" , "DIEM" , "HDSD" , "THOAT"};
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
int previous_page_index = 0;
int h_word = 9;
int screen_width = 1460;
int screen_height = 750;
int w_frame_main = 10;
int dis_frame_main = 15;
int w_subframe = 5;
int frame_left = 230;
int frame_top = 20;
int frame_right = 1245; // 1245
int frame_bottom = 730;
int w_option = (frame_right-frame_left-dis_frame_main*2-w_subframe)/7;
int w_table = 400;
int h_hdsd = 400;
int x_hdsd = (frame_right + frame_left )/2 - w_table/2;
int y_hdsd = (frame_bottom+frame_top+dis_frame_main*4)/2-h_hdsd/2;
int w_btn_x = 30;
int x_btn_x_table = x_hdsd + w_table - w_btn_x - w_subframe;
int y_btn_x_table = y_hdsd + 4 ;
bool hdsd = false;
bool thoat = false;
//-------------------------------------------//
void draw_rectangle(int left,int top,int right,int bottom, int color){
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
void screen_logo(){
	setbkcolor(cllightwhite);
	setcolor(cllightred);
	int length = textwidth(logo[0].c_str());
	// screen logo
	FOR(i,0,27){
		outtextxy((frame_left+frame_right)/2 - length/2,frame_top*8+i*15,logo[i].c_str()); // 15 la` chieu cao(y) cua chu
	}
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

void table_hdsd(){
	table(x_hdsd,y_hdsd,w_table,h_hdsd);
	// content 
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5, "- Dung chuot de thao tac" );
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*2 , "- Khi nhap khong the thao tac voi menu");
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*4 , "  chinh");
	outtextxy(x_hdsd + w_subframe*2, y_hdsd + w_btn_x + w_subframe* 5 + h_word*6 , "- Khi tat bang HDSD se tu dong ve trang 1");
}

void create_frame(){
  // main frame
    // thanh ngang
  draw_rectangle(frame_left , frame_top , frame_right , frame_top + w_frame_main ,clblue);
  draw_rectangle(frame_left , frame_bottom , frame_right , frame_bottom + w_frame_main ,clblue);
    // thanh doc
  draw_rectangle(frame_left ,frame_top , frame_left + w_frame_main , frame_bottom ,clblue);
  draw_rectangle(frame_right - w_frame_main , frame_top , frame_right , frame_bottom ,clblue);
	
  // subframe
    // thanh ngang
  draw_rectangle(frame_left+dis_frame_main, frame_top+dis_frame_main,
	frame_right-dis_frame_main, frame_top+w_subframe+dis_frame_main,clred);
  draw_rectangle(frame_left+dis_frame_main,frame_bottom-w_subframe*2,
	frame_right-dis_frame_main,frame_bottom-w_subframe,clred);
    // thanh doc chinh
  draw_rectangle(frame_left+dis_frame_main, frame_top+dis_frame_main,
	frame_left+ frame_top,frame_bottom-w_subframe,clred);
  draw_rectangle(frame_right-dis_frame_main-w_subframe, frame_top+dis_frame_main,
	frame_right-dis_frame_main,frame_bottom-w_subframe,clred);
    // thanh doc phu
    // do rong cua option la dis_frame_main*3
  draw_rectangle(frame_left + dis_frame_main,frame_top+dis_frame_main*4,
	frame_right-dis_frame_main,frame_top+dis_frame_main*4+w_subframe,clred);
  setcolor(clblack);
  int length = 0;
  FOR(i,1,8){
    // thanh doc
    draw_rectangle(frame_left+dis_frame_main+w_option*i,frame_top+dis_frame_main,
		frame_left+dis_frame_main+w_subframe+w_option*i,frame_top+dis_frame_main*4,4);
    setfillstyle(1,clyellow);
    setbkcolor(clyellow);
    length = textwidth(option[i-1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+dis_frame_main+w_subframe+w_option*(i-1),frame_top+dis_frame_main+w_subframe,
		frame_left+dis_frame_main+w_option*(i),frame_top+dis_frame_main*4);
    outtextxy(frame_left+dis_frame_main+w_subframe+w_option*(i-1)+w_option/2-w_subframe-length/2,frame_top*2+h_word,option[i-1].c_str());
  }
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
void function_LTC(){
	int x = frame_left + 40;
	draw_rectangle(x,y_hdsd-40,x+70,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+70,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+35-textwidth("THEM LTC")/2,y_hdsd-32,"THEM LTC");
	x+=80;
	
	draw_rectangle(x,y_hdsd-40,x+70,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+70,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+35-textwidth("HUY LTC")/2,y_hdsd-32,"HUY LTC");
	x+=80;
	
	draw_rectangle(x,y_hdsd-40,x+100,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+100,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+50-textwidth("DANG KY LTC")/2,y_hdsd-32,"DANG KY LTC");
	x+=110;
	
	draw_rectangle(x,y_hdsd-40,x+70,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+70,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+35-textwidth("XEM DSSV")/2,y_hdsd-32,"XEM DSSV");
	
	// SEARCH
	x = frame_right - 40;
	rectangle(x-260,y_hdsd-40,x,y_hdsd-10);
	x-= 260;
	setbkcolor(cllightwhite);
	outtextxy(x-textwidth("Nhap Ma Lop TC:"), y_hdsd - 35, "Nhap Ma Lop TC:");
	
	draw_rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10,cllightgreen);
	setbkcolor(cllightgreen);
	setcolor(clred);
	rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10);
	outtextxy(frame_left+507-textwidth("DANH SACH LOP TIN CHI")/2,frame_top+dis_frame_main*5+1,"DANH SACH LOP TIN CHI");
	setcolor(clblack);
	setbkcolor(cllightwhite);
	string s ="TONG SO LOP: 782";
	outtextxy(frame_left+507-textwidth(s.c_str())/2,frame_top+dis_frame_main*8,s.c_str());
}
void function_SV(){
	int x = frame_left + 40;
	draw_rectangle(x,y_hdsd-40,x+100,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+100,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+50-textwidth("THEM LOP HOC")/2,y_hdsd-32,"THEM LOP HOC");
	
	// SEARCH
	x = frame_right - 40;
	rectangle(x-260,y_hdsd-40,x,y_hdsd-10);
	x-= 260;
	setbkcolor(cllightwhite);
	outtextxy(x-textwidth("Nhap Ten Lop Hoc:"), y_hdsd - 35, "Nhap Ten Lop Hoc:");
	
	draw_rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10,cllightgreen);
	setbkcolor(cllightgreen);
	setcolor(clred);
	rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10);
	outtextxy(frame_left+507-textwidth("DANH SACH LOP SINH VIEN")/2,frame_top+dis_frame_main*5+1,"DANH SACH LOP SINH VIEN");
	setcolor(clblack);
	setbkcolor(cllightwhite);
	string s ="TONG SO LOP: 782";
	outtextxy(frame_left+507-textwidth(s.c_str())/2,frame_top+dis_frame_main*8,s.c_str());
}
void function_MH(){
	int x = frame_left + 40;
	draw_rectangle(x,y_hdsd-40,x+100,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+100,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+50-textwidth("THEM MON HOC")/2,y_hdsd-32,"THEM MON HOC");
	
	// SEARCH
	x = frame_right - 40;
	rectangle(x-260,y_hdsd-40,x,y_hdsd-10);
	x-= 260;
	setbkcolor(cllightwhite);
	outtextxy(x-textwidth("Nhap Ten Mon Hoc:"), y_hdsd - 35, "Nhap Ten Mon Hoc:");
	
	draw_rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10,cllightgreen);
	setbkcolor(cllightgreen);
	setcolor(clred);
	rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10);
	outtextxy(frame_left+507-textwidth("DANH SACH MON HOC")/2,frame_top+dis_frame_main*5+1,"DANH SACH MON HOC");
	setcolor(clblack);
	setbkcolor(cllightwhite);
	string s ="TONG SO MON HOC: 782";
	outtextxy(frame_left+507-textwidth(s.c_str())/2,frame_top+dis_frame_main*8,s.c_str());
}
void function_DIEM(){
	int x = frame_left + 40;
	draw_rectangle(x,y_hdsd-40,x+70,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+70,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+35-textwidth("DIEM 1 SV")/2,y_hdsd-32,"DIEM 1 SV");
	x+=80;
	
	draw_rectangle(x,y_hdsd-40,x+70,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+70,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+35-textwidth("DIEM TB")/2,y_hdsd-32,"DIEM TB");
	x+=80;
	
	draw_rectangle(x,y_hdsd-40,x+70,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+70,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+35-textwidth("DIEM TK")/2,y_hdsd-32,"DIEM TK");
	
	// SEARCH
	x = frame_right - 40;
	rectangle(x-260,y_hdsd-40,x,y_hdsd-10);
	x-= 260;
	setbkcolor(cllightwhite);
	outtextxy(x-textwidth("Nhap Ma Lop TC:"), y_hdsd - 35, "Nhap Ma Lop TC:");
	
	draw_rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10,cllightgreen);
	setbkcolor(cllightgreen);
	setcolor(clred);
	rectangle(frame_left+507-200,frame_top+dis_frame_main*4+10,
		frame_left+507+200,frame_top+dis_frame_main*6+10);
	outtextxy(frame_left+507-textwidth("DANH SACH LOP TINH CHI")/2,frame_top+dis_frame_main*5+1,"DANH SACH LOP TIN CHI");
	setcolor(clblack);
	setbkcolor(cllightwhite);
	string s ="TONG SO LOP: 782";
	outtextxy(frame_left+507-textwidth(s.c_str())/2,frame_top+dis_frame_main*8,s.c_str());
}
void background_option(int a){
	int x, y;
	create_frame();
	setcolor(clblack);
	setfillstyle(1,cllightgreen);
    setbkcolor(cllightgreen);
    int length = textwidth(option[a-1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+dis_frame_main+w_subframe+w_option*(a-1),frame_top+dis_frame_main+w_subframe,
		frame_left+dis_frame_main+w_option*(a),frame_top+dis_frame_main*4);
    outtextxy(frame_left+dis_frame_main+w_subframe+w_option*(a-1)+w_option/2-w_subframe-length/2,frame_top*2+h_word,option[a-1].c_str());
    // test
    // 50 60 100 con` lai name
    // LTC
    if(a==2){
    	function_LTC();
		string temp[]={"STT","Ma Lop","Ma MH","Ten Mon Hoc","Khoa","HK","Nhom","Sl","CL","Min","HUY","Thao Tac"};
		y = y_hdsd;
    	setcolor(clblack);
    	setbkcolor(cllightwhite);
    		x = frame_left + 40;
   			rectangle(x,y,x + 50 , y+30);
   			outtextxy(x+25-textwidth(temp[0].c_str())/2,y+5,temp[0].c_str());
			x+=50;
			rectangle(x,y,x + 60 , y+30);
			outtextxy(x+30-textwidth(temp[1].c_str())/2,y+5,temp[1].c_str());
			x+=60;
		   	rectangle(x,y,x + 60 , y+30);
			outtextxy(x+30-textwidth(temp[2].c_str())/2,y+5,temp[2].c_str());
			x+=60;
   			rectangle(x,y,x + 305 , y+30);
   			outtextxy(x+305/2-textwidth(temp[3].c_str())/2,y+5,temp[3].c_str());
			x+= 305;
			for(int i=4;i<=9;i++){
				rectangle(x,y,x + 50 , y+30);
				outtextxy(x+50/2-textwidth(temp[i].c_str())/2,y+5,temp[i].c_str());
				x+= 50;
			}
			rectangle(x,y,x + 60 , y+30);
			outtextxy(x+60/2-textwidth(temp[10].c_str())/2,y+5,temp[10].c_str());
			x+= 60;
			rectangle(x,y,x + 100 , y+30);
			outtextxy(x+100/2-textwidth(temp[11].c_str())/2,y+5,temp[11].c_str());
    		y+=30;
			 
   		for(int j=1;j<=15;j++){
   			x = frame_left + 40;
   			rectangle(x,y,x + 50 , y+30);
			x+=50;
			rectangle(x,y,x + 60 , y+30);
			x+=60;
		   	rectangle(x,y,x + 60 , y+30);
			x+=60;
   			rectangle(x,y,x + 305 , y+30);
			x+= 305;
			for(int i=0;i<6;i++){
				rectangle(x,y,x + 50 , y+30);
				x+= 50;
			}
			rectangle(x,y,x + 60 , y+30);
			x+= 60;
			rectangle(x,y,x + 100 , y+30);
				draw_rectangle(x+3,y+3,x+45,y+27,clyellow);
				rectangle(x+3,y+3,x+45,y+27);
				setbkcolor(clyellow);
				outtextxy(x+3+21-textwidth("Sua")/2,y+5,"Sua");
				draw_rectangle(x+55,y+3,x+97,y+27,cllightred);
			
				rectangle(x+55,y+3,x+97,y+27);
				setbkcolor(cllightred);
				setcolor(cllightwhite);
				outtextxy(x+55+21-textwidth("Sua")/2,y+5,"Xoa");
				setcolor(0);
   			y+=30;
		}
		button_page();
    }
    // SV
    if (a==3){
    	function_SV();
    	y = y_hdsd;
    	x = frame_left + 40;
    	setbkcolor(cllightwhite);
    	rectangle(x, y, x+50, y+30);
    	outtextxy(x+25-textwidth("STT")/2,y+5,"STT");
    	x+=50;
    	rectangle(x, y, x+395, y+30);
    	outtextxy(x+192-textwidth("Ten Lop")/2,y+5,"Ten Lop");
    	x+=395;
    	rectangle(x, y, x+390, y+30);
    	outtextxy(x+195-textwidth("So Sinh Vien Hien Tai")/2,y+5,"So Sinh Vien Hien Tai");
    	x+=390;
    	rectangle(x,y,x+100,y+30);
    	outtextxy(x+50-textwidth("Thao Tac")/2,y+5,"Thao Tac");
    	y+=30;
    	for(int j=1;j<=15;j++){
    		x = frame_left + 40;
    		rectangle(x, y, x+50, y+30);
    		x+=50;
    		rectangle(x, y, x+395, y+30);
    		x+=395;
    		rectangle(x, y, x+390, y+30);
    		x+=390;
    		rectangle(x, y, x+100, y+30);
    		
    		draw_rectangle(x+5,y+3,x+95,y+27,cllightgreen);
    		rectangle(x+5,y+3,x+95,y+27);
    		setbkcolor(cllightgreen);
    		outtextxy(x+50-textwidth("Xem DSSV")/2,y+6,"Xem DSSV");	
    		y+=30;
		}
		button_page();
	}
	// MON HOC
	if(a==4){
		function_MH();
		y = y_hdsd;
		x = frame_left + 40;
		setbkcolor(cllightwhite);
    	rectangle(x, y, x+50, y+30);
    	outtextxy(x+25-textwidth("STT")/2, y+5,"STT");
    	x+=50;
    	rectangle(x,y,x+150, y+30);
		outtextxy(x+75-textwidth("Ma Mon Hoc")/2, y+5,"Ma Mon Hoc");
    	x+=150;
    	rectangle(x,y,x+335,y+30);
    	outtextxy(x+167-textwidth("Ten Mon Hoc")/2, y+5,"Ten Mon Hoc");
    	x+=335;
    	rectangle(x,y,x+150, y+30);
    	outtextxy(x+75-textwidth("So TC Ly Thuyet")/2, y+5,"So TC Ly Thuyet");
    	x+=150;
		rectangle(x,y,x+150, y+30);
		outtextxy(x+75-textwidth("So TC Thuc Hanh")/2, y+5,"So TC Thuc Hanh");
    	x+=150;
		rectangle(x,y, x+100, y+30);
		outtextxy(x+50-textwidth("Thao Tac")/2, y+5,"Thao Tac");
		y+=30;
		for(int j=1;j<=15;j++){
			x = frame_left + 40;
    		rectangle(x, y, x+50, y+30);
    		x+=50;
    		rectangle(x,y,x+150, y+30);
    		x+=150;
    		rectangle(x,y,x+335,y+30);
    		x+=335;
    		for(int i=1;i<=2;i++){
    			rectangle(x,y,x+150, y+30);
    			x+=150;
			}
			rectangle(x,y, x+100, y+30);
		
				draw_rectangle(x+3,y+3,x+45,y+27,clyellow);
				rectangle(x+3,y+3,x+45,y+27);
				setbkcolor(clyellow);
				outtextxy(x+3+21-textwidth("Sua")/2,y+5,"Sua");
				draw_rectangle(x+55,y+3,x+97,y+27,cllightred);
			
				rectangle(x+55,y+3,x+97,y+27);
				setbkcolor(cllightred);
				setcolor(cllightwhite);
				outtextxy(x+55+21-textwidth("Sua")/2,y+5,"Xoa");
				setcolor(0);
   			y+=30;
		}
		button_page();
	}
	// DIEM
    if(a==5){
    	function_DIEM();
		y = y_hdsd;
		string temp[]={"STT","Ma Lop","Ma MH","Ten Mon Hoc","Khoa","HK","Nhom","Sl","CL","Min","HUY","Thao Tac"};
    	setcolor(clblack);
    	setbkcolor(cllightwhite);
    	x = frame_left + 40;
   		rectangle(x,y,x + 50 , y+30);
   		outtextxy(x+25-textwidth(temp[0].c_str())/2,y+5,temp[0].c_str());
		x+=50;
		rectangle(x,y,x + 60 , y+30);
		outtextxy(x+30-textwidth(temp[1].c_str())/2,y+5,temp[1].c_str());
		x+=60;
	 	rectangle(x,y,x + 60 , y+30);
		outtextxy(x+30-textwidth(temp[2].c_str())/2,y+5,temp[2].c_str());
		x+=60;
   		rectangle(x,y,x + 305 , y+30);
   		outtextxy(x+305/2-textwidth(temp[3].c_str())/2,y+5,temp[3].c_str());
		x+= 305;
		for(int i=4;i<=9;i++){
			rectangle(x,y,x + 50 , y+30);
			outtextxy(x+50/2-textwidth(temp[i].c_str())/2,y+5,temp[i].c_str());
			x+= 50;
		}
		rectangle(x,y,x + 60 , y+30);
		outtextxy(x+60/2-textwidth(temp[10].c_str())/2,y+5,temp[10].c_str());
		x+= 60;
		rectangle(x,y,x + 100 , y+30);
		outtextxy(x+100/2-textwidth(temp[11].c_str())/2,y+5,temp[11].c_str());
    	y+=30;
		
   		for(int j=1;j<=15;j++){
   			x = frame_left + 40;
   			rectangle(x,y,x + 50,y+30);
			x+=50;
			for(int i=1;i<=2;i++){
			   	rectangle(x,y,x + 60, y+30);
				x+=60;
			}
   			rectangle(x,y,x + 305, y+30);
			x+= 305;
			for(int i=1;i<=6;i++){
				rectangle(x,y,x + 50, y+30);
				x+= 50;
			}
			rectangle(x,y,x + 60, y+30);
			x+= 60;
			rectangle(x,y,x + 100, y+30);
			
    		    draw_rectangle(x+5,y+3,x+95,y+27,cllightgreen);
    			rectangle(x+5,y+3,x+95,y+27);
    			setbkcolor(cllightgreen);
    			outtextxy(x+50-textwidth("Xem Diem")/2,y+6,"Xem Diem");	
   			y+=30;
		}
		button_page();	
    }
    // test
}

void animations(int x,int y){
	// lop tin chi
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(1) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*2 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(2);
		previous_page_index = 2;
	} 
	// sinh vien
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(2) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*3 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(3);
		previous_page_index = 3;
	} 
	// mon hoc
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(3) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*4 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(4);
		previous_page_index = 4;
	}
	// diem
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(4) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*5 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(5);
		previous_page_index = 5;
	}
	// hdsd
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(5) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*6 && y < frame_top+dis_frame_main*4){
		background_option(6);
		hdsd = false ;
		table_hdsd();
	}
	// 	thoat
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(6) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*7 && y < frame_top+dis_frame_main*4){
		int x = MessageBox(NULL,"Ban co muon thoat khong","Thong bao", MB_OKCANCEL| MB_ICONWARNING);
		if(x==1)	thoat = true;
	}
	// remove table hdsd
	if(x>x_btn_x_table && y>y_btn_x_table && x<x_btn_x_table+w_btn_x && y< y_btn_x_table+w_btn_x && hdsd == false){
    	create_frame();
		hdsd = true ;
        draw_rectangle(x_hdsd , y_hdsd,x_hdsd+w_table+w_subframe , y_hdsd+h_hdsd+w_subframe,cllightwhite);
        if(previous_page_index!=0)	{
			background_option(previous_page_index);							
			animations(x,y);
		}
        else	screen_logo();
	}
	// remove content -> screen_logo
	if(x>frame_right-dis_frame_main-w_subframe*2-w_btn_x-1 && y> frame_top+dis_frame_main*4+ w_subframe 
	&& x<frame_right-dis_frame_main-w_subframe*2-w_btn_x-1 + w_btn_x && y< frame_top+dis_frame_main*4+ w_subframe+ w_btn_x+w_subframe){
		create_frame();
		draw_rectangle(frame_left+dis_frame_main+w_subframe,frame_top+dis_frame_main*4+w_subframe,
			frame_right-dis_frame_main-w_subframe,frame_bottom-w_frame_main,cllightwhite);
		screen_logo();
		previous_page_index = 0;
	}
}
void click(){		
    	if(ismouseclick(WM_LBUTTONDOWN)){
            int x = mousex();
            int y = mousey();
			animations(x,y);      		
            clearmouseclick(WM_LBUTTONDOWN);
        }	
}
void Nguyen_Tam(){
	setbkcolor(cllightred);
	setcolor(0);
	string s ="NGUYEN THANH TAM";
	int length = textwidth(s.c_str());
	// screen logo
	outtextxy((frame_left+frame_right)/2 - length/2,frame_top*8+30*15,s.c_str()); // 15 la` chieu cao(y) cua chu
}

int main(int argc, char *argv[]){
	initwindow(screen_width, screen_height);
//		setusercharsize(1,2,1,2);   
	setusercharsize(2,5,1,2);
	settextstyle(8,0,0);
	setbkcolor(cllightwhite);
	cleardevice();
	screen_logo();
	table_hdsd();
	create_frame();
	background_option(6); //  to mau o hdsd
	while(1){
		click();
		Nguyen_Tam();
		if(thoat == true ) break;
		delay(100);
	}	
}
