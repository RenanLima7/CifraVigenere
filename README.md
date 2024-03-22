# Decifrador de Vigenère

Um programa em C para decifrar mensagens cifradas usando o algoritmo de Vigenère.

## Descrição

Este programa foi desenvolvido para decifrar mensagens cifradas usando a cifra de Vigenère. Ele oferece duas opções principais: decifrar com uma chave conhecida ou usar força bruta para encontrar a chave desconhecida. A cifra de Vigenère é uma técnica de criptografia simples, mas eficaz, que usa uma série de cifras de César diferentes com base nas letras de uma palavra-chave.

## Autores

- [@RenanLima7](https://github.com/RenanLima7)
- [@carlos-aldrim](https://github.com/carlos-aldrim)
- [@jairoevaristo](https://github.com/jairoevaristo)

## Funcionalidades

1. **Decifração com chave conhecida:** O programa permite ao usuário fornecer a mensagem cifrada e a chave para decifrar a mensagem.

2. **Decifração por força bruta:** Se o usuário não conhece a chave, o programa pode tentar todas as combinações possíveis de chaves de até 4 caracteres para decifrar a mensagem.

3. **Interface simples:** O programa possui uma interface de linha de comando com um menu intuitivo que orienta o usuário na escolha da opção desejada.

## Requisitos

- Compilador GCC (ou outro compilador compatível com C)
- Sistema operacional compatível com a linguagem C (Windows, Linux, macOS, etc.)

## Instalação e Execução

Para instalar e executar o programa, siga os passos abaixo:

1. **Clone o repositório:**
    ```bash
    git clone https://github.com/RenanLima7/CifraVigenere
    ```

2. **Navegue até o diretório do projeto:**
    ```bash
    cd CifraVigenere
    ```

3. **Compile o código:**
    ```bash
    gcc -o Decifrador Decifrador.c
    ```

4. **Execute o programa:**
    ```bash
    ./Decifrador
    ```
    
## Instruções de Uso:

1. Execute o programa.

2. Insira a mensagem cifrada quando solicitado.

3. Escolha se você conhece a chave ou não.

4. Se você conhece a chave, insira-a quando solicitado.

5. Aguarde enquanto o programa decifra a mensagem.

6. O texto decifrado será exibido na tela.

## Melhorias

Algumas melhorias que podem ser implementadas incluem:

- Implementação de uma interface gráfica.
- Aprimoramento da eficiência do algoritmo de força bruta.
- Adição de suporte para chaves de comprimento variável.

