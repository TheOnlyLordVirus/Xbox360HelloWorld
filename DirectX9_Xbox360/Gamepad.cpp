#include "Gamepad.h"


void GamepadUpdate()
{
	// Get the pad state.
	XINPUT_STATE pInputState;
	XInputGetState(0, &pInputState);
	unsigned short pads = pInputState.Gamepad.wButtons;
	
	// If there is at least 1 pad.
	if (pads != 0)
	{
		printf("pad pressed 0x%X\n", pInputState.Gamepad.wButtons);

		// If there is at least 1 pad and the B button is pressed.
		if (pads & BUTTON_B) 
		{
			// Break out of the frame rendering loop.
			m_GameMain->bExitGame = true;
		}
	}
}

