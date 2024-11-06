
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Endereco {
    char local[30];
    int numero_casa;
    char bairro[30];
    char cidade[30];
    char estado[30];
    int cep;
};


struct Conta {
    int tipo; 
    int agencia;
    int numero_conta;
    char nome_cliente[30];
    int CPF;
    int data_nascimento;
    int telefone_contato;
    struct Endereco endereco;
    int senha_cliente;
    int limite_conta; 
    int data_vencimento;
    int saldo_conta;
    int codigo_funcionario;
    char cargo[30];
    char nome_funcionario[30];
    int cpf_funcionario;
    int data_nascimento_funcionario;
    int telefone_funcionario;
    struct Endereco endereco_funcionario;
};


void criar_conta(struct Conta *conta, int tipo_conta);
void excluir_conta(int numero_conta_excluir);
void menu_funcionario();
void menu_cliente();
void menu_banco();
int ler_senha();
int verificar_senha(int senha);
void escrever_senha();


void criar_conta(struct Conta *conta, int tipo_conta) {
    FILE *arquivo_contas = fopen("contas.csv", "a"); 
    if (arquivo_contas == NULL) {
        printf("Erro ao abrir o arquivo de contas.\n");
        exit(1);
    }

    printf("Digite os dados da conta:\n");
    printf("Agência: ");
    scanf("%d", &conta->agencia);
    fprintf(arquivo_contas, "Agência: %d\n", conta->agencia);

    printf("Número da Conta: ");
    scanf("%d", &conta->numero_conta);
    fprintf(arquivo_contas, "Número da Conta: %d\n", conta->numero_conta);

    printf("Nome do Cliente: ");
    scanf(" %29[^\n]", conta->nome_cliente); 
    fprintf(arquivo_contas, "Nome do Cliente: %s\n", conta->nome_cliente);

    printf("CPF do Cliente: ");
    scanf("%d", &conta->CPF);
    fprintf(arquivo_contas, "CPF do Cliente: %d\n", conta->CPF);

    printf("Data de Nascimento: ");
    scanf("%d", &conta->data_nascimento);
    fprintf(arquivo_contas, "Data de Nascimento: %d\n", conta->data_nascimento);

    printf("Telefone de Contato: ");
    scanf("%d", &conta->telefone_contato);
    fprintf(arquivo_contas, "Telefone de Contato: %d\n", conta->telefone_contato);

    printf("Endereço:\n");
    printf("Local: ");
    scanf(" %29[^\n]", conta->endereco.local); 
    fprintf(arquivo_contas, "Local: %s\n", conta->endereco.local);

    printf("Número da Casa: ");
    scanf("%d", &conta->endereco.numero_casa);
    fprintf(arquivo_contas, "Número da Casa: %d\n", conta->endereco.numero_casa);

    printf("Bairro: ");
    scanf(" %29[^\n]", conta->endereco.bairro); 
    fprintf(arquivo_contas, "Bairro: %s\n", conta->endereco.bairro);

    printf("Cidade: ");
    scanf(" %29[^\n]", conta->endereco.cidade); 
    fprintf(arquivo_contas, "Cidade: %s\n", conta->endereco.cidade);

    printf("Estado: ");
    scanf(" %29[^\n]", conta->endereco.estado); 
    fprintf(arquivo_contas, "Estado: %s\n", conta->endereco.estado);

    printf("CEP: ");
    scanf("%d", &conta->endereco.cep);
    fprintf(arquivo_contas, "CEP: %d\n", conta->endereco.cep);

    printf("Senha do Cliente: ");
    scanf("%d", &conta->senha_cliente);
    fprintf(arquivo_contas, "Senha do Cliente: %d\n", conta->senha_cliente);

    if (tipo_conta == 2) { // Conta Corrente
        printf("Limite da Conta: ");
        scanf("%d", &conta->limite_conta);
        fprintf(arquivo_contas, "Limite da Conta: %d\n", conta->limite_conta);

        printf("Data de Vencimento: ");
        scanf("%d", &conta->data_vencimento);
        fprintf(arquivo_contas, "Data de Vencimento: %d\n", conta->data_vencimento);
    }

    fprintf(arquivo_contas, "\n"); 
    fclose(arquivo_contas);
}


void excluir_conta(int numero_conta_excluir) {
    FILE *arquivo_contas = fopen("contas.csv", "r");
    FILE *arquivo_temp = fopen("temp.csv", "w");
    if (arquivo_contas == NULL || arquivo_temp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }

    char linha[256];
    int encontrou_conta = 0;

    while (fgets(linha, sizeof(linha), arquivo_contas) != NULL) {
       
        if (strstr(linha, "Número da Conta: ") != NULL) {
            int num_conta_arquivo;
            sscanf(linha, "Número da Conta: %d", &num_conta_arquivo);
            if (num_conta_arquivo == numero_conta_excluir) {
                encontrou_conta = 1; 
                continue; 
            }
        }
        
        fputs(linha, arquivo_temp);
    }

    fclose(arquivo_contas);
    fclose(arquivo_temp);

  
    if (remove("contas.csv") != 0 || rename("temp.csv", "contas.csv") != 0) {
        printf("Erro ao remover ou renomear o arquivo.\n");
        exit(1);
    }

    if (encontrou_conta) {
        printf("Conta excluída com sucesso!\n");
    } else {
        printf("Conta não encontrada.\n");
    }
}


