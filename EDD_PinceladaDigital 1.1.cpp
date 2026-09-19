#include <iostream>
#include <locale.h>
#include <string>
#include <array>
using namespace std;  


struct TAdmin{
    //Variav�is de Primeiro acesso no sistema
    string IdAdmin = "", SenhaAdmin = "", confSenhAdmin;
};
struct TLogin{
    //Vari�vies de Login
    string IdAutenticacao, SenhaAutenticacao,confSenhAutentic;
};
struct TFuncionario{
    string idFuncionario, nomeFuncionario, cpfFuncionario,emailFuncionario, senhaFuncionario, confSenhaFuncionario, cargo;
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
        <<endl<<"1.Cadastro de Funcion�rios"
        <<endl<<"2.Cadastro de Clientes"
        <<endl<<"3.Cadastro de Produtos"
        <<endl<<"4.Cadastro de Fornecedores"
        <<endl<<"0.Voltar"
        <<endl<<"Escolha: ";
        
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    /*-Vari�veis de Escolha dos Menus-*/
    int opMenuPrincipal, opMenuCadastro, opMenuCargo;
    /*-Variav�is de Primeiro acesso no sistema-*/
    const int MaxTamAdmin = 1;
    array<TAdmin, MaxTamAdmin> acessAdmin;
    int contAdmin=0;
    /*-Vari�vies de Login-*/
    const int MaxTamLogin = 10;
    array<TLogin, MaxTamLogin> login;
    int contLogin = 0;
    /*-Variaveis Funcion�rio-*/
    const int MaxTamFuncionarios = 10;
    array<TFuncionario, MaxTamFuncionarios> CdFuncionario;
    int contFuncion = 0;
    //Variaveis Cliente
    string idCliente, nomeCliente, registo,EmailCliente, telefoneCliente, enderecoCliente;
    //Variaveis Produto
    string idProduto, nomeProduto, marcaProduto, lote, dataValidade;
    //Variaveis Fornecedores
    string idFornecedor, nomeFornecedor, cnpjFornecedor, enderecoFornecedor, telefoneFornecedor, emailFornecedor;
    
