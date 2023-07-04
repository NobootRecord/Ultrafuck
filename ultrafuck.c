/*

Ааааааа... эмммм... ыыыыы... нууууууу... короче, идите в жопу)))0))

*/

#include "ultrafuck.h"

int main(int argc, char** argv)
{
    if (argc < 2)
    {
        printf("Usage: uf [filename] [-c outfilename | -v] [-q]");
        return 0;
    };

    // -q activates quiet mode

    bool quietMode = false;
    for (int i = 0; i < argc; i++)
    {
    	if (strequ(argv[i], "-q"))
    	{
    		quietMode = true; break;
    	};
    };

    // -v shows Ultrafuck version

    if (strequ(argv[1], "-v"))
    {
        printf("Ultrafuck %.1f (%s %s) [gcc %s]\n\n", UF_VERSION, __DATE__, __TIME__, __VERSION__);
        printf("Original idea by Urban Muller, 1993\n");
        printf("Ultrafuck dialect by Ivan Movchan, 2023\nLicense: The Unlicense\n\n");
		printf("Copyright (c) Ivan Movchan, 2023\nhttps://nobootrecord.github.io\nNobootRecord@outlook.com\n");
		return 0;
    };

    // Open file and read all its contents

    char* fn = argv[1];
    FILE* f = fopen(fn, "r");
    if (f == NULL)
    {
        if (!quietMode) printf("Failed to open '%s' file...\n", fn);
        return 1;
    };

    fseek(f, 0, SEEK_END); long flen = ftell(f); fseek(f, 0, SEEK_SET);
    char code[flen]; for (int i = 0; i < flen; i++) code[i] = fgetc(f);
    fclose(f);

    if (!quietMode) printf("%d bytes read\n", (int)flen);

	// -c = convert Brainfuck into Ultrafuck code

	if (argc > 3) {
		if (strequ(argv[2], "-c"))
		{
			// printf("Sample Text\n"); return 0;
					
			char* fn2 = argv[3];
			FILE* f2 = fopen(fn2, "w+");
    		if (f2 == NULL)
		    {
		        if (!quietMode) printf("Failed to open '%s' file...\n", fn2);
		        return 1;
		    };

		    char uf_code[flen*UF_FLEN_MULTIPLY]; for (int i = 0; i < flen*UF_FLEN_MULTIPLY; i++) uf_code[i] = 0x00;
		    
		    	for (unsigned int i = 0; i < strlen(code); i++)
		    	{	
		    		switch (code[i])
		    		{
		    			case '>': strcat(uf_code, ">!<"); break;
		    			case '<': strcat(uf_code, ">>!<<"); break;
		    			case '+': strcat(uf_code, ">>>!<<<"); break;
		    			case '-': strcat(uf_code, ">>>>!<<<<"); break;
		    			case '.': strcat(uf_code, ">>>>>!<<<<<"); break;
		    			case ',': strcat(uf_code, ">>>>>>!<<<<<<"); break;
		    			case '[': strcat(uf_code, "["); break;
		    			case ']': strcat(uf_code, "]"); break;
		    		};
		    	};

				uf_code[strlen(code)] = EOF;		    	

			int uf_code_len = strlen(uf_code);
		    for (int i = 0; i < uf_code_len; i++)
		    	if (uf_code[i] != EOF)
		    		fputc(uf_code[i], f2);
		        else
		        	break;
		        	
		    fclose(f2);
			
			if (!quietMode) printf("%d bytes written\n", uf_code_len);
			return 0;
		};
	};

    // Execute Ultrafuck code and calculate execution time

    double execStartTime = time(0);
    uf_exec(code);
    double execEndTime = time(0);
    double execTime = execEndTime - execStartTime;
    if (!quietMode) printf("\nExecution finished in %.2f seconds", execTime);
    
    printf("\n"); return 0; // Exit

}
