#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>

#define VETOR 50

int vetor[VETOR];

void menu(void){
	printf("\n Um programa do caralho! \n\n");
	printf("    (01) Listar todos os numeros contidos no array \n");
	printf("    (02) Listar somente os numeros pares \n");
	printf("    (03) Listar somente os numeros impares \n");
	printf("    (04) Listar somente os numeros primos \n");
	printf("    (05) Calcular e imprimir o somatorio de todos os numeros \n");
	printf("    (06) Calcular e imprimir a media aritmetica de todos os numeros \n");
	printf("    (07) Imprimir a quantidade de numeros iguais a um dado numero \n");
	printf("    (08) Imprimir a primeira ocorrencia de um dado numero do array \n");
	printf("    (09) Imprimir a ltima ocorrencia de um dado numero do array \n");
	printf("    (10) Imprimir o maior numero contido no array \n");
	printf("    (11) Imprimir o menor numero contido no array \n");
	printf("    (12) Gerar novos numeros para o array \n");
	printf("    (00) Finalizar o programa \n");
	printf(" Escolha uma opcao acima digitando o numero \n \n");
}

//Logicas para os modulos, começo

void vetorVazio(void){

	printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();
	return;

}

void impLoopParOuImpar(bool par){

	int parOuImpar;

	
	for(int i=0; i < VETOR; i++){
		parOuImpar = vetor[i] %2;
		if( parOuImpar == 0 && par == true){
			printf("%d : %d \n", i, vetor[i]);
		}
		if( parOuImpar == 1 && par == false){
			printf("%d : %d \n", i, vetor[i]);
		}
	}

}

void pausa(void){

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();

}

char vetorNumeroPosicaoImp(void){
	char arraynumero, arrayposicao;

	printf("Deseja que a posicao da array seja mostrada ?\n\n");
	printf("Apere 1 para sim ou qualquer outro botao para nao\n");
	arraynumero = getch();
	return arraynumero;
}

char vetorPosicaoImp(void){
	char arraynumero, arrayposicao;


	printf("Deseja que seja emprimido na vertical ou horizontal ?\n\n");
	printf("Apere 1 para vertical ou qualquer outro botao para horizontal\n");
	arrayposicao = getch();
	return arrayposicao;
}

void impVetorLogica (char numeros, char lados){

	if(numeros == '1' && lados == '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d : %d \n ", i, vetor[i]);
		}
	}
	if(numeros != '1' && lados == '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d \n ", vetor[i]);
		}
	}
	if(numeros == '1' && lados != '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d : %d , ", i, vetor[i]);
		}
	}
	if(numeros != '1' && lados != '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d , ", vetor[i]);
		}
	}
}

bool primosLogica (void){
	int primo=0,contador=0;
	bool nenhum = true;
	for(int i = 0; i < VETOR; i++){
		contador = 0;
		for(int l = 1; l <= vetor[i]; l++){
			primo = vetor[i] % l;
			if(primo == 0){
				contador++;
			}
			if(contador == 3){
				break;
			}
		}
		if(contador == 2){
			printf("%d : %d \n", i, vetor[i]);
			nenhum = false;
		}
	}
	return nenhum;
}
//Logicas para os modulos, Fim.


//Opcoes do menu abaixo

void impVetor(void){

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	char arrayCharacter, VertiOuHorizon;

	arrayCharacter = vetorNumeroPosicaoImp();
	VertiOuHorizon = vetorPosicaoImp();
	
	impVetorLogica(arrayCharacter,VertiOuHorizon );
	
	
	pausa();
}

void impPares(void){

	bool par = true;
	if(vetor[0] == 0){
		vetorVazio();
		return;
	}
	
	impLoopParOuImpar(par);

	pausa();
}

void impImpares(void){

	bool impar = false;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	impLoopParOuImpar(impar);

	pausa();
}

void impPrimos(void){
	bool Nprimo = true;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	Nprimo = primosLogica();

	if(Nprimo){
		printf("Nenhum primo no vetor");
	}

	pausa();
}

void impSoma(void){
	int somatorio=0;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	for(int i= 0; i < VETOR ; i++){
		somatorio += vetor[i];
	}
	printf("O total da somatoria de todos os numeros no vetor é de: \n");
	printf("%d", somatorio);

	pausa();

}

