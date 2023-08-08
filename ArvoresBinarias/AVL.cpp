#include <iostream>

using namespace std;

struct No {
    int valor;
    No* esquerda;
    No* direita;

    No(int v) {
        valor = v;
        esquerda = nullptr;
        direita = nullptr;
    }
};

void tInsere(No*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new No(valor);
    } else if (valor < raiz->valor) {
        tInsere(raiz->esquerda, valor);
    } else {
        tInsere(raiz->direita, valor);
    }
}

int tPesq(No* raiz, int valor, int& chamadas) {
    chamadas++;
    if (raiz == nullptr || raiz->valor == valor) {
        return chamadas;
    } else if (valor < raiz->valor) {
        return tPesq(raiz->esquerda, valor, chamadas);
    } else {
        return tPesq(raiz->direita, valor, chamadas);
    }
}

int altura(No* no) {
    if (no == nullptr) {
        return 0;
    }
    return max(altura(no->esquerda), altura(no->direita)) + 1;
}

int fatorBalanceamento(No* no) {
    if (no == nullptr) {
        return 0;
    }
    return altura(no->esquerda) - altura(no->direita);
}

void rotacaoEsquerda(No*& raiz) {
    No* novaRaiz = raiz->direita;
    raiz->direita = novaRaiz->esquerda;
    novaRaiz->esquerda = raiz;
    raiz = novaRaiz;
}

void rotacaoDireita(No*& raiz) {
    No* novaRaiz = raiz->esquerda;
    raiz->esquerda = novaRaiz->direita;
    novaRaiz->direita = raiz;
    raiz = novaRaiz;
}

void balancear(No*& raiz) {
    int fb = fatorBalanceamento(raiz);
    if (fb > 1) {
        if (fatorBalanceamento(raiz->esquerda) < 0) {
            rotacaoEsquerda(raiz->esquerda);
        }
        rotacaoDireita(raiz);
    } else if (fb < -1) {
        if (fatorBalanceamento(raiz->direita) > 0) {
            rotacaoDireita(raiz->direita);
        }
        rotacaoEsquerda(raiz);
    }
}

void tInsereAVL(No*& raiz, int valor) {
    if (raiz == nullptr) {
        raiz = new No(valor);
    } else if (valor < raiz->valor) {
        tInsereAVL(raiz->esquerda, valor);
    } else {
        tInsereAVL(raiz->direita, valor);
    }
    balancear(raiz);
}

int main() {
    No* raizNormal = nullptr;
    No* raizAVL = nullptr;
    int valor;

    // Leitura dos números inteiros
    cin >> valor;
    while (valor != 0) {
        tInsere(raizNormal, valor);
        tInsereAVL(raizAVL, valor);
        cin >> valor;
    }

    // Leitura do valor X
    int x;
    cin >> x;

    // Contagem de chamadas recursivas
    int chamadasNormal = 0;
    int chamadasAVL = 0;
    tPesq(raizNormal, x, chamadasNormal);
    tPesq(raizAVL, x, chamadasAVL);

    // Exibição do resultado
    cout << "Arvore normal: " << chamadasNormal << endl;
    cout << "AVL: " << chamadasAVL << endl;

    return 0;
}
