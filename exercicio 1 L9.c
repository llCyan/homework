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

void opcao1(void){

	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}

	char arrayCharacter, VertiOuHorizon;
	printf("Deseja que a posicao da array seja mostrada ?\n\n");
	printf("Apere 1 para sim ou qualquer outro botao para nao\n");
	arrayCharacter = getch();
	printf("Deseja que seja emprimido na vertical ou horizontal ?\n\n");
	printf("Apere 1 para vertical ou qualquer outro botao para horizontal\n");
	VertiOuHorizon = getch();
	
	if(arrayCharacter == '1' && VertiOuHorizon == '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d : %d \n ", i, vetor[i]);
		}
	}
	if(arrayCharacter != '1' && VertiOuHorizon == '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d \n ", vetor[i]);
		}
	}
	if(arrayCharacter == '1' && VertiOuHorizon != '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d : %d , ", i, vetor[i]);
		}
	}
	if(arrayCharacter != '1' && VertiOuHorizon != '1'){
		for(int i = 0; i < VETOR; i++){
			printf("%d , ", vetor[i]);
		}
	}	
	
	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();
}

void opcao2(void){
	int par;
	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}
	
	for(int i=0; i < VETOR; i++){
		par = vetor[i] %2;
		if( par == 0){
			printf("%d : %d \n", i, vetor[i]);
		}
	}

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();
}

void opcao3(void){
	int impar;
	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}
	
	for(int i=0; i < VETOR; i++){
		impar = vetor[i] %2;
		if( impar == 1){
			printf("%d : %d \n", i, vetor[i]);
		}
	}

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();
}

void opcao4(void){
	int primo=0,contador=0;
	bool Nprimo = true;

	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf(" Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}

    for (int i = 0; i < VETOR; i++) {
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
			Nprimo = false;
		}
	}
	if(Nprimo){
		printf("Nenhum primo no vetor");
	}

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();
}

void opcao5(void){
	int somatorio=0;

	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}

	for(int i= 0; i < VETOR ; i++){
		somatorio += vetor[i];
	}
	printf("O total da somatoria de todos os numeros no vetor é de: \n");
	printf("%d", somatorio);

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();

}

void opcao6(void){
	int somatorio=0, media=0;

	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}

	for(int i= 0; i < VETOR ; i++){
		somatorio += vetor[i];
	}
	media= somatorio/VETOR;
	printf("a media aritmetica é de :");
	printf("%d", media);

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();

}

void opcao7(void){
	int conferir =0, contador=0;
	bool nenhum = true;
	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
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

    printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();  	
}

void opcao8(void){
	int conferir =0;
	bool nenhum = true;
	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
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

    printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();  	
}

void opcao9(void){
	int conferir =0, contador=0;
	bool nenhum = true;
	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
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

	printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();  
}

void opcao10(void){
	int maior = 0;

	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}

	
    for(int i = 0; i < VETOR; i++){
        if(vetor[i] > maior){
            maior = vetor[i];
         }
    }
    printf("O maior numero e %d", maior);

    printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch();  

}

void opcao11(){
	int menor = vetor[0];

	if(vetor[0] == 0){
		printf("Seu vetor ainda esta vazio, retornando ao menu\n\n");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
		return;
	}


    for(int i = 0; i < VETOR; i++){
        if(vetor[i] < menor){
        menor = vetor[i];
        }
    }
    
    printf("O menor numero e %d", menor);

    printf("\n\n Aperte qualquer botao para continuar. \n\n");
	getch(); 
}

void opcao12(void){
	for(int i = 0; i < VETOR; i++){
		vetor[i] = (rand() % 20)+1;	//abaixei a quantidade para ter chances de numeros repetidos//
	}		
		printf("Vetor preenchido com sucesso");
		printf("\n\n Aperte qualquer botao para continuar. \n\n");
		getch();
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
			
			case 1:	 opcao1(); 	break;					
			case 2:	 opcao2(); 	break;								
			case 3:	 opcao3(); 	break;					
			case 4:	 opcao4(); 	break;								
			case 5:	 opcao5(); 	break;					
			case 6:	 opcao6(); 	break;							
			case 7:	 opcao7(); 	break;					
			case 8:	 opcao8(); 	break;								
			case 9:	 opcao9(); 	break;				
			case 10: opcao10(); break;								
			case 11: opcao11(); break;					
			case 12: opcao12(); break;								
			case 0: 
                printf("\n\n Programa sendo encerrado, aperte qualquer botao para continuar. \n\n");
	            getch();				
			break;
	
	}
}
	
	return 0;
}
