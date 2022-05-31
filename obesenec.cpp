#include <iostream>
#include <String>
#include <vector>

using namespace std;
using std::string;
using std::vector;

class Pismeno {
public:
    char p;
    bool uhadnute;
    Pismeno(char _p) {
        p = _p;
        uhadnute = false;
    }
};

void vypisCiaru() {
    cout << "---------------------------------" << endl;
}

bool skontrolujUhadnutePismeno(vector<char>& v_c, vector<Pismeno>& v_p, char& p) {
    bool flag = false;

    for (int i = 0; i < v_p.size(); i++) {
        if (p == v_p[i].p) {
            v_c.push_back(p);
            v_p[i].uhadnute = true;
            flag = true;
        }
    }

    return flag;
}

void vypisUhadnutePismena(vector<char> v_c) {
    cout << "Uhadnute pismena: ";
    for (int i = 0; i < v_c.size(); i++) {
        cout << v_c[i] << " ";
    }
    cout << endl;
}

void vypisPismena(vector<Pismeno> v_p) {
    for (int i = 0; i < v_p.size(); i++) {
        if (v_p[i].uhadnute == true) {
            cout << v_p[i].p << " ";
        }
        else {
            cout << "_ ";
        }
    }
    cout << endl;
    cout << endl;
}

void vypisObesenca(int n) {
    switch (n) {
    case 0:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 1:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 2:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << "  |   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 3:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|   |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 4:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << "      |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 5:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " /    |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    case 6:
        cout << "  +---+" << endl;
        cout << "  |   |" << endl;
        cout << "  O   |" << endl;
        cout << " /|\\  |" << endl;
        cout << " / \\  |" << endl;
        cout << "      |" << endl;
        cout << "=========" << endl;
        break;
    }
}

int main()
{
    string slovo = "";
    cout << "zadaj slovo ktore budu ostatny hadat: ";
    cin >> slovo;

    vector<Pismeno> v_pismena;
    vector<char> u_pismena;
    char pismeno;

    for (int i = 0; i < slovo.length(); i++) {
        Pismeno p = Pismeno(slovo[i]);
        v_pismena.push_back(p);
    }

    int pocet_pokusov = 0;
    do{
        vypisObesenca(pocet_pokusov);
        vypisPismena(v_pismena);
        vypisUhadnutePismena(u_pismena);
        
        if(u_pismena.size() == v_pismena.size()){
        	break;
		}

        cout << "zadaj pismeno: ";
        cin >> pismeno;

        if (skontrolujUhadnutePismeno(u_pismena, v_pismena, pismeno) == false) {
            pocet_pokusov++;
        }
        
        if(pocet_pokusov == 6){
        	vypisObesenca(pocet_pokusov);
        	cout<<"SLOVO: ";
        	for(int i = 0; i < v_pismena.size(); i++){
        		cout<<v_pismena[i].p<<" ";
			}
        	break;
		}
        
        vypisCiaru();
    } while (pocet_pokusov != 6);

    return 0;
}
