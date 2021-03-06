////////////////////////////////////////////////////////////////////////////////
// Filename: GraphicClass.h
////////////////////////////////////////////////////////////////////////////////
#pragma once



#include <time.h>
#include <string>



#include "Global.h"
#include "D3DClass.h"
#include "CameraClass.h"
#include "InputClass.h"
#include "ShapeShaderClass.h"

#include "RectClass.h"	
#include "TextClass.h"
#include "MapLoader.h"

#include "Player.h"
#include "Map.h"
#include "Bullet.h"
#include "SoundClass.h"


const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 1000.0f;
const float SCREEN_NEAR = 0.1f;


class GraphicClass
{
public:
	GraphicClass();
	GraphicClass(const GraphicClass&);
	~GraphicClass();

	bool Initialize(HWND);
	void Shutdown();
	bool Frame(int, D3DXVECTOR2);

private:
	bool Render(int, D3DXVECTOR2);

private:
	time_t now = clock();

	D3DClass * m_D3D;
	CameraClass* m_Camera;

	Player* m_player;

	
	ShapeShaderClass* m_color;

	HWND m_hwnd;

	BitmapClass* m_gameover;

	BitmapClass* m_Block[3];
	TextureShaderClass* m_textureShader;

	Map* m_map;
	MapData** m_mapdata;

	SoundClass* m_sound;

	TextClass* m_Text;
};
