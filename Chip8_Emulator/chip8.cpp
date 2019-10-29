#include "chip8.h"
#include <d2d1.h>

void Chip8::emulateCycle()
{
	//fetch opcode
	//shift [pc] left 8 bits, bitwise or with [pc+1] to merge them
	opcode = memory[pc] << 8 | memory[pc + 1];

	//decode opcode
	decode(opcode);

	//execute opcode
	//bitwise and a particular opcode
	I = opcode & 0x0FFF;
	pc += 2;
}

void Chip8::initialize()
{
	pc = 0x200;
	opcode = 0;
	I = 0;
	sp = 0;

	//loading fontset
	for (int i = 0; i < 80; ++i)
	{
		memory[i] = chip8_fontset[i];

		//reset timers
	}
}

void Chip8::loadGame(string game)
{
	for (int i = 0; i < bufferSize; i++)
	{
		memory[i + 512] = buffer[i];
	}
}

void Chip8::setKeys()
{

}

void decode(unsigned short op)
{
	
}