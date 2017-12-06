#pragma once


using namespace std;

struct MyTexture
{
	LPDIRECT3DTEXTURE9	texture;			// 출력될 이미지
	D3DXIMAGE_INFO		imageInfo;			// 출력될 이미지의 정보

	int					frameNum;			// 프레임 갯수

	int					fw;					// 프레임당 가로 길이
	int					fh;					// 프레임당 세로 길이

	int					fx;					// 가로 프레임의 갯수
	int					fy;					// 세로 프레임의 갯수

	void	Release()	{ texture->Release(); }
};

class CImageManager : public Singletone<CImageManager>
{
private:
	LPD3DXSPRITE imgRenderer;
	map <string, MyTexture> textureMap;

public:
	CImageManager();
	~CImageManager();

	MyTexture ImgLoad(string key, string path);
	MyTexture ImgLoad(string key, string path, int fw, int fh);

	void ImgRender(string key, Vector2D pos);
	void ImgRender(string key, Vector2D pos, int frame);
	void ImgRender(string key, Vector2D pos, int frame, D3DCOLOR color);
	void ImgRender(string key, Vector2D pos, int frame, float r);
	void ImgRender(string key, Vector2D pos, float r);

	void RectRender(Vector2D pos, Vector2D size);

	void Begin();
	void End();
};

#define IMAGEMANAGER CImageManager::GetSingletone()