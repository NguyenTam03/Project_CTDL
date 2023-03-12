//#pragma once
#include"LopTC.h"
#include"Graphic.h"
void background_option(int pos){
	int x, y;
	//  to mau` o vua` click vao`
	create_frame(); //  xoa mau o trc do
	setcolor(clblack);
	setfillstyle(1,cllightgreen);
    setbkcolor(cllightgreen);
    int length = textwidth(option[pos+1].c_str()); // do chieu dai (toa do) cua word
    bar(frame_left+dis_frame_main+w_subframe+w_option*(pos+1),frame_top+dis_frame_main+w_subframe,
		frame_left+dis_frame_main+w_option*(pos+2),frame_top+dis_frame_main*4); 
    outtextxy(frame_left+dis_frame_main+w_subframe+w_option*(pos+1)+w_option/2-w_subframe-length/2,frame_top*2+h_word,option[pos+1].c_str());
    // LTC
    if(pos == 0){
    	LOP_TIN_CHI();
    }
    // SV
    if (pos == 1){
    	SINH_VIEN();
	}
	// MON HOC
	if(pos == 2){
		MON_HOC();
	}
	// DIEM
    if(pos == 3){
    	DIEM();
    }
}
int test3 = false;
// --- thao tac' --- //
void THEM_LTC(){
	table_themltc();
	string s;
	setbkcolor(cllightwhite);
	while(1){
		input(s,x_hdsd+120,y_hdsd+46);
		setcolor(clblack);
    	if(ismouseclick(WM_LBUTTONDOWN)){
            int x = mousex();
            int y = mousey();
            // xoa bang quay lai trang LTC
      		if(x>x_btn_x_table&& y>y_btn_x_table+w_subframe &&
			   x<x_btn_x_table+w_btn_x && y<y_btn_x_table+w_subframe+w_btn_x+w_subframe){   
				background_option(0);
				break;
			}
            clearmouseclick(WM_LBUTTONDOWN);
        }
	}
}
void animations(int x,int y){
	// lop tin chi
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(1) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*2 && y < frame_top+dis_frame_main*4){
		hdsd = false ;
		refresh_content();
		background_option(0);
		previous_page_index = 0;
		opt[0]= true;
		opt[1]=opt[2]=opt[3]=false;
	} 
	//----------//
	if(opt[0]== true){
			// Test Click
			int x1 = frame_left + 40;
			if(x>x1 && y>y_hdsd-40 && x< x1+70 && y<y_hdsd-5){   
				THEM_LTC();
			}
			x1+=80;
			if(x> x1 && y>y_hdsd-40 && x<x1+70 && y<y_hdsd-5){
				table_huyltc();
			}
			x1+=80;
			if(x> x1 && y>y_hdsd-40 && x<x1+100 && y<y_hdsd-5){
				table_dangkyltc();
			}
			x1+=110;
			if(x> x1 && y>y_hdsd-40 && x<x1+70 && y<y_hdsd-5){
				table_xemdssv();
			}

    // close //	
	}
	//----------//
	// sinh vien
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(2) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*3 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(1);
		previous_page_index = 1;
		opt[1]= false;
		opt[0]=opt[2]=opt[3]=false;
	} 
	// mon hoc
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(3) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*4 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(2);
		previous_page_index = 2;
		opt[2]= false;
		opt[0]=opt[1]=opt[3]=false;
	}
	// diem
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(4) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*5 && y < frame_top+dis_frame_main*4){
		refresh_content();
		background_option(3);
		previous_page_index = 3;
		opt[3]= false;
		opt[0]=opt[1]=opt[2]=false;
	}
	// hdsd
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(5) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*6 && y < frame_top+dis_frame_main*4){
		hdsd = true ;
		background_option(4);
		table_hdsd();
	}
	// 	thoat
	if(x>frame_left+dis_frame_main+w_subframe+w_option*(6) && y> frame_top+dis_frame_main+w_subframe 
	&& x < frame_left+dis_frame_main+w_option*7 && y < frame_top+dis_frame_main*4){
		int x = MessageBox(NULL,"Ban co muon thoat khong","Thong bao", MB_OKCANCEL| MB_ICONWARNING);
		if(x==1)	thoat = true;
	}
	// remove table hdsd
	if(x>x_btn_x_table && y>y_btn_x_table+w_subframe && x<x_btn_x_table+w_btn_x && y< y_btn_x_table+w_btn_x+w_subframe && hdsd == true){
    	create_frame();
		hdsd = false ;
        draw_rectangle(x_hdsd , y_hdsd,x_hdsd+w_table+w_subframe , y_hdsd+h_hdsd+w_subframe,cllightwhite);
        if(previous_page_index!= -1)	{
			background_option(previous_page_index);							
			animations(x,y);
		}
        else	screen_logo();
	}
	// remove content -> screen_logo
	if(x>frame_right-dis_frame_main-w_subframe*2-w_btn_x-1 && y> frame_top+dis_frame_main*4+ w_subframe 
	&& x<frame_right-dis_frame_main-w_subframe*2-w_btn_x-1 + w_btn_x && y< frame_top+dis_frame_main*4+ w_subframe+ w_btn_x+w_subframe){
		create_frame();
		draw_rectangle(frame_left+dis_frame_main+w_subframe,
			frame_top+dis_frame_main*4+w_subframe,
			frame_right-dis_frame_main-w_subframe,
			frame_bottom-w_frame_main,cllightwhite);
		screen_logo();
		previous_page_index = -1;
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
void test(){
	table(x_hdsd,y_hdsd,w_table,h_hdsd/2);
		setbkcolor(cllightwhite);
	outtextxy(x_hdsd+150-textwidth("Nhap Ma Lop "),y_hdsd+40,"Nhap Ma Lop ");
	rectangle(x_hdsd+155,y_hdsd+35,x_hdsd+355,y_hdsd+60);
}
