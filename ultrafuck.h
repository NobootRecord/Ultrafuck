/*

ЪЕЪ

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define UF_VERSION 1.2
#define UF_FLEN_MULTIPLY 30 // idk waht da hel it doez lul
#define BF_MAXMEM 
#define BF_MAXCMD 9

#define strequ !strcmp

int memIndex = 0, cmdIndex = 0, loopA = 0, loopB = 0, iloopA = 0, iloopB = 0;
char memory[BF_MAXMEM] = {};
bool loopMode = false, iloopMode = false, commentMode = false;

//
// This function executes Ultrafuck code. No more :)
//

void uf_exec(char* code)
{
    for (unsigned int i = 0; i < strlen(code); i++)
    {
        if (code[i] == '*') { commentMode = !commentMode; }
        if (commentMode) continue;

		if (code[i] == '~') cmdIndex = 0;
        if (code[i] == '<') { if (cmdIndex > 0) cmdIndex--; else cmdIndex = BF_MAXCMD - 1; }
        if (code[i] == '>') { if (cmdIndex < BF_MAXCMD - 1) cmdIndex++; else cmdIndex = 0; }
		if (code[i] == '[') {
			if (memory[memIndex] == 0)
            {
                loopA = i; loopMode = true;
            } else {
                loopMode = false;
            };
		}
		if (code[i] == ']') {
			if (memory[memIndex] != 0)
			{
				loopB = i; loopMode = true;
			} else {
				loopMode = false;
			};
		};

	if (code[i] == '{') { iloopA = i; iloopMode = true; };
	if (code[i] == '}') { iloopB = i; iloopMode = true; i=iloopA; };
	
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
		    		case 7: memory[memIndex]=rand(); break;
		    		case 8: printf("%d",memory[memIndex]); break;
		    		case 9: return;
                };
            }
        };       
    };
}
