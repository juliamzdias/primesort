/* EA879 - 2.2017: Primesort
* Júlia Martinez Dias   156019 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

// Função que verifica se um número é primo ou não
int primo_func(int n){

 unsigned int divisor=3, primo=1, numero_teste=0;

  if (n%2==0 && n>2 || n==1){   // Se o número for par e maior que 2 ou for igual a 1, não é primo
    primo = 0;
  }
  else { //Testa os ímpares
    numero_teste = (unsigned int) sqrt(n);  // Se o número for composto, ele tem algum divisor entre 3 e raiz quadrada de n
    if(numero_teste%2==0) numero_teste = numero_teste --; // Se a raiz quadrada for par, arredonda para o menor ímpar mais próximo
    while (primo && divisor <= numero_teste){
        if(n%divisor==0) {
        primo = 0;
    }
    divisor = divisor + 2;  //Testa apenas os divisores ímpares, deixando o programa mais rápido
    }
    }
  return primo;
}

int main(){

  FILE *lista_decrescente;
  int entrada=0, saida[200000], i=0, j=0;

  scanf("%d", &entrada); // Lê o primeiro número da sequência para entrar no while

  while(entrada != -1){ //Executa enquanto não chegar ao caractere que indica fim de sequência
    if(primo_func(entrada) == 0){
      saida[i] = entrada; // Coloca os números compostos no vetor saída
      i++;
    }
    scanf("%d", &entrada);  //Lê os outros númerosa da sequência enquanto não chegar o "-1"
}

if((lista_decrescente = popen("sort -n -r", "w")) == NULL){ // Escreve os números em ordem decrescente
  perror("popen");
  exit(1);
}

for(j=0; j<i; j++){
  fprintf(lista_decrescente, "%d\n", saida[j]); //Cria o vetor de saída novamente, com os números ordenados
}

pclose(lista_decrescente);

return 0;

}
