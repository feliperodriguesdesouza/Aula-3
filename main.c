#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Jogador {
    int vida;
    int forca;
    int defesa;
    int cartas;
};

int pescarCarta() {
    return rand() % 5 + 1;
}

void atacar(struct Jogador *atacante, struct Jogador *oponente) {
    int dano = atacante->forca - oponente->defesa;
    if (dano < 0) {
        dano = 0;
    }
    oponente->vida -= dano;
    printf("Ataque! Oponente perdeu %d pontos de vida.\n", dano);
}

void usarCarta(struct Jogador *jogador, int carta) {
    jogador->cartas -= 1;
    // Lógica para efeito da carta (substitua pelo que desejar)
    printf("Jogador usou a carta %d.\n", carta);
    // Implemente a lógica da carta aqui
}

int main() {
    srand(time(NULL));

    struct Jogador jogador1 = {100, 20, 10, 3};
    struct Jogador jogador2 = {100, 18, 12, 3};

    int vez_do_jogador = 1;

    while (jogador1.vida > 0 && jogador2.vida > 0) {
        printf("Jogador %d, é a sua vez!\n", vez_do_jogador);

        int escolha;
        printf("1 - Pescar carta\n2 - Atacar\n3 - Usar carta\nEscolha uma opção: ");
        scanf("%d", &escolha);

        if (escolha == 1) {
            int carta = pescarCarta();
            printf("Você pescou a carta %d.\n", carta);
            if (vez_do_jogador == 1) {
                jogador1.cartas += 1;
            } else {
                jogador2.cartas += 1;
            }
        } else if (escolha == 2) {
            atacar(vez_do_jogador == 1 ? &jogador1 : &jogador2, vez_do_jogador == 1 ? &jogador2 : &jogador1);
        } else if (escolha == 3) {
            if (vez_do_jogador == 1 && jogador1.cartas > 0) {
                usarCarta(&jogador1, 1); // Suponha que 1 é o número da carta
            } else if (vez_do_jogador == 2 && jogador2.cartas > 0) {
                usarCarta(&jogador2, 1); // Suponha que 1 é o número da carta
            } else {
                printf("Você não possui cartas para usar.\n");
            }
        }

        vez_do_jogador = (vez_do_jogador == 1) ? 2 : 1;

        printf("Jogador 1 - Vida: %d, Cartas: %d\n", jogador1.vida, jogador1.cartas);
        printf("Jogador 2 - Vida: %d, Cartas: %d\n", jogador2.vida, jogador2.cartas);
    }

    printf("Fim do jogo! O Jogador %d venceu!\n", (jogador1.vida > 0) ? 1 : 2);

    return 0;
}
