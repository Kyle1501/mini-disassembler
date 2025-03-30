/*
Mini-disassembler
created by Kyle Anderson - 29/03/2025
*/

#include <stdio.h>
#include <stdbool.h>

struct opcodes{ // struct to define opcode entry
    unsigned char opcode_bytes[5];
    int length;
    char * mnemonic;
}; 

struct opcodes raw_table[] = { // lookup table for x86 instructions
    { {0x55}, 1, "push ebp"},
    { {0x50}, 1, "push eax"},
    { {0x89, 0xE5}, 2, "mov ebp, esp"},
    { {0xC3}, 1, "ret" }
};
    
int read_file(){
    FILE *ftpr;
    
    ftpr = fopen("test.bin", "rb");

    unsigned char myBytes[116]; // define array to hold raw numbers

    fseek(ftpr, 220, SEEK_SET); // jumps to the .text section which is 220 bytes in

    fread(myBytes, 1, 116, ftpr); // reads 166 bytes simulating .text section

    int i = 0;
    int instruct_count = sizeof(raw_table) / sizeof(raw_table[0]);
    while (i < 116){ // loop to compare raw numbers to known opcodes
        bool match = false;
        for(int j = 0; j < instruct_count; j++){
            if (myBytes[i] == raw_table[j].opcode_bytes[0]){ 
                if(raw_table[j].length >= 2){ 
                    for (int k = 0; k < raw_table[j].length; k++){
                        if(myBytes[i + k] == raw_table[j].opcode_bytes[k]){
                            printf("%s\n", raw_table[j].mnemonic);
                            i += raw_table[j].length;
                            match = true;
                            break;
                        }
                    }
                } else if (myBytes[i] == raw_table[j].opcode_bytes[0]){
                    if(raw_table[j].length < 2){
                        printf("%s\n", raw_table[j].mnemonic);
                        i++;
                        match = true;
                        break;
                    }                        
                }
            }
        }
        if (match == false){
            printf("unknown opcode %#02x\n", myBytes[i]);
            i++;
        }

    }


    fclose(ftpr);

    return 0;
}

int main(){
    read_file();
    return 0;
}