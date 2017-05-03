#include "Sound.h"
#include <SDL_mixer.h>

#include <string>

Sound* Sound::instance = 0;
Sound::audioState Sound::currentState = ERROR;
std::string Sound::currentSound = "";

void Sound::playMusic(const std::string& file, int loops, int volume) {
	//if (currentState != ERROR)
	//{
	// If no music is playing, play it
	if (Mix_PlayingMusic() == 0)
	{
		// Load music
		
		Mix_Music* music = Mix_LoadMUS(file.c_str());
		Mix_VolumeMusic(volume);
		//Play music
		if (music != NULL) {
			Mix_PlayMusic(music, loops);
			currentState = PLAYING;
			currentSound = file.c_str();
		}
	}
	else
	{
		// If music is playing, pause it
		this->pauseMusic();
	}
	//}
}

void Sound::pauseMusic() {
	//if (currentState != ERROR)
	//{
	// If music is playing, handle the pause request
	if (Mix_PlayingMusic() == 1)
	{
		if (Mix_PausedMusic() == 1)
		{
			// If we receive a pause request and the music is already paused, resume it.
			Mix_ResumeMusic();
			currentState = PLAYING;
		}
		else
		{
			// Otherwise, pause the music
			Mix_PauseMusic();
			currentState = PAUSED;
		}
	}
	//}
}

void Sound::stopMusic() {
	//if (currentState != ERROR) {
	Mix_HaltMusic();
	currentState = STOPPED;
	currentSound = "";
	//}
}


void Sound::playEffect(const std::string& file, int loops, int volume, int chan) {
	//if (currentState != ERROR)
	//{
	Mix_Chunk* fx = Mix_LoadWAV(file.c_str());
	Mix_PlayChannel(chan, fx, loops);
	Mix_VolumeChunk(fx, volume);
	//}
}

Sound::Sound() {

}

Sound::~Sound()
{
	Mix_CloseAudio();
}