QUEST�O 1

A Pandemia do COVID-19 est� lotando a fila dos hospitais, sabe-se que al�m da vacina, a preven��o atrav�s do distanciamento social, uso de �lcool para higieniza��o das m�os e uso de m�scara ainda � o melhor m�todo para controle da pandemia. A tecnologia tem sido tamb�m uma grande aliada para que a vida de milh�es de pessoas continuem relativamente normal, muitos programas de computadores realizam tarefas de forma automatizada, evitando assim a aproxima��o entre as pessoas, podemos ver por exemplo em supermercados, caixas com autoatendimento. Ferramentas de reuni�es e aulas online nunca foram t�o utilizadas como agora na Pandemia, gra�as a essas tecnologia o impacto da pandemia se torna cada vez menor al�m de se promover o distanciamento social.

Imagine ent�o que voc� faz parte de uma equipe de Tecnologia e Desenvolvimento de um grande hospital no qual possui um pronto atendimento 24 horas que atende as mais diversas emerg�ncias m�dicas, desde doen�as infecciosas como o COVID-19 a diversas outros problemas de sa�de. Devido a pandemia a fila para o primeiro atendimento est� aumentando cada vez mais, sendo um grande risco para contamina��o pelo Coronav�rus devido a alta demanda e aglomera��o que se formam com a filas.

Por isso voc� foi encarregado de criar um programa que fa�a uma triagem inicial atrav�s de totens eletr�nicos que ser�o disponibilizados no pronto atendimento, agilizando assim o atendimento e fazendo a separa��o dos suspeitos de COVID-19 dos n�o suspeitos, garantindo um distanciamento e redu��o da infec��o gerado pelas filas.

Neste programa o paciente chegar� ao totem e far� um cadastro pr�vio indicando os seguintes dados:
    - CPF
    - Nome
    - Sexo
    - Idade

Ap�s o cadastro o paciente deve responder a um question�rio de sintomas no qual cada sintoma ter� um peso para avalia��o do risco de COVID, os sintomas s�o:

    - Tem Febre? (5 pontos)
    - Tem dor de cabe�a? (1 ponto)
    - Tem secre��o nasal ou espirros? (1 ponto)
    - Tem dor/irrita��o na garganta? (1 ponto)
    - Tem tosse seca? (3 pontos)
    - Tem dificuldade respirat�ria? (10 pontos)
    - Tem dores no corpo? (1 ponto)
    - Tem diarr�ia? (1 ponto)
    - Esteve em contato, nos �ltimos 14 dias, com um caso diagnosticado com COVID-19? (10 pontos)
    - Esteve em locais com grande aglomera��o? (3 pontos)

OBS: Caso o usu�rio indique que SIM (S) soma o valor, caso seja indicado N�O (N) n�o soma o valor.

O encaminhamento ser� feito para 3 alas, as de Risco Baixo, Risco M�dio e Risco Alto.
    Para o risco baixo o total de pontos dos sintomas dever�o ser de 0 a 9;
    Para o risco m�dio de 10 a 19 pontos;
    para o risco alto de 20 ou mais pontos.

Ap�s preenchimento indicar para qual ala o paciente dever� se dirigir

Para finalizar deve ser salvo em um arquivo com os dados do paciente e qual sua pontua��o de sintomas para que seja realizada poss�veis auditorias por parte da dire��o do hospital.

?A sua atividade MAPA deve ser entregue em um arquivo de c�digo fonte para linguagem C (extens�o .c).

Algumas fun��es que ser�o �teis durante o desenvolvimento do programa:
 
* system(�pause�) � chamada de sistema que �pausa� o programa e o faz aguardar pelo usu�rio;
* system(�cls�) � chamada de sistema que limpa os caracteres que foram impressos na tela anteriormente;
* fflush(stdin) � limpar o buffer do teclado. Essa fun��o deve sempre ser utilizada ap�s ter utilizado alguma fun��o de entrada de dados como o scanf, gets, etc. Isso se d� pois em algumas situa��es o buffer do teclado mant�m �lixo de mem�ria�, prejudicando a pr�xima opera��o de entrada do programa;
* A fun��o setlocale(LC_ALL, "Portuguese") da biblioteca locale.h pode ser �til, caso voc� queira que os acentos e pontua��es da l�ngua portuguesa sejam impressos corretamente.




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
	printf("Selecione uma op��o: \n");
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
