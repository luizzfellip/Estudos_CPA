#include <bits/stdc++.h>
using namespace std;

vector<int> mochilaPD(const vector<pair<int,int>> &lista_produtos,int W){
    int n = lista_produtos.size();
    vector<vector<int>> custo(n+1,vector<int>(W+1)); // adiciona +1 para considerar peso/itens = 0
    
    for(int i=1; i<=n; i++){
        int preco = lista_produtos[i-1].first; // tem o -1 pq adicionamos +1 peso/item
        int peso = lista_produtos[i-1].second;

        for(int j=1; j<=W; j++){
            if(peso > j)
                custo[i][j] = custo[i-1][j];
            else
                custo[i][j] = max(
                    custo[i-1][j],
                    preco + custo[i-1][j-peso]
                    );
        }
    }
    return custo[n];
}

int main(){
    
    int casos;
    scanf("%d",&casos);
    for(int c=0;c<casos;c++){
        int produtos;
        scanf("%d",&produtos);
        vector<pair<int,int>> lista_produtos (produtos);

        for(int i=0;i<produtos;i++){
            scanf("%d %d",&lista_produtos[i].first,&lista_produtos[i].second);
        }

        int pessoas;
        scanf("%d",&pessoas);
        vector<int> familia (pessoas);
        int maior_capacidade = 0;

        for(int i=0;i<pessoas;i++){;
            scanf("%d",&familia[i]);
            maior_capacidade = max(maior_capacidade,familia[i]);
        }
        
        vector<int> melhores = mochilaPD(lista_produtos,maior_capacidade);
        
        int sum_total = 0;
        for(int capacidade : familia){
            sum_total += melhores[capacidade];
        }

        printf("%d\n",sum_total);

    }

    return 0;
}

/*
    Tempo: O(G + N * W)
    Espaço: O(N * W)
*/