/*

This file is a part of Ultrafuck project.

This software is provided "As Is", without any warranties of any kind. You are using this software at your own risk. See LICENSE file for more details.

Copyright (c) Ivan Movchan <NobootRecord@mail.ru>, 2023
https://nobootrecord.github.io

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define UF_VERSION 1.0
#define BF_MAXMEM 
#define BF_MAXCMD 8

#define strequ !strcmp

#define printver printf("Ultrafuck %.1f (built on %s %s with gcc version %s)\n", UF_VERSION, __DATE__, __TIME__, __VERSION__)

int memIndex = 0, cmdIndex = 0, loopA = 0, loopB = 0;
char memory[BF_MAXMEM] = {};
bool loopMode = false, commentMode = false;

//
// This function executes Ultrafuck code. No more :)
//

void ufExec(char* code)
{
    for (int i = 0; i < strlen(code); i++)
    {
        if (code[i] == '*') { commentMode = !commentMode; }
        if (commentMode) continue;

		if (code[i] == '~') cmdIndex = 0;
        if (code[i] == '<') { if (cmdIndex > 0) cmdIndex--; else cmdIndex = BF_MAXCMD - 1; }
        if (code[i] == '>') { if (cmdIndex < BF_MAXCMD - 1) cmdIndex++; else cmdIndex = 0; } 
        if (code[i] == '!') {
            if (!loopMode)
            {
                switch (cmdIndex)
                {
                    case 1: memIndex++; break; // >
                    case 2: memIndex--; break; // <
                    case 3: memory[memIndex]++; break; // +
                    case 4: memory[memIndex]--; break; // -
                    case 5: putchar(memory[memIndex]); break; // .
                    case 6: memIndex = getchar(); break; // ,
                };
            }
            if (cmdIndex == 7)
            {
                if (memory[memIndex] == 0)
                {
                    loopA = i; loopMode = true;
                } else {
                    loopMode = false;
                };
            };
            if (cmdIndex == 8)
            {
                if (memory[memIndex] != 0)
                {
                    loopB = i; loopMode = true;
                } else {
                    loopMode = false;
                };
            };
        };       
    };
}
