#ifndef _SOUND_H
#define	_SOUND_H


#include <iostream>
#include <SDL.h>
#include <SDL_mixer.h>
#include <string>


class Sound
{
public:
	Sound();
	virtual ~Sound();


	static Sound* getInstance() {
		if (instance == 0) {
			instance = new Sound;
			Sound::init();
		}
		return instance;
	}

	void playMusic(const std::string& file, int loops, int volume);
	void pauseMusic();
	void stopMusic();
	void playEffect(const std::string& file, int loops, int volume, int chan);

	bool isPaused() {
		return currentState == PAUSED;
	}

	bool isStopped() {
		return currentState == STOPPED;
	}

	bool isPlaying() {
		return currentState == PLAYING;
	}

	bool error() {
		return currentState == ERROR;
	}

private:
	static std::string currentSound;
	static Sound* instance;

	enum audioState
	{
		ERROR = 0,
		WAITING,
		PAUSED,
		STOPPED,
		PLAYING
	};
	static audioState currentState;

	static void init() {
		if (SDL_Init(SDL_INIT_AUDIO) != -1)
		{
			if (Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096) == -1)
			{
				std::cerr << "Error initializing audio device...\n";
				currentState = ERROR;
			}
			else
			{
				currentState = WAITING;
			}
		}
		else
		{
			std::cerr << "Error initializing SDL audio subsystem...\n";
			currentState = ERROR;
		}
	}
};



#endif