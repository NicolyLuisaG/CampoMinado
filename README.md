# 💣 Campo Minado - STM32

Este projeto é uma implementação do clássico jogo **Campo Minado (Minesweeper)** desenvolvida em **linguagem C**, projetada para rodar diretamente em **microcontroladores STM32**, utilizando apenas **periféricos básicos**.

---

## 📋 Descrição do Projeto

O jogo foi desenvolvido sem o uso de sistema operacional, explorando diretamente os recursos de hardware do STM32. A interação é feita por meio de **botões físicos**, e o estado do jogo é exibido em um **display LCD**.

---

## ✅ Funcionalidades

- 📟 Interface gráfica em LCD
- 🔘 Navegação por botões físicos (direcional e seleção)
- 💣 Geração aleatória de minas
- 🧠 Lógica completa de jogo: marcação de minas, abertura de células, verificação de vitória/derrota
- 🚫 Sem uso de sistema operacional ou bibliotecas externas

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Microcontrolador **STM32**
- **GPIO** (para botões)
- **LCD** (para exibição do jogo)
- **Timers** e interrupções para controle de tempo e entrada

---

## 🎮 Objetivo

Demonstrar como um jogo completo pode ser desenvolvido para sistemas embarcados com **recursos limitados**, utilizando apenas controle direto de hardware.

---

## ⚙️ Possíveis Expansões

- Implementar níveis de dificuldade
- Adicionar contagem de tempo e recordes
- Criar interface com buzzer para efeitos sonoros

---
