#pragma once
#include "Const.h"
#include "Sinhvien.h"

struct LopSV{
	string MALOP;
	PTR_SV First_dssv;
	int soluongsv = 0;
};

struct DS_LopSV{
	int n = 0;
	LopSV *lopsv;
};

bool isNull_LopSV(DS_LopSV dslsv) {
	return dslsv.n == 0;
}

bool isFull_LopSV(DS_LopSV dslsv) {
	return dslsv.n == MAX_LOPSV;
}

// them lop sinh vien
int add_LSV(DS_LopSV &dslsv, string malop) {
	if(isFull_LopSV(dslsv)) return -1;
	int pos = 0;
	for(; pos < dslsv.n; pos++) {
		if(dslsv.lopsv[pos].MALOP > malop) break;
		if(dslsv.lopsv[pos].MALOP == malop) return 2; // malop trung
	}
	for(int i = dslsv.n; i > pos; i--) {
		dslsv.lopsv[i] = dslsv.lopsv[i - 1];
	}
	dslsv.lopsv[pos].MALOP = malop;
	dslsv.lopsv[pos].First_dssv = NULL;
	dslsv.n++;
	return 1;
}

//tim lop sinh vien
int search_LSV(DS_LopSV dslsv, string malop) {
	if(isNull_LopSV(dslsv)) return -1;
	for(int i = 0; i < dslsv.n; i++) {
		if(dslsv.lopsv[i].MALOP == malop) return i;
	}
	return -1;
}

int searchSV_LopSV(DS_LopSV dslsv, SINHVIEN SV) {
	for(int i = 0; i < dslsv.n; i++) {
		if(search_SV(dslsv.lopsv[i].First_dssv, SV.MASV) != -1) {
			return i;
		}
	}
	return -1;
}

// doc ghi file lop sinh vien, danh sach sinh vien
void readFile_LopSV(DS_LopSV &dslsv) {
	ifstream filein;
	filein.open("D:\\QUAN_LI_SINH_VIEN\\data\\DSLSV.txt", ios::in);
	if(filein.is_open()) {
		string s;
		int kq;
		while(!filein.eof()) {
			getline(filein, s, '\n');
			if(s == "") break;
			kq = add_LSV(dslsv, s);
		}
	}else {
		cout << "\nKHONG TIM THAY FILE LOP SINH VIEN";
	}
	filein.close();
}

void readFile_DSSV(DS_LopSV &dslsv) {
	ifstream filein;
	filein.open("data\\DSSV.txt", ios::in);
	if(filein.is_open()) {
		string s;
		int temp;
		while(!filein.eof()) {
			SINHVIEN info;
			getline(filein, s, ',');
			info.MASV = s;
			getline(filein, s, ',');
			info.HO = s;
			getline(filein, s, ',');
			info.TEN = s;
			getline(filein, s, ',');
			info.PHAI = s;
			getline(filein, s, ',');
			info.SODT = s;
			getline(filein, s, ',');
			info.MALOP = s;
			filein >> temp;
			info.namnhaphoc = temp;
			int pos_lop = search_LSV(dslsv, info.MALOP);
			if(pos_lop != -1) {
				add_SV(dslsv.lopsv[pos_lop].First_dssv, info);
				
				dslsv.lopsv[pos_lop].soluongsv++;
			}
		}
	}else {
		cout << "\nKHONG TIM THAY FILE LOP SINH VIEN";
	}
	filein.close();
}


void writeData_LopSV(ofstream &fileout, LopSV lopsv) {
	fileout << lopsv.MALOP;
	fileout << '\n';
}

void writeDataDS_LopSV(DS_LopSV dslsv) {
	ofstream fileout;
	fileout.open("data\\SaveDSLSV.txt");
	if(fileout.is_open()) {
		for(int i = 0; i < dslsv.n; i++) {
			writeData_LopSV(fileout, dslsv.lopsv[i]);
		}
	}
	fileout.close();
}

