#include <iostream>
#include <map>
#include <vector>
#include <string>

class Sound {
public:
	Sound() : m_Path(""), m_dB(45)
	{
	}
	Sound(std::string path, int dB) : m_Path(path), m_dB(dB)
	{
	}

	Sound(const Sound& other)
	{
		std::cout << "Copied" << std::endl;
		m_dB = other.m_dB;
		m_Path = other.m_Path;
	}

	friend std::ostream& operator<<(std::ostream& os, const Sound& other)
	{
		os << "Sound path: " << other.m_Path << ", Peak dB: " << other.m_dB << std::flush;
		return os;
	}

	// To allow the objects of this class to be used as a map keys
	bool operator<(const Sound& other) const
	{
		// This would differenciate two sounds that are the same file but have different level
		if (m_Path == other.m_Path)
			return m_dB < other.m_dB;
		else
			return m_Path < other.m_Path;
	}

private:
	std::string m_Path;
	int m_dB;
};

int main()
{
	using SoundMap = std::map<int, Sound>;
	SoundMap sounds;

	sounds.emplace(3, Sound("folder/sound4.wav", 45));
	sounds.emplace(2, Sound("folder/sound3.wav", 60));
	sounds.emplace(1, Sound("folder/sound2.wav", 65));
	sounds.emplace(0, Sound("folder/sound1.wav", 55));

	for (SoundMap::iterator it = sounds.begin(); it != sounds.end(); ++it)
		std::cout << it->second << std::endl;

	std::cout << std::endl;

	// C++17 Structured Bindings test
	for (auto& [key, sound] : sounds)
		std::cout << key << "- " << sound << std::endl;

	return 0;
}
