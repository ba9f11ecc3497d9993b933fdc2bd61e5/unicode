#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// user input
unsigned char user_input[1000];

// various temporary buffers
char tmpbuff_decimal[5];
char tmpbuff_hexadecimal[4];
char tmpbuff_binary[8];

// strings to hold the output
char decimal_output[4000];
char hexadecimal_output[3000];
char binary_output[9000];

// length counters
int bytes;
int extra_byte;
int user_input_length;


const char * to_binary(int dec_input) {
  for (int i=7;i>-1;i--) {
    if (dec_input % 2 != 0) {
      tmpbuff_binary[i] = 49;
    }
    else {
      tmpbuff_binary[i] = 48;
    }
    dec_input = dec_input>>1;
  }
  return tmpbuff_binary;
}


int main() {
  printf("Enter unicode string : ");
  fgets(user_input, 999, stdin);
  user_input[strcspn(user_input, "\n")] = 0;
  for (int i;;i++) {
    if (user_input[i] == 0) {
      break;
    }
    snprintf(tmpbuff_decimal, 5, "%d ", user_input[i]);
    snprintf(tmpbuff_hexadecimal, 4, "%x ", user_input[i]);
    strncat(decimal_output, tmpbuff_decimal, 5);
    strncat(hexadecimal_output, tmpbuff_hexadecimal, 4);
    strncat(binary_output, to_binary(user_input[i]), 8);
    strncat(binary_output, " ", 2);
    if ((user_input[i] >= 0 && user_input[i] <= 127)) {
      //printf("char %c encoded in 1 byte\n", user_input[i]);
      bytes++;
      user_input_length++;
    }
    else if ((user_input[i] >= 192) && (user_input[i] <= 223))  {
      //printf("char %c is encoded in 2 bytes\n", user_input[i]);
      bytes++;
      extra_byte = 1;
      user_input_length++;
      continue;
    }
    else if ((user_input[i] >= 224) && (user_input[i] <= 239))  {
      //printf("char %c is encoded in 3 bytes\n", user_input[i]);
      bytes++;
      extra_byte = 2;
      user_input_length++;
      continue;
    }
    else if ((user_input[i] >= 240) && (user_input[i] <= 247))  {
      //printf("char %c is encoded in 4 bytes\n", user_input[i]);
      bytes++;
      extra_byte = 3;
      user_input_length++;
      continue;
    }
    else if ((user_input[i] >= 128 && user_input[i] <= 191 )) {
      //printf("this %c is a subsequent unicode byte\n", user_input[i]);
      bytes++;
      if (extra_byte > 1) {
        extra_byte--;
      }
      if (extra_byte == 0) {
        user_input_length++;
      }
    }
    //printf("char is %d\n", user_input[i]);
  }
  printf("\n\n");
  printf("string is encoded in %d bytes that represent %d unicode characters.\n\n", bytes, user_input_length);
  printf("unicode\t\t:\t%s\n", user_input);
  printf("decimal\t\t:\t%s\n", decimal_output);
  printf("hexadecimal\t:\t%s\n", hexadecimal_output);
  printf("binary\t\t:\t%s\n", binary_output);
}
