#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
    USAR FGETS NO LUGAR DA FUNÇÃO "LER PRIMERIA LINHA"

*/

void LerPrimeiraLinha(char **primeira_linha, FILE *arquivo) {

    size_t linha_len = 16;
    size_t char_index = 0;

    *primeira_linha = malloc(sizeof(char)*linha_len);

    while (!feof(arquivo) && (*primeira_linha)[char_index - 1] != '\n') {

        if (linha_len == char_index) {
            linha_len *= 8;
            *primeira_linha = realloc(*primeira_linha, sizeof(char)*linha_len);
        }

        (*primeira_linha)[char_index] = fgetc(arquivo);
        char_index++;
    }

    (*primeira_linha)[char_index - 1] = '\0';
}

void Ctrl_F(FILE *arq_texto, FILE *arq_trechos, FILE *arq_saida){
    /*
        Entrada: arquivo trechos, arquivo texto, arquivo saida
    */

   char *trecho, *texto, *texto_aux;
   texto = malloc(sizeof(char)*1);

   while (!feof(arq_texto)){
       
       LerPrimeiraLinha(&texto_aux, arq_texto);
       texto = realloc(texto, (sizeof(char)*(strlen(texto)+strlen(texto_aux))+1));
       strcat(texto, " ");
       strcat(texto, texto_aux);
    }

   while(!feof(arq_trechos)){
       
       LerPrimeiraLinha(&trecho, arq_trechos);  
       
       int i = 0;

       while (texto[i] != '\0' && trecho[0] != NULL){

           int j = 0;

           while ((trecho[j] != '\0') && (texto[i+j] == trecho[j]))
               j++;
           
           if(trecho[j] == '\0'){

               fprintf(arq_saida,"%d, %d\n", (i-1), (j+i-2));
               //break;

            }

           i++;        
           
        }
       
    }

   free(texto);
   free(texto_aux);

}

int main(int *argc, char *argv []){

    FILE *texto, *trechos, *saida;
    texto = fopen("texto.txt", "r");
    trechos = fopen("trechos.txt", "r");
    saida = fopen("saida.txt", "a");

    Ctrl_F(texto, trechos, saida);

    fclose(texto);
    fclose(trechos);
    fclose(saida);

    return 0;
}