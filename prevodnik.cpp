#include <iostream>
#include <String>
#include <map>
#include <iomanip>
#include <vector>

using namespace std;
vector<string> mapa_c = {'I', 'IV', 'V', 'IX', 'X', 'XL', 'L', 'LC', 'C', 'CD', 'D', 'DM', 'M'};
vector<int> mapa_i = {    1,    4};

const char tb_c[7] = {'I', 'V', 'X', 'L', 'C',  'D',  'M'   };
const int  tb_i[7] = { 1,   5,   10,  50,  100,  500,  1000};
const char tb_cs[6] = {'IV', 'IX',  'XL', 'LC', 'CD', 'DM'};
const char tb_is[6] = { 4,     9,    40,  90,   400,  900};

void Ciara(){
	cout<<"--------------------------"<<endl;
}

int velkost(int n){
	if(n >= 1000)
	{
		return 1000;
	}else if(n < 1000 && n >= 100){
		if(n%500==0){
			return 500;
		}else{
			return 100;			
		}
	}else if(n < 100 && n >= 10){
		if(n%50==0){
			return 50;
		}else{
			return 10;			
		}
	}else{
		if(n%5==0){
			return 5;
		}else{
			return 1;			
		}
	}
}

int najdiPoziciuCislaS(int n){
	int v = -1;
	for(int i = 0; i < 6; i++){
		if(tb_is[i] == n){
			v = i;
		}
	}	
	return v;
}

int najdiPoziciuCisla(int n){
	int v = -1;
	for(int i = 0; i < 7; i++){
		if(tb_i[i] == n){
			v = i;
		}
	}
	
	if(v == -1)
	{
		najdiPoziciuCislaS(n);
	}
	return v;	
}

string a_na_r(int n){
	string vysledok;
	
	int zvysok=n;
	
	while(true){
		if(n < 5){
			int pozCisla = najdiPoziciuCisla(tb_i[i]);
			for(int i = n; i >= 1; i--){
				if(v != -1){
					vysledok+=tb_c[pozCisla];					
				}else{
					vylsedok+=tb_cs[pozCisla];	
				}

			}
			break;			
		}
		
		for(int i = 6; i >= 0; i--){
			n=zvysok/tb_i[i];
			zvysok=zvysok%tb_i[i];
			
			cout<<"n: "<<n<<endl;
			cout<<"zvysok: "<<zvysok<<endl;
			
			int pozCisla = najdiPoziciuCisla(tb_i[i]);
			for(int i = n; i >= 1; i--){
				if(v != -1){
					vysledok+=tb_c[pozCisla];					
				}else{
					vylsedok+=tb_cs[pozCisla];	
				}
			}
		}
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
	
	int a_vstup;
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

