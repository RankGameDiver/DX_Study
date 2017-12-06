#pragma once

enum SoundType
{
	BGM,
	SEF
};

class SoundManager
	: public Singletone<SoundManager>
{
public:
	SoundManager();
	virtual ~SoundManager();

public:
	void init();
	void LoadSound(std::string key, std::wstring path, SoundType type);
	void SoundPlay(std::string key);
	void SoundStop(std::string key);
	bool CheckIsPlayer(std::string key);
	void SoundPause(std::string key, bool stop);
	void VolumeControl(float volume, SoundType type);
	void ErrorCheck(FMOD_RESULT _r);

private:
	FMOD::System*	pFmod;
	std::map<std::string, FMOD::Sound*>   m_soundMap;
	std::map<std::string, FMOD::Channel*> m_channelMap;
	FMOD::SoundGroup* allBGMSound;
	FMOD::SoundGroup* allSEFSound;
	FMOD_RESULT	r;
	std::array<char, MAX_PATH> str;
	bool isPlaying;
};

#define SOUNDMANAGER SoundManager::GetSingletone()