    // Verifica��o se o m�ximo de admins foi atingido
    if(contAdmin < MaxTamAdmin){
        //Primeiro acesso no sistema
        if(acessAdmin.at(contAdmin).IdAdmin == ""){
            //La�o de repeti��o de verifica��o de senha
            cout<<endl<<"==== Primeiro Acesso ===="
                <<endl<<"Nenhum administrador foi encontrado!!"
                <<endl<<"Crie sua conta de admin agora: "<<endl
                <<endl<<"Crie um Id (ex: xxxx)...: ";
                getline(cin, acessAdmin.at(contAdmin).IdAdmin);
                do{
                    cout<<endl<<"Crie uma senha do Admin...: ";
                    getline(cin, acessAdmin.at(contAdmin).SenhaAdmin);
                    cout<<endl<<"Insira a senha novamente...: ";
                    getline(cin,acessAdmin.at(contAdmin).confSenhAdmin);
                    //Mensagem de erro para senhas diferentes
                    if(acessAdmin.at(contAdmin).confSenhAdmin != acessAdmin.at(contAdmin).SenhaAdmin){
                    cout<<endl<<"Senhas diferentes, tente novamente!!"<<endl;
                    system("pause");
                    }
                }while(acessAdmin.at(contAdmin).confSenhAdmin != acessAdmin.at(contAdmin).SenhaAdmin);
                contAdmin++;  
        }
    }
    else{
        cout<<endl<<"Cadastro de Administradores est� completo!!";
    }
    // Verifica��o se o m�ximo de logins foi atingido
    if(contLogin < MaxTamLogin){
        // La�o de repeti��o Autentica��o
        do { 
            system("cls");
            cout<<endl<<"======== Login ========"
                <<endl<<"Id Funcionario...: ";
            getline(cin, login.at(contLogin).IdAutenticacao);
                //La�o de repeti��o de verifica��o de senha
                    cout<<endl<<"Senha...: ";
                    getline(cin, login.at(contLogin).SenhaAutenticacao);
                    // Mensagens de erro
                    if(login.at(contLogin).IdAutenticacao != acessAdmin.at(0).IdAdmin) {
                        cout<<endl<<"ID incorreto, tente novamente."<<endl;
                        system("pause");
                    }
                    else if(login.at(contLogin).SenhaAutenticacao != acessAdmin.at(0).SenhaAdmin){
                        cout<<endl<<"Senha incorreta, tente novamente."<<endl;
                        system("pause");
                    }  
        }while(login.at(contLogin).IdAutenticacao != acessAdmin.at(0).IdAdmin || login.at(contLogin).SenhaAutenticacao != acessAdmin.at(0).SenhaAdmin);
    contLogin++;
    }
    else{
        cout<<endl<<"M�ximo de login por instancia atingido! Saia do sistema para reiniciar.";
    }
    //Mensagem de Autentica��o
    cout<<endl<<"Login realizado com sucesso!"<<endl;
    system("pause");
    //La�o de repeti��o do menu principal
    do{
    //Fun��o do Menu Principal
    MenuPrincipal();
    cin>>opMenuPrincipal;
        //Controle de Fluxo do Menu Principal
        switch (opMenuPrincipal)
        {
        /* == Modulo de Cadastro == */
        case 1:
            do{
            //Fun��o do Menu de Cadastro
            MenuCadastro();
            cin>>opMenuCadastro;
                /*== Controle de Fluxo do Menu_Cadastro ==*/
                switch (opMenuCadastro)
                {
                case 1:
                if(contFuncion < MaxTamFuncionarios){
                    //Cadastro de Funcion�rios
                        system("cls");
                        cout<<endl<<"==== Cadastro de Funcionario ===="
                        //Entrada de Dados do Funcion�rio
                            <<endl<<"Insira o nome...: ";
                        cin.ignore();
                        getline(cin, CdFuncionario.at(contFuncion).nomeFuncionario);
                        
                        cout<<endl<<"Insira o CPF...: ";
                        getline(cin, CdFuncionario.at(contFuncion).cpfFuncionario);

                        cout<<endl<<"Insira o E-mail...: ";
                        getline(cin, CdFuncionario.at(contFuncion).emailFuncionario);
                        
                        //la�o de repeti��o para verifica��o de senha
                        do{
                            //Adicionar caracteres para a senha
                            cout<<endl<<"Insira a senha...: ";
                            getline(cin, CdFuncionario.at(contFuncion).senhaFuncionario);
                            cout<<endl<<"Confirme a senha...: ";
                            getline(cin, CdFuncionario.at(contFuncion).confSenhaFuncionario);
                            
                            //Mensagem de erro para senhas diferentes
                            if(CdFuncionario.at(contFuncion).confSenhaFuncionario != CdFuncionario.at(contFuncion).senhaFuncionario){
                                cout<<endl<<"Senhas diferentes, tente novamente!!"<<endl;
                                system("pause");
                            }
                        }while(CdFuncionario.at(contFuncion).confSenhaFuncionario != CdFuncionario.at(contFuncion).senhaFuncionario);
                        
                        cout<<endl<<"======== Cargos ========"
                            <<endl<<"1.Gerente"
                            <<endl<<"2.Vendedor"
                            <<endl<<"3.Estoquista"
                            <<endl<<"Selecione o Cargo do funcion�rio...: ";
                        cin>>opMenuCargo;
                        cout<<endl<<"========================"<<endl;
                        do{
                            switch (opMenuCargo)
                            {
                            case 1:
                                CdFuncionario.at(contFuncion).cargo = "Gerente";
                                break;
                            case 2:
                                CdFuncionario.at(contFuncion).cargo = "Vendedor";
                                break;
                            case 3:
                                CdFuncionario.at(contFuncion).cargo = "Estoquista";
                                break;
                            
                            default:
                                cout<<endl<<"Op��o errada, tente novamente!!";
                                break;
                            }
                        }while(opMenuCargo <1 || opMenuCargo > 3);
                        //Exibi��o das informa��es de Cadastro do funcion�rio
                        system("cls");
                        cout<<endl<<"==== Cadastro realizado com sucesso ===="
                            <<endl<<"ID: 1234-1"
                            <<endl<<"Nome: "<<CdFuncionario.at(contFuncion).nomeFuncionario
                            <<endl<<"CPF: "<<CdFuncionario.at(contFuncion).cpfFuncionario
                            <<endl<<"E-mail: "<<CdFuncionario.at(contFuncion).emailFuncionario
                            //Futuramente exibir (Senha: ****) 
                            <<endl<<"Cargo: "<<CdFuncionario.at(contFuncion).cargo
                            <<endl<<"======================================="<<endl;
                        system("pause");
                        contFuncion++;
                }
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
                    
                    cout<<endl<<"Insira o endere�o...: ";
                    getline(cin, enderecoCliente);
                    
                    //Exibi��o das informa��es de Cadastro do Cliente
                    system("cls");
                    cout<<endl<<"==== Exibi��o Cadastro Cliente ===="
                        <<endl<<"ID: 1234-1"
                        <<endl<<"Nome: "<<nomeCliente
                        <<endl<<"CPF: "<<registo
                        <<endl<<"E-mail: "<<EmailCliente
                        <<endl<<"Telefone: "<<telefoneCliente
                        <<endl<<"Endere�o: "<<enderecoCliente
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
                    //Exibi��o das informa��es de Cadastro do Produto
        
                    system("cls");
                    cout<<endl<<"==== Exibi��o Cadastro do Produto ===="
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

                    cout<<endl<<"Insira o endere�o do fornecedor...: ";
                    getline(cin,enderecoFornecedor);
                    
                    cout<<endl<<"Insira o telefone do fornecedor...: ";
                    getline(cin, telefoneFornecedor);

                    cout<<endl<<"Insira o email do fornecedor...: ";
                    getline(cin,emailFornecedor);

                    //Exibi��o das informa��es de Cadastro do Produto
        
                    system("cls");
                    cout<<endl<<"==== Exibi��o Cadastro do Fornecedor ===="
                        <<endl<<"ID: 1234"
                        <<endl<<"Nome: "<<nomeFornecedor
                        <<endl<<"CNPJ: "<<cnpjFornecedor
                        <<endl<<"Endere�o: "<<enderecoFornecedor
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
                    cout<<endl<<"Op��o inv�lida!!";
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
            cout<<endl<<"Op��o incorreta, tente novamente!!";
            break;
        }
    }while(opMenuPrincipal != 0);
    return 0;
}