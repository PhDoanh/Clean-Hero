#include "Sound.hpp"

std::map<std::string, Mix_Chunk *> sounds;
std::map<std::string, Mix_Music *> musics;

void Sound::loadSoundEffect(const std::string &name, const std::string &path)
{
	info("Trying to load " + path + " ... \n");
	sounds[name] = Mix_LoadWAV(path.c_str());
	if (!sounds[name])
	{
		Mix_FreeChunk(sounds[name]);
		sounds[name] = nullptr;
		sounds.erase(name);
		error(path + " - fail.\n");
	}
	info(path + " - done.\n");
}

void Sound::playSoundEffect(const std::string &name, int chanel, int loop)
{
	stopSoundEffect(chanel);
	Mix_FadeInChannel(chanel, sounds[name], loop, 5);
}

void Sound::stopSoundEffect(int chanel)
{
	Mix_FadeOutChannel(chanel, 5);
}

void Sound::loadMusic(const std::string &name, const std::string &path)
{
	info("Trying to load " + path + " ... \n");
	musics[name] = Mix_LoadMUS(path.c_str());
	if (!musics[name])
	{
		Mix_FreeMusic(musics[name]);
		musics[name] = nullptr;
		musics.erase(name);
		error(path + " - fail.\n");
	}
	info(path + " - done.\n");
}

void Sound::playMusic(const std::string &name, int loop)
{
	Mix_PlayMusic(musics[name], loop);
}

void Sound::stopMusic()
{
	Mix_HaltMusic();
}

void Sound::deleteSoundEffects()
{
	info("Deleting all sound effects ...\n");
	for (auto &&sound : sounds)
	{
		Mix_FreeChunk(sound.second);
		sound.second = nullptr;
		if (sound.second)
			error(sound.first + " - fail.\n");
		else
			info(sound.first + " - done.\n");
	}
}

void Sound::deleteMusics()
{
	info("Deleting all musics ...\n");
	for (auto &&music : musics)
	{
		Mix_FreeMusic(music.second);
		music.second = nullptr;
		if (music.second)
			error(music.first + " - fail.\n");
		else
			info(music.first + " - done.\n");
	}
}