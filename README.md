# 🎮 Projeto Acionamento de LEDs com Temporizadores e Botão

Este projeto aciona uma sequência de LEDs (verde, vermelho e azul) ao pressionar um botão na Raspberry Pi Pico. Os LEDs são desligados gradualmente com a operação programada de temporizadores. 

---

## 🔧 Hardware
### Componentes necessários:
- Placa **Raspberry Pi Pico**
- 3 LEDs: **verde**, **vermelho** e **azul**
- 3 resistores de 220Ω
- 1 botão


### 📍 Pinagem
- LED **Verde**: GPIO12 
- LED **Vermelho**: GPIO13
- LED **Azul**: GPIO11 
- Botão: GPIO5 

---

## 💻 Software Necessário
- **IDE**: Visual Studio Code (com extensão CMake e ambiente configurado para Raspberry Pi Pico)
- **SDK**: Raspberry Pi Pico C/C++ SDK ([Documentação Oficial](https://github.com/raspberrypi/pico-sdk))
- **Compilador**: GCC e CMake
- **Simulador**: Wokwi (opcional, útil para simulações online)

---

## 📁 Estrutura do Projeto

```plaintext
.
├── .vscode/                # Configurações do workspace no VSCode
├── build/                  # Build gerado pelo CMake
├── CMakeLists.txt          # Configurações do projeto com CMake
├── Temporizador_Disparo.c  # Código principal do projeto
├── pico_sdk_import.cmake   # Inclusão do SDK do Raspberry Pi Pico
├── wokwi.toml              # Configuração para simulação no Wokwi (opcional)
├── diagram.json            # Arquivo de configuração do simulador Wokwi
└── README.md               # Documentação do projeto
```

---

## 🚀 Compilação e Execução do Código

### Configuração do Ambiente
1. Instale o SDK do **Raspberry Pi Pico** seguindo o guia oficial.
2. Configure a extensão CMake do Visual Studio Code.
3. Certifique-se de que o Pico está conectado via USB.

### Comandos para Compilar:
Execute os comandos abaixo no terminal:
```bash
mkdir build
cd build
cmake ..
make
```

### Upload para o Raspberry Pi Pico:
1. Após a compilação, será gerado um arquivo `.uf2` no diretório `build`.
2. Coloque o Pico no modo de bootloader (segure o botão BOOTSEL ao conectar via USB).
3. Copie o arquivo `.uf2` para o dispositivo detectado como drive USB.

---

## 🚀 Funcionamento do Projeto

Ao pressionar o botão:
1. Os LEDs **verde**, **vermelho** e **azul** são ligados simultaneamente.
2. Após 3 segundos:
   - O LED **azul** será desligado.
3. Após mais 3 segundos:
   - O LED **vermelho** será desligado.
4. Após mais 3 segundos:
   - O LED **verde** será desligado, finalizando a sequência.
   
A interrupção é utilizada para acionar o evento de ligar os LEDs e iniciar a sequência de temporizadores. Caso o botão seja pressionado novamente antes de a sequência terminar, ela não será reiniciada até que todos os LEDs sejam desligados.

---


## 🗺️ Esquemático

![image](https://github.com/user-attachments/assets/8c8b7098-08cf-4f7f-b6cd-485401b5fc96)

## 🔗 **Link do Vídeo de Funcionamento**: 

https://drive.google.com/file/d/1z7KSB5yTfnw8luRekICxHLJt66-nt8jP/view?usp=sharing

📞 **Contato**:

👤 Autor: Jonas Souza Pinto

📧 E-mail: Jonassouza871@hotmail.com

