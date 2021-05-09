#pragma once
#include "Main.h"

#define D3DFVF_CUSTOMVERTEX (D3DFVF_DIFFUSE)

// Custom vertex definition.
struct CUSTOMVERTEX 
{
	float x, y, z, rhw;
	unsigned int color;
};

// Define DrawText.
void DrawText(HXUIDC hdc, HXUIFONT hFont, D3DCOLOR color, float x, float y, LPCWSTR text);

// Define our class.
class GameMain 
{
public:
	GameMain();

	virtual void Render();

	D3DVertexBuffer * g_D3DVB;
	HXUIDC g_hDC;
	HXUIFONT g_pFont;

	bool bExitGame;
	bool bDirectInit;
};

extern GameMain * m_GameMain;
