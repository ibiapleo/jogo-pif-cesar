# Programação Imperativa e Funcional - 2024.2 | CESAR School

# Código atualizado se encontra na developer.

## Equipe:
- Leonardo Ibiapina (@ibiapleo)
- Ênio Bazante (@EnioBazante)
- Gabriel Moraes (@GabrielMorais2)

# Jogo: Wobble Wing

## Descrição do jogo:
O Wobble Wing é um jogo do estilo Bullet Hell, onde você deve desviar de balas enquanto derrota hordas de inimigos, desenvolvido em linguagem C. Ele utiliza a biblioteca CLI-lib para interação em linha de comando e foi projetado para rodar exclusivamente em sistemas **Linux** e **macOS**.

O objetivo do jogo é baseado na movimentação e na capacidade de atirar do seu helicóptero. Inimigos tentarão lhe atingir, você deverá desviar das balas enquanto tenta acertá-los para acabar com todos o mais rápido possível e conseguir a maior pontuação! . Os jogadores interagem com o jogo através do terminal, utilizando comandos que influenciam as ações e resultados.

## Regras do Jogo:
- Utilize as teclas "W A S D" para se movimentar.
- Utiliza a tecla "SPACE" para atirar
- Desvie das balas dos inimigos
- Se for atingido, perde vida
- Acerte os seus inimigos para faze-los sumir.

## Compatibilidade:
Este jogo **não é compatível com sistemas Windows** devido ao uso da biblioteca CLI-lib, que suporta apenas **Linux** e **macOS**.

## Instruções de Compilação e Execução:

### Pré-requisitos:
Certifique-se de que você tem um sistema operacional compatível (Linux ou macOS) e que a CLI-lib está instalada. Siga as instruções abaixo para instalação e execução:

1. Clone o repositório:
   ```bash
   git clone https://github.com/ibiapleo/jogo-pif-cesar.git

2. Entre na pasta do projeto:
   ```bash
   cd projeto
3. Compile o código:
   ```bash
      gcc ./src/.c -I./include -o cli-lib-[A definir]

4. Execute o jogo:
      ```bash
      ./build/[A definir]
## Observações:
- Este jogo utiliza a biblioteca CLI-lib para interações via terminal.
- Windows não é suportado. Para jogar no Windows, recomenda-se utilizar uma máquina virtual ou ambiente WSL (Windows Subsystem for Linux), mas não é garantido que todas as funcionalidades do jogo funcionem corretamente.
## Dependências:
- CLI-lib (instruções fornecidas acima)
## Licença:
Este projeto é licenciado sob a [MIT License](LICENSE), veja o arquivo de licença para mais detalhes.
