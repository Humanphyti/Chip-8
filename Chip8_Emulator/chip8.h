#pragma once
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stdint.h>
using std::string;

class Chip8 {
private:
	//2 byte long storage of chip-8 opcodes
	unsigned short opcode;

	//4K of RAM
	unsigned char memory[4096];

	//array of registers
	unsigned char V[16];

	//index registers and program counters
	unsigned short I;
	unsigned short pc;

	//register interpreter used for clock registers
	unsigned char delay_timer;
	unsigned char sound_timer;

	//stack to store locations before jump or subroutine calls
	//stack pointer to point to the actual location
	unsigned short stack[16];
	unsigned short sp;

	//buffer variables


public:
	//hex-based keypad array to store current state of the key
	unsigned char key[16];

	//graphics system used for collision detection
	//indices will be either a 1 or a 0 to indicate pixel on or off
	unsigned char gfx[64 * 32];

	void emulateCycle();
	void initialize();
	void loadGame(string game);
	void setKeys();
};