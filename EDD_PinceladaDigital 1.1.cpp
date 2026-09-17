#include <iostream>
#include <locale.h>
#include <string>
#include <array>
using namespace std;  


struct TAdmin{
    //Variavéis de Primeiro acesso no sistema
    string IdAdmin = "", SenhaAdmin = "", confSenhAdmin;
};

/* ==== Modulo do Menu Principal ==== */
void MenuPrincipal(){
    system("cls");
    cout<<endl<<"==== Menu Principal ===="
        <<endl<<"1.Modulo de Cadastro"
        <<endl<<"2.Modulo de Venda"
        <<endl<<"3.Sair da Conta"
        <<endl<<"0.Sair"
        <<endl<<"Escolha: ";

}
/* ==== Modulo de Cadastro ====*/
void MenuCadastro(){
    system("cls");
    cout<<endl<<"==== Modulo de Cadastro ===="
        <<endl<<"1.Cadastro de Funcionários"
        <<endl<<"2.Cadastro de Clientes"
        <<endl<<"3.Cadastro de Produtos"
        <<endl<<"4.Cadastro de Fornecedores"
        <<endl<<"0.Voltar"
        <<endl<<"Escolha: ";
        
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    //Variavéis de Primeiro acesso no sistema
    const int MaxTamAdmin = 1;
    array<TAdmin, MaxTamAdmin> acessAdmin;
    int contAdmin=0;
    //Variáveis de Escolha dos Menus
    int opMenuPrincipal, opMenuCadastro, opMenuCargo;
    //Variávies de Login
    string IdAutenticacao, SenhaAutenticacao,confSenhAutentic;
    //Variaveis Funcionário
    string idFuncionario, nomeFuncionario, cpfFuncionario,emailFuncionario, senhaFuncionario, confSenhaFuncionario, cargo;
    //Variaveis Cliente
    string idCliente, nomeCliente, registo,EmailCliente, telefoneCliente, enderecoCliente;
    //Variaveis Produto
    string idProduto, nomeProduto, marcaProduto, lote, dataValidade;
    //Variaveis Fornecedores
    string idFornecedor, nomeFornecedor, cnpjFornecedor, enderecoFornecedor, telefoneFornecedor, emailFornecedor;
    
    //Primeiro acesso no sistema
    if(contAdmin < MaxTamAdmin){
        if(acessAdmin.IdAdmin == ""){
            do{
                cout<<endl<<"==== Primeiro Acesso ===="
                    <<endl<<"Nenhum administrador foi encontrado!!"
                    <<endl<<"Crie sua conta de admin agora: "<<endl
                    <<endl<<"Crie um Id (ex: xxxx)...: ";
                getline(cin,IdAdmin);
                cout<<endl<<"Crie uma senha do Admin...: ";
                getline(cin, SenhaAdmin);
                cout<<endl<<"Insira a senha novamente...: ";
                getline(cin,confSenhAdmin);
                //Mensagem de erro para senhas diferentes
                if(confSenhAdmin != SenhaAdmin){
                cout<<endl<<"Senhas diferentes, tente novamente!!"<<endl;
                system("pause");
                }
                cout<<endl<<"========================="<<endl;
            }while(confSenhAdmin != SenhaAdmin);   
        }
    }
    // Laço de repetição Autenticação
    do {
        do{
            system("cls");
            cout<<endl<<"======== Login ========"
                <<endl<<"Id Funcionario...: ";
            getline(cin, IdAutenticacao);
            cout<<endl<<"Senha...: ";
            getline(cin, SenhaAutenticacao);
            cout<<endl<<"Senha novamente...: ";
            getline(cin, confSenhAutentic);
            cout<<endl<<"======================="<<endl;
            // Mensagens de erro
            if(IdAutenticacao != IdAdmin) {
                cout<<endl<<"ID incorreto, tente novamente."<<endl;
                system("pause");
            }
            else if(SenhaAutenticacao != SenhaAdmin){
                cout<<endl<<"Senha incorreta, tente novamente."<<endl;
                system("pause");
            }  
        }while(confSenhAutentic != SenhaAutenticacao); 
    } while(IdAutenticacao != IdAdmin || SenhaAutenticacao != SenhaAdmin);
    
    //Mensagem de Autenticação
    cout<<endl<<"Login realizado com sucesso!"<<endl;
    system("pause");
    //Laço de repetição do menu principal
    do{
    //Função do Menu Principal
    MenuPrincipal();
    cin>>opMenuPrincipal;
        //Controle de Fluxo do Menu Principal
        switch (opMenuPrincipal)
        {
        /* == Modulo de Cadastro == */
        case 1:
            do{
            //Função do Menu de Cadastro
            MenuCadastro();
            cin>>opMenuCadastro;
                /*== Controle de Fluxo do Menu_Cadastro ==*/
                switch (opMenuCadastro)
                {
                case 1:
                //Cadastro de Funcionários
                    system("cls");
                    cout<<endl<<"==== Cadastro de Funcionario ===="
                    //Entrada de Dados do Funcionário
                        <<endl<<"Insira o nome...: ";
                    cin.ignore();
                    getline(cin, nomeFuncionario);
                    
                    cout<<endl<<"Insira o CPF...: ";
                    getline(cin, cpfFuncionario);

                    cout<<endl<<"Insira o E-mail...: ";
                    getline(cin, emailFuncionario);
                    
                    //laço de repetição para verificação de senha
                    do{
                        //Adicionar caracteres para a senha
                        cout<<endl<<"Insira a senha...: ";
                        getline(cin, senhaFuncionario);
                        cout<<endl<<"Confirme a senha...: ";
                        getline(cin, confSenhaFuncionario);
                        
                        //Mensagem de erro para senhas diferentes
                        if(confSenhaFuncionario != senhaFuncionario){
                            cout<<endl<<"Senhas diferentes, tente novamente!!"<<endl;
                            system("pause");
                        }
                    }while(confSenhaFuncionario != senhaFuncionario);
                    
                    cout<<endl<<"======== Cargos ========"
                        <<endl<<"1.Gerente"
                        <<endl<<"2.Vendedor"
                        <<endl<<"3.Estoquista"
                        <<endl<<"Selecione o Cargo do funcionário...: ";
                    cin>>opMenuCargo;
                    cout<<endl<<"========================"<<endl;
                    
                    do{
                        switch (opMenuCargo)
                        {
                        case 1:
                            cargo = "Gerente";
                            break;
                        case 2:
                            cargo = "Vendedor";
                            break;
                        case 3:
                            cargo = "Estoquista";
                            break;
                        
                        default:
                            cout<<endl<<"Opção errada, tente novamente!!";
                            break;
                        }
                    }while(opMenuCargo <1 || opMenuCargo > 3);
                    //Exibição das informações de Cadastro do funcionário
                    system("cls");
                    cout<<endl<<"==== Exibição Cadastro Funcionário ===="
                        <<endl<<"ID: 1234-1"
                        <<endl<<"Nome: "<<nomeFuncionario
                        <<endl<<"CPF: "<<cpfFuncionario
                        <<endl<<"E-mail: "<<emailFuncionario
                        //Futuramente exibir (Senha: ****) 
                        <<endl<<"Cargo: "<<cargo
                        <<endl<<"======================================="<<endl;
                    cout<<endl<<"Voltando para menu Principal, limite de 1 cadastro de funcionário atingido!!"<<endl;
                    system("pause");
                    break;
                case 2:
                //Cadastro de Clientes 
                system("cls");
                    cout<<endl<<"==== Cadastro de Clientes ===="
                    //Entrada de Dados do Cliente 
                        <<endl<<"Insira o nome...: ";
                    cin.ignore();
                    getline(cin, nomeCliente);
                    
                    cout<<endl<<"Insira o CPF ou CNPJ...: ";
                    getline(cin, registo);
                    
                    cout<<endl<<"Insira o E-mail...: ";
                    getline(cin, EmailCliente);
                    
                    cout<<endl<<"Insira o telefone...: ";
                    getline(cin, telefoneCliente);
                    
                    cout<<endl<<"Insira o endereço...: ";
                    getline(cin, enderecoCliente);
                    
                    //Exibição das informações de Cadastro do Cliente
                    system("cls");
                    cout<<endl<<"==== Exibição Cadastro Cliente ===="
                        <<endl<<"ID: 1234-1"
                        <<endl<<"Nome: "<<nomeCliente
                        <<endl<<"CPF: "<<registo
                        <<endl<<"E-mail: "<<EmailCliente
                        <<endl<<"Telefone: "<<telefoneCliente
                        <<endl<<"Endereço: "<<enderecoCliente
                        <<endl<<"==================================="<<endl;
                    cout<<endl<<"Voltando para menu Principal, limite de 1 cadastro de Cliente atingido!!"<<endl;
                    system("pause");
                    break;     
                case 3:
                //Cadastro de Produtos
                system("cls");
                    cout<<endl<<"==== Cadastro de Produtos ===="
                    //Entrada de Dados do Produto
                        <<endl<<"Insira o nome do produto...: ";
                    cin.ignore();
                    getline(cin, nomeProduto);

                    cout<<endl<<"Insira a marca do produto...: ";
                    getline(cin, marcaProduto);

                    cout<<endl<<"Insira a Data de Validade do produto...: ";
                    getline(cin,dataValidade);
                    //Exibição das informações de Cadastro do Produto
        
                    system("cls");
                    cout<<endl<<"==== Exibição Cadastro do Produto ===="
                        <<endl<<"ID: 1234"
                        <<endl<<"Nome: "<<nomeProduto
                        <<endl<<"Marca: "<<marcaProduto
                        <<endl<<"Data de Validade: "<<dataValidade
                        <<endl<<"======================================"<<endl;
                    cout<<endl<<"Voltando para menu Principal, limite de 1 cadastro de Produto atingido!!"<<endl;
                    system("pause");
                    break;   
                case 4:
                //Cadastro de Fornecedores
                system("cls");
                     cout<<endl<<"==== Cadastro de Fornecedores ===="
                    //Entrada de Dados do Fornecedor
                        <<endl<<"Insira o nome do Fornecedor...: ";
                    cin.ignore();
                    getline(cin, nomeFornecedor);

                    cout<<endl<<"Insira o CNPJ...: ";
                    getline(cin, cnpjFornecedor);

                    cout<<endl<<"Insira o endereço do fornecedor...: ";
                    getline(cin,enderecoFornecedor);
                    
                    cout<<endl<<"Insira o telefone do fornecedor...: ";
                    getline(cin, telefoneFornecedor);

                    cout<<endl<<"Insira o email do fornecedor...: ";
                    getline(cin,emailFornecedor);

                    //Exibição das informações de Cadastro do Produto
        
                    system("cls");
                    cout<<endl<<"==== Exibição Cadastro do Fornecedor ===="
                        <<endl<<"ID: 1234"
                        <<endl<<"Nome: "<<nomeFornecedor
                        <<endl<<"CNPJ: "<<cnpjFornecedor
                        <<endl<<"Endereço: "<<enderecoFornecedor
                        <<endl<<"Telefone...: "<<telefoneFornecedor
                        <<endl<<"E-mail: "<<emailFornecedor
                        <<endl<<"========================================="<<endl;
                    cout<<endl<<"Voltando para menu Principal, limite de 1 cadastro de Fornecedor atingido!!"<<endl;
                    system("pause");
                    break;
                //Voltar para menu principal    
                case 0:
                    cout<<endl<<"Voltando para menu principal...";
                    break;
                    
                default:
                    cout<<endl<<"Opção inválida!!";
                    break;
                }
                //Fechamento do Modulo de Cadastro
            }while(opMenuCadastro != 0);  
            break;
        /* == Modulo de vendas == */
        case 2:
            cout<<endl<<"Cadastro de Vendas em desenvolvimento";
            break;   
        /* == Sair da Conta == */
        case 3:
            cout<<endl<<"Em desenvolvimento"<<endl;
            system("pause");
            break;
        /* == Sair do Sistema == */
        case 0:
            cout<<endl<<"Saindo do Sistema...";
            break;
            
        default:
            cout<<endl<<"Opção incorreta, tente novamente!!";
            break;
        }
    }while(opMenuPrincipal != 0);
    return 0;
}