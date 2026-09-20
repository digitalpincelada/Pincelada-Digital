#include <iostream>
#include <locale.h>
#include <string>
#include <array>
using namespace std;  
/* ==== Structs principais ====*/
struct TAdmin{
    /*-Struct Admin-*/
    string IdAdmin = "", SenhaAdmin = "";
};
struct TFuncionario{
    /*-Struct Funcionário-*/
    string idFuncionario, nomeFuncionario, cpfFuncionario,emailFuncionario, senhaFuncionario, cargo;
};
struct TCliente{
    /*-Struct Cliente-*/
    string idCliente, nomeCliente, registo,EmailCliente, telefoneCliente, enderecoCliente;

};
struct TProduto{
    /*-Struct Produto-*/
    string idProduto, nomeProduto, marcaProduto, lote, dataValidade;

};
struct TFornecedor{
    /*-Struct Fornecedor-*/
    string idFornecedor, nomeFornecedor, cnpjFornecedor, enderecoFornecedor, telefoneFornecedor, emailFornecedor;

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
    /*-Variáveis de Escolha dos Menus-*/
    int opMenuPrincipal, opMenuCadastro, opMenuCargo;
    /*-Variáveis de Primeiro acesso no sistema-*/
    const int MaxTamAdmin = 1;
    array<TAdmin, MaxTamAdmin> acessAdmin;
    int contAdmin=0;
    /*-Variavel de Confirmação de senha*/
    string confirmacaoTemporaria;
    /*-Variáveis de Login-*/
    string idLogin, senhaLogin;
    /*-Variaveis Funcionário-*/
    const int MaxTamFuncionarios = 10;
    array<TFuncionario, MaxTamFuncionarios> CdFuncionario;
    int contFuncion = 0;
    /*-Variaveis Cliente-*/
    const int MaxTamClientes = 10;
    array<TCliente, MaxTamClientes> CdClientes;
    int contClient = 0;
    /*-Variaveis Produto-*/
    const int MaxTamProduto = 10;
    array<TProduto, MaxTamProduto> CdProdutos;
    int contProdut = 0;
    /*-Variaveis Fornecedores-*/
    const int MaxTamFornecedor = 10;
    array<TFornecedor, MaxTamFornecedor> CdFornecedores;
    int contFornec = 0;

