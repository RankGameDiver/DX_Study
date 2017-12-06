#include "stdafx.h"
#include "SoundManager.h"

SoundManager::SoundManager()
{
	init();
}

SoundManager::~SoundManager()
{
	ZeroMemory(&str, sizeof(str));

	for (auto& iter : m_soundMap)
		iter.second->release();
	m_soundMap.clear();

	pFmod->close();
	pFmod->release();
}

void SoundManager::init()
{
	r = FMOD::System_Create(&pFmod);
	ErrorCheck(r);
	r = pFmod->init(100, FMOD_INIT_NORMAL, NULL);
	ErrorCheck(r);
	r = pFmod->createSoundGroup("AllBGM", &allBGMSound);
	ErrorCheck(r);
	r = pFmod->createSoundGroup("AllSEF", &allSEFSound);
	ErrorCheck(r);
}

void SoundManager::LoadSound(std::string key, std::wstring path, SoundType type)
{
	WideCharToMultiByte(CP_ACP, 0, path.c_str(), -1, str.data(), MAX_PATH, 0, 0);

	switch (type)
	{
	case BGM:
		r = pFmod->createStream(str.data(), FMOD_LOOP_NORMAL, NULL, &m_soundMap[key]);
		ErrorCheck(r);
		r = m_soundMap[key]->setSoundGroup(allBGMSound);
		ErrorCheck(r);
		return;
	case SEF:
		r = pFmod->createSound(str.data(), FMOD_DEFAULT, NULL, &m_soundMap[key]);
		ErrorCheck(r);
		r = m_soundMap[key]->setSoundGroup(allSEFSound);
		ErrorCheck(r);
		return;
	}
}

void SoundManager::SoundPlay(std::string key)
{
	pFmod->update();
	r = pFmod->playSound(FMOD_CHANNEL_FREE, m_soundMap[key], false, &m_channelMap[key]);
	ErrorCheck(r);
}

void SoundManager::SoundStop(std::string key)
{
	if (!m_channelMap[key]) return;

	m_channelMap[key]->isPlaying(&isPlaying);
	if (isPlaying)
		m_channelMap[key]->stop();
}

bool SoundManager::CheckIsPlayer(std::string key)
{
	m_channelMap[key]->isPlaying(&isPlaying);
	return isPlaying;
}

void SoundManager::SoundPause(std::string key, bool stop)
{
	m_channelMap[key]->setPaused(stop);
}

void SoundManager::VolumeControl(float volume, SoundType type)
{
	switch (type)
	{
	case BGM:
		allBGMSound->setVolume(volume);
		return;
	case SEF:
		allSEFSound->setVolume(volume);
		return;
	}
}

void SoundManager::ErrorCheck(FMOD_RESULT _r)
{
	if (_r != FMOD_OK)
	{
		TCHAR szStr[256] = { 0 };
		MultiByteToWideChar(CP_ACP, NULL, FMOD_ErrorString(r), -1, szStr, 256);
		MessageBox(NULL, szStr, L"Sound Error", MB_OK);
	}
}
