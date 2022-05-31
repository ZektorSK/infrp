#include <iostream>
#include <String>
#include <map>
#include <iomanip>

using namespace std;

const char tb_c[7] = {'I', 'V', 'X', 'L', 'C',  'D',  'M'   };
const char tbi_c[7]= {'1', '5', '10','50','100','500','1000'};
const int  tb_i[7] = { 1,   5,   10,  50,  100,  500,  1000};

void Ciara(){
	cout<<"--------------------------"<<endl;
}

string a_na_r(string n){
	string vysledok = "";
	
	int d = n.length();
	for(int i = 0; i < d; i++){
		
	}
	
	return vysledok;
}

int najdiPoziciuPismena(char c){
	for(int i = 0; i < 7; i++){
		if(tb_c[i] == c){
			return i;
		}
	}
}

int r_na_a(string s){
	int d = s.length();
	int vysledok = 0;
	
	for(int i = d; i > 0; i--)
	{
		char pismeno = s[i-1];
		int i_pismeno = najdiPoziciuPismena(pismeno);
		
		if(i-1 > 0){
			char pismenoZA = s[i-2];
			int i_pismenoZA = najdiPoziciuPismena(pismenoZA);
			
			//specialny pripad
			if(pismeno == 'X' && pismenoZA =='I'){
				i--;
				vysledok += 9;
			} else if(pismeno == 'C' && pismenoZA == 'L'){
				i--;
				vysledok += 90;
			} else if(pismeno == 'M' && pismenoZA == 'D'){
				i--;
				vysledok += 900;
			}
			
			else if(i_pismenoZA == najdiPoziciuPismena(tb_c[i_pismeno-1])){
				vysledok += tb_i[i_pismeno]-tb_i[i_pismenoZA];
				i--;
			}
			else{
				vysledok += tb_i[i_pismeno];
			}
		}else{
			vysledok += tb_i[i_pismeno];
		}
	}
	
	return vysledok;
}

int main()
{
	cout<<"chces zadat rimske (r) alebo arabske (a) ?: r/a"<<endl;
	char k;
	cin>>k;
	
	Ciara();
	
	string a_vstup;
	string r_vstup;
	switch(k)
	{
		case 'a':
			cout<<"zadaj cele arabske cislo: ";
			cin>>a_vstup;
		 	cout<<endl;
			
			cout<<"Arabske cislo:"<<setw(8)<<a_vstup<<endl;
			cout<<"Rimske cislo :"<<setw(8)<<a_na_r(a_vstup)<<endl;
			
			break;
		case 'r':
			cout<<"zadaj rimske cislo: ";
			cin>>r_vstup;
			cout<<endl;
			
			cout<<"Rimske cislo :"<<setw(8)<<r_vstup<<endl;
			cout<<"Arabske cislo:"<<setw(8)<<r_na_a(r_vstup)<<endl;
			break;
		default:
			cout<<"nespravny udaj!"<<endl;
			cout<<"stlac hocijaku klavesu na ukoncenie tohto programu: ";
	}
	
    return 0;
}

