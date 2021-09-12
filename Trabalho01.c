#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    int opcao=1;
    char nomearq[40];
    while (opcao!=0){

        printf("###############################################################");
        printf("\n####                                                       ####");
        printf("\n###                                                         ###");
        printf("\n##                Funcao                              Opcao  ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n## Abrir arquivo de texto:                               1   ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n## Contar vogais:                                        2   ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n## Converte para I:                                      3   ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n## Grava arquivo com primeira letra em maiusculo:        4   ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n## Gera arquivo figura:                                  5   ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n## Sair:                                                 0   ##");
        printf("\n## --------------------------------------------------------- ##");
        printf("\n###                                                         ###");
        printf("\n####                                                       ####");
        printf("\n###############################################################");
        printf("\n\n\n***DIGITE A OPCAO DESEJADA:*** \n");

        scanf("%d",&opcao);

        switch(opcao){
        case 1:
            abreArquivo(nomearq);
            break;
        case 2:
            contaVogais(nomearq);
            break;
        case 3:
            converteI(nomearq);
            break;
        case 4:
            criaMaiusculo(nomearq);
            break;
        case 5:
            desenho();
            break;
        case 0:
            printf("\n\n****OPCAO SAIR SELECIONADA****\n\n");
            break;
        default:
            printf("### OPCAO DIGITADA INVALIDA ###");
            break;
        }
    }
}
void abreArquivo(char nomearq[40]){
    FILE *fptr;
    int fechArquivo;
    char ch;
    printf("\nDigite o nome do arquivo: ");
    fflush(stdin);
    gets(nomearq);

    if ((fptr = fopen(nomearq,"r")) == NULL){
        printf("\n***ERRO NA ABERTURA DO ARQUIVO %s***\n\n",nomearq);
    }else{
        printf("***ARQUIVO ABERTO COM SUCESSO***\n\n");
        while((ch=getc(fptr))!=EOF){
            printf("%c",ch);
        }
    }
    fclose(fptr);
    printf("\nDeseja continuar trabalhando neste arquivo? 1-SIM/2-NAO ");
    scanf("%d",&fechArquivo);
    if (fechArquivo==1){
        printf("\n**ARQUIVO COM POSSIBILIDADE DE TRABALHAR**");
    }else if (fechArquivo==2){
        printf("\n**ARQUIVO FECHADO, PARA TRABALHAR NOVAMENTE REABRA**");
        gets(nomearq);
    }else{
        printf("\nOpcao escolhida invalida! Arquivo continua Aberto");
    }

    printf("\n\n");
}
void contaVogais (char nomearq[40]){
    FILE *fptr;
    char ch, chant;
    int contVogais=0, contA=0,contE=0,contI=0,contO=0,contU=0, fechArquivo=0;

    if ((fptr = fopen(nomearq,"r")) == NULL){
        printf("\n***ERRO, ARQUIVO NAO FOI ABERTO***\n\n");
        return;
    }else{
        while((ch=getc(fptr))!=EOF){
            printf("%c",ch);
            if((ch=='a')||(ch=='A')){
                contA++;
                contVogais++;
            }else if ((ch=='e')||(ch=='E')){
                contE++;
                contVogais++;
            }else if ((ch=='i')||(ch=='I')){
                contI++;
                contVogais++;
            }else if ((ch=='o')||(ch=='O')){
                contO++;
                contVogais++;
            }else if ((ch=='u')||(ch=='U')){
                contU++;
                contVogais++;
            }
        }
    }
    printf("\nquantidade de vogais A: %i",contA);
    printf("\nquantidade de vogais E: %i",contE);
    printf("\nquantidade de vogais I: %i",contI);
    printf("\nquantidade de vogais O: %i",contO);
    printf("\nquantidade de vogais U: %i",contU);
    printf("\nQuantidade total de vogais: %i\n\n",contVogais);
    fclose(fptr);
    printf("\nDeseja continuar trabalhando neste arquivo? 1-SIM/2-NAO ");
    scanf("%d",&fechArquivo);
    if (fechArquivo==1){
        printf("\n**ARQUIVO COM POSSIBILIDADE DE TRABALHAR**");
    }else if (fechArquivo==2){
        printf("\n**ARQUIVO FECHADO, PARA TRABALHAR NOVAMENTE REABRA**");
        gets(nomearq);
    }else{
        printf("\nOpcao escolhida invalida! Arquivo continua Aberto");
    }

    printf("\n\n");

}
void converteI (char nomearq[40]){
    FILE *fptr;
    int fechArquivo;
    char ch, chant;

    if ((fptr = fopen(nomearq,"r")) == NULL){
        printf("\n***ERRO, ARQUIVO NAO FOI ABERTO***\n\n");
        return;
    }else{
        printf("**TROCANDO VOGAIS PELA LETRA I**\n\n");
        while((ch=getc(fptr))!=EOF){
            if ((ch=='a')||(ch=='A')||
                    (ch=='e')||(ch=='E')||
                    (ch=='i')||(ch=='I')||
                    (ch=='o')||(ch=='O')||
                    (ch=='u')||(ch=='U')){
                ch='i';
            }
            printf("%c",ch);
        }
    printf("\n\n");
    }
    fclose(fptr);
    printf("\nDeseja continuar trabalhando neste arquivo? 1-SIM/2-NAO ");
    scanf("%d",&fechArquivo);
    if (fechArquivo==1){
        printf("\n**ARQUIVO COM POSSIBILIDADE DE TRABALHAR**");
    }else if (fechArquivo==2){
        printf("\n**ARQUIVO FECHADO, PARA TRABALHAR NOVAMENTE REABRA**");
        gets(nomearq);
    }else{
        printf("\nOpcao escolhida invalida! Arquivo continua Aberto");
    }

    printf("\n\n");
}
void criaMaiusculo (char nomearq[40]){
    FILE *fptr, *fmaiusculo;
    int fechArquivo;
    char ch, chant;

    if ((fptr = fopen(nomearq,"r")) == NULL){
        printf("\n***ERRO, ARQUIVO NAO FOI ABERTO***\n\n");
        return;
    }if ((fmaiusculo = fopen("arquivoMaiusculo.txt","w")) == NULL){
        printf("\nErro na abertura do arquivo arquivoMaiusculo.txt");
        return;
    }else{
        while ((ch=getc(fptr))!=EOF){
            printf("%c",ch);
            if (((chant==NULL)||(chant==' ')||(chant=='\n'))
                    &&(ch>=97)&&(ch<=122)){
                ch = ch - 32;
            }
            chant=ch;
            putc(ch,fmaiusculo);
        }
    }
    fclose(fmaiusculo);
    fclose(fptr);
    printf("\n\nArquivo em MAIUSCULO gerado com sucesso.\n");
    printf("\n\nNome do arquivo: arquivoMaiusculo.txt\n\n");
    printf("\nDeseja continuar trabalhando no arquivo %s? 1-SIM/2-NAO ", nomearq);
    scanf("%d",&fechArquivo);
    if (fechArquivo==1){
        printf("\n**ARQUIVO COM POSSIBILIDADE DE TRABALHAR**");
    }else if (fechArquivo==2){
        printf("\n**ARQUIVO FECHADO, PARA TRABALHAR NOVAMENTE REABRA**");
        gets(nomearq);
    }else{
        printf("\nOpcao escolhida invalida! Arquivo continua Aberto");
    }

    printf("\n\n");
}
void desenho(){
    int linhas=0, c=0;
    printf("Digite a Quantidade de linhas\n");
    scanf("%d",&linhas);
    printf("\n");
    for (int i=linhas; i>0; i--){
        for (int j=0; j<i; j++){
            printf(" ");
        }
        c=c+2;
        for (int x=1; x<c; x++){
            printf("*");
        }
        printf("\n");
    }
    printf("\n\n");
}
