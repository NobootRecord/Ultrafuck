all:
		gcc -o uf -m32 ultrafuck.c
		gcc -o uf64 -m64 ultrafuck.c
		i686-w64-mingw32-gcc -o uf.exe ultrafuck.c
		x86_64-w64-mingw32-gcc -o uf64.exe ultrafuck.c

unix:
		gcc -o uf -m32 ultrafuck.c
		gcc -o uf64 -m64 ultrafuck.c
	
win:
		i686-w64-mingw32-gcc -o uf.exe ultrafuck.c
		x86_64-w64-mingw32-gcc -o uf64.exe ultrafuck.c

32:
		gcc -o uf -m32 ultrafuck.c
		i686-w64-mingw32-gcc -o uf.exe ultrafuck.c

64:
		gcc -o uf64 -m64 ultrafuck.c
		x86_64-w64-mingw32-gcc -o uf64.exe ultrafuck.c