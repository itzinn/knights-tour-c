#include <stdio.h>
#include <stdlib.h>

/*
problema: dado as dimensoes de um tabuleiro, determinar se um cavalo,
inicialmente na primeira posicao do tabuleiro, é capaz de visitar todas
as posições do tabuleiro.
*/

void exibeTabuleiro(int **tab, int l, int c){
	for(int i=0; i<l; i++){
		for(int j=0; j<c; j++){
			printf("%4d", tab[i][j]);
		}
		printf("\n");
	}
}

int te(int **tab, int l, int c, int x, int y, int numC){

	if(numC == l*c){
		return 1;
	}

	//opcoes possiveis de movimentos
	int pulos[][2] = {{1,2},{-1,2},{1,-2},{-1,-2},
					  {2,1},{-2,1},{2,-1},{-2,-1}};

	//tenta realizar a tentativa e erro para cada pulo possivel
	for(int i=0; i<8; i++){
		int nx = x + pulos[i][0];
		int ny = y + pulos[i][1];

		//verifica se a posicao está disponivel
		if(nx < l && ny < c && nx >= 0 && ny >=0 && tab[nx][ny] == 0){
			tab[nx][ny] = numC + 1;
			
			//chama a recursiva
			int res = te(tab, l, c, nx, ny, numC+1);
			
			if(res)
				return 1;

			//voltou uma jogada para tentar uma alternativa
			tab[nx][ny] = 0;
		}
	}

	return 0;
}

int main(){

	//recebe dimensões
	int l, c;

	scanf("%d", &l);
	scanf("%d", &c);

	//aloca matriz l x c

	int **tab = (int **)malloc(l * sizeof(int *));
	for(int i=0; i<l; i++)
		tab[i] = (int *)malloc(c * sizeof(int));

	//exibe tabuleiro
	//exibeTabuleiro(tab, l, c);

	tab[0][0] = 1;

	if(te(tab, l, c, 0, 0, 1))
		exibeTabuleiro(tab, l, c);
	else
		printf("solucao nao existe");

	//free matrix
	for(int i=0; i<l; i++)
		free(tab[i]);
	free(tab);


	return 0;
}