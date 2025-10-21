# 🤖 Robô Autônomo de Sumô

Projeto de robô autônomo desenvolvido durante minha participação na **Equipe Phoenix – Unicamp**.  
Esta é uma **versão pessoal** do projeto, mantida para fins de portfólio e aprimoramento técnico.  
Grande parte da base de código já havia sido desenvolvida em projetos anteriores da equipe, voltados a outros robôs autônomos.  
Nesta versão, o código foi adaptado, reorganizado e aprimorado para atender às necessidades específicas do robô treinado por mim para a competição.

---

## ⚙️ Descrição do Projeto

O robô de sumô foi projetado para competir em arenas circulares, detectando adversários e limites por meio de sensores analógicos.  
A lógica embarcada permite que o robô **identifique o oponente, evite sair da arena e otimize sua estratégia de ataque e defesa**.

---

## 🧩 Funcionalidades Principais

- Detecção de oponentes com **sensores infravermelhos**
- Identificação das bordas da arena com sensores de refletância
- Controle de movimentação e velocidade via **PWM**
- Estratégia de ataque autônoma com base em leitura de múltiplos sensores
- Rotinas de calibração e inicialização automática

---

## 🧠 Arquitetura e Componentes

| Componente | Função |
|-------------|--------|
| **Microcontrolador** | ESP32 / Arduino |
| **Sensores IR** | 5 sensores analógicos: 1 central, 2 diagonais, 2 laterais |
| **Motores DC** | Movimentação e rotação controladas via PWM |
| **Drivers de motor** | Ponte H (L298N / L293D) |
| **Bateria LiPo** | Alimentação autônoma do sistema |
| **LEDs de status** | Indicação de modo e leitura de sensores |

---

## 🧰 Tecnologias e Ferramentas

- **C / C++**
- **PlatformIO** 
- **Git & GitHub** para versionamento e colaboração

---

## 🚀 Como Executar

O projeto pode ser compilado e carregado em microcontroladores **ESP32**.  
As instruções abaixo detalham o método de execução:

---

### 🧰 Usando PlatformIO

1. **Instale o PlatformIO**  
   - Via [VS Code](https://platformio.org/install/ide?install=vscode) (extensão PlatformIO IDE)
   - Ou via terminal:  
     ```bash
     pip install platformio
     ```

2. **Clone este repositório:**
   ```bash
   git clone https://github.com/anitainfo/robo-autonomo-sumo.git
   cd robo-autonomo-sumo
