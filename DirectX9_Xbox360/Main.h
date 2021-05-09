#pragma once
#include <xtl.h>
#include <xbox.h>
#include <string>
#include <d3d9.h>
#include <d3dx9.h>
#include <xui.h>

#pragma comment(lib, "xuirun.lib")
#pragma comment(lib, "xuirender.lib")

#include "Gamepad.h"
#include "GameMain.h"
#include "MainMenu.h"

extern IDirect3D9 * g_pD3D;
extern IDirect3DDevice9 * g_pDevice;
extern D3DPRESENT_PARAMETERS d3dpp;


