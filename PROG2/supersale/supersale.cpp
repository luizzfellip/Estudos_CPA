#include <bits/stdc++.h>
using namespace std;

int mochilaPD(vector<pair<int,int>> lista_produtos,int W){
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
    return custo[n][W];
}

int main(){
    
    int casos;
    scanf("%d",&casos);
    for(int c=0;c<casos;c++){
        int produtos;
        scanf("%d",&produtos);
        vector<pair<int,int>> lista_produtos (produtos);

        for(int i=0;i<produtos;i++){
            int preco;
            int peso;
            scanf("%d %d",&lista_produtos[i].first,&lista_produtos[i].second);
        }

        int pessoas;
        scanf("%d",&pessoas);
        vector<int> familia (pessoas);
        for(int i=0;i<pessoas;i++){
            int preco;
            int peso;
            scanf("%d",&familia[i]);
        }

        int sum_total = 0;
        for(int i=0;i<familia.size();i++){
            sum_total += mochilaPD(lista_produtos,familia[i]);
        }
        printf("%d \n",sum_total);
    }

    return 0;
}

/*
    Tempo: O(G * N * W)
    Espaço: O(N * W)
*/