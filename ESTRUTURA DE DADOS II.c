QUESTÃO 1
Existem várias formas de se implementar uma árvore binária. A mais simples delas é usar um vetor de nós. Dessa forma, cada nó possui pelo menos três valores: uma referência para o pai do nó, uma referência para o filho à esquerda do nó e mais uma outra referência para o filho à direita do respectivo nó. O atributo "pai" vai apontar para a posição na qual o pai do nó se encontra, no vetor. O atributo "esquerda" vai armazenar a posição da raiz da sub-árvore à esquerda do nó, e o atributo "direita" guarda a posição da raiz da sub-árvore direita do nó, no vetor. Além disso, é relevante estabelecer um atributo "dado" que irá armazenar o conteúdo do nó.
 
É possível adicionar algumas regras à inserção de dados em uma árvore para que ela se torne ordenada. Assim, sempre que um novo dado estiver para ser adicionado junto à árvore, ele será comparado com o nó raiz. Se ele é menor do que a raiz, deverá ser adicionado na sub-árvore esquerda, caso contrário na sub-árvore direita.
 
Considere que, no seu primeiro estágio, ao realizar um teste no seu programa que implementa árvores binárias, você inseriu os números de seu RA (da esquerda para a direita) como se cada algarismo fosse um nó na árvore. Dessa forma, altere o código-fonte dado para que seu programa, durante a execução, monte uma árvore binária a partir dos dígitos de seu RA. O seu programa não deve realizar a inserção automaticamente ordenada, ou seja, não é preciso desenvolver um método que realize a inserção ordenadamente. Você mesmo pode construir a árvore (via inserções simples, porém seguindo as regras de inserção ordenada), de maneira a compor a árvore ordenada com os números de seu RA. Além disso, você precisará criar uma função que seja capaz de realizar o percurso pré-ordem na árvore recém-criada, partindo da raiz e imprimindo na tela os nós visitados de acordo com esse método.
 
Por exemplo, considere que seu RA é igual a 61207895. Veja na figura abaixo como sua árvore ordenada deveria ser, bem como o resultado do caminhamento pré-ordem quando executado a partir da raiz da respectiva árvore:
 

 
Visitação pré-ordem: 6 1 0 2 7 5 8 9





#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int recebe;
    struct NO *esq;
    struct NO *dir;
    struct NO *pai;
} NO;

typedef struct ARVORE{
    NO *raiz;
}ARVORE;

ARVORE i;

void preOrdem(NO* raiz);
void arvore(ARVORE arvore)
{
    arvore.raiz = NULL;
}

void no(NO* n, int val){
    n->pai = NULL;
    n->esq = NULL;
    n->dir = NULL;
    n->recebe = val;
}

void noArvoreRa(int valor)
{
    NO* sequencia = i.raiz;
    NO* pai;

    NO* novoNo = (NO*) malloc(sizeof(NO));
    no(novoNo, valor);

    if(sequencia == NULL)
    {
        i.raiz = novoNo;
        return;
    }

    while(sequencia){
        pai = sequencia;
        if(novoNo->recebe < sequencia->recebe){
            sequencia = sequencia->esq;
            if(!sequencia){
                pai->esq = novoNo;
                return;
            }
        }
        else{
            sequencia = sequencia->dir;
            if(!sequencia){
                pai->dir = novoNo;
                return;
            }
        }
    }
}

void preOrdem(NO* raiz){
    if(raiz){
        printf("%d \t", raiz->recebe);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
    }
}

int main()
{

    arvore(i);

    noArvoreRa(2);
    noArvoreRa(0);
    noArvoreRa(1);
    noArvoreRa(1);
    noArvoreRa(9);
    noArvoreRa(1);
    noArvoreRa(2);
    noArvoreRa(8);
    noArvoreRa(5);

    printf("\nBusca pela Arvore, visitacao em pre ordem: \n");
    preOrdem(i.raiz);
}

