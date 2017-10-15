
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

struct nodo {
    int cubeta[2];
    int cuantos;
};

int n, m = 1, l;
nodo trie[10000002];
char palabra[202];

void meter(int l) {
    int pos = 1;
    for (int i = 0; i < l; i++) {
        int letra = (palabra[i] - '0');
        if (trie[pos].cubeta[letra] == 0) {
            trie[pos].cubeta[letra] = ++m;
        }
        pos = trie[pos].cubeta[letra];
        trie[pos].cuantos++;
    }
}

int mayor;

void recorre(int pos, int cont) {
    if (cont * trie[pos].cuantos > mayor) {
        mayor = cont * trie[pos].cuantos;
    }
    if (trie[pos].cubeta[0] != 0) {
        recorre(trie[pos].cubeta[0], cont + 1);
    }
    if (trie[pos].cubeta[1] != 0) {
        recorre(trie[pos].cubeta[1], cont + 1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", palabra);
        l = strlen(palabra);
        meter(l);
    }
    recorre(1, 0);
    printf("%d\n", mayor);
    return 0;
}