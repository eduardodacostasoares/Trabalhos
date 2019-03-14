#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	
    char nome[100];
    int mat;
    float media;
    
} aluno;

aluno estudante[3];

typedef struct tree
{
	char name[100]; //nome do aluno
	int matri; //matricula
	float m; //media
	struct tree* esq;
    struct tree* dir;
}Tree;

Tree* construirArvore()
{
	return NULL;
}

int vazioVer(Tree* t)
{
	return t == NULL;
}

void inserirVal(Tree** t, int matri, char* name[], float m) //PODE DAR ERRO, NO CASO, VERIFICAR DE RETIRAR O CONST OU O "*".
{
	if(*t == NULL)
	{
		*t = (Tree*)malloc(sizeof(Tree));
		(*t)->esq = NULL;
		(*t)->dir = NULL;
		(*t)->matri = matri;
		(*t)->m = m;
		strcpy((*t)->name[100], name[100]); //ATENÇÃO PODE DAR ERRO!!!! Verificar possibilidade de tirar os termos "CHAR".
	}
	
	else
	{
		if(matri < (*t)->matri)
		{
			inserirVal(&(*t)->esq, matri, name[100], m);
		}
		
		if(matri > (*t)->matri)
		{
			inserirVal(&(*t)->dir, matri, name[100], m);
		}
	}
}

int busca(Tree* t, int matri)
{
	if(vazioVer(t))
	{
		return(0); //Retorna 0, se a árvore estiver vazia.
	}
	
	if(t->matri > matri)
	{
		return busca(t->esq, matri);
	}
	else
	{
		return busca(t->dir, matri);
	}
}
int main()
{
	int i, j, inf, sup, meio, aux;
	char aux1[100];
	float aux2;
	setlocale(LC_ALL, "Portuguese");
	
	for(i=0; i<3; i++)
	{
		strcpy(estudante[i].nome, "NULL");
		estudante[i].mat = 0;
		estudante[i].media = 0.0;
	}
	
	
	for(i=0; i<3; i++)
	{
		printf("********************CADASTRO DOS ALUNOS********************");
		
		printf("\n\n\n\n\nDigite o nome do estudante:\n ");
		fgets(estudante[i].nome, 100, stdin);
		
		printf("\n\n\nDigite matrícula do estudante:\n ");
		scanf("%d", &estudante[i].mat);
		
		printf("\n\n\nDigite o valor da média do aluno:\n");
		scanf("%f", &estudante[i].media);
		
		fflush(stdin);
		system("cls");
	}
	
	for(i=0; i<3;i++)
	{
		inf = i;
			
		for(j=i+1; j<3; j++)
		{
			if(estudante[j].mat < estudante[inf].mat)
			{
				
				inf = j;
					
			}
		}

		
		aux = estudante[inf].mat;
		estudante[inf].mat = estudante[i].mat;
		estudante[i].mat = aux;	
		
		
  		strcpy(aux1, estudante[inf].nome);
		strcpy(estudante[inf].nome, estudante[i].nome);
		strcpy(estudante[i].nome, aux1);
		
		
		aux2 = estudante[inf].media;
		estudante[inf].media = estudante[i].media;
		estudante[i].media = aux2;

	}
	
	printf("********************ORDENAÇÃO DOS ALUNOS********************");
	for(i=0; i<3; i++)
	{
		printf("\n\n\nALUNO: %s\n", estudante[i].nome);
		printf("\nMatricula: %d\n", estudante[i].mat);
		printf("\nMedia: %.1f\n", estudante[i].media);
	}
	
	getch();
	
	fflush(stdin);
	system("cls");
	
	inf = 0;
	sup = 2;
	aux=0;
	
	printf("********************BUSCA BINÁRIA********************");	
	printf("\n\n\n\nDigite a matrícula a ser buscada: \n");
	scanf("%d", &j);
	
	while (inf <= sup)
    {
        meio = (inf + sup)/2;
        if (j == estudante[meio].mat)
        {
        	aux=1;
        	break;
		}
		    
        
		if (j < estudante[meio].mat)
        {
        	sup = meio-1;
		}
            
        else
        {        
			inf = meio+1;
		}    
    }
	
	
	printf("A matricula foi encontrada no campo %d.\n\n\n", meio+1);
	printf("ALUNO:\n%s\n", estudante[meio].nome);
	printf("Matrícula:\n%d\n\n", estudante[meio].mat);
	printf("Média:\n%f\n\n", estudante[meio].media);
	
	getch();
	system("cls");
	
	printf("********************BUSCA SEQUENCIAL********************");
	
	inf = 0;
	printf("\n\n\n\nDigite a matrícula a ser buscada: \n");
	scanf("%d", &j);
	
	for(i=0; i<3; i++)
	{
		if(estudante[i].mat == j) 
		{
			inf = 1; //reaproveitando variáveis "inf" (como um "achou")
			
			sup = i;
		}
	}
	
	if(inf == 1)
	{
		printf("Matrícula encontrada na posição %d da lista.\n\n\n\n", sup+1);
		printf("ALUNO:\n%s\n\n", estudante[sup].nome);
		printf("Matrícula:\n%d\n\n", estudante[sup].mat);
		printf("Média:\n%f\n\n", estudante[sup].media);
	}
	
	getch();
	
	fflush(stdin);
	system("cls");
	
	
	printf("********************ÁRVORE BINÁRIA DE BUSCA********************");	
	
	aux = estudante[1].mat;
	strcpy(aux1, estudante[1].nome);
	aux2 = estudante[1].media;
	
	Tree* t = construirArvore();
	
	inserirVal(&t, aux, aux1, aux2);
	
	
	
	printf("\n\n\n\n\n\nDigite a matricula que deseja buscar:\n");
	scanf("&d", &inf);
	
	if(busca(&t, inf)) 
	{
		printf("O aluno está cadastrado.");
	}
	else
	{
		printf("Aluno não cadastrado.");
	}
	
	
	
	return(0);
}


