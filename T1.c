//a88421Lourenço_Andrade 88427Simao_Domingues
#include <stdio.h>

// f(d) = a*d^2 + b*d + c
int f(int d, int a, int b, int c) {
    return a * d * d + b * d + c;
}

// Soma recursiva dos f(d) para todos os dígitos de m
int soma_digitos(int m, int a, int b, int c) {
    if (m == 0) return 0;
    int d = m % 10;
    return f(d, a, b, c) + soma_digitos(m / 10, a, b, c);
}

// Produto recursivo dos f(d) para todos os dígitos de m (exceto os zeros)
int prod_digitos(int m, int a, int b, int c) {
    if (m == 0) return 1; // metemos a multiplicar por 1 para  assim ignorarmos o 0 na multiplicacao
    int d = m % 10;
    if (d == 0) return prod_digitos(m / 10, a, b, c);
    return f(d, a, b, c) * prod_digitos(m / 10, a, b, c);
}

// Função F(m)
int F(int m, int a, int b, int c) {
    if (m == 0) return 0;
    if (m % 2 == 0) { // m par
        return soma_digitos(m, a, b, c);
    } else { // m ímpar
        int soma = soma_digitos(m, a, b, c);
        int prod = prod_digitos(m, a, b, c);
        if (soma == 0) return 0;
        return prod % soma;
    }
}

// Aplicação recursiva da função F até as condições de paragem
void aplica_F(int n, int a, int b, int c, int L, int etapa) {
    printf("%d\n", n);
    if (etapa == L) return; // atingiu o limite
    if (n >= 0 && n <= 9) return; // número de um dígito
    int prox = F(n, a, b, c);
    if (prox == n) return; // se prox o f(n) == n estabiliza
    aplica_F(prox, a, b, c, L, etapa + 1);
}

int main() {
    int n, a, b, c, L;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &L);
    aplica_F(n, a, b, c, L, 0);
    return 0;
}
