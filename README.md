# Usage
Open your operational system's command-line shell and navigate to the directory containing the project files, then type `gcc caesar.c -o caesar` to compile the source code. To run it, enter the following:

    ./caesar [TASK] [KEY] [MESSAGE] [OUTPUT]

- For the `[TASK]` argument, type `e` for encrypting or `d` for decrypting
- For the `[KEY]` argument, type an integer from 1 to 25
- For the `[MESSAGE]` argument, type the filename containing the text you want to encrypt or decrypt
- For the `[OUTPUT]` argument, type the filename for the new file that will be created containing your encrypted or decrypted message

Example command:

    ./caesar d 3 test.txt output.txt
    
(All generated files will be in the same directory as the source code.)
