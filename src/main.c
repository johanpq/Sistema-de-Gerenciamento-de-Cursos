/* #include "./alunos/alunos.c" */
#include "./cursos/cursos.c"

/* union aluno_curso {
    char NomeCurso[50];
    int Codigo;
};

union aluno_matricula {
    char NomeAluno[50];
    int Matricula;
}; */

int main() {
    /* AlunoCurso *Alunocurso = (AlunoCurso*)malloc(sizeof(AlunoCurso));
    AlunoMatricula *Alunomatricula = (AlunoMatricula*)malloc(sizeof(AlunoMatricula)); */
    ListaMatricula *Lista = NULL;
    Alunos *Var_Alunos = (Alunos*)malloc(sizeof(Alunos));
    Cursos *Var_Cursos = (Cursos*)malloc(sizeof(Cursos)); 

    char NomeAluno[50];
    int NumeroMatricula;
    float notas[3];
    int contador = 0, SairCase = 0;
    int contador2 = 0, contador3, Vagas2 = 3;

    int escolha = 0, escolha2 = 0;

    char Nomealuno[50], Nomecurso[50];
    int matricula, codigo;

    char NomeCurso[50];
    int CodigoCurso;
    int Vagas = 0; //limite de vagas no curso criado

    int MenuEscolha;

    do{
        //system("cls");
        menu();
        scanf("%d", &MenuEscolha);

        switch(MenuEscolha) {
        case 1:
                system("cls");
                SairCase = 0;
                while(SairCase != 2) {
                    system("cls");
                    int Comparar = 0;
                    contador++;
                    Vagas++;
                    printf("Informe o nome do aluno(a) %i: ", contador);
                    scanf(" %[^\n]", NomeAluno);
                    getchar();
                    printf("Infome o numero de matricula do aluno(a) %i: ", contador);
                    scanf("%d", &NumeroMatricula);

                    Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);

                    while(Comparar == 1) {
                        system("cls");
                        Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);
                        if(Comparar == 1) {
                            printf("Informe o numero da matricula novamente: ");
                            scanf("%d", &NumeroMatricula);
                            Comparar = CompararMatricula(Var_Alunos, NumeroMatricula, contador);
                        }
                    }

                    for(int j = 0; j < 3; j++) {
                        printf("Digite a nota %i: ", j + 1);
                        scanf("%f", &notas[j]);
                    }

                    Alunos *VarAluno = Criar_Alunos(NomeAluno, NumeroMatricula, notas);

                    printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                    scanf("%d", &SairCase);

                    if(SairCase == 1) {
                        Var_Alunos = (Alunos*)realloc(Var_Alunos, (contador + 2) * sizeof(Alunos));
                        if(Var_Alunos == NULL) {
                            printf("Erro ao realocar Var_Alunos \n");
                        }
                    }

                    Var_Alunos[contador - 1] = *VarAluno;

                    if(SairCase != 1 && SairCase != 2) {
                        while(SairCase != 1 && SairCase != 2) {
                            printf("Voce digitou uma opcao invalida! \n");
                            printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                            scanf("%d", &SairCase);
                        }
                    }
                }
                 //Matricula(&Lista, Var_Alunos, Var_Cursos);
                break;

            case 2:  
                system("cls");
                SairCase = 0;
                while(SairCase != 2) { 
                    system("cls");
                    int Comparar = 0;
                    contador2++;
                    Vagas2++;
                    printf("Infome a disciplina: ");
                    scanf(" %[^\n]", NomeCurso);
                    getchar();
                    printf("Informe o codigo do curso: ");
                    scanf("%d", &CodigoCurso);
                    Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                    
                    while(Comparar == 1) {
                        system("cls");
                        Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                        if(Comparar == 1) {
                            printf("Informe o codigo do curso novamente: ");
                            scanf("%d", &CodigoCurso);
                            Comparar = CompararCodigo(Var_Cursos, CodigoCurso, contador2);
                        }
                        if(Comparar == 2) {
                            printf("Disciplina criada! \n");
                        }
                    }
                  
                    Cursos *VarCursos = Criar_Cursos(NomeCurso, CodigoCurso, Vagas2);

                    printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                    scanf("%d", &SairCase);

                    if(SairCase == 1) {
                        Var_Cursos = (Cursos*)realloc(Var_Cursos, (contador2 + 2) * sizeof(Cursos));
                        if(Var_Cursos == NULL) {
                            printf("Realocacao de Var_Cursos falhou! \n");
                            exit(1);
                        }
                    }

                    Var_Cursos[contador2 - 1] = *VarCursos;

                    //printf("\n\nVagas: %d, contador: %d\n", Vagas2, contador2); //pra checar o valor (pode ignorar) 

                    if(SairCase != 1 && SairCase != 2) {
                        while(SairCase != 1 && SairCase != 2) {
                            printf("Voce digitou uma opcao invalida! \n");
                            printf("Deseja continuar cadastrando? |1.SIM| 2.NAO| ");
                            scanf("%d", &SairCase);
                        }
                    }
                }

                break;
            case 3:
                escolha = 0;
                while(escolha != 2) {
                    //system("cls");
                    Imprimir_Cursos(Var_Cursos, contador2);
                    printf("\nLISTA DE ALUNOS: \n");
                    Imprimir_Alunos(Var_Alunos, contador);
                    if(contador == 0 || contador2 == 0) {
                        printf("\nDigite 2 para sair! \n");
                        scanf("%d", &escolha);
                        if(escolha != 2) {
                            while(escolha != 2) {
                                printf("\nDigite 2 para sair! \n");
                                scanf("%d", &escolha);
                            }
                        }
                    } else {
                        escolha = 0;
                        contador3 = contador;
                        printf("Informe | 1. MATRICULA DO ALUNO | 2. SAIR DA MATRICULA |: \n");
                        scanf("%d", &escolha);

                        switch(escolha) {
                            case 1:
                                printf("Informe a matricula do aluno: ");
                                scanf("%d", &matricula);
                                break;
                            case 2:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        } 
                        if(escolha == 2) {
                            break;
                        } else {
                            escolha = 0;
                        }
                        printf("\nInforme | 1.CODIGO | 2.SAIR DA MATRICULA |: ");
                        scanf("%d", &escolha);
                        switch(escolha) {
                            case 1:
                                printf("Digite o codigo: ");
                                scanf("%d", &codigo);
                                break;    
                            case 2:
                                break;
                            default:
                                printf("Digite uma opcao valida! \n");
                        }
                        // Procura o aluno pelo número da matrícula e o curso pelo código
                        Alunos *alunoSelecionado = NULL;
                        Cursos *cursoSelecionado = NULL;

                        for (int i = 0; i < contador3; i++) {
                            if (Var_Alunos[i].numero_matricula == matricula) {
                                alunoSelecionado = &Var_Alunos[i];
                                break;
                            }
                        }

                        for (int i = 0; i < contador3; i++) {
                            if (Var_Cursos[i].codigo == codigo) {
                                cursoSelecionado = &Var_Cursos[i];
                                break;
                            }
                        }

                        if (alunoSelecionado != NULL && cursoSelecionado != NULL) {
                            // Matricular o aluno no curso
                            MatricularAlunoEmCurso(alunoSelecionado, cursoSelecionado, &Lista);
                        } else {
                            printf("Aluno ou curso nao encontrado.\n");
                        }
                        /* Alunomatricula = (AlunoMatricula*)realloc(Alunomatricula, (contador3) * sizeof(AlunoMatricula));
                        if(Alunomatricula == NULL) {
                            printf("Erro ao alocar Alunomatricula! \n");
                            exit(1);
                        } 
                        Alunocurso = (AlunoCurso*)realloc(Alunocurso, (contador3) * sizeof(AlunoCurso));
                        if(Alunocurso == NULL) {
                            printf("Erro ao alocar Alunocurso! \n");
                            exit(1);
                        } */
                    } 
                } 
                
                break;

            case 4:
                break;
            case 5:
                ImprimirListaMatriculas(Lista);
                break;
            case 6:
                break;
            case 7:
                break;
            case 8: 
                break;
            case 9:
                break;
            case 10:
                break;
            default:
                printf("Voce digitou um opcao invalida! \n");
        }

    } while(MenuEscolha != 10);

    // Libera a memória alocada para alunos
    free(Var_Alunos);
    free(Var_Cursos);

    return 0;
}