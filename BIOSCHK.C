#include<stdio.h>
#include<mem.h>
#include<stdlib.h>
#include<dos.h>
#include<string.h>
#include<stdarg.h>

/*
Written By: Kevin Moonlight <me@yyzkevin.com>
Date: 2023-04-10
Title: BIOS Copyright String Checker

Program takes one string as an argument that is used in a case-insensitive
search of 128 bytes starting at F000:E000.   If there is a match it exists
with ERRORLEVEL 2,   otherwise it exits with ERRORLEVEL 1.

This is used as a simple way to identify the machine type and load specific
drivers when used in conjunction with a batchfile.
*/


void main(int argc,char *argv[]) {
	char far *bios;
	int i;
	if(!argc) printf("Error: No search string specified\n");
	bios = MK_FP(0xF000,0xE000);
	printf("Checking for %s...",argv[1]);
	for(i=0;i<128;i++) {
		if(_fmemicmp(bios+i,argv[1],strlen(argv[1]))==0) {
			printf("Found.\n");
			exit(2);
		}
	}
	printf("Not Found.\n");
	exit(1);
}
