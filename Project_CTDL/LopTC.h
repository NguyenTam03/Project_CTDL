// LOP TIN CHI
#pragma once
#include"Const.h"
#include"Function.h"
void table_themltc(){
	// table Them LTC
	table(x_hdsd,y_hdsd,w_table,h_hdsd);
	draw_rectangle(x_hdsd+w_table/2-50,y_hdsd+7,x_hdsd+w_table/2+50,y_hdsd+30,claqua);
	setbkcolor(claqua);
	outtextxy(x_hdsd+w_table/2-textwidth("THEM LTC")/2,y_hdsd+9,"THEM LTC");
	setbkcolor(cllightwhite);
	int y = y_hdsd+40;
	outtextxy(x_hdsd+100-textwidth("Ma Lop"),y+6,"Ma Lop");
	rectangle(x_hdsd+105,y,x_hdsd+355,y+30);
	y+=50;
	outtextxy(x_hdsd+100-textwidth("Ma Mon Hoc"),y+6,"Ma Mon Hoc");
	rectangle(x_hdsd+105,y,x_hdsd+235,y+30);
	// button
	draw_rectangle(x_hdsd+285,y,x_hdsd+355,y+30,cllightgreen);
	setbkcolor(cllightgreen);
	rectangle(x_hdsd+285,y,x_hdsd+355,y+30);
	outtextxy(x_hdsd+320-textwidth("Ma MH")/2,y+6,"Ma MH");
	setbkcolor(cllightwhite);
	y+=50;
	outtextxy(x_hdsd+100-textwidth("Nien Khoa"),y+6,"Nien Khoa");
	rectangle(x_hdsd+105,y,x_hdsd+185,y+30);
	outtextxy(x_hdsd+280-textwidth("Hoc Ky"),y+6,"Hoc Ky");
	rectangle(x_hdsd+285,y,x_hdsd+355,y+30);
	y+=50;
	outtextxy(x_hdsd+100-textwidth("Nhom"),y+6,"Nhom");
	rectangle(x_hdsd+105,y,x_hdsd+235,y+30);
	y+=50;
	outtextxy(x_hdsd+100-textwidth("SL Min"),y+6,"SL Min");
	rectangle(x_hdsd+105,y,x_hdsd+185,y+30);
	outtextxy(x_hdsd+280-textwidth("SL Max"),y+6,"SL Max");
	rectangle(x_hdsd+285,y,x_hdsd+355,y+30);
	y+=75;
	setbkcolor(clyellow);
	draw_rectangle(x_hdsd+150,y,x_hdsd+250,y+40,clyellow);
	rectangle(x_hdsd+150,y,x_hdsd+250,y+40);
	outtextxy(x_hdsd+w_table/2-textwidth("THEM")/2,y+11,"THEM");
		
}
//  ----------
void table_huyltc(){
	table(x_hdsd,y_hdsd,w_table,h_hdsd*2/3);
	draw_rectangle(x_hdsd+w_table/2-50,y_hdsd+7,x_hdsd+w_table/2+50,y_hdsd+30,claqua);
	setbkcolor(claqua);
	outtextxy(x_hdsd+w_table/2-textwidth("HUY LTC")/2,y_hdsd+9,"HUY LTC");
	
	int y = y_hdsd+40;
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd+100-textwidth("Nien Khoa"),y+6,"Nien Khoa");
	rectangle(x_hdsd+105,y,x_hdsd+350,y+30);
	y+=40;
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd+100-textwidth("Hoc Ky"),y+6,"Hoc Ky");
	rectangle(x_hdsd+105,y,x_hdsd+350,y+30);
	y+=75;
	setbkcolor(clyellow);
	draw_rectangle(x_hdsd+150,y,x_hdsd+250,y+40,clyellow);
	rectangle(x_hdsd+150,y,x_hdsd+250,y+40);
	outtextxy(x_hdsd+w_table/2-textwidth("HUY")/2,y+11,"HUY"); 
}
// ----------------
void table_dangkyltc(){
	table(x_hdsd,y_hdsd,w_table,h_hdsd*2/3);
	draw_rectangle(x_hdsd+w_table/2-50,y_hdsd+7,x_hdsd+w_table/2+50,y_hdsd+30,claqua);
	setbkcolor(claqua);
	outtextxy(x_hdsd+w_table/2-textwidth("DANG KY LTC")/2,y_hdsd+9,"DANG KY LTC");
	int y = y_hdsd+40;
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd+100-textwidth("Ma Sinh Vien"),y+6,"Ma Sinh Vien");
	rectangle(x_hdsd+105,y,x_hdsd+350,y+30);
	y+=40;
	outtextxy(x_hdsd+100-textwidth("Nien Khoa"),y+6,"Nien Khoa");
	rectangle(x_hdsd+105,y,x_hdsd+350,y+30);
	y+=40;
	outtextxy(x_hdsd+100-textwidth("Hoc Ky"),y+6,"Hoc Ky");
	rectangle(x_hdsd+105,y,x_hdsd+350,y+30);
	y+=75;
	setbkcolor(clyellow);
	draw_rectangle(x_hdsd+150,y,x_hdsd+250,y+40,clyellow);
	rectangle(x_hdsd+150,y,x_hdsd+250,y+40);
	outtextxy(x_hdsd+w_table/2-textwidth("TIEP TUC")/2,y+11,"TIEP TUC"); 
}
//--------------
void table_xemdssv(){
	table(x_hdsd,y_hdsd,w_table,h_hdsd/2);
	draw_rectangle(x_hdsd+w_table/2-50,y_hdsd+7,x_hdsd+w_table/2+50,y_hdsd+30,claqua);
	setbkcolor(claqua);
	outtextxy(x_hdsd+w_table/2-textwidth("XEM DSSV")/2,y_hdsd+9,"XEM DSSV");
	int y = y_hdsd+40;
	setbkcolor(cllightwhite);
	outtextxy(x_hdsd+120-textwidth("Nhap Ma Lop TC"),y+6,"Nhap Ma Lop TC");
	rectangle(x_hdsd+125,y,x_hdsd+350,y+30);
	
	y+=75;
	setbkcolor(clyellow);
	draw_rectangle(x_hdsd+150,y,x_hdsd+250,y+40,clyellow);
	rectangle(x_hdsd+150,y,x_hdsd+250,y+40);
	outtextxy(x_hdsd+w_table/2-textwidth("XEM")/2,y+11,"XEM");	
}
