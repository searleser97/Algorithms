#include <bits/stdc++.h>
using namespace std;
typedef long long int Long;

int main(){

	Long N;
	int K;
	int izq,der,n;

	ios_base::sync_with_stdio(0);
	

	while(cin >> N >> K){
		int n = 0 ;
		for(; (1LL << n) <= N ; n++);
		
		if(K >= n){
			cout << (1LL << K) -1LL << '\n';
		} else {
			int izq = 0 , der = K-1 , cuenta = 0;
			for(int i = 0 ; i < K ; i ++){
				if(N&(1LL << i)) cuenta ++;				
			}			

			Long menor = 1LL << 60 , act;

			while(der < n ){				
				if(cuenta == K ){
					menor = N;
					break;
				} else {
					act = (N&~((1LL<<(der+1))-1LL)) + (((1LL << (der+1))-1LL)&~((1LL << izq)-1LL));
					if(act >= N )
						menor = min(act,menor);
				}				
				if(N&(1LL << izq)) cuenta--;
				izq++;
				der++;
				if(N&(1LL << der)) cuenta++;
			}

			cout << menor << '\n';

		}
		
		
	}

	return 0;
}