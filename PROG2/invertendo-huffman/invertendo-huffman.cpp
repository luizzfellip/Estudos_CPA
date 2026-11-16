#include <bits/stdc++.h>
using namespace std;

long long tamanhoMinimo(const vector<int> &comprimentos) {
    int maiorComprimento = *max_element(comprimentos.begin(), comprimentos.end());
    vector<vector<long long>> pesos(maiorComprimento + 1);

    for (int comprimento : comprimentos) {
        pesos[comprimento].push_back(1);
    }

    long long ultimoPeso = 1;
    for (int nivel = maiorComprimento; nivel > 0; nivel--) {
        // Folhas novas precisam pesar pelo menos o ultimo no removido.
        // Os nos internos ja satisfazem esse limite pelas somas anteriores.
        for (long long &peso : pesos[nivel]) {
            peso = max(peso, ultimoPeso);
        }
        sort(pesos[nivel].begin(), pesos[nivel].end());

        // A entrada garante uma arvore valida: cada nivel tem pares de nos.
        for (int i = 0; i < (int)pesos[nivel].size(); i += 2) {
            long long primeiroPeso = pesos[nivel][i];
            long long segundoPeso = pesos[nivel][i + 1];
            pesos[nivel - 1].push_back(primeiroPeso + segundoPeso);
            ultimoPeso = segundoPeso;
        }
    }

    return pesos[0][0];
}

int main() {
    int caracteres;
    while (scanf("%d", &caracteres) == 1 && caracteres != 0) {
        vector<int> comprimentos(caracteres);

        for (int i = 0; i < caracteres; i++) {
            if (scanf("%d", &comprimentos[i]) != 1)
                return 0;
        }

        printf("%lld\n", tamanhoMinimo(comprimentos));
    }

    return 0;
}

/*
    Por caso, N representa o numero de caracteres e L o maior comprimento.
    Tempo:  O(N log N + L)
    Espaço: O(N + L)
*/
