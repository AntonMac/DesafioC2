# DesafioC2
Resolução do Desafio 4 de C
DESAFIO 4: The Walking Dead é uma febre mundial. Esta série de zumbis despertou o seu interesse para o desenvolvimento de um jogo de sobrevivência. Neste jogo, existem zumbis, obstáculos (pedras, árvores, carros parados,...) e Rick, o personagem principal. O objetivo de Rick é encontrar a única saída existente em meio a uma horda de zumbis e obstáculos espalhados no cenário.
Nesta questão, você deve desenvolver 1 estágio deste jogo, respeitando as seguintes instruções:
1-O Cenário possui 100 metros quadrados.
2-Rick acorda atordoado em algum lugar aleatório no cenário, com uma arma sem balas.
3-Existem 15 zumbis espalhados aleatoriamente pelo cenário.
4-Os obstáculos estão em toda parte. São ao todo 4 carros, 7 árvores e 8 pedras distribuídas aleatoriamente.
5-No cenário existe uma única saída, também definida aleatoriamente. Se ela estiver bloqueada por obstáculos, Rick não tem saída e morrerá. Caso contrário, se Rick alcançar a saída, o jogo é encerrado.
6-Rick possui 4 movimentações possíveis: cima, baixo, esquerda e direita. Embora a vida de Rick esteja complicada, existem 4 balas espalhadas no cenário. Se Rick se movimentar e tiver uma bala naquela posição, Rick carregará a arma imediatamente. 
7-Se Rick tentar se mover para uma região em que há um obstáculo, ele permanece onde está e não se movimenta. Caso ele se movimente para uma região em que há um zumbi, existem duas possibilidades: se Rick estiver com a arma descarregada, ele é atacado e morre; caso contrário, Rick usa a bala no zumbi. 
8-Obstáculos são estáticos, não se movimentam.
9-Zumbis possuem 4 movimentações possíveis: cima, baixo, esquerda e direita. Os zumbis que estão a 3 metros quadrados de Rick passam a persegui-lo. Os que estão mais distantes, ficam parados.
10-Toda vez que Rick realizar um movimento no cenário, a posição dos zumbis próximos deve ser atualizada.
Implemente o jogo e informe a situação de Rick: morreu ou fugiu.












