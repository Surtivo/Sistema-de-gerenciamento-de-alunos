// Funções de Ordenação;
void selectionsort (Aluno **tabela_hash, int t)
void troca_notas (Notas *a, Notas *b);
Notas* particiona(Notas *inicio, Notas *fim);
void QuickSort(Notas *inicio, Notas *fim);
int particiona_mat(Aluno **tabela_hash, int beg, int end);
void quicksort_mat(Aluno **tabela_hash, int beg, int end);
int particiona_nome (Aluno **tabela_hash, int beg, int end);
void quicksort_nome (Aluno **tabela_hash, int beg, int end);
int particiona_somatorio (Aluno **tabela_hash, int beg, int end);
void quicksort_somatorio(Aluno **tabela_hash, int beg, int end);
int particiona_falta(Aluno **tabela_hash, int beg, int end);
void quicksort_falta(Aluno **tabela_hash, int beg, int end);
void troca_posicao (Aluno **tabela_hash, int k, int l);
void printa_lista_ordenada (Lista_notas* l);
void ordenaNotasAvaliacao(Lista *l, int cod_avaliacao);


void selectionsort (Aluno **tabela_hash, int t){
    int menor;
	for(int i=0; i<t-1; i++)
	{
	    menor = i;

		for(int j=(i+1); j<=t; j++)
		{
			if(tabela_hash[j]->matricula<tabela_hash[menor]->matricula)
			    menor=j;
		}
		troca_posicao(tabela_hash, i, menor);
	}
}

void troca_notas (Notas *a, Notas *b){
    float tempNota = a->nota_aluno;
    int tempDisciplina = a->disciplina;
    int tempCodAvaliacao = a->cod_avaliacao;

    a->nota_aluno = b->nota_aluno;
    a->disciplina = b->disciplina;
    a->cod_avaliacao = b->cod_avaliacao;

    b->nota_aluno = tempNota;
    b->disciplina = tempDisciplina;
    b->cod_avaliacao = tempCodAvaliacao;
}

Notas* particiona(Notas *inicio, Notas *fim){
    int pivo = (int) fim->nota_aluno;
    Notas *i = inicio;
    Notas *j = inicio;

    while (j != fim){
        if (j->nota_aluno > pivo){
            troca_notas(i, j);
            i = i->prox;
        }
        j = j->prox;
    }
    troca_notas(i, fim);
    return i;
}

void QuickSort(Notas *inicio, Notas *fim){
    if (inicio != NULL && fim != NULL && inicio != fim && inicio != fim->prox){
        Notas *pivo = particiona(inicio, fim);
        if (pivo != NULL){
            if (inicio != pivo){
                QuickSort(inicio, pivo->prox);
            }
            if (pivo->prox != NULL){
                QuickSort(pivo->prox, fim);
            }
        }
    }
}

int particiona_mat(Aluno **tabela_hash, int beg, int end) {

    int pivo = ((tabela_hash[end]->matricula) + (tabela_hash[beg]->matricula) + (tabela_hash[(end+beg)/2]->matricula)) / 3;

    while (beg < end) {
        while (beg<end && (tabela_hash[beg] == NULL || tabela_hash[beg]->matricula <= pivo)) {
            beg++;
        }

        while (beg<end && (tabela_hash[end] == NULL || tabela_hash[end]->matricula > pivo)) {
            end--;
        }
        troca_posicao(tabela_hash, beg, end);
    }
    return beg;
}

void quicksort_mat(Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_mat(tabela_hash, beg, end);
        quicksort_mat(tabela_hash, beg, mid-1);
        quicksort_mat(tabela_hash, mid, end);
    }
}

int particiona_nome (Aluno **tabela_hash, int beg, int end) {
    Aluno *pivo = tabela_hash[end]; // Escolhe o último elemento como pivô
    int i = beg - 1;

    for (int j = beg; j < end; j++) {
        if (strcmp(tabela_hash[j]->nome, pivo->nome) < 0) {
            i++;
            troca_posicao(tabela_hash, i, j);
        }
    }

    troca_posicao(tabela_hash, i + 1, end);
    return (i + 1);
}

void quicksort_nome (Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_nome(tabela_hash, beg, end);
        quicksort_nome(tabela_hash, beg, mid - 1);
        quicksort_nome(tabela_hash, mid, end);
    }
}

