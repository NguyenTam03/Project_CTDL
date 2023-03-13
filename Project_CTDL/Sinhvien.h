#pragma once

#include "Const.h"

using namespace std;


struct SINHVIEN{
	string MASV;
	string HO;
	string TEN;
	string PHAI;
	string SODT;
	string MALOP;
	int namnhaphoc;
};

struct nodeSV{
	SINHVIEN info;
	nodeSV* next;
};
typedef nodeSV* PTR_SV;

/* 
******* DSSV******
*/
void Init(PTR_SV First) {
	First = NULL;
}

bool Empty(PTR_SV First) {
	return First == NULL;
}

void Insert_Head(PTR_SV First, SINHVIEN sv) {
	PTR_SV temp = new nodeSV;
	temp->info = sv;
	temp->next = First;
	First = temp;
}

int find_Pos(PTR_SV First, SINHVIEN sv) {
	int pos = 1;
	PTR_SV p = First;
	while(p != NULL && p->info.MALOP <= sv.MALOP) {
		if(p->info.MALOP == sv.MALOP) {
			while(p != NULL && p->info.TEN <= sv.TEN) {
				if(p->info.TEN == sv.TEN) {
					while(p != NULL && p->info.HO < sv.HO) {
						pos++;
						p = p->next;
					}
					return pos;
				}
				pos++;
				p = p->next;
			}
			return pos;
		}
		pos++;
		p = p->next;
	}
	return pos;
}

void add_SV(PTR_SV &First, SINHVIEN sv) {
	int add_pos = find_Pos(First, sv);
	if(First == NULL || add_pos == 1) {
		Insert_Head(First, sv);
		return;
	}
	int pos = 1;
	PTR_SV p = First;
	for(; p->next != NULL && pos < add_pos - 1; pos++, p = p->next);
	PTR_SV q = new nodeSV;
	q->info = sv;
	q->next = p->next;
	p->next = q;
}

int delete_SV(PTR_SV First, string masv) {
	if(First == NULL) return - 1;
	PTR_SV p, q;
	if(First->info.MASV == masv) {
		p = First;
		First = p->next;
		delete p;
		return 1;
	}
	for(p = First; p->next != NULL && p->next->info.MASV != masv; p = p->next);
	if(p->next->info.MASV == masv) {
		q = p->next;
		p->next = q->next;
		delete q;
		return 1;
	}
	return -1;
}

bool check_Trung(PTR_SV First, string masv) {
	if(First == NULL) return false;
	PTR_SV p = First;
	for(; p->next != NULL && p->info.MASV != masv; p = p->next);
	if(p->info.MASV == masv) {
		return true;
	}
	return false;
}

int count_SLSV(PTR_SV First) {
	int n = 0;
	for(PTR_SV p = First; p != NULL; n++, p = p->next);
	return n;
}

int search_SV(PTR_SV First, string masv) {
	int pos = 0;
	PTR_SV p = First;
	for(; p != NULL; pos++, p = p->next) {
		if(p->info.MASV == masv) {
			return pos;
		}
	}
	return -1;	
}

void free_DSSV(PTR_SV &First) {
	PTR_SV temp = NULL;
	while(First != NULL) {
		temp = First;
		First = temp->next;
		delete temp;
	}
}





