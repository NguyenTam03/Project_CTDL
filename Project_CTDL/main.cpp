#include"Menu.h"
int main(){
	initwindow(screen_width, screen_height);
//	setusercharsize(1,2,1,2);   
	setusercharsize(2,5,1,2);
	settextstyle(8,0,0);
	setbkcolor(cllightwhite);
	cleardevice();
	screen_logo();
	table_hdsd();
	create_frame();
	background_option(4);
	while(1){
//		test();
		click();
		Nguyen_Tam();
		if(thoat == true ) break;
		delay(100);
	}	
}
