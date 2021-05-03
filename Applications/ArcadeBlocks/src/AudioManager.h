#ifndef AUDIO_MANAGER_H_
#define AUDIO_MANAGER_H_

#include <string_view>
#include <string>
#include <map>

#include <fmod.hpp>

class AudioManager {
public:
	AudioManager();
	~AudioManager();
	void Update(float elapsed);

	void SetAudioListener(FMOD_VECTOR& pos, FMOD_VECTOR& vel, FMOD_VECTOR& forward,
			      FMOD_VECTOR& up);
	void SetReverb(FMOD_REVERB_PROPERTIES& props, FMOD_VECTOR& pos);

	void LoadSFX(std::string_view path);
	void LoadSong(std::string_view path);
	void PlaySFX(std::string_view path, float minVol, float maxVol, float minPitch,
		     float maxPitch, FMOD_VECTOR& pos, FMOD_VECTOR& vel);
	void PlaySong(std::string_view path);
	void StopSFXs();
	void StopSongs();

	void SetMasterVol(float vol);
	void SetSFXsVol(float vol);
	void SetSongsVol(float vol);

private:
	using SoundMap = std::map<std::string, FMOD::Sound*>;
	enum class Category { SFX, SONG, CATEGORY_COUNT };
	enum class FadeState { NONE, FADE_IN, FADE_OUT };

	void Load(const Category type, std::string_view path);
	static float ChangeSemitone(float freq, float var);
	static float RandomBetween(float min, float max);

	FMOD::System* system;
	FMOD::ChannelGroup* master;
	FMOD::Channel* currentSong;
	FMOD::Reverb3D* reverb;

	FMOD::ChannelGroup* groups[int(Category::CATEGORY_COUNT)];
	SoundMap sounds[int(Category::CATEGORY_COUNT)];
	FMOD_MODE modes[int(Category::CATEGORY_COUNT)];

	std::string currentSongPath;
	std::string nextSongPath;
	FadeState fade;
};

#endif // AUDIO_MANAGER_H_
