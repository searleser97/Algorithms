#include <bits/stdc++.h>
using namespace std;


int main(){
    string frase;
    int N;

    std::ios_base::sync_with_stdio(0); cin.tie(0);//que chingados es esto
    
    cin >> N;
    frase = input();
  
  cout << frase << endl;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < frase.size(); ++j)
        {
            if(frase[j] == 'a'){
                cout << "apa";
            }
            else{
                if(frase[j] == 'e'){
                    cout << "epe";
                }
                else{
                    if(frase[j] == 'i'){
                        cout << "ipi";
                    }
                    else{
                        if(frase[j] == 'o'){
                            cout << "opo";
                        }
                        else{
                            if(frase[j] == 'u'){
                                cout << "upu";
                            }
                            else{
                                cout << frase[i];
                            }
                        }
                    }
                }
            }
        }
        cout << "\n";
    }
    

    return 1;

}