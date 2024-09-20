//Outras Funções;
void cadastra_aluno(Lista *l, Lista_Avs *l_avs, Aluno **tabela_hash);
void relatorio_alunos (Aluno **tabela_hash, Lista *l);
void chamada (Lista *l);
Lista_notas* cria_lista_notas ();
void insere_nota(Lista_notas* l, Notas *av_aluno);

void cadastra_aluno(Lista *l, Lista_Avs *l_avs, Aluno **tabela_hash){
    Aluno *novo_aluno = (Aluno *)malloc(sizeof(Aluno));
    novo_aluno->nome = (char *)malloc(50);      //Aloca memória para o nome
    novo_aluno->curso = (char *)malloc(20);     //Aloca memória para o curso

    printf("\nMatricula do aluno: ");
    scanf("%d", &novo_aluno->matricula);
    getchar();

    printf("Nome do aluno: ");
    fgets(novo_aluno->nome, 50, stdin);
    novo_aluno->nome[strcspn(novo_aluno->nome, "\n")] = '\0';

    printf("Curso do aluno: ");
    fgets(novo_aluno->curso, 20, stdin);
    novo_aluno->curso[strcspn(novo_aluno->curso, "\n")] = '\0';

    printf("Data de entrada no curso do aluno: ");
    scanf("%d", &novo_aluno->data_curso);
    getchar();

    printf("Total de faltas do aluno: ");
    scanf("%d", &novo_aluno->faltas);
    getchar();

    novo_aluno->somatorio_notas = 0;
    novo_aluno->notas = NULL;

    novo_aluno->prox = l->alunos;
    l->alunos = novo_aluno;

    insere_hash(novo_aluno, tabela_hash);       //Insere aluno na TabelaHash;
    checa_avs(l_avs->avaliacoes, novo_aluno);   //Chama a função "checa_avs" para checar se já existem avaliações e, se tiver, dar a nota do aluno nelas;
    global_numero_alunos++;
    printf("\n");
}

void relatorio_alunos (Aluno **tabela_hash, Lista *l){

    if(l->alunos == NULL){
        printf("Nao ha alunos para se obter um relatorio!\n\n");
        return;
    }

    printf("\n\nDigite um numero para organizar o relatorio por:\n\t1 - Matricula\n\t2 - Nome\n\t3 - Somatorio das notas\n\t4 - Numero de faltas\n");       //Menu;

    int aux;
    scanf("%d", &aux);
    getchar();

    Aluno *tabela_aux [global_numero_alunos];      //Tabela auxiliar com tamanho do número de alunos;
    int j = 0;
    switch (aux){
        case 1:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){             //Passamos os parâmetros da TabelaHash principal para a auxiliar. Mas apenas se a TabelaHash tiver algo;
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Matricula: %d\n", tabela_aux[j++]->matricula);
                    }
                }
            quicksort_mat(tabela_aux, 0, global_numero_alunos-1);                //Chamamos um quicksort para o tipo de organização desejada;
            imprime_hashe_v2(tabela_aux, 1);
            break;
        case 2:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                    }
                }
            quicksort_nome(tabela_aux, 0, global_numero_alunos-1);
            imprime_hashe_v2(tabela_aux, 2);
            break;
        case 3:
                for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Somatorio: %d\n", tabela_aux[j++]->somatorio_notas);
                    }
                }
            quicksort_somatorio (tabela_aux, 0, global_numero_alunos-1);
            imprime_hashe_v2(tabela_aux, 3);
            break;
        case 4:
            for(int i=0; i<TAM; i++){
                    if(tabela_hash[i] != NULL){
                        tabela_aux[j++] = tabela_hash[i];
                        //printf("Numero de faltas: %d\n", tabela_aux[j++]->faltas);
                    }
                }
            quicksort_falta(tabela_aux, 0, global_numero_alunos-1);
            imprime_hashe_v2(tabela_aux, 4);
            break;
        default:
            printf("Selecao invalida! Tente novamente.\n");
    }
}

void chamada (Lista *l){
    Aluno *nova = l->alunos;
    if(nova == NULL){
        printf("Nao ha alunos para realizar a chamada!\n\n");
        return;
    }

    char aux;
    while (nova != NULL){
        printf("Aluno %s - Digite 'P' para Presente || 'A' para Ausente: ", nova->nome);
        scanf(" %c", &aux);         //O espaço antes de %c é para ignorar espaços em branco, caso ainda estejam no buffer na memória;
        switch (aux) {
            case 'P':
            case 'p':
                break;
            case 'a':
            case 'A':
                nova->faltas++;         //Incrementa o número de faltas;
                if (nova->faltas >= 10)
                    printf("----O(a) Aluno(a) %s foi reprovado(a) por faltas!----\n\n", nova->nome);
                break;
            default:
                printf("\nCaracter invalido! Tente novamente.\n");
        }
        nova = nova->prox;      //Passa para o próximo aluno;
    }
}

Lista_notas* cria_lista_notas (){
    Lista_notas *nova = (Lista_notas*) malloc(sizeof(Lista_notas));
    nova->notas = NULL;
    return nova;
}

void insere_nota(Lista_notas* l, Notas *av_aluno){
    av_aluno->prox = l->notas;
    l->notas = av_aluno;
}
