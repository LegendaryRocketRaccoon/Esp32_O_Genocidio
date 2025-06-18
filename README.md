Relatório


Objetivo do Projeto:

Desenvolver um sistema baseado em ESP32 que permita o controle individual de 8 LEDs por meio de uma página web. O ESP32 atua como ponto de acesso, sem necessidade de roteador externo, e exibe uma interface gráfica simples onde o usuário pode ligar ou desligar os LEDs remotamente.


Materiais Utilizados:

Quantidade	Componente

1	           ESP32
8	           LEDs
8	           Resistores (180Ω)
1	           Cabo micro USB
	           Protoboard e jumpers
1	           Dispositivo móvel com Wi-Fi


Ligação:

Cada LED está conectado a um pino digital do ESP32:

GPIO 25 → LED 1

GPIO 27 → LED 2

GPIO 14 → LED 3

GPIO 26 → LED 4

GPIO 12 → LED 5

GPIO 13 → LED 6

GPIO 32 → LED 7

GPIO 33 → LED 8


Os resistores limitadores de corrente (180Ω) são usados em série com os LEDs.


Funcionamento Geral:

O ESP32 cria uma rede Wi-Fi com SSID e senha definidos no código. Ao conectar-se a essa rede via celular ou computador e acessar o IP do servidor, o se visualiza uma interface web com botões para controle de cada LED.

Após carregar o código e conectar-se à rede Wi-Fi:

- O celular acessa o IP;


- A página exibida permite ligar/desligar cada um dos 8 LEDs;


- O estado de cada LED é mantido na interface com base na variável statePinXX.


Realização de Testes:

- LEDs respondem corretamente aos comandos via página web;

- Página recarrega com os estados corretos;

- Interface acessível por múltiplos dispositivos;

- Estável por sessões contínuas de uso.
