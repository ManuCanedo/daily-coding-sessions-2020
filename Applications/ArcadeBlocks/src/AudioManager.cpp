#include "AudioManager.h"

#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

AudioManager::AudioManager() 
	: currentSong(0), reverb(), groups(), fade(FadeState::NONE)
{
	// Initialize system
	FMOD::System_Create(&system);
	system->init(100, FMOD_INIT_NORMAL, 0);

	// Create channel groups for each category
	system->getMasterChannelGroup(&master);
	for (int i = 0; i < (int)Category::CATEGORY_COUNT; ++i) 
	{
		system->createChannelGroup(0, &groups[i]);
		master->addGroup(groups[i]);
	}

	// Set up modes for each category
	modes[(int)Category::SFX] = FMOD_2D;
	modes[(int)Category::SONG] = FMOD_DEFAULT | FMOD_CREATESTREAM | FMOD_LOOP_NORMAL;

	// Seed random number generator
	srand(time(0));
}

AudioManager::~AudioManager() 
{
	// Release sounds in each category
	SoundMap::iterator iter;
	for (int i = 0; i < (int)Category::CATEGORY_COUNT; ++i) 
	{
		for (iter = sounds[i].begin(); iter != sounds[i].end(); ++iter)
			iter->second->release();
		sounds[i].clear();
	}

	// Release system
	system->release();
}

void AudioManager::LoadSFX(std::string_view path) 
{
	Load(Category::SFX, path);
}

void AudioManager::LoadSong(std::string_view path) 
{
	Load(Category::SONG, path);
}

void AudioManager::PlaySFX(std::string_view path, float minVol, float maxVol, float minPitch, float maxPitch, FMOD_VECTOR& pos, FMOD_VECTOR& vel) 
{
	// Try to find sound effect and return if not found
	SoundMap::iterator sound = sounds[(int)Category::SFX].find(std::string(path));

	if (sound == sounds[(int)Category::SFX].end()) 
		return;

	// Calculate random volume and pitch in selected range
	float vol = RandomBetween(minVol, maxVol);
	float pitch = RandomBetween(minPitch, maxPitch);

	// Play the sound effect with these initial values
	FMOD::Channel* channel;
	system->playSound(sound->second, NULL, true, &channel);
	
	channel->setChannelGroup(groups[(int)Category::SFX]);
	channel->set3DAttributes(&pos, &vel);
	channel->setVolume(vol);
	float freq;
	channel->getFrequency(&freq);
	channel->setFrequency(ChangeSemitone(freq, pitch));
	channel->setPaused(false);
}

void AudioManager::StopSFXs() 
{
	groups[(int)Category::SFX]->stop();
}

void AudioManager::PlaySong(std::string_view path) 
{
	// Ignore if this song is already playing
	if (currentSongPath == path) 
		return;

	// If a song is playing stop them and set this as the next song
	if (currentSong != 0) 
	{
		StopSongs();
		nextSongPath = path;
		return;
	}

	// Search for a matching song in the sound map
	SoundMap::iterator sound = sounds[(int)Category::SONG].find(path.data());
	
	if (sound == sounds[(int)Category::SONG].end()) 
		return;

	// Start playing song with volume set to 0 and fade in
	currentSongPath = path;
	system->playSound(sound->second, NULL, true, &currentSong);
	currentSong->setChannelGroup(groups[(int)Category::SONG]);
	currentSong->setVolume(0.0f);
	currentSong->setPaused(false);
	fade = FadeState::FADE_IN;
}

void AudioManager::StopSongs() 
{
	if (currentSong != 0)
		fade = FadeState::FADE_OUT;

	nextSongPath.clear();
}

void AudioManager::Update(float elapsed) 
{
	
	const float fadeTime = 1.0f; // in seconds

	if (currentSong != 0 && fade == FadeState::FADE_IN) 
	{
		float vol;
		currentSong->getVolume(&vol);
		float nextVol = vol + elapsed / fadeTime;
		
		if (nextVol >= 1.0f) 
		{
			currentSong->setVolume(1.0f);
			fade = FadeState::NONE;
		}
		else 
		{
			currentSong->setVolume(nextVol);
		}
	}
	else if (currentSong != 0 && fade == FadeState::FADE_OUT) 
	{
		float vol;
		currentSong->getVolume(&vol);
		float nextVol = vol - elapsed / fadeTime;
		
		if (nextVol <= 0.0f) 
		{
			currentSong->stop();
			currentSong = 0;
			currentSongPath.clear();
			fade = FadeState::NONE;
		}
		else 
		{
			currentSong->setVolume(nextVol);
		}
	}
	else if (currentSong == 0 && !nextSongPath.empty()) 
	{
		PlaySong(nextSongPath);
		nextSongPath.clear();
	}

	system->update();
}

void AudioManager::SetMasterVol(float vol) 
{
	master->setVolume(vol);
}
void AudioManager::SetSFXsVol(float vol) 
{
	groups[(int)Category::SFX]->setVolume(vol);
}
void AudioManager::SetSongsVol(float vol) 
{
	groups[(int)Category::SONG]->setVolume(vol);
}

void AudioManager::SetAudioListener(FMOD_VECTOR& pos, FMOD_VECTOR& vel, FMOD_VECTOR& forward, FMOD_VECTOR& up)
{
	system->set3DListenerAttributes(0, &pos, &vel, &forward, &up);
}

void AudioManager::SetReverb(FMOD_REVERB_PROPERTIES &props, FMOD_VECTOR &pos)
{
	system->createReverb3D(&reverb);
	reverb->setProperties(&props);
	reverb->set3DAttributes(&pos, 10.0f, 20.0f);
}

void AudioManager::Load(Category type, std::string_view path)
{
	if (sounds[(int)type].find(path.data()) != sounds[(int)type].end())
		return;

	FMOD::Sound* sound;
	system->createSound(path.data(), modes[(int)type], 0, &sound);
	sounds[(int)type].insert(std::make_pair(path, sound));
}

float AudioManager::ChangeSemitone(float freq, float var)
{
	static float semitone_ratio = pow(2.0f, 1.0f / 12.0f);
	return freq * pow(semitone_ratio, var);
}

float AudioManager::RandomBetween(float min, float max)
{
	if (min == max)
		return min;
	float n = (float)rand() / (float)RAND_MAX;
	return min + n * (max - min);
}