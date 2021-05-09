#include "Main.h"

// DirectX93D Variables. 
IDirect3D9 * g_pD3D;
IDirect3DDevice9 * g_pDevice;
D3DPRESENT_PARAMETERS d3dpp;


/*
	This was written Mostly by my buddy David, I did refractor this code a bit from my own use's.
	This can be turned in to a menu that will select functions of your own desires, Or really anything if you know what your doing in DirectX9...
*/

// Entry Point.
int main()
{
	m_GameMain = new GameMain();
	if (m_GameMain != 0) 
	{
		// The main DirectX9 Device object.
		g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);

		// Well fuck.
		if (g_pD3D == NULL)
		{
			printf("something went wrong while creating the device: 0x%X\n", GetLastError());
		}
		
		// Clear the memory for the DirectX API.
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		// Xbox 360 video output setting NEEDED!
		XVIDEO_MODE VideoMode;
		XGetVideoMode(&VideoMode);
		d3dpp.BackBufferWidth = min(VideoMode.dwDisplayWidth, 1280);
		d3dpp.BackBufferHeight = min(VideoMode.dwDisplayHeight, 720);
		d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
		d3dpp.BackBufferCount = 1;
		d3dpp.EnableAutoDepthStencil = TRUE;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

		// Create the DirectX 9 Device.
		g_pD3D->CreateDevice(0, D3DDEVTYPE_HAL, NULL, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pDevice);

		// Run this over, and over and over again as fast as the CPU/GPU Allow.
		while (true)
		{
			// Call the render function for our 'Game'
			m_GameMain->Render();

			if (m_GameMain->bExitGame)
			{
				// Remove this from memory to prevent memory leaks!
				delete m_GameMain;
				break;
			}

			// Check gamepad state.
			GamepadUpdate();
		}
	}

	else 
	{
		printf("m_GameMain did not allocate in memory!\n");
	}

	// Remove this from memory to prevent memory leaks!
	delete m_GameMain;

	return 0;
}
