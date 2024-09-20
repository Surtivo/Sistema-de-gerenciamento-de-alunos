//Funções de Avaliação;
void distribui_avaliacao (Avaliacao *av, Lista *l);
int checa_nota_av (Avaliacao *av, float nota);
int checa_av_igual (Lista_Avs *l_avs, Avaliacao *av);
void cadastra_avaliacao (Lista *l, Lista_Avs *l_avs);
void checa_avs (Avaliacao *teste, Aluno *aluno);
void lista_avaliacoes (Lista_Avs *l_avs, Lista *l);
void relatorio_avaliacao (Avaliacao *av, Lista *l);

void distribui_avaliacao(Avaliacao *av, Lista *l){
    if (l->alunos == NULL){                                        //Se não houver alunos cadastrados, a função termina;
        return;
    }

    printf("\n----Distribuicao de notas----\n");
    Aluno *atual = l->alunos;
    while (atual != NULL){
        if (atual->faltas < 10){                                     //Se o aluno ter mais de dez faltas o sistema ira ignorar ele;
            Notas *nova_nota = (Notas *)malloc(sizeof(Notas));       //Aloca memória para a nota do aluno nessa avaliação;
            nova_nota->cod_avaliacao = av->cod_avaliacao;
            nova_nota->disciplina = av->disciplina;

            printf("Nota do aluno %s: ", atual->nome);
            scanf("%f", &nova_nota->nota_aluno);
            getchar();

            float checagem = checa_nota_av(av, nova_nota->nota_aluno);

            while(checagem == -1){                          //Caso a nota fornecida para o aluno seja acima do valor da avaliacao, esse loop não permitirá a funçao seguir;
                printf("\nNota invalida! Nota maior que o valor da avaliacao.\nTente novamente com um valor apropriado como nota para essa avaliacao.\n\n");
                printf("Nota do aluno %s: ", atual->nome);
                scanf("%f", &nova_nota->nota_aluno);
                getchar();
                checagem = checa_nota_av(av, nova_nota->nota_aluno);
            }

            nova_nota->prox = atual->notas;
            atual->notas = nova_nota;
            atual->somatorio_notas += nova_nota->nota_aluno;
        }
        atual = atual->prox;
    }
    printf("-----------------------------\n\n");
}

int checa_nota_av (Avaliacao *av, float nota){
    if(nota > av->valor_avaliacao){
        return -1;
    }
    return 1;
}

int checa_av_igual (Lista_Avs *l_avs, Avaliacao *av){
    Avaliacao *aux = l_avs->avaliacoes;
    while(aux != NULL){
        if(av->cod_avaliacao == aux->cod_avaliacao){
            printf("\nEsse codigo de avaliacao ja esta em uso! Insercao terminda.\nPor favor, re-insira a avaliacao novamente com um codigo que nao esteja em uso.\n\n");
            return -1;
        }
        aux = aux->prox;
    }
    return 1;
}

void cadastra_avaliacao (Lista *l, Lista_Avs *l_avs){
    Avaliacao *av = (Avaliacao *)malloc(sizeof(Avaliacao));         //Aloca memória para a nova avaliação;
    av->nome_avaliacao = (char *)malloc(20);                        //Aloca memória para a string;

    printf("Nome da avaliacao: ");
    fgets(av->nome_avaliacao, 20, stdin);
    av->nome_avaliacao[strcspn(av->nome_avaliacao, "\n")] = '\0';   //Elimina o "troca linha" recebido pela função "fgets" ao apertar ENTER e o substitui por um caracter de fim de string;
                                                                    //Isso é feito para evitar problemas na impressão e evitar um "troca linha" nela;
    printf("Valor da avaliacao: ");
    scanf("%f", &av->valor_avaliacao);
    getchar();                                                      //Consome o "troca linha" que a função "scanf" não lê, mas que fica armazenado no buffer da memória;

    printf("Identificador da avaliacao: ");
    scanf("%d", &av->cod_avaliacao);
    getchar();

    printf("Codigo da disciplina ao qual a avaliacao pertence: ");
    scanf("%d", &av->disciplina);
    getchar();

    if(checa_av_igual(l_avs, av) == -1){                            //Confere se o codigo da avaliação não está em uso. Se estiver, a função "checa-avs" retorna -1 e o processo termina.
        free(av);                                                   //Libera o espaço da memória;
        return;
    }

    //Encadeia as avaliações;
    av->prox = l_avs->avaliacoes;
    l_avs->avaliacoes = av;
    distribui_avaliacao(l_avs->avaliacoes, l);                      //Chama a função "distribui_avalicao" para dar a nota de todos o alunos nela;
    printf("\n");                                                   //É passado como parâmetro a cabeça da lista de avaliações que agora é a nova avaliação, av;
}

