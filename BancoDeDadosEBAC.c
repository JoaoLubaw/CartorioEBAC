#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por strings

int registro() //fun��o respons�vel pelo cadastro de novos usu�rios
{
	//inicio de cria��o de vari�veis/strings
	char arquivo[40]; //[string]
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de cria��o de vari�veis/strings
	
	
	system("cls");
	printf("Digite o CPF a ser cadastrado: "); //coleta de informa��es
	scanf("%s", cpf); // %s salva na string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores dos strings ( do cpf pro arquivo)
	
	FILE *file; //FILE abre fun��o arquivo. *cria o arquivo
	file = fopen(arquivo, "w"); //fopen abre arquivo w � de write
	
	//in�cio de salvamento de cpf no arquivo
	fprintf(file,cpf); //salva valor da variavel cpf no arquivo
	fclose(file); //fecha arquivo
	//fim de salvamento de cpf no arquivo
	
	
	//in�cio de coloca��o de v�rgula e salvamento de nome no arquivo
	file = fopen(arquivo, "a"); // "a" atualiza arquivo j� salvo
	fprintf(file,", Nome:"); 
	fclose(file);
	
	printf("Digite o nome:");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	//fim de coloca��o de v�rgula e salvamento de nome no arquivo
	
	
	//in�cio de coloca��o de v�rgula e salvamento de sobrenome no arquivo
	file=fopen(arquivo, "a");
	fprintf(file,", Sobrenome:"); 
	fclose(file);
	
	printf("Digite o sobrenome:");
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	//fim de coloca��o de v�rgula e salvamento de sobrenome no arquivo
	
	
	//in�cio de coloca��o de v�rgula e salvamento de cargo no arquivo
	file=fopen(arquivo, "a");
	fprintf(file,", Cargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);	
	fclose(file);
	//fim de coloca��o de v�rgula e salvamento de cargo no arquivo
}

int consulta() //fun��o respons�vel pela busca por usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //indica que textos s�o em portugu�s e possuem acento
	

	//inicio de cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	//fim de cria��o de vari�veis/strings
	
	
	system("cls"); //limpa a tela
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //salva conte�do digitado na vari�vel cpf
	
	FILE *file; 
	file = fopen (cpf, "r"); //ler o arquivo (read)
	
	if(file == NULL) //se arquivo == (for igual) a nulo
	{ 
		printf("\n\nSinto muito mas esse CPF n�o foi localizado em nossos registros.\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //salvando na variavel conteudo enquanto estiver em 200 caracteres dentro do arquivo
	{
		printf("\nEssas s�o as informa��es do usu�rio: CPF:");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
	
}

int deletar() //Fun��o respons�vel por deletar alunos
{
	
	//inicio de cria��o de vari�veis/strings
	char cpf[40];
	char conteudo[200];
	int opcao=0;
	//fim de cria��o de vari�veis/strings
	
	
	system("cls");
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //salva valor digitado na vari�vel cpf
	
	FILE *file;
	file = fopen (cpf, "r"); //abre e l� arquivo com o mesmo titulo que a vari�vel cpf
	
	
	//Inicio do que ocorre se o arquivo n�o existir:
	if(file == NULL) 
	{ 
		system("cls");
		printf("Este usu�rio n�o se encontra no sistema.\n\n\n");
		system("pause");
	}
	//Fim do que ocorre se o arquivo n�o existir:
	
	
	//In�cio do que ocorre se o arquivo existir:   (Tomei a liberdade de adicionar uma tela de confirma��o, para evitar a exclus�o de um usu�rio errado por engano.)
		while(fgets(conteudo, 200, file) !=NULL) 
	{
		system("cls");
		printf("\nVoc� tem certeza que deseja deletar o usu�rio de CPF:");
		printf("%s", conteudo); //Exibe as informa��es de dentro do arquivo
		fclose(file); //fecha o arquivo
		printf("?\n\n\n1:Sim.\n\n"); //Pede por confirma��o de exclus�o

		scanf("%d", &opcao); //procura pela resposta do utilizador
		
		
		switch(opcao) 
		{
			case 1: //se confirmar:
			remove(cpf); //remove o arquivo do sistema
			system("cls");
			printf("Usu�rio removido do banco de dados com sucesso.\n\n\n"); //d� mensagem de sucesso
			system("pause");
			break;

			
			default: //se cancelar:
			system("cls");
			printf("Exclus�o de usu�rio cancelada.\n\n\n"); //confirma cancelamento de exclus�o
			system("pause");
			break;
				
	}	}
	//Fim do que ocorre se o arquivo existir:
} 



int main() //ponto de partida, tela inicial.

{
	int opcao=0; // Defini��o de vari�vel. Numero inteiro op��o vale 0, este espa�o � nosso.
	int laco=1; //mantem laco como 1 
	
	for(laco=1;laco=1;) //usu�rio s� vai sair quando fechar 
	{

		system("cls"); //limpeza de tela
		setlocale (LC_ALL, "Portuguese"); //todas as linguagens de texto s�o em portugu�s e ele acha os acentos na biblioteca.

		//inicio da Lista de op��es
		printf("\t\tCart�rio da EBAC\n\n");
		printf("Escolha a op��o desejada do menu:\n\n"); //� possivel fazer numa �nica linha, com \n j� pula para uma pr�xima linha
		printf("\t1- Registrar novo usu�rio.\n");
		printf("\t2- Realizar consulta por usu�rio.\n");
		printf("\t3- Deletar usu�rio do banco de dados.\n\n\n \tOp��o: "); // Fim do menu
		//fim da Lista de op��es
		
		scanf("%d", &opcao); //escaneia o que o usu�rio responde. Armazene na variavel (%d) op��o
	
		system("cls");
	
		switch(opcao) //Prossegue com o sistema conforme escolha de utilizador
		{
			case 1: //se escolher 1 
			printf("Voc� escolheu registrar um novo usu�rio.\n\n\n");
			system("pause");
			registro();
			break;
			
			case 2: //se escolher 2 
			printf("Voc� escolheu realizar consulta por um usu�rio.\n\n\n");
			system("pause");
			consulta();
			break;
			 
			case 3: //se escolher 3
			printf("Voc� escolheu deletar um usu�rio do banco de dados.\n\n\n");
			system("pause");
			deletar();
			break;
			
			default: //se escolher uma op��o inexistente
			printf("Hmmmm...Essa n�o parece com uma das op��es...\n\n\n");
			system("pause");
			break;
		}	
	}
		
	printf("\n \n \nEsse software � de livre uso da Equipe EBAC \n~Desenvolvido por Jo�o Lubawaski"); //assinatura
}



