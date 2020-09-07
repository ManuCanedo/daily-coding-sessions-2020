#include <iostream>
#include <map>
#include <vector>
#include <string>

class Sound
{
public:
    Sound() : m_Path(""), m_dB(45) {}
    Sound(std::string path, int dB) : m_Path(path), m_dB(dB) {}

    Sound(const Sound &other)
    {
        std::cout << "Copied" << std::endl;
        m_dB = other.m_dB;
        m_Path = other.m_Path;
    }

    friend std::ostream &operator<<(std::ostream &os, const Sound &other)
    {
        os << "Sound path: " << other.m_Path << ", Peak dB: " << other.m_dB << std::flush;
        return os;
    }

    // To allow the objects of this class to be used as a map keys
    bool operator<(const Sound &other) const
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
    std::map<int, Sound> sounds;

    sounds.emplace(3, Sound("folder/sound4.wav", 45));
    for (std::map<int, Sound>::iterator it = sounds.begin(); it != sounds.end(); ++it)
        std::cout << it->second << std::endl;

    return 0;
}