int particiona_somatorio(Aluno **tabela_hash, int beg, int end) {       //Deu erro apenas 1 vez;

    float pivo = ((tabela_hash[end]->somatorio_notas) + (tabela_hash[beg]->somatorio_notas) + (tabela_hash[(end+beg)/2]->somatorio_notas)) / 3;

    while (beg < end) {
        while (beg<end && (tabela_hash[beg] == NULL || tabela_hash[beg]->somatorio_notas <= pivo)) {
            beg++;
        }

        while (beg<end && (tabela_hash[end] == NULL || tabela_hash[end]->somatorio_notas > pivo)) {
            end--;
        }
        troca_posicao(tabela_hash, beg, end);
    }
    return beg;
}

void quicksort_somatorio(Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_somatorio(tabela_hash, beg, end);
        quicksort_somatorio(tabela_hash, beg, mid-1);
        quicksort_somatorio(tabela_hash, mid, end);
    }
}

int particiona_falta(Aluno **tabela_hash, int beg, int end) {

    int pivo = ((tabela_hash[end]->faltas) + (tabela_hash[beg]->faltas) + (tabela_hash[(end+beg)/2]->faltas)) / 3;

    while (beg < end) {
        while (beg<end && (tabela_hash[beg] == NULL || tabela_hash[beg]->faltas <= pivo)) {
            beg++;
        }

        while (beg<end && (tabela_hash[end] == NULL || tabela_hash[end]->faltas > pivo)) {
            end--;
        }
        troca_posicao(tabela_hash, beg, end);
    }
    return beg;
}

void quicksort_falta(Aluno **tabela_hash, int beg, int end) {
    if (beg < end) {
        int mid = particiona_falta(tabela_hash, beg, end);
        quicksort_falta(tabela_hash, beg, mid-1);
        quicksort_falta(tabela_hash, mid, end);
    }
}

void troca_posicao(Aluno **tabela_hash, int k, int l) {
    if (k < 0 || l < 0 || k >= global_numero_alunos || l >= global_numero_alunos) {
        printf("Indices fora dos limites!\n");
        return;
    }

    Aluno *temp = tabela_hash[k];
    tabela_hash[k] = tabela_hash[l];
    tabela_hash[l] = temp;
}

void printa_lista_ordenada (Lista_notas* l){
    int i = 1;
    Notas *atual = l->notas;
    printf("Notas Gerais:\n");
    while (atual != NULL) {
        printf("Nota %d: %.2f\n",i++, atual->nota_aluno);
        atual = atual->prox;
    }
}

void ordenaNotasAvaliacao(Lista *l, int cod_avaliacao){
    if (l == NULL || l->alunos == NULL) return;         //Se não houver nenhum aluno cadastrado, não há nada para ordenar. A função termina;

    Lista_notas *l_notas = cria_lista_notas();
    Aluno *atual = l->alunos;

    //Encontrar todas as notas para a avaliação específica;
    while (atual != NULL){
        Notas *av_aluno = atual->notas;
        while (av_aluno != NULL){
            if (av_aluno->cod_avaliacao == cod_avaliacao){
                Notas *nova_nota = (Notas *)malloc(sizeof(Notas));
                *nova_nota = *av_aluno;                 //Copiar dados da nota;
                nova_nota->prox = l_notas->notas;
                l_notas->notas = nova_nota;
            }
            av_aluno = av_aluno->prox;                  //Se a avaliação atual não for a procurada, passamos para a próxima;
        }
        atual = atual->prox;                            //Passamos para o próximo aluno;
    }

    //Ordenar usando QuickSort;
    Notas *inicio = l_notas->notas;                 //Marca quem é o inicio;
    Notas *fim = inicio;
    while (fim != NULL && fim->prox != NULL){       //Para conseguir marcar quem é o final;
        fim = fim->prox;
    }

    if (inicio != NULL && fim != NULL){
        QuickSort(inicio, fim);                     //Chama o QuickSort para começar a ordenação;
    }

    printa_lista_ordenada(l_notas);

    //Libere a memória da lista de notas após a impressão;
    Notas *temp;
    while (l_notas->notas != NULL) {
        temp = l_notas->notas;
        l_notas->notas = l_notas->notas->prox;
        free(temp);
    }
    free(l_notas);
}
