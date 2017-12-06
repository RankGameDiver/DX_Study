#pragma once


using namespace std;

struct MyTexture
{
	LPDIRECT3DTEXTURE9	texture;			// ��µ� �̹���
	D3DXIMAGE_INFO		imageInfo;			// ��µ� �̹����� ����

	int					frameNum;			// ������ ����

	int					fw;					// �����Ӵ� ���� ����
	int					fh;					// �����Ӵ� ���� ����

	int					fx;					// ���� �������� ����
	int					fy;					// ���� �������� ����

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