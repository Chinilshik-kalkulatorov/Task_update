#include <stdio.h>
#include <stdlib.h>

void hex_to_binary(char *hex, char *binary, int bits) {
    long int num = strtol(hex, NULL, 16);
    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = (num % 2) + '0';
        num /= 2;
    }
    binary[bits] = '\0';
}

int hex_to_decimal(char *hex) {
    return (int) strtol(hex, NULL, 16);
}

int twos_complement_to_decimal(char *binary, int bits) {
    if (binary[0] == '1') {  // Check if the first (most significant) bit is 1 -> negative number
        int complement = (1 << bits) - strtol(binary, NULL, 2);
        return -complement;
    } else {
        return strtol(binary, NULL, 2);
    }
}

void convert_hex(char *hex) {
    int bits = 16;
    char *binary = calloc(bits + 1, sizeof(char)); // Allocate memory for binary representation +1 for '\0'
    if (!binary) {
        printf("Memory allocation failed\n");
        return;
    }

    hex_to_binary(hex, binary, bits);
    int decimal_unsigned = hex_to_decimal(hex);
    int decimal_twos_complement = twos_complement_to_decimal(binary, bits);

    printf("Hexadecimal: %s\n", hex);
    printf("Binary (16 bits): %s\n", binary);
    printf("Decimal (unsigned): %d\n", decimal_unsigned);
    printf("Decimal (two's complement): %d\n", decimal_twos_complement);

    free(binary); // Free the allocated memory
}

int main() {
    char hex_number[5];  // Array to store hexadecimal input
    printf("Enter a 4-digit hexadecimal number: ");
    scanf("%4s", hex_number);

    convert_hex(hex_number);
    return 0;
}
