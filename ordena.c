# include <stdio.h>
# include <stdlib.h>
# include <time.h>

//Imprime o Vetor.
void Imprime(int *v,int a) {
	int i;
    for (i = 0; i < a; i++){
    	printf("%d\n",v[i]);	
    } 
	
}

//Troca os dois valores de posição
void Troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Ordena por Seleção
void Selecao(int *v, int tam) {
    int i, j, min;
    for(i=0; i<tam-1; i++) {
    	min = i;
//For para achar o minimo dentro do vetor não ordenado
    	for(j=i+1; j<tam; j++) {
	    	if (v[j] < v[min]) {
	    		min=j;
	    	}
    	}
//Chamada da função de Troca, para trocar o mínimo pelo primeiro elemento do vetor
    Troca(&v[min], &v[i]);
    }
}

/* Pega o primeiro valor do vetor como pivo, e organiza os elementos menores
    que ele para seu lado esquerdo e os maiores para seu lado direito.*/
int Particiona(int *v, int p, int q){
    int pivo = v[p];    // Pivo
    int i = p ;  // Indice dos elementos menores
    int j;
    for (j = p+1; j <= q; j++){
    // Se o elemento atual é maior ou igual ao pivo
	    if (v[j] <= pivo){
		    i++;    // Incrementa o indice para os elementos menores
		    Troca(&v[i], &v[j]);// Chama função Troca
	    }
    }
    Troca(&v[i], &v[p]);// Chama função Troca
    return (i);
}
 /* Função de ordenação, onde vetores de tamanho menor que k são ordenados pelo método de oredenação por Seleção
    e vetores de tamanho maior ou igual a k pelo método QuickSort*/
void QuickSelect(int *v, int a, int b){
	int k = 12;
    if (a < b) {
	    if (b-a+1<k){
	    	Selecao(v,b);
    	}
    else{
    int m = Particiona(v, a, b);
    QuickSelect(v, a, m - 1);
    QuickSelect(v, m + 1, b);}

    }
}
//Imprime o tempo que levou pra executar o algoritmo
void imprime_tempo ( clock_t tini , clock_t tfim ) {
	printf (" Tempo = %2.5f segundos \n",
	(( double ) ( tfim - tini ) / (( double ) CLOCKS_PER_SEC ) ) ) ;
}
	clock_t tini , tfim ;
int main() {
	clock_t t; //variável para armazenar tempo
	float tempo;
    int tam, i = 1;
    int *v;
 /*Alocação e preenchimento do vetor a ser ordenado.*/
    v = malloc (i + sizeof(int));
    v[0] = 0;
    while (scanf("%d",&v[i-1]) != EOF) {
	    ++i;
	    v = (int*) realloc(v, i * sizeof(int));
    }
    --i; --i;
    tam = i+1;
 	tini = clock ();
    QuickSelect(v, 0, tam);
    //Impressão do vetor ordenado
    Imprime(v,tam);
 //imprime o tempo na tela
    tfim = clock ();
    imprime_tempo (tini, tfim );

}
