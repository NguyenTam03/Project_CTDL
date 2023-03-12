//#pragma once
#include"Function.h"

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
    if(i==1){
    	setfillstyle(1,cllightpurple);
    	setbkcolor(cllightpurple);
	}
    length = textwidth(option[i-1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+dis_frame_main+w_subframe+w_option*(i-1),frame_top+dis_frame_main+w_subframe,
		frame_left+dis_frame_main+w_option*(i),frame_top+dis_frame_main*4);
    outtextxy(frame_left+dis_frame_main+w_option*(i-1)+w_option/2-length/2,frame_top*2+h_word,option[i-1].c_str());
  }
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

//------- Lop tin chi -------
void LOP_TIN_CHI(){
	int x, y;
	// button -- open --
	x = frame_left + 40;
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
	outtextxy(x-textwidth("Nhap Ma Lop TC:")-3, y_hdsd - 35, "Nhap Ma Lop TC:");
	
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
	// button -- close --
	// content -- open -- 
	string temp[]={"STT","Ma Lop","Ma MH","Ten Mon Hoc","Khoa","HK","Nhom","Sl","CL","Min","HUY","Thao Tac"};
	y = y_hdsd;
	setcolor(clblack);
	setbkcolor(cllightwhite);
	setfillstyle(1,cllightwhite);
		// in ten o? hang` 1 
		x = frame_left + 40;
			bar(x +1,y+1 ,x + 50 -1  , y+30 -1 );
		rectangle(x,y,x + 50 , y+30);
		outtextxy(x+25-textwidth(temp[0].c_str())/2,y+5,temp[0].c_str());
		x+=50;
			bar(x+1,y+1,x + 60-1 , y+30-1);
		rectangle(x,y,x + 60 , y+30);
		outtextxy(x+30-textwidth(temp[1].c_str())/2,y+5,temp[1].c_str());
		x+=60;
			bar(x+1,y+1,x + 60 -1, y+30-1);
		rectangle(x,y,x + 60 , y+30);
		outtextxy(x+30-textwidth(temp[2].c_str())/2,y+5,temp[2].c_str());
		x+=60;
			bar(x,y,x + 305 , y+30);
		rectangle(x,y,x + 305 , y+30);
		outtextxy(x+305/2-textwidth(temp[3].c_str())/2,y+5,temp[3].c_str());
		x+= 305;
		for(int i=4;i<=9;i++){
				bar(x,y,x + 50 , y+30);
			rectangle(x,y,x + 50 , y+30);
			outtextxy(x+50/2-textwidth(temp[i].c_str())/2,y+5,temp[i].c_str());
			x+= 50;
		}
			bar(x,y,x + 60, y+30);
		rectangle(x,y,x + 60 , y+30);
		outtextxy(x+60/2-textwidth(temp[10].c_str())/2,y+5,temp[10].c_str());
		x+= 60;
			bar(x+1,y+1,x + 100 -1, y+30-1);
		rectangle(x,y,x + 100 , y+30);
		outtextxy(x+100/2-textwidth(temp[11].c_str())/2,y+5,temp[11].c_str());
		y+=30;
		// ve table
	for(int j=1;j<=15;j++){
		setfillstyle(1,cllightwhite);
		x = frame_left + 40;
			bar(x+1,y+1,x + 50-1 , y+30-1); //  +1 -1  de cho no khong bi. de` lên voi ham rectangle
		rectangle(x,y,x + 50 , y+30);
		x+=50;
			bar(x+1,y+1,x + 60-1 , y+30-1);
		rectangle(x,y,x + 60 , y+30);
		x+=60;
			bar(x+1,y+1,x + 60-1 , y+30-1);
		rectangle(x,y,x + 60 , y+30);
		x+=60;
			bar(x,y,x + 305 , y+30);
		rectangle(x,y,x + 305 , y+30);
		x+= 305;
		for(int i=0;i<6;i++){
			bar(x,y,x + 50 , y+30);
			rectangle(x,y,x + 50 , y+30);
			x+= 50;
		}
			bar(x,y,x + 60 , y+30);
		rectangle(x,y,x + 60 , y+30);
		x+= 60;
//			bar(x,y,x + 100 , y+30);
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
		setcolor(clblack);
		y+=30;
	}
	button_page();
	// content -- close --
}
//-----------------------//

//------- Sinh Vien -------
void SINH_VIEN(){
	int x, y;
	// button -- open --
	x = frame_left + 40;
	draw_rectangle(x,y_hdsd-40,x+100,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+100,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+50-textwidth("THEM LOP HOC")/2,y_hdsd-32,"THEM LOP HOC");
	// SEARCH
	x = frame_right - 40;
	rectangle(x-260,y_hdsd-40,x,y_hdsd-10);
	x-= 260;
	setbkcolor(cllightwhite);
	outtextxy(x-textwidth("Nhap Ten Lop Hoc:")-3, y_hdsd - 35, "Nhap Ten Lop Hoc:");
	
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
	// button -- close --
	// content -- open --
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
	// content -- close --
}
//-----------------------//
//------- Mon Hoc -------
void MON_HOC(){
	int x, y;
	// button -- open -- 
	x = frame_left + 40;
	draw_rectangle(x,y_hdsd-40,x+100,y_hdsd-5,claqua);
	rectangle(x,y_hdsd-40,x+100,y_hdsd-5);
	setbkcolor(claqua);
	outtextxy(x+50-textwidth("THEM MON HOC")/2,y_hdsd-32,"THEM MON HOC");
	
	// SEARCH
	x = frame_right - 40;
	rectangle(x-260,y_hdsd-40,x,y_hdsd-10);
	x-= 260;
	setbkcolor(cllightwhite);
	outtextxy(x-textwidth("Nhap Ten Mon Hoc:")-3, y_hdsd - 35, "Nhap Ten Mon Hoc:");
	
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
	// button -- close --
	// content -- open --  
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
			outtextxy(x+55+21-textwidth("Xoa")/2,y+5,"Xoa");
			setcolor(0);
		y+=30;
	}
	button_page();
	// content -- close --  
}
//-----------------------//
//------- Diem -------
void DIEM(){
	int x, y;
	// button -- open --
	x = frame_left + 40;
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
	outtextxy(x-textwidth("Nhap Ma Lop TC:")-3, y_hdsd - 35, "Nhap Ma Lop TC:");
	
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
	// button -- close --
	// content -- open --
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
	// content -- close --
}
