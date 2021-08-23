//Matheus L e Marina
 #include <iostream>
 #include <list>
 using namespace std;
 #include "lampada.h"

int main() {
    int n, estado,ligadas, m, i;
    Lampada *pontlamp;
    list<Lampada> lista;
    cout << "Quantos lampadas?\n";
    cin >>  n;
    for(int cont=0;cont<n;cont++){
        cout << "Qual o estado da lampada " << cont +1 << "?\n(-1=queimada, 0=desligada, 1=ligada)\n";
        cin >> estado;
        pontlamp = new Lampada;
        if(estado==1)pontlamp->ligar();
            else if (estado==0)pontlamp->desligar();
                else pontlamp->queimar();
        lista.push_back(*pontlamp); // Aqui
    }
    list<Lampada>::iterator lit;
    estado=0;
    int cont=1;
    cout << "\n";

    while(true){
        for(lit=lista.begin();lit!=lista.end();lit++){
            estado=lit->getEstado();
            cout << "\nO estado atual da lampada "<< cont <<" e:\n";
            if(estado==1){cout<<"Ligado\n";ligadas++;}
                else if (estado==0)cout<<"Desligado\n";
                    else cout << "Queimado\n";
            cont ++;
        }

        if(1+n/2==ligadas){
            for(lit=lista.begin();lit!=lista.end();lit++){
            lit->queimar();
            }
           break;
        }

        cout << "Escolha uma lampada(Existem " << n << " lampadas):\n";
        cin >> m;
        estado=0;
        i=0;

        for(lit=lista.begin();lit!=lista.end();lit++){
            i++;
            if(i==m){cout << "3=Queima, 2=Desliga, 1=Liga";cin >> estado;}
                else if(estado==1)pontlamp->ligar();
                    else if (estado==2)pontlamp->desligar();
                        else pontlamp->queimar();
        }
    }
        for(lit=lista.begin();lit!=lista.end();lit++){
            lit->getEstado();
        }
}
