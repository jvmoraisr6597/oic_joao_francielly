# Controle de lâmpadas: Sensor de som e monitoramento a distância via protocolo MQTT

  De acordo com a Agência Nacional de Energia Elétrica (Aneel) em uma matéria publicada
em 27/08/2021 e disponibilizada pelo G1 (SILVEIRA, 2021), a conta de luz, que já estava
sofrendo um crescimento constante na casa dos brasileiros nos últimos tempos, continuará
crescendo. Isso porque, será criada a bandeira tarifária escassez hídrica e causará o aumento
de em torno de 7% no valor da conta na casa de cada brasileiro.

  Pensando nesse problema econômico enfrentado pela grande maioria dos brasileiros
e nos prejuízos financeiros causados principalmente por este terrível período que
vivenciamos e ainda nos encontramos, que é a pandemia de COVID-19, o projeto
desenvolvido visa auxiliar no controle do gasto de energia elétrica em residências por meio
de uma automação capaz de ligar e desligar lâmpadas do ambiente a qualquer momento, tanto
via Wi-Fi quanto pelo bater de palmas.

  O equipamento utilizado será um Node MCU que junto ao seu chip ESP-8266 nos
permite enviar e receber informações via o protocolo MQTT. Para o acionamento da lâmpada
iremos usar um modulo relé para atuar como um interruptor de energia. Ademais iremos
utilizar um sensor sonoro para possibilitar que a luz seja controlada com palmas.

  Os componentes trabalharão juntos para tornarem possível acionar sua
funcionalidade tanto por meio de um dispositivo móvel quanto por meio do som, sendo um
bater de palmas. Dessa maneira, o usuário consegue ter um controle mais assertivo e
dinâmico de certificar-se que nenhuma lâmpada fora esquecida acesa em casa e caso tenha,
ainda que este não esteja presente no local para realizar o desligamento pelo som, é possível
realizar tal ação utilizando seu próprio aparelho celular.

Montagem final do projeto:
![](https://cdn.discordapp.com/attachments/860944415237734430/911462432864608287/3848c712-7c4e-4ad1-ac81-915724fe53ff.jpg)


Modelo digital do projeto:
![](https://cdn.discordapp.com/attachments/860944415237734430/911462433128841256/Untitled_Sketch_bb.png)


Modelo esquemático do projeto:
![](https://cdn.discordapp.com/attachments/860944415237734430/911462433363738634/Untitled_Sketch_Esquematico.png)


## Materiais e Métodos
* 1x Módulo WiFi ESP8266 NodeMcu - Placa que possui o chip de wi-fi integrado e possibilita a integração com o protocolo MQTT para o projeto.
* 1x Protoboard de 400 pontos - Ferramenta que permite o acoplamento de todos os componentes para a montagem do projeto final.
* 1x Modulo Relé 5V - Modulo este nos permitirá controlar o estado da lâmpada.
* 1x Módulo sensor de som - Sensor que no possibilitará identifcar discrepâncias de som para ligar oudesligar a lâmpada.
* 1x Lâmpada de LED - Lâmpada de tecnologia LED (Light Emitting Diode).

----

[Link para demonstração do projeto](https://www.youtube.com/watch?v=78MzOEfjNdY)
