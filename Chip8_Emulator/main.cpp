#include <d2d1.h>
#include "chip8.h";

Chip8 myChip8;

int main()
{
	setupGraphics();
	setupInput();

	//initialize the Chip8 system and load the game into the memory
	myChip8.initialize();
	myChip8.loadGame("pong");

	for (;;)
	{
		//emulate one cycle
		myChip8.emulateCycle();
		
		//if the draw flag is set, update the screen
		if (myChip8.drawFlag)
			drawGraphics();

		//store key press states
		myChip8.setKeys();
	}

	return 0;
}