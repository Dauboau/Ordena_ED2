#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void LerLinha(char **primeira_linha, FILE *arquivo) {

    //Variaveis auxiliares para controlar o tamanho e acessar uma posicao da string que armazenara o texto do arquivo
    size_t linha_len = 32;
    size_t char_index = 0;

    *primeira_linha = malloc(sizeof(char)*linha_len);

    //O laço é executado até que se chegue ao fim de uma linha(\n) ou ao fim de um arquivo(!feof)
    while (!feof(arquivo) && (*primeira_linha)[char_index - 1] != '\n') {
        
        //Se o ponteiro estiver na última posicao da string e feita a realocacao
        if (linha_len == char_index) {
            
            linha_len += 16;
            *primeira_linha = realloc(*primeira_linha, sizeof(char)*linha_len);
        
        }

        //A copia e feita caracter a caracter
        (*primeira_linha)[char_index] = fgetc(arquivo);
        char_index++;
    }

    (*primeira_linha)[char_index - 1] = '\0';
}


void Ctrl_F(char* nome_texto, char* nome_trechos, char* nome_saida){

   FILE* arq_texto = fopen(nome_texto, "r");
   FILE* arq_trechos = fopen(nome_trechos, "r");
   FILE* arq_saida = fopen(nome_saida, "w");

   char *trecho, *texto, *texto_aux;
   texto = malloc(sizeof(char)*1);

   //O laço é executado até que se chegue ao fim do arquivo copiando linha a linha e concatenando em uma string
   while (!feof(arq_texto)){
       
       LerLinha(&texto_aux, arq_texto);
       texto = realloc(texto, (sizeof(char)*(strlen(texto)+strlen(texto_aux))+1));
       strcat(texto, " ");
       strcat(texto, texto_aux);
    
    }

    while(!feof(arq_trechos)){
       
        //Realiza a leitura da string a ser localizada
        LerLinha(&trecho, arq_trechos);  
    
        int i = 0;

        //A busca e realizada ate que se chegue ao fim do texto
        //A condicao "trecho[0] != NULL" deve-se a uma leitura residual do "fgetc" da funcao "LerLinha" ao final do arquivo 
        while (texto[i] != '\0' && trecho[0] != NULL){
            
            int j = 0;
            
            while ((trecho[j] != '\0') && (texto[i+j] == trecho[j]))
                j++;
        
            if(trecho[j] == '\0'){

                fprintf(arq_saida,"%d, %d\n", (i-1), (j+i-2));
                break;

            }
        
            i++;        
        
        }
       
    }

   free(texto);
   free(texto_aux);
   fclose(arq_texto);
   fclose(arq_trechos);
   fclose(arq_saida);

}
