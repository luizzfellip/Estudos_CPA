#include <bits/stdc++.h>
using namespace std;

int cortePD(vector<int> &posicoes) {
    sort(posicoes.begin(), posicoes.end());
    int n = posicoes.size();
    vector<vector<int>> custo(n, vector<int>(n));

    // Intervalos sem cortes internos possuem custo zero.
    for (int tamanho = 2; tamanho < n; tamanho++) {
        for (int inicio = 0; inicio + tamanho < n; inicio++) {
            int fim = inicio + tamanho;
            custo[inicio][fim] = numeric_limits<int>::max();

            for (int corte = inicio + 1; corte < fim; corte++) {
                int novoCusto = posicoes[fim] - posicoes[inicio]
                              + custo[inicio][corte] + custo[corte][fim];
                custo[inicio][fim] = min(custo[inicio][fim], novoCusto);
            }
        }
    }

    return custo[0][n - 1];
}

int main() {
    int comprimento;
    while (scanf("%d", &comprimento) == 1 && comprimento != 0) {
        int cortes;
        if (scanf("%d", &cortes) != 1)
            return 0;
        vector<int> posicoes(cortes + 2);
        posicoes[0] = 0;
        posicoes[cortes + 1] = comprimento;

        for (int i = 1; i <= cortes; i++) {
            if (scanf("%d", &posicoes[i]) != 1)
                return 0;
        }

        printf("%d\n", cortePD(posicoes));
    }

    return 0;
}

/*
    Por caso, N representa o numero de cortes.
    Tempo:  O((N)^3)
    Espaço: O((N)^2)
*/
