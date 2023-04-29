/*

This file is a part of Ultrafuck project.

This software is provided "As Is", without any warranties of any kind. You are using this software at your own risk. See LICENSE file for more details.

Copyright (c) Ivan Movchan <NobootRecord@mail.ru>, 2023
https://nobootrecord.github.io

*/

#include "ultrafuck.h"

int main(int argc, char** argv)
{

    // If no arguments passed, show help message

    if (argc < 2)
    {
        printver;
        printf("Usage: uf [filename] <arguments>\n\n[filename]\t\tUltrafuck source code filename\n<arguments>\t\tAdditional arguments\n--> (no arguments)\tShow help message (you are reading now)\n--> -q / --quiet\tQuiet mode (no messages, program output only)\n\n");
        printf("Copyright (c) Ivan Movchan, 2023 / https://nobootrecord.github.io / NobootRecord@mail.ru\nThis is open source software is licensed under the terms of MIT License. See LICENSE file for more details...\n");
        return 0;
    };

    // -q / --quiet activates quiet mode

    bool quietMode = false;
    if (argc > 2) quietMode = (strequ(argv[2], "-q") || strequ(argv[2], "--quiet"));

    // Print program version

    if (!quietMode) printver;

    // Open file and read all its contents

    char* fn = argv[1];
    FILE* f = fopen(fn, "r");
    if (f == NULL)
    {
        if (!quietMode) printf("Failed to open '%s' file...\n", fn);
        return 1;
    };

    fseek(f, 0, SEEK_END); long flen = ftell(f); fseek(f, 0, SEEK_SET);
    char ufCode[flen]; for (int i = 0; i < flen; i++) ufCode[i] = fgetc(f);
    fclose(f);

    if (!quietMode) printf("0x%.8X bytes read\n", (int)flen);

    // Execute Ultrafuck code and calculate execution time

    double execStartTime = time(0);
    ufExec(ufCode);
    double execEndTime = time(0);
    double execTime = execEndTime - execStartTime;
    if (!quietMode) printf("\nExecution finished in %.2f seconds", execTime);
    
    printf("\n"); return 0; // Exit

}