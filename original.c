#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct cad_cliente
{
    char nome[10];
    int idade;
    char CPF_CNPJ[20];
    char CNH[30];
    char Endereco[50];
};
typedef struct cad_cliente Cliente;

typedef struct
{
    char placa[10];
    char modelo[20];
    char marca[20];
    char cor[20];
    char ano[5];
}   Carro;

int     le_um_carro(Carro*);
int     le_um_cliente(Cliente*);
int     menu();
int     mostra_um_carro(Carro*);
int     mostra_um_cliente(Cliente*);

int origem();

int     main(void)
{
    int opcao = 5;
    Carro   info;
    Cliente cliente;

    origem();
    while (opcao != 5) // sair = 5
    {
        opcao = menu();
        switch (opcao)
        {
        case 1:
            le_um_cliente(&cliente);
            mostra_um_cliente(&cliente);
            break;
        case 2:
            le_um_carro(&info);
            mostra_um_carro(&info);
            break;
        case 5:
            break;
        default:
            printf("Opcao inesperada: %d\n", opcao);
            break;
        };  // switch()
    };   // while();
};  // main()

int     le_um_carro(Carro * C)
{
    char aux[200];
    Carro info;
    printf("Informe o numero da placa [7 digitos]: ");
    placa:
    fflush(stdin);
    fgets(aux, 10, stdin);
    if (strlen(aux) < 8) {
        printf("erro quantidade de digitos menor do que o correto\n");
        printf("Digite novamente: ");
        goto placa;
    }
    else if (strlen(aux) > 8) {
        printf("erro quantidade de digitos maior do que o correto\n");
        printf("Digite novamente: ");
        goto placa;
    }
    else {
        strcpy(info.placa, aux);
    }
    printf("Informe a marca do veiculo: ");
    fgets(info.marca,20,stdin);
    printf("Informe o modelo do veiculo: ");
    fgets(info.modelo,30,stdin);
    printf("Informe a cor do veiculo: ");
    fgets(info.cor,20,stdin);
    printf("Informe o ano do veiculo: ");
    fgets(info.ano,5,stdin);
    *C = info;
    return 0;
};  // le_um_carro()

int     le_um_cliente(Cliente* C)
{
    Cliente info;
    char aux[200];
    system("cls");
    printf("Informe o nome do cliente: ");
    fflush(stdin);
    fgets(info.nome,30,stdin);
    printf("Informe a idade do cliente: ");
    scanf("%d", &info.idade);

    printf("Informe o CPF/CNPJ do cliente: ");
cpf:
    fflush(stdin);
    fgets(aux,20,stdin);
    if (strlen(aux) < 11) {
        printf("erro quantidade de digitos menor do que o correto\n");
        printf("Digite novamente: \n");
        goto cpf;

    }
    else if (strlen(aux) > 11) {
        printf("erro quantidade de digitos maior do que o correto\n");
        printf("Digite novamente: \n");
        goto cpf;

    }
    else {
        strcpy(info.CPF_CNPJ, aux);
    }
    printf("Informe o número do CNH do cliente: ");
cnh:
    fflush(stdin);
    fgets(aux,10,stdin);
    if (strlen(aux) < 11) {
        printf("erro quantidade de digitos menor do que o correto\n");
        printf("digite novamente: \n");
        goto cnh;

    }
    else if (strlen(aux) > 11) {
        printf("erro quantidade de digitos maior do que o correto\n");
        printf("digite novamente: \n");
        goto cnh;

    }
    else {
        strcpy(info.CNH, aux);
    }

    printf("Informe o endereco do cliente: ");
    fgets(info.Endereco,30,stdin);
    *C = info;
    return 0;
};

int     menu()
{
    int opcao = 0;
    system("cls");
    printf("-----------------------------------------\n");
    printf("\tCONTROLE DE ESTACIONAMENTO\n");
    printf("-----------------------------------------\n\n");
    printf("1- Cadastrar Cliente\n");
    printf("\n2- Cadastrar Veiculo\n");
    printf("\n3- Listar veiculos cadastrados\n");
    printf("\n4- Creditos\n");
    printf("\n5- Sair\n");
    printf("\nOpcao: ");
    scanf("%d", &opcao);
    return opcao;
};

int     mostra_um_carro(Carro * c)
{
    printf("Marca/Modelo: %s %s Cor: %s Placa: %s Entrada: %s \n",
        c->marca,
        c->modelo,
        c->cor,
        c->placa,
        c->ano
    );
    return 0;
};

int     mostra_um_cliente(Cliente* C)
{
    return 0;
};

int origem()
{
    struct ficha
    {
        int clube;
        int salario;
        int origem;
    };

    struct ficha pesquisa[10] =
    {
        { 1,1000,1 },
        { 2,31000,2},
        { 3,12300,1},
        { 1,5500,2},
        { 2,18000,1},
        { 3,10200,2},
        { 1,15000,1},
        { 2,10400,2},
        { 3,10300,1},
        { 1,16000,1}
    };

    int	De_SP_XX = 0; // nasceu em SP, nao torce nem para SP nem para CO
    int salarios_CO = 0;
    int salarios_SP = 0;
    int torcedores_CO = 0;
    int torcedores_SP = 0;
    int torcedores_XX = 0;

    for (int i = 0; i < 10; i += 1)
        printf("Ficha %2d: Clube: %2d, salario: %8d, origem: %2d\n",
            1+i,
            pesquisa[i].clube,
            pesquisa[i].salario,
            pesquisa[i].origem);

    time_t hora;
    clock_t hora = _t();

};

int uma_funcao(const char* mensagem, int valor)
{
    if ((mensagem[0] >= 'a') && (mensagem[0] <= 'z'))
        mensagem[0] -= 32; // equivale a converter para maiuscula
    printf("Mensagem: '%s' valor %d\n", mensagem, valor);
    return 0;
};