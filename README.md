# 🧵 Soma Paralela de Matrizes usando OpenMP
Este repositório contém um exemplo simples de paralelização em C utilizando OpenMP.
O programa realiza a soma de duas matrizes 4×4 de forma paralela, distribuindo as operações entre múltiplas threads de acordo com o número de núcleos disponíveis na máquina.

📌 Objetivo do Projeto
Demonstrar como usar:
- Diretivas OpenMP (#pragma omp parallel for)
- Divisão de tarefas entre threads
- Detecção automática do número de núcleos do processador
- Execução paralela da soma de matrizes

🧩 Como o código funciona
O programa:
- Cria duas matrizes A e B de tamanho 4x4.
- Preenche as matrizes com valores simples:
  A[i][j] = i + j
  B[i][j] = i * j
- Detecta automaticamente quantos núcleos lógicos existem no computador:
  int num_cores = omp_get_num_procs();
- Define o número de threads igual ao número de núcleos:
  omp_set_num_threads(num_cores);
- Usa paralelização para somar as matrizes:
  #pragma omp parallel for collapse(2)
- Cada thread imprime qual elemento calculou.
- Exibe a matriz resultante.

🛠️ Tecnologias utilizadas
- C;
- OpenMP;
- Ambiente recomendado: MinGW; GCC; Linux; WSL ou qualquer compilador com suporte a OpenMP.

📦 Como compilar
- No Linux / WSL / MinGW (GCC):
  gcc openmpMatriz.c -fopenmp -o matriz

Executar:
./matriz
