#include <iostream>
using namespace std;

struct No {
	int valor;
	No *proximo;
};

void inserir(No *novoNo, No **primeiroNo, No **ultimoNo) {
	if(*primeiroNo == NULL) {
		*primeiroNo = novoNo;
		*ultimoNo = novoNo;
	}
	else {
	    (*ultimoNo)->proximo = novoNo;
	    *ultimoNo = novoNo;
	}
}
void remover(No *no, No **primeiroNo, No **ultimoNo) {
	if(*primeiroNo == NULL) {
		cout << "A lista está vazia!!" << endl;
		return;
	}
	if(*primeiroNo == no) {
		*primeiroNo = (*primeiroNo)->proximo;
		
		if(*primeiroNo == NULL) {
			*ultimoNo = NULL;
		}
		delete no;
		return;
	}
	No *atual = *primeiroNo;
	
	while(atual->proximo != NULL) {
		if(atual->proximo == no) {
			atual->proximo = no->proximo;
			if(atual->proximo == NULL) {
				*ultimoNo = atual;
			}
			delete no;
			return;
		}
		atual = atual->proximo;
	}
}
No* buscar(int valor, No *primeiroNo) {
	No *atual = primeiroNo;

	while(atual != NULL) {
		if(atual->valor == valor) {
			return atual;
		}
		atual = atual->proximo;
	}
	return NULL;
}

bool verificaSeExiste(int valor, No *primeiroNo) {
	No *atual = primeiroNo;
	No *retornoDeBuscar = buscar(valor, atual);

	bool seExiste = (retornoDeBuscar != NULL) ? true : false;
	return seExiste;
}

void imprimir(No *primeiroNo) {
	No *atual = primeiroNo;
	if(atual == NULL) {
		cout << "A lista está vazia!" << endl;
	}
	while(atual) {
		cout << atual->valor << " -> ";
		atual = atual->proximo;
	}
	cout << "NULL" << endl;
}

void removerNo(int valor, No *primeiroNo, No *ultimoNo) {
	No *retornoDeBuscar = buscar(valor, primeiroNo);
	
	if(retornoDeBuscar != NULL) {
		remover(retornoDeBuscar, &primeiroNo, &ultimoNo);
	} else {
		cout << "Valor não existe dentro da lista!" << endl;
	}
}

No* criarNo() {
	No *novoNo = new No();
	int valorEscolhido;	

	cout << "VALOR: ";
	cin >> valorEscolhido;

	novoNo->valor = valorEscolhido;
	novoNo->proximo = NULL;
	
	return novoNo;
}

void interface() {
	cout << "=-==-==-==-==-==-==-==-==-==-==-==-==-==" << endl;
	cout << "\t1) INSERIR"<< endl;
	cout << "\t2) REMOVER"<< endl;
	cout << "\t3) IMPRIMIR"<< endl;
	cout << "\t4) VERIFICAR SE EXISTE" << endl;
	cout << "\t5) SAIR" << endl;
	cout << "=-==-==-==-==-==-==-==-==-==-==-==-==-==" << endl;
}

int main() {
	No *primeiroNo = NULL;
	No *ultimoNo = NULL;
	int opcao = 0, numeroEscolhido;

	do{
		interface();
		cin >> opcao;
		cout << endl;
	
		switch(opcao) {
			case 1: {
				No *novoNo = criarNo();
				inserir(novoNo, &primeiroNo, &ultimoNo);
				break;
			}
			case 2: { 
				cout << "Deseja remover qual valor?" << endl;
				cin >> numeroEscolhido;
				
				removerNo(numeroEscolhido, primeiroNo, ultimoNo);
				break;
			}
			case 3: 
				imprimir(primeiroNo);
				break;
			case 4: {
				cout << "Deseja verificar qual valor?" << endl;
				cin >> numeroEscolhido;
				
				(verificaSeExiste(numeroEscolhido, primeiroNo) == true) ? 
				                            cout << "Existe na fila!" << endl : 
				                            cout << "Não existe na fila!" << endl;
				                            
				break;
			}
			case 5: 
				break;
			default:
				cout << "Opção inválida!" << endl;
		}
	}while(opcao != 5);
	
	return 0;
}