void impMedia(void){
	int somatorio=0, media=0;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	for(int i= 0; i < VETOR ; i++){
		somatorio += vetor[i];
	}
	media= somatorio/VETOR;
	printf("a media aritmetica é de :");
	printf("%d", media);

	pausa();

}

void impNumeroRepetido(void){
	int conferir =0, contador=0;
	bool nenhum = true;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	printf("Digite o numero a ser conferido no vetor \n");
	scanf("%d",& conferir);
	for(int i=0; i < VETOR ; i++){
		if(conferir == vetor[i]){
			printf("%d : %d \n", i,vetor[i]);
			contador++;
			nenhum = false;
		}
	}
	if(nenhum){
		printf("Nenhum numero igual ao informado foi encontrado\n\n");
	}else{
		printf("%d iguais ao numero informado foram encontrado\n", contador);
	}

	pausa();  	
}

void ImpPrimeiraAparicao(void){
	int conferir =0;
	bool nenhum = true;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	printf("Digite o numero a ser conferido no vetor \n");
	scanf("%d",& conferir);
	for(int i=0; i < VETOR ; i++){
		if(conferir == vetor[i]){
			printf("a primeira aparicao do numero informado e no vetor %d : %d \n", i,vetor[i]);
			nenhum = false;
			break;
		}
	}
	if(nenhum){
		printf("Nenhum numero igual ao informado foi encontrado\n\n");
	}

	pausa();  	
}

void ImpUltimaAparicao(void){
	int conferir =0, contador=0;
	bool nenhum = true;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	printf("Digite o numero a ser conferido no vetor \n");
	scanf("%d",& conferir);
	for(int i=0; i < VETOR ; i++){	
		if(conferir == vetor[i]){
			nenhum = false;
			contador = i;
		}
	}
	if(nenhum){
		printf("Nenhum numero igual ao informado foi encontrado\n\n");
	}else{
		printf("a ultima apiracao do numero informado e no vetor %d : %d \n", contador, vetor[contador]);
	}

	pausa(); 
}

void ImpMaiorNumero(void){
	int maior = 0;

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}

	
    for(int i = 0; i < VETOR; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
         }
    }
    printf("O maior numero e %d", maior);

	pausa(); 

}

void ImpMenorNumero(){
	int menor = vetor[0];

	if(vetor[0] == 0){
		vetorVazio();
		return;
	}


    for(int i = 0; i < VETOR; i++){
        if(vetor[i] < menor){
        menor = vetor[i];
        }
    }
    
    printf("O menor numero e %d", menor);

	pausa();
}

void encherVetor(void){
	int aleatorio=0;
	bool sair = false;

	printf("Digite a distancia de numeros aleatorio a ser gerado, o numero deverar ser um numero positivo maior que 1\n");
	do{		
		scanf("%d", & aleatorio);			
		if(aleatorio <= 0){
			printf("Numero invalido, escolha novamente \n\n");
		}else{
			sair=true;
		}
	}while(!sair);

	for(int i = 0; i < VETOR; i++){
		vetor[i] = (rand() % aleatorio)+1;	
	}		
	printf("Vetor preenchido com sucesso");

	pausa();
}


int main(){
	srand(time(NULL));
	int caso = -1 ;
	bool sair = false;

	while(caso != 0){	
		
		menu();
		
		do{		
			scanf("%d", & caso);			
			if(caso > 12 || caso < 0){
				printf("Numero invalido, escolha novamente \n\n");
			}else{
				sair=true;
			}
		}while(!sair);

		switch(caso){
			
			case 1:	 impVetor(); break;					
			case 2:	 impPares(); break;								
			case 3:	 impImpares(); break;					
			case 4:	 impPrimos(); break;								
			case 5:	 impSoma(); break;					
			case 6:	 impMedia(); break;							
			case 7:	 impNumeroRepetido(); break;					
			case 8:	 ImpPrimeiraAparicao(); break;								
			case 9:	 ImpUltimaAparicao(); break;				
			case 10: ImpMaiorNumero(); break;								
			case 11: ImpMenorNumero(); break;					
			case 12: encherVetor(); break;								
			case 0: 
                printf("\n\n Programa sendo encerrado, aperte qualquer botao para continuar. \n\n");
	            getch();				
			break;
	
	}
}
	
	return 0;
}