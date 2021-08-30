# Arvore_Binaria_AVL
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f7/Binary_tree.svg/200px-Binary_tree.svg.png">

## Arvore Binária
* Uma árvore binária é uma estrutura de dados caracterizada por:

* Ou não tem elemento algum (árvore vazia).
Ou tem um elemento distinto, denominado raiz, com dois ponteiros para duas estruturas diferentes, denominadas subárvore esquerda e subárvore direita.
* Perceba que a definição é recursiva e, devido a isso, muitas operações sobre árvores binárias utilizam recursão. É o tipo de árvore mais utilizado na computação. A principal utilização de árvores binárias são as árvores binárias de busca
## Arvore AVL

<img src="https://panda.ime.usp.br/pythonds/static/pythonds_pt/_images/rightrotate1.png">

* Árvore AVL é uma árvore binária de busca balanceada[2], ou seja, uma árvore balanceada (árvore completa) são as árvores que minimizam o número de comparações efetuadas no pior caso para uma busca com chaves de probabilidades de ocorrências idênticas. Contudo, para garantir essa propriedade em aplicações dinâmicas, é preciso reconstruir a árvore para seu estado ideal a cada operação sobre seus nós (inclusão ou exclusão), para ser alcançado um custo de algoritmo com o tempo de pesquisa tendendo a {\displaystyle O(\log n)}{\displaystyle O(\log n)}.

* As operações de busca, inserção e remoção de elementos possuem complexidade {\displaystyle O(\log n)}{\displaystyle O(\log n)}(no qual {\displaystyle n}n é o número de elementos da árvore), que são aplicados a árvore de busca binária.

* O nome AVL vem de seus criadores soviéticos Adelson Velsky e Landis, e sua primeira referência encontra-se no documento "Algoritmos para organização da informação" de 1962 [3].

* Nessa estrutura de dados cada elemento é chamado de nó. Cada nó armazena uma chave e dois ponteiros, uma para a subárvore esquerda e outro para a subárvore direita.

* No presente artigo serão apresentados: os conceitos básicos, incluindo uma proposta de estrutura; apresentação das operações busca, inserção e remoção, todas com complexidade {\displaystyle O(\log n)}{\displaystyle O(\log n)}.
