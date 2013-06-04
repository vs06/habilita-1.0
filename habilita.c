# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define MAXP 1000

struct db {
     int flag;
	   char pergunta[400];
	   char a[255];
	   char b[255];
	   char c[255];
	   char d[255];
	   char e[255];
	   char correta[8];
	   char resposta;	   	   	   	   
	  };

int inicializa_db (struct db *, FILE *);
char mostra_pergunta (struct db *, int );
void teste (struct db *, int );
int confere_respostas (struct db *, int);
float calcula_porcentagem (int );

int main ()
{
 FILE *arq;
 char *nome_arq="bancodequestoes.db";
 struct db *questoes = (struct db *) malloc (MAXP*sizeof(struct db));
 int N_perguntas;
 int N_acertos=0;
 int N_porcentagem=0;
 time_t inicio;
 time_t fim;
 
 arq = fopen (nome_arq, "r");
 if (arq == NULL)
   printf("Erro na abertura do banco de questoes. Digite Ctrl + C para sair\n");
 
 inicio = time(NULL);
 N_perguntas= inicializa_db(questoes, arq);
 teste(questoes, N_perguntas);
 fim = time(NULL);
 
 system("CLS");
 N_acertos= confere_respostas(questoes, N_perguntas);
 N_porcentagem= calcula_porcentagem(N_acertos);
 printf("Total de acertos: %d\n", N_acertos );
 
 if (N_porcentagem >= 70)
   {
    printf("Porcentagem de acertos: %d", N_porcentagem);
    printf("%\nResultado final: APROVADO\n");
   }
 else
   {
    printf("Porcentagem de acertos: %d", N_porcentagem);
    printf("%\nResultado final: REPROVADO\n");
   }
 printf("Tempo total: %.f minuto(s)\n", difftime(fim, inicio)/60.0);
   
 printf("\n\n\t######################################################\n");
 printf("\t#             Habilita (C) 2008 by vs06              #\n");
 printf("\t#               Creative Commons 2.5                 #\n");
 printf("\t#            http://www.inf.ufpr.br/vs06             #\n");
 printf("\t######################################################\n");
 
 system("PAUSE");
 return EXIT_SUCCESS;
}

int inicializa_db (struct db *p, FILE *arqui)
{
 int i=0;

 while (!feof(arqui))
      {
       p[i].flag=0;
       fgets(p[i].pergunta, 401, arqui);
       fgets(p[i].a, 256, arqui);
       fgets(p[i].b, 256, arqui);
       fgets(p[i].c, 256, arqui);
       fgets(p[i].d, 256, arqui);
       fgets(p[i].e, 256, arqui);
       fgets(p[i].correta, 9, arqui);
       i++;
      }
 return i;
}

void teste (struct db *p, int num_perg)
{
 int i, j;
 
 i=0;
 while (i<30)
   {
    srand((unsigned)time(NULL));
    j = (rand()%num_perg -1);
    if (j == -1)
      j=0;
    if (p[j].flag == 0)
     {
      p[j].resposta= mostra_pergunta(p, j);
      i++;
     }
   }  
 
}

char mostra_pergunta (struct db *p, int i)
{
 char resposta;

 p[i].flag=1;

 printf("%s", p[i].pergunta);
 printf("a) %s", p[i].a);
 printf("b) %s", p[i].b);
 printf("c) %s", p[i].c);
 printf("d) %s", p[i].d);
 printf("e) %s", p[i].e);
 printf("Digite a resposta correta:(""a"", ""b"", ""c"", ""d"" ou ""e"")\n");
 fflush(stdin);
 scanf("%c", &resposta);
 printf("Resposta correta: %s\n", p[i].correta);
 
 return resposta;
}

int confere_respostas (struct db *p, int num_perg)
{
 int acertos=0;
 int i;
 
 for (i=0; i<num_perg; i++)
    {
     if (p[i].flag == 1)         
       if (p[i].resposta == p[i].correta[6])
         acertos++;
    }
    
  return acertos;
}

float calcula_porcentagem (int certas)
{
  return (certas*100)/30;
}
