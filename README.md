#### Nomes: Felipe Men dos Santos; Otho Oliveira Candido; Lucas Rodrigues de Queiroz; João Pedro Silva Pinheiro
#### RMs: 557571; 557054; 556323; 557013

# Crônometro para Pit Stop

## Descrição: 
O nosso projeto foi feito para ser usado em corridas, com o intuito de marcar a velocidade de cada Pit Stop no meio da corrida, podendo ajudar a eficiência das equipes e trazer novas pessoas para acompanhar as corridas, já que até mesmo quem não conhece muito das corridas sabe o quão importante uma boa eficiência de Pit Stop é.

## Componentes Ultilizados:
- 01 Arduino UNO R3
- 01 Display LCD
- 01 Sensor Ultrasônico de Distância HC-SR04

## Funcionalidades:
1. Configuração Inicial:
    - Define os pinos do sensor ultrassônico e a distância mínima para detecção.
    - Configura os pinos do sensor, inicializa a comunicação serial e o display LCD.

2. Loop Principal:
    - Envia um pulso ultrassônico e mede o tempo de retorno para calcular a distância do objeto.
    - Se a distância for menor que a mínima definida, o código registra o tempo inicial e calcula o tempo decorrido em milissegundos.
    - Exibe o tempo decorrido no display LCD em segundos e milissegundos.
    - Se a distância for maior ou igual à mínima, o código reseta a detecção do objeto, limpa o display e apaga a luz de fundo após um pequeno atraso.

## Imagem no WOKWI:
### Nenhum Veículo Detectado
![image](https://github.com/FelipeMen10/Sprint-1-Edge/assets/153327403/4729b1ec-033a-43d8-a301-85e5a7c36499)

### Veículo Detectado
![image](https://github.com/FelipeMen10/Sprint-1-Edge/assets/153327403/d3b4c23b-ddc4-4302-b9fd-feb0f4680a74)


## Instalação
Para usar o sistema, monte o circuito conforme descrito no [vídeo explicativo](https://youtu.be/cGM4jccZ2P0). Além disso, você pode visualizar e editar o circuito no [WOKWI](https://wokwi.com/projects/400588640966434817)

## Dificuldades Encontradas:
Tivemos problema com a contagem e a economia de bateria do LCD, porém após mexer em alguns delays e estudar um pouco das funções da biblioteca do LCD conseguimos faazer o código funcionar como desejado.
