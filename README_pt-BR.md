# Uso
Abra o shell de linha de comando do seu sistema operacional e navegue até o diretório que contém os arquivos do projeto e digite `gcc caesar.c -o caesar` para compilar o código-fonte. Para executá-lo, execute o seguinte:

    ./caesar [TASK] [KEY] [MESSAGE] [OUTPUT]

- Para o argumento `[TASK]`, digite `e` para criptografar ou `d` para descriptografar
- Para o argumento `[KEY]`, digite um inteiro de 1 a 25
- Para o argumento `[MESSAGE]`, digite o nome do arquivo que contém o texto que você deseja criptografar ou descriptografar
- Para o argumento `[OUTPUT]`, digite o nome do arquivo para o novo arquivo que será criado contendo sua mensagem criptografada ou descriptografada

Comando de exemplo:

    ./caesar d 3 test.txt output.txt