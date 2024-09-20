//Funções de Hash;
unsigned int funcao_hash(int chave, int tamanho_tabela);
void insere_hash (Aluno *aluno, Aluno **tabela_hash);
void imprime_hash (Aluno **tabela_hash);
void imprime_hashe_v2 (Aluno **tabela_hash, int caso);

unsigned int funcao_hash(int chave, int tamanho_tabela) {           //Método da Multiplicação do livro "Algoritmos - Teoria e Prática";
    const double A = 0.6180339887;                                  //Constante que é o inverso da proporção áurea;
    double valor = chave * A;
    valor = valor - (int)valor;                                     //Parte fracionária;
    return (unsigned int)(tamanho_tabela * valor);
}

void insere_hash (Aluno *aluno, Aluno **tabela_hash){               //Função para inserir aluno na TabelaHash;
    int indice = funcao_hash(aluno->matricula, TAM);                //Chama "funcao_hash" para determinar o índice de qual posição o aluno ficará na tabela;
    if(tabela_hash[indice] == NULL)                                 //Se a posição estiver vazia, insere o aluno nessa posição;
        tabela_hash[indice] = aluno;
    else{
        printf("Colisao na Tabela Hash detectada! Matricula do aluno '%s' alterada para %d\n", aluno->nome, ++aluno->matricula);
        insere_hash(aluno, tabela_hash);                            //Incrementa a matricula do aluno para evitar colisão na tabela e chama a função novamente;
    }
}

void imprime_hash (Aluno **tabela_hash){
    printf("\n----------Inicio da Tabela Hash----------\n\n");
    for (int i = 0; i < TAM; i++){
        if (tabela_hash[i] != NULL){  // Verifica se a posição não é NULL
            printf("Indice %d: Matricula do aluno: %d\n", i, tabela_hash[i]->matricula);
        }
    }
    printf("\n-----------------------------------------\n");
}

void imprime_hashe_v2 (Aluno **tabela_hash, int caso) {        //Aqui recebemos a tabela e o número do caso. Desse modo, sabemos em qual ordem fazer a impressão;
    printf("\n\n----------Inicio da Tabela Hash----------\n\n");
    if(caso == 1){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Matricula: %d\t| Somatorio das notas: %.2f\t| Total de faltas: %d\t| Nome: %s\n", tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->faltas, tabela_hash[i]->nome);
            }
        }
    }
    if(caso == 2){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Nome: %s\t| Matricula: %d\t| Somatorio das notas: %.2f\t| Total de faltas: %d\n", tabela_hash[i]->nome, tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->faltas);
            }
        }
    }
    if(caso == 3){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Somatorio das notas: %.2f\t| Matricula: %d\t| Total de faltas: %d\t| Nome: %s\n", tabela_hash[i]->somatorio_notas, tabela_hash[i]->matricula, tabela_hash[i]->faltas, tabela_hash[i]->nome);
            }
        }
    }
    if(caso == 4){
        for (int i=0; i<global_numero_alunos; i++) {
            if (tabela_hash[i] != NULL) {  //Verifica se a posição não é NULL;
                printf("Numero de faltas: %d\t| Matricula: %d\t| Somatorio das notas: %.2f\t| Nome: %s\n", tabela_hash[i]->faltas, tabela_hash[i]->matricula, tabela_hash[i]->somatorio_notas, tabela_hash[i]->nome);
            }
        }
    }
    printf("\n-----------------------------------------\n");
}
