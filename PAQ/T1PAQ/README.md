# Analisador de frequência de bytes

Objetivo: analisar a frequencia com que os valores inteiros (bytes consecutivos) aparecem em arquivos de diversos formatos.  
Foram escolhidos arquivos com os formatos BMP, JPEG, (podendo ser o BMP anterior convertido), DOC (ou outro arquivo Office), 
AVI, MP3, HTML, cada um devendo ser compactado (ZIP ou RAR).  

O programa abre esses arquivos (original e compactado) e lê 2 a 2 os bytes dos arquivos (short int - 16 bits) e conta 
sempre que um determinado short int é encontrado.  
Em um arquivo texto é armazenado o resultado contendo o valor dos contadores para todos os numeros de 16 bits (0 - 65535) e 
com esse arquivo, é feito um gráfico de colunas mostrando a quantidade de cada numero de 16 bits (através do arquivo .py).  
São gerados graficos para cada arquivo, original e compactado.
