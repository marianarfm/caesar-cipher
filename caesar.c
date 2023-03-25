#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encryptToFile(FILE *f, char* str, int key);
int decryptToFile(FILE *f, char* str, int key);

int main(int argc, char* argv[]) {
  int key = atoi(argv[2]);
  FILE *finput, *foutput;
  char *str;
  size_t fsize, readret;

  // User input check
  if (argc != 5) {
    printf("Invalid number of arguments\n");
    return 1;
  }
  if (strcmp(argv[1], "e") != 0 && strcmp(argv[1], "d") != 0) {
    printf("Invalid second argument\n");
    return 1;
  }
  if (key < 1 || key > 25) {
    printf("Invalid input key\n");
    return 1;
  }

  // Open file to be encrypted or decrypted
  finput = fopen(argv[3], "r");
  if (finput == NULL) {
    printf("Error opening file %s for reading\n", argv[3]);
    return 1;
  }
  
  // Read all file contents to the buffer
  fsize = 0;
  while (fgetc(finput) != EOF) {
    fsize++;
  }
  str = (char*)malloc(sizeof(char) * fsize + 1);
  if (str == NULL) {
    printf("Error allocating memory\n");
    return 1;
  }
  rewind(finput);
  readret = fread(str, sizeof(char), fsize, finput);
  if (readret != fsize) {
    printf("Error reading contents of file %s into buffer\n", argv[3]);
    return 1;
  }
  fclose(finput);
  str[fsize] = '\0';

  // Open new file for writing encrypted/decrypted message
  foutput = fopen(argv[4], "w");
  if(foutput == NULL) {
    printf("Error creating file %s for writing\n", argv[4]);
    return 1;
  }

  // Call encrypt or decrypt function
  if (strcmp(argv[1], "e") == 0) {
    if (encryptToFile(foutput, str, key) != 0) {
      printf("Error encrypting file %s into %s\n", argv[3], argv[4]);
      return 1;
    }
  } else if (strcmp(argv[1], "d") == 0) {
    if (decryptToFile(foutput, str, key) != 0) {
      printf("Error decrypting file %s into %s\n", argv[3], argv[4]);
      return 1;
    }
  }
  fclose(foutput);
  free(str);
  return 0;
}

int encryptToFile(FILE *f, char* str, int key) {
  while (*str) {
    if (*str >= 'A' && *str <= 'Z') {
      *str = (*str - 'A' + key) % 26 + 'A';
      fputc(*str, f);
    } else if (*str >= 'a' && *str <= 'z') {
      *str = (*str - 'a' + key) % 26 + 'a';
      fputc(*str, f);
    } else fputc(*str, f);
    str++;
  }
  if (ferror(f) != 0) return 1; else return 0;
}

int decryptToFile(FILE *f, char* str, int key) {
  while (*str) {
    if (*str >= 'A' && *str <= 'Z') {
      *str = (*str - 'A' + 26 - key) % 26 + 'A';
      fputc(*str, f);
    } else if (*str >= 'a' && *str <= 'z') {
      *str = (*str - 'a' + 26 - key) % 26 + 'a';
      fputc(*str, f);
    } else fputc(*str, f);
    str++;
  }
  if (ferror(f) != 0) return 1; else return 0;
}