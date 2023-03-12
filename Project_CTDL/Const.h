#pragma once
#include<string>
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
const int h_word = 9;
const int screen_width = 1460;
const int screen_height = 750;
const int w_frame_main = 10;
const int dis_frame_main = 15;
const int w_subframe = 5;
const int frame_left = 230;
const int frame_top = 20;
const int frame_right = 1245; // 1245
const int frame_bottom = 730; // 730
const int w_option = (frame_right-frame_left-dis_frame_main*2-w_subframe)/7;
const int w_table = 400;
const int h_hdsd = 400;
const int x_hdsd = (frame_right + frame_left )/2 - w_table/2;
const int y_hdsd = (frame_bottom+frame_top+dis_frame_main*4)/2-h_hdsd/2;
const int w_btn_x = 30;
const int x_btn_x_table = x_hdsd + w_table - w_btn_x - w_subframe;
const int y_btn_x_table = y_hdsd + 4 ;
int previous_page_index = -1;
bool hdsd = true;
bool thoat = false;
bool opt[4]={false};
