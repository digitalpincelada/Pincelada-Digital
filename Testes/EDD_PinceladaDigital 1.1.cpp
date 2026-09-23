#include <iostream>
#include <locale.h>
#include <string>
#include <array>
#include <iomanip>
using namespace std;  
/* ==== Structs principais ====*/
struct TAdmin{
    /*-Struct Admin-*/
    string IdAdmin = "", SenhaAdmin = "";
};
struct TFuncionario{
    /*-Struct Funcionario-*/
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
        <<endl<<"3.Modulo de Consultas"
        <<endl<<"4.Sair da Conta"
        <<endl<<"0.Sair"
        <<endl<<"Escolha: ";
}
/* ==== Modulo de Cadastro ====*/
void MenuCadastro(){
    system("cls");
    cout<<endl<<"==== Modulo de Cadastro ===="
        <<endl<<"1.Cadastro de Funcionarios"
        <<endl<<"2.Cadastro de Clientes"
        <<endl<<"3.Cadastro de Produtos"
        <<endl<<"4.Cadastro de Fornecedores"
        <<endl<<"0.Voltar"
        <<endl<<"Escolha: ";
        
}
/* ==== Modulo de Consultas ====*/
void ModuloConsultas(){
    system("cls");
    cout<<endl<<"==== Modulo de Consultas ===="
        <<endl<<"1.Consulta de Funcionarios"
        <<endl<<"2.Consulta de Clientes"
        <<endl<<"3.Consulta de Produtos"
        <<endl<<"4.Consulta de Fornecedores"
        <<endl<<"0.Voltar"
        <<endl<<"Escolha: ";
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    /*-Variaveis de Escolha dos Menus-*/
    int opMenuPrincipal, opMenuCadastro, opMenuConsulta;
    /*-Variavel do conversor de IDs*/
    stringstream conversor;
    /*-Variaveis de Primeiro acesso no sistema-*/
    const int MaxTamAdmin = 1;
    array<TAdmin, MaxTamAdmin> acessAdmin;
    int contAdmin=0;
    /*-Variavel de Confirmacao de senha*/
    string confirmacaoTemporaria;
    /*-Variaveis de Login-*/
    string idLogin, senhaLogin;
    /*-Variaveis Funcionario-*/
    const int MaxTamFuncionarios = 10;
    array<TFuncionario, MaxTamFuncionarios> CdFuncionario;
    int opMenuCargo;
    int contFuncion = 0, geradorIdFuncion = 0;
    /*-Variaveis Cliente-*/
    const int MaxTamClientes = 10;
    array<TCliente, MaxTamClientes> CdClientes;
    int contClient = 0, geradorIdClient = 0;
    /*-Variaveis Produto-*/
    const int MaxTamProduto = 10;
    array<TProduto, MaxTamProduto> CdProdutos;
    int contProdut = 0, geradorIdProduto = 0;
    /*-Variaveis Fornecedores-*/
    const int MaxTamFornecedor = 10;
    array<TFornecedor, MaxTamFornecedor> CdFornecedores;
    int contFornec = 0, geradorIdFornec = 0;
    /*-Variavies de Consultas-*/
    int opConsultFuncion, opConsultClient, opConsultProdut, opConsultFornec;
    int escolhaId;

    // Verificacao se o maximo de admins foi atingido
    if(contAdmin < MaxTamAdmin){
        //Primeiro acesso no sistema
        if(acessAdmin.at(contAdmin).IdAdmin == ""){
            //Laco de repeticao de verificacao de senha
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
        cout<<endl<<"Cadastro de Administradores esta completo!!";
    }
    // Laco de repeticao Autenticacao
    do { 
        system("cls");
        cout<<endl<<"======== Login ========"
            <<endl<<"Id Funcionario...: ";
        getline(cin, idLogin);
            //Laco de repeticao de verificacao de senha
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
    //Mensagem de Autenticacao
    cout<<endl<<"Login realizado com sucesso!"<<endl;
    system("pause");
    //Laco de repeticao do menu principal
    do{
    //Funcao do Menu Principal
    MenuPrincipal();
    cin>>opMenuPrincipal;
        //Controle de Fluxo do Menu Principal
        switch (opMenuPrincipal)
        {
        /* == Modulo de Cadastro == */
        case 1:
            do{
            //Funcao do Menu de Cadastro
            MenuCadastro();
            cin>>opMenuCadastro;
                /*== Controle de Fluxo do Menu_Cadastro ==*/
                switch (opMenuCadastro)
                {
                case 1:
                if(contFuncion < MaxTamFuncionarios){
                    //Cadastro de Funcionarios
                        system("cls");
                        cout<<endl<<"==== Cadastro de Funcionario ===="
                        //Entrada de Dados do Funcionario
                            <<endl<<"Insira o nome...: ";
                        cin.ignore();
                        getline(cin, CdFuncionario.at(contFuncion).nomeFuncionario);
                        
                        cout<<endl<<"Insira o CPF...: ";
                        getline(cin, CdFuncionario.at(contFuncion).cpfFuncionario);

                        cout<<endl<<"Insira o E-mail...: ";
                        getline(cin, CdFuncionario.at(contFuncion).emailFuncionario);
                        
                        //laco de repeticao para verificacao de senha
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
                            <<endl<<"Selecione o Cargo do funcionario...: ";
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
                                cout<<endl<<"Opcao errada, tente novamente!!";
                                break;
                            }
                        }while(opMenuCargo <1 || opMenuCargo > 3);
                        //Gerando o Id do funcionario
                        conversor.str("");
                        conversor.clear();
                        conversor << setw(4) << setfill('0') << geradorIdFuncion;
                        CdFuncionario.at(contFuncion).idFuncionario = conversor.str();
                        //Exibicao das informacoes de Cadastro do funcionario
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informacoes Cadastro do Funcionario ===="
                            <<endl<<"Matricula: "<<CdFuncionario.at(contFuncion).idFuncionario
                            <<endl<<"Nome: "<<CdFuncionario.at(contFuncion).nomeFuncionario
                            <<endl<<"CPF: "<<CdFuncionario.at(contFuncion).cpfFuncionario
                            <<endl<<"E-mail: "<<CdFuncionario.at(contFuncion).emailFuncionario
                            //Futuramente exibir (Senha: ****) 
                            <<endl<<"Cargo: "<<CdFuncionario.at(contFuncion).cargo
                            <<endl<<"======================================="<<endl;
                        system("pause");
                        contFuncion++;
                        geradorIdFuncion++;
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
                        
                        cout<<endl<<"Insira o endereco...: ";
                        getline(cin, CdClientes.at(contClient).enderecoCliente);
                        //Gerando o ID do cliente
                        conversor.str("");
                        conversor.clear();
                        conversor << setw(4) << setfill('0') << geradorIdClient;
                        CdClientes.at(contClient).idCliente = conversor.str();
                        //Exibicao das informacoes de Cadastro do Cliente
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informacoes Cadastro do Cliente ===="
                            <<endl<<"ID: "<<CdClientes.at(contClient).idCliente
                            <<endl<<"Nome: "<<CdClientes.at(contClient).nomeCliente
                            <<endl<<"CPF: "<<CdClientes.at(contClient).registo
                            <<endl<<"E-mail: "<<CdClientes.at(contClient).EmailCliente
                            <<endl<<"Telefone: "<<CdClientes.at(contClient).telefoneCliente
                            <<endl<<"Endereco: "<<CdClientes.at(contClient).enderecoCliente
                            <<endl<<"==================================================="<<endl;
                        system("pause");
                        contClient++;
                        geradorIdClient++;
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
                        //Gerando o ID do Produto
                        conversor.str("");
                        conversor.clear();
                        conversor<<setw(4) << setfill('0') << geradorIdProduto;
                        CdProdutos.at(contProdut).idProduto = conversor.str();
                        //Exibicao das informacoes de Cadastro do Produto
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informacoes Cadastro do Produto ===="
                            <<endl<<"Codigo do Produto: "<<CdProdutos.at(contProdut).idProduto
                            <<endl<<"Nome: "<<CdProdutos.at(contProdut).nomeProduto
                            <<endl<<"Marca: "<<CdProdutos.at(contProdut).marcaProduto
                            <<endl<<"Data de Validade: "<<CdProdutos.at(contProdut).dataValidade
                            <<endl<<"======================================"<<endl;
                        system("pause");
                        contProdut++;
                        geradorIdProduto++;
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

                        cout<<endl<<"Insira o endereco do fornecedor...: ";
                        getline(cin, CdFornecedores.at(contFornec).enderecoFornecedor);
                        
                        cout<<endl<<"Insira o telefone do fornecedor...: ";
                        getline(cin, CdFornecedores.at(contFornec).telefoneFornecedor);

                        cout<<endl<<"Insira o email do fornecedor...: ";
                        getline(cin,CdFornecedores.at(contFornec).emailFornecedor);
                        //Gerando o ID do Funcionario
                        conversor.str("");
                        conversor.clear();
                        conversor << setw(4) << setfill('0') << geradorIdFornec;
                        CdFornecedores.at(contFornec).idFornecedor = conversor.str();      
                        //Exibicao das informacoes de Cadastro do Produto
                        system("cls");
                        cout<<endl<<"Cadastro realizado com sucesso!!"
                            <<endl<<"==== Informacoes Cadastro do Fornecedor ===="
                            <<endl<<"ID: "<< CdFornecedores.at(contFornec).idFornecedor
                            <<endl<<"Nome: "<<CdFornecedores.at(contFornec).nomeFornecedor
                            <<endl<<"CNPJ: "<<CdFornecedores.at(contFornec).cnpjFornecedor
                            <<endl<<"Endereco: "<<CdFornecedores.at(contFornec).enderecoFornecedor
                            <<endl<<"Telefone...: "<<CdFornecedores.at(contFornec).telefoneFornecedor
                            <<endl<<"E-mail: "<<CdFornecedores.at(contFornec).emailFornecedor
                            <<endl<<"========================================="<<endl;
                        system("pause");
                        contFornec++;
                        geradorIdFornec++;
                    }
                    break;
                //Voltar para menu principal    
                case 0:
                    cout<<endl<<"Voltando para menu principal...";
                    break;
                    
                default:
                    cout<<endl<<"Opcao invalida!!";
                    break;
                }
                //Fechamento do Modulo de Cadastro
            }while(opMenuCadastro != 0);  
            break;
        /* == Modulo de vendas == */
        case 2:
            cout<<endl<<"Cadastro de Vendas em desenvolvimento";
            break; 
        /* ==== Modulo de Consultas ====*/  
        case 3:
            ModuloConsultas();
            cin>>opMenuConsulta;

            switch(opMenuConsulta)
            {
            //Consulta Funcionario
            case 1:
                cout<<endl<<"-Escolha o tipo de Filtro-"
                    <<endl<<"1.Filtrar ID"
                    <<endl<<"2.Filtrar Todos"
                    <<endl<<"Escolha: ";
                cin>>opConsultFuncion;
                switch (opConsultFuncion)
                {
                //Filtro Por Id
                case 1:
                    cout<<endl<<"Digite o ID...:";
                    cin>>escolhaId;
                    
                    break;
                //Filtrar Todos
                case 2:
                cout<<endl<<"Lista de Funcionarios Cadastrados"<<endl;
                for (int x=0; x<contFuncion; x++) {
                    cout<<endl<<"ID: "<<CdFuncionario.at(x).idFuncionario<<" - "
                        <<"Nome: "<<CdFuncionario.at(x).nomeFuncionario<<" - "
                        <<"Matricula: "<<CdFuncionario.at(x).idFuncionario<<" - "
                        <<"CPF: "<<CdFuncionario.at(x).cpfFuncionario<<" - "
                        <<"e-mail: "<<CdFuncionario.at(x).emailFuncionario<<" - "
                        <<"senha: "<<CdFuncionario.at(x).senhaFuncionario<<" - "
                        <<"Cargo: "<<CdFuncionario.at(x).cargo<<endl
                        <<"--------------------------------------------------------"
                        <<"--------------------------------------------------------";
                }                   
                    break;
                default:
                    break;
                }
                break;
            case 2:
            
                break;
            default:
                break;
            }
            
            
        /* == Sair da Conta == */
        case 4:
            cout<<endl<<"Em desenvolvimento"<<endl;
            system("pause");
            break;
        /* == Sair do Sistema == */
        case 0:
            cout<<endl<<"Saindo do Sistema...";
            break;
            
        default:
            cout<<endl<<"Opcao incorreta, tente novamente!!";
            break;
        }
    }while(opMenuPrincipal != 0);
    return 0;
}