#ifndef CPU_H
#define CPU_H

#include <stdio.h>
#include <stdlib.h>

#define RAM_SIZE 1000
#define true 1
#define false 0

#define AX 0
#define BX 1
#define CX 2
#define DX 3
#define PC 4

#define NUM_OF_REGS 5

#define fetch() program[mem->reg[PC]]
#define inc() mem->reg[PC]++;
#define dec() mem->reg[PC]--;

typedef struct memory {
    // registers
    int reg[NUM_OF_REGS];

    // RAM
    int ram[RAM_SIZE];
} memory;

void memoryInit(memory* mem, int log) {
    
    if (log) {
        printf("Initializing VM's memory...\n");
    }

    for (int i = 0; i < NUM_OF_REGS; i++) {
        mem->reg[i] = 0;
    }

    for (int i = 0; i < RAM_SIZE; i++) {
        mem->ram[i] = 0;
    }
}

void run(int* program, memory* mem) {
    int running = true;

    int reg, reg1, reg2; // temporary stocking purpose

    while (running) {
        switch (fetch()) {
            case 0: // halt
                running = false;
                break;



            case 1: // mov
                inc();
                int reg_name = fetch();
                inc();
                mem->reg[reg_name] = fetch();
                break;
            case 2: // movr
                inc(); reg1 = fetch();
                inc(); reg2 = fetch();
                mem->reg[reg1] = mem->reg[reg2];
                break;



            case 3: // addr
                inc (); reg1 = fetch();
                inc(); reg2 = fetch();
                mem->reg[reg1] = mem->reg[reg1] + mem->reg[reg2];
                break;
            case 4: // addi
                inc(); reg = fetch();
                inc();
                mem->reg[reg] = mem->reg[reg] + fetch();
                break;


            case 5: // subr
                inc (); reg1 = fetch();
                inc(); reg2 = fetch();
                mem->reg[reg1] = mem->reg[reg1] - mem->reg[reg2];
                break;
            case 6: // subi
                inc(); reg = fetch();
                inc();
                mem->reg[reg] = mem->reg[reg] - fetch();
                break;


            case 7: // mulr
                inc (); reg1 = fetch();
                inc(); reg2 = fetch();
                mem->reg[reg1] = mem->reg[reg1] * mem->reg[reg2];
                break;
            case 8: // muli
                inc(); reg = fetch();
                inc();
                mem->reg[reg] = mem->reg[reg] * fetch();
                break;
            

            case 9: // divr
                inc (); reg1 = fetch();
                inc(); reg2 = fetch();
                mem->reg[reg1] = mem->reg[reg1] / mem->reg[reg2];
                break;
            case 10: // divi
                inc(); reg = fetch();
                inc();
                mem->reg[reg] = mem->reg[reg] / fetch();
                break;
            

            case 11: // printi
                inc();
                printf("%d", fetch());
                break;
            case 12: //printc
                inc();
                printf("%c", fetch());
                break;



                
            default:
                printf("Fatal error, invalid instruction code : %d\n", fetch());
                break;
        }
    }
}


#endif 