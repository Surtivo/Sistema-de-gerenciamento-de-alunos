int main(){
    Aluno* TabelaHash [TAM] = {NULL};                             //A tabela possuirá endereços do tipo Aluno. Será uma tabela que aponta para onde o aluno está na memória;
    Lista *l = crialista();
    Lista_Avs *l_avs = crialista_avs();
    int menu = 1;

    while(menu != 0){
        printf("Digite um numero para:\n\t1 - Cadastrar um aluno;\n\t2 - Cadastrar uma avaliacao;\n\t3 - Realizar chamada;\n\t4 - Solicitar relatorio dos alunos;\n\t5 - Soliciar relatorio de uma avaliacao;\n\t0 - Sair;\n");       //Menu;
        scanf("%d", &menu);
        getchar();

        switch (menu){
        case 0:
            return 0;
        case 1:
            cadastra_aluno(l, l_avs, TabelaHash);
            break;
        case 2:
            cadastra_avaliacao(l, l_avs);
            break;
        case 3:
            chamada(l);
            break;
        case 4:
            relatorio_alunos(TabelaHash, l);
            break;
        case 5:
            lista_avaliacoes(l_avs, l);
            break;
        default:
            printf("Selecao invalida! Tente novamente.\n\n");
        }
    }
}
