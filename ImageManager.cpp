#include "stdafx.h"
#include "ImageManager.h"


CImageManager::CImageManager()
{
	int temp;
	temp = D3DXCreateSprite(Device, &imgRenderer);
	this->ImgLoad("rect", "./rect.png");
}


CImageManager::~CImageManager()
{
	imgRenderer->Release();
}

MyTexture CImageManager::ImgLoad(string key, string path)
{
	MyTexture texture;
	D3DXCreateTextureFromFileExA(Device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), &texture.imageInfo, 0, &texture.texture);
	texture.frameNum = 1;
	texture.fw = texture.imageInfo.Width;
	texture.fh = texture.imageInfo.Height;

	textureMap.insert(make_pair(key, texture));
	return texture;
}

MyTexture CImageManager::ImgLoad(string key, string path, int fw, int fh)
{
	MyTexture texture;
	D3DXCreateTextureFromFileExA(Device, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_DEFAULT, D3DX_DEFAULT, D3DCOLOR_XRGB(255, 0, 255), &texture.imageInfo, 0, &texture.texture);

	texture.fh = fh; 
	texture.fw = fw;

	texture.fx = texture.imageInfo.Width / fw;
	texture.fy = texture.imageInfo.Height / fh;

	texture.frameNum = texture.fx * texture.fy;

	textureMap.insert(make_pair(key, texture));
	return texture;
}

void CImageManager::ImgRender(string key, Vector2D pos)
{
	D3DXMATRIX mat;
	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, 0.f, &D3DXVECTOR2(pos.x, pos.y));
	imgRenderer->SetTransform(&mat);

	auto find = textureMap.find(key);
	imgRenderer->Draw(find->second.texture, 0, 0, 0, D3DCOLOR_XRGB(255, 255, 255));
}

void CImageManager::ImgRender(string key, Vector2D pos, int frame, D3DCOLOR color)
{
	D3DXMATRIX mat;

	auto find = textureMap.find(key);

	int fw = find->second.fw;
	int fh = find->second.fh;

	int fx = frame % find->second.fx;
	int fy = frame / find->second.fx;

	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, 0.f, &D3DXVECTOR2(pos.x - (fw / 2), pos.y - (fh / 2)));
	imgRenderer->SetTransform(&mat);


	RECT outputRect = { fw * fx , fh * fy, (fw * (fx + 1)) - 1, (fh * (fy + 1))};

	imgRenderer->Draw(find->second.texture, &outputRect, 0, 0, color);
}


void CImageManager::ImgRender(string key, Vector2D pos, int frame)
{
	D3DXMATRIX mat;

	auto find = textureMap.find(key);

	int fw = find->second.fw;
	int fh = find->second.fh;

	int fx = frame % find->second.fx;
	int fy = frame / find->second.fx;

	D3DXMatrixAffineTransformation2D(&mat, 1.f, nullptr, 0.f, &D3DXVECTOR2(pos.x - (fw / 2), pos.y - (fh / 2)));
	imgRenderer->SetTransform(&mat);

	RECT outputRect = { fw * fx , fh * fy, (fw * (fx + 1)) - 1, (fh * (fy + 1)) };

	imgRenderer->Draw(find->second.texture, &outputRect, 0, 0, D3DCOLOR_XRGB(255, 255, 255));
}




void CImageManager::ImgRender(string key, Vector2D pos, int frame, float r)
{
	D3DXMATRIX mat;

	auto find = textureMap.find(key);

	int fw = find->second.fw;
	int fh = find->second.fh;

	int fx = frame % find->second.fx;
	int fy = frame / find->second.fx;

	D3DXMatrixAffineTransformation2D(&mat, 1.f, &D3DXVECTOR2(fw / 2, fh / 2), D3DXToRadian(r), &D3DXVECTOR2(pos.x - (fw / 2), pos.y - (fh / 2)));
	imgRenderer->SetTransform(&mat);




	RECT outputRect = { fw * fx , fh * fy, (fw * (fx + 1)) - 1, (fh * (fy + 1)) };

	imgRenderer->Draw(find->second.texture, &outputRect, 0, 0, D3DCOLOR_XRGB(255, 255, 255));
}

void CImageManager::ImgRender(string key, Vector2D pos, float r)
{
	D3DXMATRIX mat;

	auto find = textureMap.find(key);

	int fw = find->second.fw;
	int fh = find->second.fh;

	D3DXMatrixAffineTransformation2D(&mat, 1.f, &D3DXVECTOR2(fw / 2, fh / 2), D3DXToRadian(r), &D3DXVECTOR2(pos.x - (fw / 2), pos.y - (fh / 2)));
	imgRenderer->SetTransform(&mat);




	RECT outputRect = { 0, 0, fw, fh };

	imgRenderer->Draw(find->second.texture, &outputRect, 0, 0, D3DCOLOR_XRGB(255, 255, 255));
}

void CImageManager::RectRender(Vector2D pos, Vector2D size)
{
	D3DXMATRIX matS;
	D3DXMATRIX matT;
	D3DXMATRIX matF;


	D3DXMatrixScaling(&matS, size.x / 200, size.y / 200, 1);
	D3DXMatrixTranslation(&matT, pos.x - (size.x / 2), pos.y - (size.y / 2), 0);
	matF = matS * matT;
	imgRenderer->SetTransform(&matF);

	auto find = textureMap.find("rect");
	imgRenderer->Draw(find->second.texture, 0, 0, 0, D3DCOLOR_ARGB(127, 255, 255, 255));
}

void CImageManager::Begin()
{
	imgRenderer->Begin(D3DXSPRITE_ALPHABLEND);
}

void CImageManager::End()
{
	imgRenderer->End();
}