void checa_avs(Avaliacao *teste, Aluno *aluno){
    if (teste == NULL) return;              //Se não houver avaliações a função termina;

    float aux;
    printf("\nAvaliacao encontrada!\nDigite a nota desse aluno na avaliacao: %d - %s, valor: %.2f - ", teste->cod_avaliacao, teste->nome_avaliacao, teste->valor_avaliacao);
    scanf("%f", &aux);
    getchar();

    float checagem = checa_nota_av(teste, aux);

    while(checagem == -1){                          //Caso a nota fornecida para o aluno seja acima do valor da avaliacao, esse loop não permitirá a funçao seguir;
        printf("\nNota invalida! Nota maior que o valor da avaliacao.\nTente novamente com um valor apropriado como nota para essa avaliacao.\n");
        printf("\nDigite a nota desse aluno na avaliacao: %d - %s, valor: %.2f - ", teste->cod_avaliacao, teste->nome_avaliacao, teste->valor_avaliacao);
        scanf("%f", &aux);
        getchar();
        checagem = checa_nota_av(teste, aux);
    }

    Notas *nova_nota = (Notas *)malloc(sizeof(Notas));    //Aloca memória para a nova nota;
    nova_nota->cod_avaliacao = teste->cod_avaliacao;
    nova_nota->disciplina = teste->disciplina;
    nova_nota->nota_aluno = aux;
    aluno->somatorio_notas += aux;
    //Encadeia as notas do aluno;
    nova_nota->prox = aluno->notas;
    aluno->notas = nova_nota;

    checa_avs(teste->prox, aluno);                        //Chama a função novamente, mas agora com a próxima avaliação;
}

void lista_avaliacoes (Lista_Avs *l_avs, Lista *l){
    Avaliacao *av = l_avs->avaliacoes;
    int cod_av;

    if(l_avs == NULL || l_avs->avaliacoes == NULL){
        printf("Nao ha avaliacoes!\n\n");
        return;
    }

    printf("Escolha uma das avaliacoes informando seu codigo:\n");
    while(av != NULL){
        printf("\tCodigo: %d - Nome: %s\n", av->cod_avaliacao, av->nome_avaliacao);
        av = av->prox;
    }
    scanf("%d", &cod_av);
    getchar();

    av = l_avs->avaliacoes;

    while(av != NULL){
        if(av->cod_avaliacao == cod_av){
            relatorio_avaliacao(av, l);
            return;
        }
        av = av->prox;
    }
    printf("Avaliacao com codigo %d nao foi encontrada!\n\n", cod_av);
}

void relatorio_avaliacao (Avaliacao *av, Lista *l){             //Deu erro apenas uma vez;
    if (l == NULL || l->alunos == NULL || av == NULL) {
        printf("\nErro: Lista de alunos vazia ou avaliacao inexistente.\n\n");
        return;
    }

    printf("\n----Relatorio da avaliacao: %d - %s ----\n", av->cod_avaliacao, av->nome_avaliacao);
    float max = 0;
    float min = 100;        //Valor alto pois toda nota será menor que 100 ou, na pior das hipóteses, todas as notas serão 100;
    float soma_notas = 0;
    int num_provas = 0;

    Aluno *atual = l->alunos;
    Notas *av_aluno;

    while(atual != NULL){               //Enquanto houver um aluno, passaremos por cada avaliação dele até indentificar a avaliação que se quer;
        av_aluno = atual->notas;        //av_aluno é uma avaliação da lista de avaliações de um aluno;
        while(av_aluno != NULL){
            if(av_aluno->cod_avaliacao == av->cod_avaliacao){
                soma_notas = soma_notas + av_aluno->nota_aluno;
                num_provas++;
                if(av_aluno->nota_aluno < min)
                    min = av_aluno->nota_aluno;     //Altera nota mínima;
                if(av_aluno->nota_aluno > max)
                    max = av_aluno->nota_aluno;     //Altera nota máxima;
                break;                              //Se já identificamos a avaliação que se pede, já podemos sair do loop para encontrar a avaliação;
            }else av_aluno = av_aluno->prox;        //Se ainda não a encontramos, passamos para a próxima avalição do aluno;
        }
        if(av_aluno == NULL)
            printf("O aluno %s de matricula %d nao fez essa avaliacao!\n", atual->nome, atual->matricula);
        atual = atual->prox;        //Ao fim da busca pela avaliação desejada, passamos para o próximo aluno;
    }

    printf("Nota Maxima: %.2f\nNota Minima: %.2f\nMedia das notas: %.2f\n\n", max, min, (soma_notas/num_provas));
    ordenaNotasAvaliacao(l, av->cod_avaliacao);         //Chama a função "ordenaNotasAvaliacao" para ordenar as notas de forma decrescente;
    printf("--------------------------------------\n\n");
}
