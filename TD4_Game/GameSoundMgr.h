#pragma once
#include <Audio.h>

#include <array>

class GameSoundMgr
{
private:
	//�e���f�[�^
	std::unique_ptr<SoundData> titleBgm;
	std::unique_ptr<SoundData> gameBgm;
	std::unique_ptr<SoundData> resultBgm;
	std::unique_ptr<SoundData> tutorialBgm;

	std::array<std::unique_ptr<SoundData>, 3> slapSe = {};
	std::array<std::unique_ptr<SoundData>, 2> cutSe = {};
	std::unique_ptr<SoundData> pullSe;
	std::unique_ptr<SoundData> buttonSe;
	std::unique_ptr<SoundData> cancelSe;


	GameSoundMgr() = default;
	~GameSoundMgr();

public:
	static GameSoundMgr *get()
	{
		static GameSoundMgr ins;
		return &ins;
	}

	void Init();

	//BGM
	void PlayTitleBGM();
	void StopTitleBGM();
	void PlayGameBGM();
	void StopGameBGM();
	void PlayResultBGM();
	void StopResultBGM();
	void PlayTutorialBGM();
	void StopTutorialBGM();

	//SE
	void PlayCutSE();
	void PlaySlapSE();
	void PlayPullSE();
	void PlayButtonSE();
	void PlayCancelSE();


};

