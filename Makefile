all:
		gcc -o uf.exe -O2 -Wl,-s -static ultrafuck.c
