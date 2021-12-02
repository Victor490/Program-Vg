
#include <stdio.h>
#include <stdlib.h>

int main(void) {

  FILE *login_banco;  
  char login[100]; 

  
   
  int result;
  char nome[50];
  char cpf[15];
  int saldo = 0;
  int numero_conta = 0;
  int op = 0;
  int valor;
  char V[50];


  while (op != 6) {

       printf("\nDigite o numero conforme o que você deseja fazer\n");
       printf("1 - Cadastro\n");
       printf("2 - Depositar\n");
       printf("3 - Sacar\n");
       printf("4 - Verificar saldo\n");
       printf("5 - Sair\n");
       scanf("%i", &op);

  switch (op)  {
      // Cadastro
      case 1:
        printf("\nInforme seu nome: ");
        scanf("%s", nome);

        printf("\nInforme seu cpf: ");
        scanf("%s", cpf);

        printf("\nInforme seu saldo inicial: ");
        scanf("%i", &saldo);

        printf("\nVocê finalizou seu cadastro\n");
        
        printf("\nnumero_conta: %d\nnome: %s\ncpf: %s\nsaldo: %d\n", numero_conta, nome, cpf, saldo);
        
        login_banco = fopen("usuario.txt", "a+");

        sprintf(login, "numero_conta: %i\nnome: %s\ncpf: %s \nsaldo: %i\n", numero_conta, nome, cpf, saldo);
        //printf("\nnumero_conta: %i\nnome: %s\ncpf: %s \nsaldo: %i\n", numero_conta, nome, cpf, saldo);
        result = fputs (login, login_banco);
        fclose(login_banco);
        numero_conta++;
        

    if  (login_banco == NULL) 
        {
          printf("Erro na abertura do arquivo");
          return 0;
        }
        

       login_banco = fopen("usuario.txt", "r");
       fscanf (login_banco, "%s", V);

       fclose (login_banco);
       
       /* 
       R - O arquivo é apagado sem qualquer aviso e um novo arquivo vazio é criado em seu lugar.  
       

       A - O arquivo é aberto para adição de caracteres no fim. 

       R+ -  O arquivo é aberto para adição de caracteres no início, sobrescrevendo caracteres no início, sobrescrevendo

       W+ - O arquivo é aberto para adição de caracteres no início, sobrescrevendo o arquivo inteiro

       A+ - O arquivo é aberto para adição de caracteres no fim.  

       */
        

       //NAO MEXER
        break; 
      
      // Deposito
      case 2:
      
        printf("\nInforme o numero da conta :");
        scanf("%i", &numero_conta);
        printf("\nInforme o valor que deseja depositar : ");
        scanf("%i", &valor);
        saldo = (saldo + valor);
        printf("\nVocê realizou o deposito! ");
        break;
      
      // Saque
      case 3:
        printf("\nInfore o numero da conta :");
        scanf("%i", &numero_conta);
        printf("\nInforme o valor que deseja sacar : ");
        scanf("%i", &valor);

        if (valor > saldo) {

          printf("\nVocê não tem saldo suficiente!\n");
        
        }       
        else {

          saldo = (saldo - valor); 
          printf("\nSeu saque foi efetuado com sucesso");
        }
        break;
       
     
      
      //Verificar saldo
      case 4:
        printf("\nO seu saldo atual é de: %i reais\n", saldo);
        break;

      //Sair
      case 5:
        printf("\n Você saiu do programa ");
        break;
      
      default:
        break;
    } 

    
  
  }  

  return 0;

}

  

      


      
 
 
