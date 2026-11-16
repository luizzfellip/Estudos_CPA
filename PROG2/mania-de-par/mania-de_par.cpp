#include <bits/stdc++.h>
using namespace std;

int main() {
    int c, v;
    if (scanf("%d %d", &c, &v) != 2)
        return 0;

    vector<vector<pair<int, int>>> grafo(c + 1);

    for (int i = 0; i < v; i++) {
        int a, b, peso;
        scanf("%d %d %d", &a, &b, &peso);
        grafo[a].push_back({b, peso});
        grafo[b].push_back({a, peso});
    }

    const long long INF = numeric_limits<long long>::max();
    // Paridade 0: quantidade par de pedagios; paridade 1: impar.
    vector<array<long long, 2>> dist(c + 1, {INF, INF});
    using Estado = tuple<long long, int, int>; // custo acumulado, cidade, paridade
    priority_queue<Estado, vector<Estado>, greater<Estado>> fila;

    dist[1][0] = 0;
    fila.push({0, 1, 0});

    while (!fila.empty()) {
        auto [custo, cidade, paridade] = fila.top();
        fila.pop();

        // Uma entrada antiga pode permanecer na fila apos uma melhoria.
        if (custo != dist[cidade][paridade])
            continue;

        if (cidade == c && paridade == 0)
            break;

        for (auto [vizinha, peso] : grafo[cidade]) {
            int novaParidade = 1 - paridade;
            long long novoCusto = custo + peso;

            if (novoCusto < dist[vizinha][novaParidade]) {
                dist[vizinha][novaParidade] = novoCusto;
                fila.push({novoCusto, vizinha, novaParidade});
            }
        }
    }

    printf("%lld\n", dist[c][0] == INF ? -1LL : dist[c][0]);

    return 0;
}

/*
    Tempo:  O((C+V) log(C+V))
    Espaço: O(C + V)
*/