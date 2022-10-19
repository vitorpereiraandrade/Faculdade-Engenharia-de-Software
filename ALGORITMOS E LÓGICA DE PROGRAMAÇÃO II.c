QUESTÃO 1

A Pandemia do COVID-19 está lotando a fila dos hospitais, sabe-se que além da vacina, a prevenção através do distanciamento social, uso de álcool para higienização das mãos e uso de máscara ainda é o melhor método para controle da pandemia. A tecnologia tem sido também uma grande aliada para que a vida de milhões de pessoas continuem relativamente normal, muitos programas de computadores realizam tarefas de forma automatizada, evitando assim a aproximação entre as pessoas, podemos ver por exemplo em supermercados, caixas com autoatendimento. Ferramentas de reuniões e aulas online nunca foram tão utilizadas como agora na Pandemia, graças a essas tecnologia o impacto da pandemia se torna cada vez menor além de se promover o distanciamento social.

Imagine então que você faz parte de uma equipe de Tecnologia e Desenvolvimento de um grande hospital no qual possui um pronto atendimento 24 horas que atende as mais diversas emergências médicas, desde doenças infecciosas como o COVID-19 a diversas outros problemas de saúde. Devido a pandemia a fila para o primeiro atendimento está aumentando cada vez mais, sendo um grande risco para contaminação pelo Coronavírus devido a alta demanda e aglomeração que se formam com a filas.

Por isso você foi encarregado de criar um programa que faça uma triagem inicial através de totens eletrônicos que serão disponibilizados no pronto atendimento, agilizando assim o atendimento e fazendo a separação dos suspeitos de COVID-19 dos não suspeitos, garantindo um distanciamento e redução da infecção gerado pelas filas.

Neste programa o paciente chegará ao totem e fará um cadastro prévio indicando os seguintes dados:
    - CPF
    - Nome
    - Sexo
    - Idade

Após o cadastro o paciente deve responder a um questionário de sintomas no qual cada sintoma terá um peso para avaliação do risco de COVID, os sintomas são:

    - Tem Febre? (5 pontos)
    - Tem dor de cabeça? (1 ponto)
    - Tem secreção nasal ou espirros? (1 ponto)
    - Tem dor/irritação na garganta? (1 ponto)
    - Tem tosse seca? (3 pontos)
    - Tem dificuldade respiratória? (10 pontos)
    - Tem dores no corpo? (1 ponto)
    - Tem diarréia? (1 ponto)
    - Esteve em contato, nos últimos 14 dias, com um caso diagnosticado com COVID-19? (10 pontos)
    - Esteve em locais com grande aglomeração? (3 pontos)

OBS: Caso o usuário indique que SIM (S) soma o valor, caso seja indicado NÃO (N) não soma o valor.

O encaminhamento será feito para 3 alas, as de Risco Baixo, Risco Médio e Risco Alto.
    Para o risco baixo o total de pontos dos sintomas deverão ser de 0 a 9;
    Para o risco médio de 10 a 19 pontos;
    para o risco alto de 20 ou mais pontos.

Após preenchimento indicar para qual ala o paciente deverá se dirigir

Para finalizar deve ser salvo em um arquivo com os dados do paciente e qual sua pontuação de sintomas para que seja realizada possíveis auditorias por parte da direção do hospital.

?A sua atividade MAPA deve ser entregue em um arquivo de código fonte para linguagem C (extensão .c).

Algumas funções que serão úteis durante o desenvolvimento do programa:
 
* system(“pause”) – chamada de sistema que “pausa” o programa e o faz aguardar pelo usuário;
* system(“cls”) – chamada de sistema que limpa os caracteres que foram impressos na tela anteriormente;
* fflush(stdin) – limpar o buffer do teclado. Essa função deve sempre ser utilizada após ter utilizado alguma função de entrada de dados como o scanf, gets, etc. Isso se dá pois em algumas situações o buffer do teclado mantém “lixo de memória”, prejudicando a próxima operação de entrada do programa;
* A função setlocale(LC_ALL, "Portuguese") da biblioteca locale.h pode ser útil, caso você queira que os acentos e pontuações da língua portuguesa sejam impressos corretamente.




