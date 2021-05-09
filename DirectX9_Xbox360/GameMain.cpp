#include "GameMain.h"

// Constuctor.
GameMain::GameMain() 
{
	// Add shit here.
}

void DrawText(HXUIDC hdc, HXUIFONT hFont, D3DCOLOR color, float x, float y, LPCWSTR text)
{
	// Measure the text
	XUIRect clipRect(0, 0, d3dpp.BackBufferWidth - x, d3dpp.BackBufferHeight - y);
	XuiMeasureText(hFont, text, -1, XUI_FONT_STYLE_NORMAL, 0, &clipRect);

	// Set the text position in the device context
	D3DXMATRIX matXForm;
	D3DXMatrixIdentity(&matXForm);
	matXForm._41 = x;
	matXForm._42 = y;
	XuiRenderSetTransform(hdc, &matXForm);

	// Select the font and color into the device context
	XuiSelectFont(hdc, hFont);
	XuiSetColorFactor(hdc, (DWORD)color);

	// Draw the text
	XuiDrawText(hdc, text, XUI_FONT_STYLE_NORMAL, 0, &clipRect);
}

// Renders a frame with a background color and text.
void GameMain::Render()
{
	if (!bDirectInit) 
	{
		XUIInitParams initparams =
		{
			0
		};
		XUI_INIT_PARAMS(initparams);
		
		TypefaceDescriptor desc =
		{
			0
		};

		desc.szTypeface = L"Arial Unicode MS";
		desc.szLocator = L"file://game:/media/xarialuni.ttf";
		
		XuiRenderInitShared(g_pDevice, &d3dpp, XuiD3DXTextureLoader);
		XuiRenderCreateDC(&g_hDC);

		XuiInit(&initparams);
		XuiRegisterTypeface(&desc, TRUE);

		XuiCreateFont(L"Arial Unicode MS", 18.0f, XUI_FONT_STYLE_NORMAL, 0, &g_pFont);

		// DirectX 9 Was successfully started.
		bDirectInit = true;
	}

	// Clear the entire screen with a black background.
	// This will be the 'Backdrop' for everything else you render.
	g_pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, D3DCOLOR_XRGB(0, 0, 0)/*Background color*/, 1.0f, 0);
	XuiRenderBegin(g_hDC, D3DCOLOR_ARGB(255, 0, 255, 0));

	// Tells Direct X where and what text to render to the Screen.
	DrawText(m_GameMain->g_hDC, m_GameMain->g_pFont, D3DCOLOR_ARGB(255, 255, 255, 255)/*Text color*/, 600/*X*/, 300/*Y*/, L"Hello World");
	
	// Some matrix shit I don't understand why I need yet...
	D3DXMATRIX matView;
	D3DXMatrixIdentity(&matView);
	XuiRenderSetViewTransform(g_hDC, &matView);

	// Render.
	XuiRenderEnd(g_hDC);
	XuiRenderPresent(g_hDC, NULL, NULL, NULL);
	g_pDevice->Present(0, 0, 0, 0);

}

GameMain * m_GameMain;