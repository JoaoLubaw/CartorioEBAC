#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por strings

int registro() //função responsável pelo cadastro de novos usuários
{
	//inicio de criação de variáveis/strings
	char arquivo[40]; //[string]
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim de criação de variáveis/strings
	
	
	system("cls");
	printf("Digite o CPF a ser cadastrado: "); //coleta de informações
	scanf("%s", cpf); // %s salva na string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores dos strings ( do cpf pro arquivo)
	
	FILE *file; //FILE abre função arquivo. *cria o arquivo
	file = fopen(arquivo, "w"); //fopen abre arquivo w é de write
	
	//início de salvamento de cpf no arquivo
	fprintf(file,cpf); //salva valor da variavel cpf no arquivo
	fclose(file); //fecha arquivo
	//fim de salvamento de cpf no arquivo
	
	
	//início de colocação de vírgula e salvamento de nome no arquivo
	file = fopen(arquivo, "a"); // "a" atualiza arquivo já salvo
	fprintf(file,", Nome:"); 
	fclose(file);
	
	printf("Digite o nome:");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	//fim de colocação de vírgula e salvamento de nome no arquivo
	
	
	//início de colocação de vírgula e salvamento de sobrenome no arquivo
	file=fopen(arquivo, "a");
	fprintf(file,", Sobrenome:"); 
	fclose(file);
	
	printf("Digite o sobrenome:");
	scanf("%s",sobrenome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	//fim de colocação de vírgula e salvamento de sobrenome no arquivo
	
	
	//início de colocação de vírgula e salvamento de cargo no arquivo
	file=fopen(arquivo, "a");
	fprintf(file,", Cargo:");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado:");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);	
	fclose(file);
	//fim de colocação de vírgula e salvamento de cargo no arquivo
}

int consulta() //função responsável pela busca por usuários
{
	setlocale(LC_ALL, "Portuguese"); //indica que textos são em português e possuem acento
	

	//inicio de criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	//fim de criação de variáveis/strings
	
	
	system("cls"); //limpa a tela
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); //salva conteúdo digitado na variável cpf
	
	FILE *file; 
	file = fopen (cpf, "r"); //ler o arquivo (read)
	
	if(file == NULL) //se arquivo == (for igual) a nulo
	{ 
		printf("\n\nSinto muito mas esse CPF não foi localizado em nossos registros.\n\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL) //salvando na variavel conteudo enquanto estiver em 200 caracteres dentro do arquivo
	{
		printf("\nEssas são as informações do usuário: CPF:");
		printf("%s", conteudo);
		printf("\n\n");
	}

	system("pause");
	
}

int deletar() //Função responsável por deletar alunos
{
	
	//inicio de criação de variáveis/strings
	char cpf[40];
	char conteudo[200];
	int opcao=0;
	//fim de criação de variáveis/strings
	
	
	system("cls");
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //salva valor digitado na variável cpf
	
	FILE *file;
	file = fopen (cpf, "r"); //abre e lê arquivo com o mesmo titulo que a variável cpf
	
	
	//Inicio do que ocorre se o arquivo não existir:
	if(file == NULL) 
	{ 
		system("cls");
		printf("Este usuário não se encontra no sistema.\n\n\n");
		system("pause");
	}
	//Fim do que ocorre se o arquivo não existir:
	
	
	//Início do que ocorre se o arquivo existir:   (Tomei a liberdade de adicionar uma tela de confirmação, para evitar a exclusão de um usuário errado por engano.)
		while(fgets(conteudo, 200, file) !=NULL) 
	{
		system("cls");
		printf("\nVocê tem certeza que deseja deletar o usuário de CPF:");
		printf("%s", conteudo); //Exibe as informações de dentro do arquivo
		fclose(file); //fecha o arquivo
		printf("?\n\n\n1:Sim.\n\n"); //Pede por confirmação de exclusão

		scanf("%d", &opcao); //procura pela resposta do utilizador
		
		
		switch(opcao) 
		{
			case 1: //se confirmar:
			remove(cpf); //remove o arquivo do sistema
			system("cls");
			printf("Usuário removido do banco de dados com sucesso.\n\n\n"); //dá mensagem de sucesso
			system("pause");
			break;

			
			default: //se cancelar:
			system("cls");
			printf("Exclusão de usuário cancelada.\n\n\n"); //confirma cancelamento de exclusão
			system("pause");
			break;
				
	}	}
	//Fim do que ocorre se o arquivo existir:
} 



int main() //ponto de partida, tela inicial.

{
	int opcao=0; // Definição de variável. Numero inteiro opção vale 0, este espaço é nosso.
	int laco=1; //mantem laco como 1 
	
	for(laco=1;laco=1;) //usuário só vai sair quando fechar 
	{

		system("cls"); //limpeza de tela
		setlocale (LC_ALL, "Portuguese"); //todas as linguagens de texto são em português e ele acha os acentos na biblioteca.

		//inicio da Lista de opções
		printf("\t\tCartório da EBAC\n\n");
		printf("Escolha a opção desejada do menu:\n\n"); //é possivel fazer numa única linha, com \n já pula para uma próxima linha
		printf("\t1- Registrar novo usuário.\n");
		printf("\t2- Realizar consulta por usuário.\n");
		printf("\t3- Deletar usuário do banco de dados.\n\n\n \tOpção: "); // Fim do menu
		//fim da Lista de opções
		
		scanf("%d", &opcao); //escaneia o que o usuário responde. Armazene na variavel (%d) opção
	
		system("cls");
	
		switch(opcao) //Prossegue com o sistema conforme escolha de utilizador
		{
			case 1: //se escolher 1 
			printf("Você escolheu registrar um novo usuário.\n\n\n");
			system("pause");
			registro();
			break;
			
			case 2: //se escolher 2 
			printf("Você escolheu realizar consulta por um usuário.\n\n\n");
			system("pause");
			consulta();
			break;
			 
			case 3: //se escolher 3
			printf("Você escolheu deletar um usuário do banco de dados.\n\n\n");
			system("pause");
			deletar();
			break;
			
			default: //se escolher uma opção inexistente
			printf("Hmmmm...Essa não parece com uma das opções...\n\n\n");
			system("pause");
			break;
		}	
	}
		
	printf("\n \n \nEsse software é de livre uso da Equipe EBAC \n~Desenvolvido por João Lubawaski"); //assinatura
}



