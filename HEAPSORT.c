#include<stdio.h>
#include<stdlib.h>

#define troca (A, B) {int t = A; A = B; B = t;} 

int vector[10], trocaHeap=0, trocaMerge=0, trocaSelection=0;

int constroiHeap(int v[], int m)
{
	int i, x;
	
	for(i = m/2; i>=0; i--)
	{
		peneirar(v, i, m-1);
	}
	
	for(i = m-1; i>=1; i--)
	{
		x = v[0];
		v[0] = v[i];
		v[i] = x;
		trocaHeap=trocaHeap+1;
		peneirar(v, 0, i-1);
	}

	system("cls");
	
	printf("***************Vetor HEAPSORTeado***************");
	for(i=0; i<10;i++)
	{
		printf("\n\n%d", v[i]);
	}
}

int peneirar(int v[], int raiz, int fundo)
{
	int p, fm, t;
	
	p = 0;
	
	while((raiz*2 <= fundo) && (!p))
	{
		if(raiz*2 == fundo)
		{
			fm = raiz*2;
		}
		
		else if(v[raiz*2] > v[raiz*2 + 1])
		{
			fm = raiz*2;
		}
		
		else
		{
			fm = raiz*2 + 1;
		}
		
		if(v[raiz] < v[fm])
		{
			t = v[raiz];
			v[raiz] = v[fm];
			v[fm] = t;
			raiz = fm;
			trocaHeap=trocaHeap+1;
		}
		
		else
		{
			p = 1;
		}
	}
}

int mergesort(int v[], int n) 
{
	int i;
	int *c = malloc(sizeof(int) * n);
	sort(v, c, 0, n - 1);
	
	for(i=0; i<10; i++)
	{
		printf("\n%d\n", v[i]);	
	}
	getch();

	
	free(c);
	


}

int sort(int v[], int *c, int i, int f) 
{

	if (i >= f)
	{
		return;
	}
	
	int m = (i + f) / 2;
	sort(v, c, i, m);
	sort(v, c, m + 1, f);
	
	if (v[m] <= v[m + 1]) 
	{
		return;	
	}
	
	merge(v, c, i, m, f);

}


int merge(int v[], int *c, int i, int m, int f) 
{	

  	int z, iv = i, ic = m + 1;

  	for (z = i; z <= f; z++) 
  	{
  		c[z] = v[z];
	  	
  	}

  	z = i;

	while (iv <= m && ic <= f) 
	{

    	if (c[iv] < c[ic]) 
		{
			v[z++] = c[iv++];
			trocaMerge=trocaMerge+1;	
		}

    	else /* if (c[iv] > c[ic]) */ 
		{
			v[z++] = c[ic++];
			trocaMerge=trocaMerge+1;
		}

  	}	

	while (iv <= m) 
	{
		v[z++] = c[iv++];
		trocaMerge=trocaMerge+1;	
	};



	while (ic <= f)
	{
		v[z++] = c[ic++];	
		
	} 
	
	
}

int selectionSort (int vetor[],int max) 
{
	int i, j, min, aux;
  
  	for (i = 0; i < (max - 1); i++) 
	{
    	// "min" representa o índice do primeiro número, não ordenado ainda.
    	min = i;
    	for (j = i+1; j < max; j++) 
		{
     		// Caso tenha algum numero menor que o número da posição "min", ele faz a troca do minimo
      		if (vetor[j] < vetor[min]) 
			{
   				min = j;
      		}
    	}
    /* Se a menor posição não for a de "i",é feita a troca para ordena-los*/
    	
		if (i != min) 
		{
      		aux = vetor[i];
      		vetor[i] = vetor[min];
      		vetor[min] = aux;
      		trocaSelection = trocaSelection + 1;
    	}
  	}
  	
	for(i=0; i<10; i++)
	{
		printf("\n%d\n", vetor[i]);		
	}
}


int main()
{
	int i;
	
	for(i=0; i<10; i++)
	{
		printf("****************Construindo um vetor****************\n\n");
		printf("Digite um valor para o vetor:\n");
		scanf("%d", &vector[i]);
		
		system("cls");
		
	}
	
	printf("****************Heap Sort****************");
		
	constroiHeap(vector, 10);
	
	getch();
	system ("cls");
	
	for(i=0; i<10; i++)
	{
		printf("****************Construindo um vetor****************\n\n");
		printf("Digite um valor para o vetor:\n");
		scanf("%d", &vector[i]);
		
		system("cls");
		
	}
	
	printf("****************Merge Sort****************");
	mergesort(vector, 10);

	getch();

	system ("cls");	
	
	for(i=0; i<10; i++)
	{
		printf("****************Construindo um vetor****************\n\n");
		printf("Digite um valor para o vetor:\n");
		scanf("%d", &vector[i]);
		system("cls");
	}
	
	printf("****************Selection Sort****************");
	selectionSort(vector, 10);	
	getch();
	system ("cls");
	

	
	getch();
	
	system("cls");
	

	
	
	printf("****************** RESULTADOS 'COMPARANDO TROCAS'*****************");
 	
  	printf("\n\n\nQuantidade de trocas do Heap Sort:\n%d\n\n", trocaHeap);
  	printf("Quantidade de trocas do Merge Sort:\n%d\n\n", trocaMerge);
  	printf("Quantidade de trocas do Selection Sort:\n%d\n\n", trocaSelection);
  	
  
	getch();

	return(0);
}


