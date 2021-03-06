#pragma once

#include <d3d11.h>
#include <d3dx10math.h>
#include <d3dx11async.h>
#include <fstream>
using namespace std;

class ShapeShaderClass
{
private:
	struct MatrixBufferType
	{
		D3DXMATRIX world;
		D3DXMATRIX view;
		D3DXMATRIX projection;
	};

public:
	ShapeShaderClass();
	ShapeShaderClass(const ShapeShaderClass&);
	~ShapeShaderClass();

	bool Initialize(ID3D11Device*, HWND hwnd);
	void Shutdown();
	bool Render(ID3D11DeviceContext*, int indexCount, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix);

private:
	bool InitializeShader(ID3D11Device*, HWND, WCHAR* vsFilename, WCHAR* psFilename);
	void ShutdownShader();
	void OutputShaderErrorMessage(ID3D10Blob*, HWND, WCHAR* shaderFilename);

	bool SetShaderParameters(ID3D11DeviceContext*, D3DXMATRIX worldMatrix, D3DXMATRIX viewMatrix, D3DXMATRIX projectionMatrix);
	void RenderShader(ID3D11DeviceContext*, int indexCount);

private:
	ID3D11VertexShader * m_vertexShader;
	ID3D11PixelShader* m_pixelShader;
	ID3D11InputLayout* m_layout;
	ID3D11Buffer* m_matrixBuffer;
};