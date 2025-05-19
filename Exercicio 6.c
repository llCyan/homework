#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

#define VETOR 50
#define VETORIF 49

int main(){
	srand(time(NULL));
    float notas[VETOR]= {0}, soma=0, soma2 = 0, maior = 0, menor = 0, imprimir= 0;
    int i = 0, contador=0, menu = -1, escolha=-1;
    bool saida = false;
    printf("Ensira as notas dos 50 alunos \n");
    do{
        scanf("%f", & notas[i] );
        if(notas[i] >= 0 && notas[i] < 10){
            printf("Nota do aluno %d adicionada com sucesso, adicione a nota do proximo aluno \n", i+1);
            i++;
        }
        else{
            printf("Nota invalida, digite novamente");
        }
    }while(i <= VETORIF);
    
    /*for(int l=0; l <= 49; l++){
        notas[l]= rand() % 11;
    }*/

    do{
        printf("\n \n Todas as notas enserida com sucesso, escolha uma opcao do menu para continuar \n \n");
        printf("    (1) Imprimir todas as notas digitadas para conferência \n");
        printf("    (2) Calcular e imprimir a media da turma \n");
        printf("    (3) Alterar uma nota \n");
        printf("    (4) Imprimir a maior nota da turma \n");
        printf("    (5) Imprimir a menor nota da turma \n");
        printf("    (6) Imprimir as notas acima de uma nota informada \n");
        printf("    (7) Imprimir as notas abaixo de uma nota informada \n");
        printf("    (0) Encerrar o programa \n");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                contador=0;
                printf("Imprimindo todas as notas...\n");
                for(int l = 0; l <= VETORIF; l++){
                    printf("%d - %.1f \n", l+1, notas[l]);
                    contador ++;
                }
                printf("%d notas foram impressas\n", contador);    
                
                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch();
            break;

            case 2:
                soma = 0;
                soma2 = 0;
                for(int l = 0; l <= VETORIF; l++){
                    soma += notas[l];
                }
                soma2 = soma / VETOR;
                printf("a media da sala e de: %.1f", soma2);

                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch();                
            break;

            case 3:
                escolha= 0;
                printf("Digite o numero do aluno que voce deseja alterar a nota\n");
                do{
                    scanf("%d",& escolha);
                    if(escolha >= 1 && escolha <= VETOR){
                        saida=true;
                    }else{
                        printf("numero invalido, digite novamente\n");
                    }
                }while(!saida);
                escolha--;
                printf("Digite a nova nota:\n");
                saida=false;
                do{
                scanf("%f",& notas[escolha]);
                    if(notas[escolha] >= 0 && notas[escolha] <= 10){
                    printf("\n nota alterada com sucesso");
                    saida=true;
                    }else{
                        printf("nota invalida, ensira uma nota valida\n");
                    }
                }while(!saida);

                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch();

            break;

            case 4:
                maior = notas[0];
                for(int l = 0; l <= VETORIF; l++){
                    if(notas[l] > maior){
                        maior = notas[l];
                    }
                }
                printf("A maior nota e %.1f", maior);

                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch();  

            break;

            case 5:
                menor = notas[0];
                for(int l = 0; l <= VETORIF; l++){
                    if(notas[l] < menor){
                        menor = notas[l];
                    }
                }
                contador +=1;
                printf("A menor nota e %.1f", menor);

                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch();  
            break;

            case 6:
                maior = 0;
                printf("informe uma nota: \n");
                scanf("%f",& maior);
                for(int l= 0; l <= VETORIF; l++){
                    if(maior <= notas[l]){
                        printf("Aluno %d : %.1f\n",l+1, notas[l]);
                    }
                }

                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch();  

            break;

            case 7:
                menor = 0;
                printf("informe uma nota: ");
                scanf("%f",& menor);
                for(int l= 0; l <= VETORIF; l++){
                    if(menor >= notas[l]){
                        printf("Aluno %d : %.1f \n",l+1, notas[l]);
                    }
                }

                printf("\n\n Aperte qualquer botao para continuar. \n\n");
	            getch(); 
            break;

            case 0:
                printf("\n\n Programa sendo encerrado, aperte qualquer botao para continuar. \n\n");
	            getch();
            break;

        }
    }while(menu != 0);

    return 0;
}