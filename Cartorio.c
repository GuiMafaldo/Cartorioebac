#include<stdio.h>//biblioteca de comunicaçao com o usuario
#include<stdlib.h>//biblioteca de alocaçao de espaço em memoria
#include<locale.h>//biblioteca de alocaçao de texto por regiao
#include<string.h>//biblioteca responsavel por cuidar das strings

int registro()//funçao responsavel por cadastrar os usuarios no sistema
{
	//inicio da criaçao de variaveis/string
   char arquivo[40];
   char cpf[40];
   char nome[40];
   char sobrenome[40];
   char cargo[40];
   //final da criaçao de variaveis/string
   
   printf("Digite o cpf a ser cadastrado: ");//coletando os valores das string
   scanf("%s",cpf);//%s refere-se a string
   
   strcpy(arquivo, cpf);//responsavel por copiar os valores das strings
   
   FILE *file;//cria o arquivo
   file = fopen(arquivo, "w");//cria o arquivo e o"w" significa escrever/novo
   fprintf(file,cpf);//salva o valor da variavel
   fclose(file);
   
   file = fopen(arquivo, "a");//"a" ultilizado para atualizar um arquivo
   fprintf(file,",");//colocar virgula dentro do arquivo","
   fclose(file);// fechamento de arquivo
   
   printf("Digite o nome a ser  cadastrado:");
   scanf("%s",nome);
   
   file = fopen(arquivo, "a");
   fprintf(file,nome);
   fclose(file);
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o sobrenome a ser cadastrado: ");
   scanf("%s",sobrenome);
   
   file = fopen(arquivo, "a");
   fprintf(file,sobrenome);
   fclose(file);
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   printf("Digite o cargo a ser cadastrado:");
   scanf("%s",cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file,cargo);
   fclose(file);
   
   file = fopen(arquivo,"a");
   fprintf(file,",");
   fclose(file);
   
   system("pause");//pause para nao voltar direto e dar tempo de ler oque foi feito
}
int consulta()
{
	setlocale(LC_ALL, "portuguese");//definindo a linguagem
	
	char cpf[40];//variavel/string
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//"r" responsavel por ler o arquivo e trazer uma resposta 
	
	if(file == NULL)//if: si tudo estiver certo executa o programa/arquivo
	 {
	 	printf("Nao foi possivel abrir o arquivo,nao localizado!\n");
	 }
	 
	 while(fgets(conteudo, 200, file) != NULL)//while,fgets:enquanto tiver buscando no arquivo executa a funçao definida
	 {
	     printf("\nEssas sao as informaçoes do usuario:");
		 printf("%s",conteudo);
		 printf("\n\n");	
	 } 
	 
	 system("pause");
}

int deletar()
{
     char cpf[40];
     
     printf("Digite o CPF do usuario a ser deletado: ");
     scanf("%s",cpf);
     
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("O usuario nao se encontra no sistema!.\n");
    	system("pause");
	}
}
int main()
    {
    	int opcao=0;//definindo variaveis
    	int laco=1;
    	
    	for(laco=1;laco=1;)
    	{
    		system("cls");
    		
    		setlocale(LC_ALL,"portuguese");
    		
    		printf("### Cartorio da EBAC ###\n\n");
    		printf("Escolha a opçao desejada do menu\n");
    		printf("\t1 - Registrar nomes\n");
    		printf("\t2 - Consultar nomes\n");
    		printf("\t3 - Deletar nomes\n\n");
    		
			printf("\t4 - sair do sistema\n\n");
    		
			printf("opçao:");
    	
    		scanf("%d",&opcao);//armazenando a escolha do usuario
    		system("cls");//responsavel por limpar a tela
    		
    		switch(opcao)//inicio da seleçao
    		{
    			case 1:
    			registro();//chamada de funçoes
				break;
				
				case 2:
				consulta();
				break;
				
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por ultilizar o sistema\n");
				return 0;
				break;
				
			    default:
			    printf("Essa opçao nao esta disponivel\n");
			    system("pause");
			    break;
				//fim da seleçao
			}
    	}
	}
    
       


    

