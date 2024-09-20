//Criação e Manipulação de Listas;
Lista* crialista ();
Lista_Avs* crialista_avs ();
void printalista (Lista *l);
void printalista_avs (Lista_Avs *l);

Lista* crialista (){
    Lista *nova = (Lista*) malloc(sizeof(Lista));
    nova->alunos = NULL;
    return nova;
}

Lista_Avs* crialista_avs (){
    Lista_Avs *nova = (Lista_Avs*) malloc(sizeof(Lista_Avs));
    nova->avaliacoes = NULL;
    return nova;
}

void printalista (Lista *l){
    Aluno *novo = l->alunos;
    printf("\n\n----------Inicio da listagem----------\n\n");
    while (novo != NULL){
        printf("Matricula: %d\n", novo->matricula);
        printf("Nome: %s\n", novo->nome);
        printf("Curso: %s\n", novo->curso);
        printf("Total de faltas: %d\n\n", novo->faltas);
        novo = novo->prox;
    }
    printf("--------------------------------------\n\n");
}

void printalista_avs (Lista_Avs *l){
    Avaliacao *novo = l->avaliacoes;
    printf("\n\n----------Inicio da listagem de avaliacoes----------\n\n");
    while (novo != NULL){
        printf("Codigo da avaliacao: %d\n", novo->cod_avaliacao);
        printf("Nome da avaliacao: %s\n", novo->nome_avaliacao);
        printf("Curso da avaliacao: %d\n", novo->disciplina);
        printf("Valor da avaliacao: %.2f\n", novo->valor_avaliacao);
        novo = novo->prox;
        printf("\n");
    }
    printf("----------------------------------------------------\n\n");
}
