#include <stdio.h>

int main()
{
    int a=10;
    int* b=&a; //atribuição do endereço de memória da variável a
            //à variável b
    
    printf("a=%d\n",a);
    printf("conteudo b = %p\n",b);
    printf("endereco a = %p\n",&a); // endereço de a
    printf("endereco b = %p\n",&b); // endereço de b
    
    printf("b= %d\n", *b); // consultar o valor apontado por b
    *b = 20;  // alteração do conteúdo da variável a 
        // a partir do seu endereço de memória
    printf("a = %d\n",a);
    
    int c = *(&a); // valor apontado pelo endereço de a
    int** e = &b; // atribuição do endereço de memória de b
    printf("**e = %d\n",**e); 
    printf("*e = %p\n",*e); 
    printf("e = %p\n",e); 
    printf("endereco e = %p\n",&e); 


    return(0);
}