// NOME: VITOR PEREIRA ANDRADE
// RA: 20119128-5


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

	char nome[200];
	char cpf[50];
	char sexo [2];
	int idade;
	char reposta1;
	int soma;
	
struct elemento{
	char pergunta[200];
	int pontuacao;
};	

struct elemento questoes[] = {
	{ .pergunta = "Tem febre? ", .pontuacao = 5},
	{ .pergunta = "Tem dor de cabeca? ", .pontuacao = 1},
	{ .pergunta = "Tem secrecao nasal ou espirros? ", .pontuacao = 1},
	{ .pergunta = "Tem dor/irritacao na garganta? ", .pontuacao = 1},
	{ .pergunta = "Tem tosse seca? ", .pontuacao = 3},
	{ .pergunta = "Tem dificuldade respiratoria? ", .pontuacao = 10},
	{ .pergunta = "Tem dores no corpo? ", .pontuacao = 1},
	{ .pergunta = "Tem diarreia? ", .pontuacao = 1},
	{ .pergunta = "Esteve em contato, nos ultimos 14 dias, com um caso diagnosticado com COVID-19? ", .pontuacao = 10},
	{ .pergunta = "Esteve em locais com grande aglomeracao? ", .pontuacao = 3},
	
};


void questionario(){
	
	int i = 0;
	int soma = 0;
	char resposta;
	
	FILE *pont_arq;
	pont_arq = fopen("arquivo.txt", "a");
	
	if (pont_arq == NULL){
		printf("Erro ao criar arquivo");
		
	}
	
	system("cls");
	printf("Responda o questionario com S(sim) ou N(nao)\n");
	for(i = 0; i < 10; i++){
		printf("%s", questoes[i].pergunta);
		scanf("%c", &resposta);
		fflush(stdin);
		fprintf(pont_arq, "%s %c\n", questoes[i].pergunta, resposta);
		if(resposta == 'S' || resposta == 's'){
			soma = soma + questoes[i].pontuacao;
		}	
		
	}
	fprintf(pont_arq, "Pontuacao Total: %d", soma);
	fclose(pont_arq);
	
	system("cls");
	if(soma >= 0 && soma < 10){
		printf("A soma foi %d pontos e paciente deve se encaminhar para ala de BAIXO RISCO", soma);
	}
	if(soma >= 10 && soma < 20){
		printf("A soma foi %d pontos e paciente deve se encaminhar para ala de MEDIO RISCO", soma);
	}
	if(soma >= 20){
		printf("A soma foi %d pontos e paciente deve se encaminhar para ala de ALTO RISCO", soma);
	}
	soma = 0;
	
	getchar();
}

void cadastroPaciente(){
	
	setlocale(LC_ALL, "portuguese");
	
	FILE *pont_arq;
	pont_arq = fopen("arquivo.txt", "a");
	
	if (pont_arq == NULL){
		printf("Erro ao criar arquivo");
		
	}
	
	printf("Nome Paciente: ");
	scanf("%s", nome);
	fflush(stdin);
	
	printf("CPF: ");
	scanf("%s", cpf);
	fflush(stdin);
	
	printf("Sexo (M/F): ");
	scanf("%s", sexo);
	fflush(stdin);
	
	printf("Idade: ");
	scanf("%d", &idade);
	fflush(stdin);
	
	fprintf(pont_arq, "Nome: %s\n", nome);
	fprintf(pont_arq, "CPF: %s\n", cpf);
	fprintf(pont_arq, "Sexo: %s\n", sexo);
	fprintf(pont_arq, "Idade: %d\n", idade);
	
	fclose(pont_arq);
	
	printf("**** Dados gravados com sucesso ****");
	getchar();
	questionario();		
}



int main() {
	setlocale(LC_ALL, "portuguese");
	
	int menu;
	
	printf("1 - Cadastrar Paciente: \n");
	printf("0 - Sair: \n ");
	printf("Selecione uma opção: \n");
	scanf("%i", &menu);
	fflush(stdin);
	
	switch(menu) {
		case 0:
			printf("\n******* Finalizado ******* ");
			break;
		case 1: 
			cadastroPaciente();
			break;
		default:
			break;
	}
	
		
}
