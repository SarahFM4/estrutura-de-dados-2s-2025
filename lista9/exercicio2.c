/*
Pilha de execução de programas. Este exercício não só simula o funcionamento da pilha de
execução como também o processamento das diretivas #include e #define do pré-
processador do compilador C. Escreva um programa que receba um arquivo de texto ASCII e
grave outro arquivo de texto ASCII como especificado a seguir. Cada linha do arquivo de
entrada contém palavras separadas por espaços; as palavras que começam
com # são especiais e as outras são normais. O arquivo de saída conterá as palavras normais,
em uma só linha, numa certa ordem. Suponha, por exemplo, que o arquivo de entrada contém
as seguintes linhas:

(Os números no início das linha servem apenas de referência e não fazem parte do arquivo.)
Então o arquivo de saída deverá conter: GG hhh aaa CC GG hhh DDD bbb ee
Como o exemplo sugere, as palavras especiais são substituídas pela linha do arquivo de
entrada cujo número é dado depois de # , e isso deve ser feito recursivamente. Para tornar o
exercício mais interessante, não use funções recursivas.
*/