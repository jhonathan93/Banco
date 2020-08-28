//estrutura
#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <locale.h>
#include <cmath>
#include <stdio.h>
//
using namespace std;
//
int main(void)
{
	system("cls");//limpa tela
	//prepara ambiente
	setlocale(LC_ALL, "portuguese");
	cout << setprecision(02); //numero de casas decimais
	cout << setiosflags(ios::right);
	cout << setiosflags(ios::fixed);
	//declara��o vari�veis
	int I, pesq, size, num;
	char RESP;
	float saldo;
	bool acha = false;
	
	//camandos l�gicos
	cout<<"Quantas contas bancarias deseja criar :";
	cin>>size;
	size -= 1;
	int conta[size];
	float dinheiro[size];
	char nome[40][size], nom[size];
	setbuf(stdin, NULL);
	system("cls");	
	
	for (I = 0; I <= size; I++){
		
		cout<<"====== Bem-vindo ao banco Silva ====== \n "<<endl;
		cout<<" Informe o seu nome completo: ";
		gets(nome[I]);
		system("cls");
		
		do{
			cout<<" "<<nome[I]<<", Deposite no minino 20 reais R$: ";
			cin>>dinheiro[I];	
		}while (dinheiro[I] < 20);
		
		conta[I] = 1000 + I;
		system("cls");
		
		cout<<" ====== Dados da conta banc�ria ====== \n "<<endl;
		cout<<" Titular: "<<nome[I]<<endl;
		cout<<" Conta n�mero: "<<conta[I]<<endl;
		cout<<" Saldo: "<<dinheiro[I]<<"\n"<<endl;
		cout<<"Sua conta banc�ria foi criada com sucesso. Apertei ENTRE para continuar. "<<endl;
		system("pause");
		system("cls");
		setbuf(stdin, NULL);	
	}

	system("cls");
	do{
		cout<<" ====== Menu de acesso ====== \n "<<endl;
		cout<<"Digite o n�mero de acesso da sua conta: ";
		cin>>pesq;
		cout<<endl;
		I=0;

		while(I <= size && acha == false){
			if(pesq == conta[I]){
				acha = true;
				nom[40] = nome[40][I];
				num = conta[I];
				saldo = dinheiro[I];
			}else{
				I++;
			}
		}

		if(acha==true){
			cout<<"Conta localizada com sucesso, Apertei ENTRE para continuar."<<endl;
			system("pause");
			do{	
				system("cls");	
				cout<<"Bem-vindo, "<<nom<<endl;
				cout<<"voc� est� logado na conta N�, "<<num<<endl;
				cout<<"Seu saldo atual � R$: "<<saldo<<endl;	
				cout<<"========Menu========="<<endl;
				cout<<"1- Saldo "<<endl;
				cout<<"2- Saque "<<endl;
				cout<<"3- Deposito "<<endl;
				cout<<"4- Transfer�ncia "<<endl;
				cout<<"5- Trocar de conta "<<endl;
				cout<<"6- Sair "<<endl;
				cout<<"Informe a op��o desejada: ";
				int op; 
				float valor;
				cin>>op;
				cout<<endl;

				switch(op){
					case 1:
						cout<<"Seu saldo atual � de R$: "<<saldo<<endl;
					break;

					case 2:
						cout<<"Informe o valor do saque: ";
						cin>>valor;
						if(valor > 0 && valor <= saldo){
							saldo -= valor;
							cout<<"Saque realizado com sucesso. "<<endl;
						}else{
							cout<<"Lamento, imposs�vel sacar esse valor: "<<valor;
						}
					break;

					case 3:
						cout<<"Informe o valor a ser depositado: ";
						cin>>valor;
						if(valor > 0){
							cout<<"Deposito realizado com sucesso. "<<endl;
							saldo += valor;
						}else{
							cout<<"Lamento, imposs�vel depositar esse valor: "<<valor;
						}
					break;

					case 4:
						cout<<"Informe o valor que ser� transferido: ";
						cin>>valor;
						if(valor > 0 && valor <= saldo ){
							cout<<"Informe o n�mero da conta destino: ";
							cin>>pesq;
							if(pesq != num){
								acha = false;
								I = 0;
								while(I <= size && acha == false){
									if (pesq == conta[I]){
										acha = true;
										dinheiro[I] += valor;
										saldo -= valor;
									}else{
										I++;
									}
								}
								if(acha == true){
									cout<<"Transfer�ncia realizado com sucesso. ";
								}else{
									cout<<"Conta inexistente. ";
								}
							}else{
								cout<<"imposs�vel transferir para a propria conta: ";
							}
						}else{
							cout<<"Lamento, imposs�vel Transferir esse valor: "<<valor;
						}
					break;

					case 5:
						cout<<"Informe o n�mero da conta que desejar acessar: ";
						cin>>pesq;
						if(pesq != num){
							I=0;
							acha = false;
							while(I <= size && acha == false){
								if(pesq == conta[I]){
									acha = true;
									num = conta[I];
									saldo = dinheiro[I];
								}else{
									I++;	
								}
							}
							if(acha == true){
								cout<<"Conta localizada com sucesso.";
							}else{
								cout<<" Conta inexistente. ";
							}
						}else{
							cout<<"Voc� j� est� logado na conta: "<<pesq;
						}
					break;

					case 6:
						cout<<"Tem certeza que deseja sair: ";
						cin>>RESP;
						RESP=toupper(RESP);	
						if(RESP == 'S'){
							exit(0);
						}
					break;

					default:
					cout<<"Op��o invalida.";
				}

				for(I = 0; I <= size; I++){
					if(num == conta[I]){
						dinheiro[I] = saldo;
					}
				}

				cout<<endl;
				cout<<"Continua? (S)IM/(N)�O + <Enter>";
				cin>>RESP;
				RESP=toupper(RESP);
				setbuf(stdin, NULL);
			}while(RESP == 'S');
		}else{
			cout<<"Conta inexistente, Apertei ENTRE para continuar "<<endl;
			system("pause");
			system("cls");
		}
		setbuf(stdin, NULL);
	}while(acha == false);
	system("pause");
	return 0;
}