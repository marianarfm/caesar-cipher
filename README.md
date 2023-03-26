# Overview
Named after Roman general Julius Caesar, who used it for protecting correspondence regarding military matters, this encryption technique is one of the most known in the world. It is also one of the simplest, meaning this cipher can be broken by brute force alone or by documenting the frequency distribution of the letters. The encryption works by replacing every letter of the unaltered text for another some number of positions down the alphabet.

This code was developed as a casual exercise in learning basic file manipulation in the C language.
# Usage
Open your operational system's command-line shell and navigate to the directory containing the project files, then type `gcc caesar.c -o caesar` to compile the source code. To run it, enter the following:

`./caesar [ACTION] [KEY] [TARGET] [OUTPUT]`

- For the `[ACTION]` argument, type `e` for encrypting or `d` for decrypting
- For the `[KEY]` argument, type an integer from 1 to 25
- For the `[TARGET]` argument, type the filename containg the message you want to encrypt or decrypt
- For the `[OUTPUT]` argument, type the filename for the new file that will be created containing your encrypted or decrypted message

Example command:

`./caesar d 3 test.txt output.txt`

(All generated files will be in the same directory as the source code.)