void menu_banco() {
    system("cls"); 

  
    printf(" /$$                                                                                       /$$   /$$     /$$     /$$       /$$                                        \n");
    printf("| $$                                                                                      | $$  | $$    | $$    | $$      |__/                                        \n");
    printf("| $$ /$$   /$$  /$$$$$$$  /$$$$$$   /$$$$$$$        /$$$$$$        /$$$$$$/$$$$   /$$$$$$ | $$ /$$$$$$ /$$$$$$  | $$$$$$$  /$$ /$$$$$$$  /$$$$$$$   /$$$$$$   /$$$$$$ \n");
    printf("| $$| $$  | $$ /$$_____/ |____  $$ /$$_____/       /$$__  $$      | $$_  $$_  $$ |____  $$| $$|_  $$_/|_  $$_/  | $$__  $$| $$| $$__  $$| $$__  $$ /$$__  $$ /$$__  $$\n");
    printf("| $$| $$  | $$| $$        /$$$$$$$|  $$$$$$       | $$$$$$$$      | $$ \\ $$ \\ $$  /$$$$$$$| $$  | $$    | $$    | $$  \\ $$| $$| $$  \\ $$| $$  \\ $$| $$$$$$$$| $$  \\__/ \n");
    printf("| $$| $$  | $$| $$       /$$__  $$ \\____  $$      | $$_____/      | $$ | $$ | $$ /$$__  $$| $$  | $$ /$$| $$ /$$| $$  | $$| $$| $$  | $$| $$  | $$| $$_____/| $$       \n");
    printf("| $$|  $$$$$$/|  $$$$$$$|  $$$$$$$ /$$$$$$$/      |  $$$$$$$      | $$ | $$ | $$|  $$$$$$$| $$  |  $$$$/|  $$$$/| $$  | $$| $$| $$  | $$| $$  | $$|  $$$$$$$| $$       \n");
    printf("|__/ \\______/  \\_______/ \\_______/|_______/        \\_______/      |__/ |__/ |__/ \\_______/|__/   \\___/   \\___/  |__/  |__/|__/|__/  |__/|__/  |__/ \\_______/|__/       \n");

    printf("\n");
    printf("    BEM-VINDO AO BANCO.\n");
    printf("    Digite a opção desejada:\n\n");
    printf("    (1) Funcionário\n");
    printf("    (2) Cliente\n");
    printf("    (3) Sair do programa\n\n");
    printf("Opção: ");
}


int ler_senha() {
    int senha;
    FILE *arquivo_senha = fopen("senha.csv", "r");
    if (arquivo_senha == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fscanf(arquivo_senha, "%d", &senha);
    fclose(arquivo_senha);
    return senha;
}


int verificar_senha(int senha) {
    int senha_correta = ler_senha();
    return (senha == senha_correta);
}


void escrever_senha() {
    FILE *arquivo_senha = fopen("senha.csv", "w");
    if (arquivo_senha == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        exit(1);
    }
    fprintf(arquivo_senha, "%d", 1234); 
    fclose(arquivo_senha);
}


void banco() {
    int opcao, senha, senha_correta = 0; 

  
    FILE *arquivo_senha = fopen("senha.csv", "r");
    if (arquivo_senha == NULL) {
        escrever_senha(); 
    } else {
        fclose(arquivo_senha);
    }

   
    do {
        menu_banco(); 
        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                printf("Digite a senha de funcionário: ");
                scanf("%d", &senha);
                senha_correta = verificar_senha(senha);
                if (senha_correta) {
                    printf("Bem-vindo, funcionário!\n");
                    menu_funcionario(); 
                } else {
                    printf("Senha incorreta! Tente novamente.\n");
                }
                break;
            case 2: 
                printf("Opção para cliente selecionada.\n");
                menu_cliente();
                break;
            case 3: 
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 3);
}


void menu_funcionario() {
    int opcao;
    do {
        printf("\nMenu Funcionário:\n");
        printf("(1) Abertura de conta\n");
        printf("(2) Encerramento da conta\n");
        printf("(3) Consultar dados\n");
        printf("(4) Alterar dados\n");
        printf("(5) Cadastro de funcionários\n");
        printf("(6) Gerar relatório\n");
        printf("(7) Sair\n\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                {
                    struct Conta nova_conta;
                    int tipo_conta;

                    printf("Tipo de Conta (1 para Poupança, 2 para Corrente): ");
                    scanf("%d", &tipo_conta);

                    criar_conta(&nova_conta, tipo_conta);

                    printf("Conta criada com sucesso!\n");
                }
                break;
            case 2:
                {
                    int numero_conta_excluir;
                    printf("Digite o número da conta a ser excluída: ");
                    scanf("%d", &numero_conta_excluir);
                    excluir_conta(numero_conta_excluir);
                }
                break;
            case 3:
               
                break;
            case 4:
                
                break;
            case 5:
              
                break;
            case 6:
                
                break;
            case 7:
                printf("Saindo do menu funcionário...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while (opcao != 7);
}


void menu_cliente() {
   
}

int main() {
    system("color 2");
    banco(); 
    return 0;
}


