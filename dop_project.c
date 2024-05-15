#include <stdio.h>
#include <stdlib.h>

void hex_to_binary(char hex[], char binary[], int bits) {
    long int num = strtol(hex, NULL, 16);
    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = (num % 2) + '0';
        num /= 2;
    }
    binary[bits] = '\0';
}

int hex_to_decimal(char hex[]) {
    return (int) strtol(hex, NULL, 16);
}

int twos_complement_to_decimal(char binary[], int bits) {
    if (binary[0] == '1') {
        int complement = (1 << bits) - strtol(binary, NULL, 2);
        return -complement;
    } else {
        return strtol(binary, NULL, 2);
    }
}

void convert_hex(char hex[]) {
    int bits = 16;
    char binary[bits + 1];
    hex_to_binary(hex, binary, bits);

    int decimal_unsigned = hex_to_decimal(hex);
    int decimal_twos_complement = twos_complement_to_decimal(binary, bits);

    printf("Hexadecimal: %s\n", hex);
    printf("Binary (16 bits): %s\n", binary);
    printf("Decimal (unsigned): %d\n", decimal_unsigned);
    printf("Decimal (two's complement): %d\n", decimal_twos_complement);
}

int main() {
    char hex_number[5];
    char continue_flag = 'Y';

    do {
        printf("Enter a 4-digit hexadecimal number: ");
        scanf("%4s", hex_number);
        convert_hex(hex_number);

        printf("Do you want to convert another number? (Y/N): ");
        scanf(" %c", &continue_flag); // Пробел перед %c для корректного чтения символа
    } while (continue_flag == 'Y' || continue_flag == 'y');

    return 0;
}