    // Verificação se o máximo de admins foi atingido
    if(contAdmin < MaxTamAdmin){
        //Primeiro acesso no sistema
        if(acessAdmin.at(contAdmin).IdAdmin == ""){
            //Laço de repetição de verificação de senha
            cout<<endl<<"==== Primeiro Acesso ===="
                <<endl<<"Nenhum administrador foi encontrado!!"
                <<endl<<"Crie sua conta de admin agora: "<<endl
                <<endl<<"Crie um Id (ex: xxxx)...: ";
                getline(cin, acessAdmin.at(contAdmin).IdAdmin);
                do{
                    cout<<endl<<"Crie uma senha do Admin...: ";
                    getline(cin, acessAdmin.at(contAdmin).SenhaAdmin);
                    cout<<endl<<"Insira a senha novamente...: ";
                    getline(cin, confirmacaoTemporaria);
                    //Mensagem de erro para senhas diferentes
                    if(confirmacaoTemporaria != acessAdmin.at(contAdmin).SenhaAdmin){
                    cout<<endl<<"Senhas diferentes, tente novamente!!"<<endl;
                    system("pause");
                    }
                }while(confirmacaoTemporaria != acessAdmin.at(contAdmin).SenhaAdmin);
                contAdmin++;  
        }
    }
    else{
        cout<<endl<<"Cadastro de Administradores está completo!!";
    }
    // Laço de repetição Autenticação
    do { 
        system("cls");
        cout<<endl<<"======== Login ========"
            <<endl<<"Id Funcionario...: ";
        getline(cin, idLogin);
            //Laço de repetição de verificação de senha
                cout<<endl<<"Senha...: ";
                getline(cin, senhaLogin);
                // Mensagens de erro
                if(idLogin != acessAdmin.at(0).IdAdmin) {
                    cout<<endl<<"ID incorreto, tente novamente."<<endl;
                    system("pause");
                }
                else if(senhaLogin != acessAdmin.at(0).SenhaAdmin){
                    cout<<endl<<"Senha incorreta, tente novamente."<<endl;
                    system("pause");
                }  
    }while(idLogin != acessAdmin.at(0).IdAdmin || senhaLogin != acessAdmin.at(0).SenhaAdmin);
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
                if(contFuncion < MaxTamFuncionarios){
                    //Cadastro de Funcionários
                        system("cls");
                        cout<<endl<<"==== Cadastro de Funcionario ===="
                        //Entrada de Dados do Funcionário
                            <<endl<<"Insira o nome...: ";
                        cin.ignore();
                        getline(cin, CdFuncionario.at(contFuncion).nomeFuncionario);
                        
                        cout<<endl<<"Insira o CPF...: ";
                        getline(cin, CdFuncionario.at(contFuncion).cpfFuncionario);

                        cout<<endl<<"Insira o E-mail...: ";
                        getline(cin, CdFuncionario.at(contFuncion).emailFuncionario);
                        
                        //laço de repetição para verificação de senha
                        do{
                            //Adicionar caracteres para a senha
                            cout<<endl<<"Insira a senha...: ";
                            getline(cin, CdFuncionario.at(contFuncion).senhaFuncionario);
                            cout<<endl<<"Confirme a senha...: ";
                            getline(cin, confirmacaoTemporaria);
                            
                            //Mensagem de erro para senhas diferentes
                            if(confirmacaoTemporaria != CdFuncionario.at(contFuncion).senhaFuncionario){
                                cout<<endl<<"Senhas diferentes, tente novamente!!"<<endl;
                                system("pause");
                            }
                        }while(confirmacaoTemporaria != CdFuncionario.at(contFuncion).senhaFuncionario);
                        
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
                                CdFuncionario.at(contFuncion).cargo = "Gerente";
                                break;
                            case 2:
                                CdFuncionario.at(contFuncion).cargo = "Vendedor";
                                break;
                            case 3:
                                CdFuncionario.at(contFuncion).cargo = "Estoquista";
                                break;
                            
                            default:
                                cout<<endl<<"Opção errada, tente novamente!!";
                                break;
                            }
                        }while(opMenuCargo <1 || opMenuCargo > 3);
                        //Exibição das informações de Cadastro do funcionário
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informações Cadastro do Funcionário ===="
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
                    if(contClient < MaxTamClientes){
                        //Cadastro de Clientes 
                        system("cls");
                        cout<<endl<<"==== Cadastro de Clientes ===="
                        //Entrada de Dados do Cliente 
                            <<endl<<"Insira o nome...: ";
                        cin.ignore();
                        getline(cin, CdClientes.at(contClient).nomeCliente);
                        
                        cout<<endl<<"Insira o CPF ou CNPJ...: ";
                        getline(cin, CdClientes.at(contClient).registo);
                        
                        cout<<endl<<"Insira o E-mail...: ";
                        getline(cin, CdClientes.at(contClient).EmailCliente);
                        
                        cout<<endl<<"Insira o telefone...: ";
                        getline(cin, CdClientes.at(contClient).telefoneCliente);
                        
                        cout<<endl<<"Insira o endereço...: ";
                        getline(cin, CdClientes.at(contClient).enderecoCliente);
                        
                        //Exibição das informações de Cadastro do Cliente
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informações Cadastro do Cliente ===="
                            <<endl<<"ID: 1234-1"
                            <<endl<<"Nome: "<<CdClientes.at(contClient).nomeCliente
                            <<endl<<"CPF: "<<CdClientes.at(contClient).registo
                            <<endl<<"E-mail: "<<CdClientes.at(contClient).EmailCliente
                            <<endl<<"Telefone: "<<CdClientes.at(contClient).telefoneCliente
                            <<endl<<"Endereço: "<<CdClientes.at(contClient).enderecoCliente
                            <<endl<<"==================================================="<<endl;
                        system("pause");
                        contClient++;
                    }
                    break;     
                case 3:
                    if(contProdut < MaxTamProduto){
                        //Cadastro de Produtos
                        system("cls");
                        cout<<endl<<"==== Cadastro de Produtos ===="
                        //Entrada de Dados do Produto
                            <<endl<<"Insira o nome do produto...: ";
                        cin.ignore();
                        getline(cin, CdProdutos.at(contProdut).nomeProduto);

                        cout<<endl<<"Insira a marca do produto...: ";
                        getline(cin, CdProdutos.at(contProdut).marcaProduto);

                        cout<<endl<<"Insira a Data de Validade do produto...: ";
                        getline(cin,CdProdutos.at(contProdut).dataValidade);
                        //Exibição das informações de Cadastro do Produto
            
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informações Cadastro do Produto ===="
                            <<endl<<"ID: 1234"
                            <<endl<<"Nome: "<<CdProdutos.at(contProdut).nomeProduto
                            <<endl<<"Marca: "<<CdProdutos.at(contProdut).marcaProduto
                            <<endl<<"Data de Validade: "<<CdProdutos.at(contProdut).dataValidade
                            <<endl<<"======================================"<<endl;
                        system("pause");
                        contProdut++;
                    }
                    break;   
                case 4:
                    if(contFornec < MaxTamFornecedor){
                        //Cadastro de Fornecedores
                        system("cls");
                        cout<<endl<<"==== Cadastro de Fornecedores ===="
                        //Entrada de Dados do Fornecedor
                            <<endl<<"Insira o nome do Fornecedor...: ";
                        cin.ignore();
                        getline(cin, CdFornecedores.at(contFornec).nomeFornecedor);

                        cout<<endl<<"Insira o CNPJ...: ";
                        getline(cin, CdFornecedores.at(contFornec).cnpjFornecedor);

                        cout<<endl<<"Insira o endereço do fornecedor...: ";
                        getline(cin, CdFornecedores.at(contFornec).enderecoFornecedor);
                        
                        cout<<endl<<"Insira o telefone do fornecedor...: ";
                        getline(cin, CdFornecedores.at(contFornec).telefoneFornecedor);

                        cout<<endl<<"Insira o email do fornecedor...: ";
                        getline(cin,CdFornecedores.at(contFornec).emailFornecedor);

                        //Exibição das informações de Cadastro do Produto
            
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informações Cadastro do Fornecedor ===="
                            <<endl<<"ID: 1234"
                            <<endl<<"Nome: "<<CdFornecedores.at(contFornec).nomeFornecedor
                            <<endl<<"CNPJ: "<<CdFornecedores.at(contFornec).cnpjFornecedor
                            <<endl<<"Endereço: "<<CdFornecedores.at(contFornec).enderecoFornecedor
                            <<endl<<"Telefone...: "<<CdFornecedores.at(contFornec).telefoneFornecedor
                            <<endl<<"E-mail: "<<CdFornecedores.at(contFornec).emailFornecedor
                            <<endl<<"========================================="<<endl;
                        system("pause");
                        contFornec++;
                    }
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