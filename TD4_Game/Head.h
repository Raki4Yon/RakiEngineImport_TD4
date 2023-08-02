#pragma once
#include <RVector.h>
#include<ParticleManager.h>

#include "ProtoPlayer.h"
#include<NY_Object3DMgr.h>
#include<FbxLoader.h>

using namespace Rv3Ease;

class Head
{
public:

	Head() {};
	virtual ~Head() {};

	virtual void Init() {};

	virtual void ResetFrontEase() {};

	virtual void Update() {};

	virtual void Draw() {};

	virtual void DrawParticle() {};

	virtual void Finalize() {};

	virtual void KramerMove() {};

	virtual void SlappingMove() {};

	virtual void FailMove() {};

	virtual void GoHome() {};

	static void setPlayerPtr(std::shared_ptr<ProtoPlayer> ptr);

	static void loadHeadModel();

	static void setStaticData();

	static void setIsStop(bool stop);

	void SetPlayer(ProtoPlayer* ptr) {
		this->playerPtr = ptr;
	}

	void Activate() {
		isactive = true;
	}

public:
	//���f���f�[�^
	static std::shared_ptr<fbxModel> headModelStatic;
	static std::shared_ptr<fbxModel> hairModelStatic;
	static std::shared_ptr<fbxModel> afroModelStatic;

	static bool isStop;

	//�r���^���ꂽ���̃p�[�e�B�N��
	std::unique_ptr<ParticleManager> SlapParticle;

	static UINT slapTex;
	static UINT pullTex;

	//�A�t�B���ϊ�
	RVector3 pos, rot, scale;

	//������тȂ����]
	RVector3 blustVec;
	RVector3 blustRot;

	//������Ԏ���
	int blustTime = 0;
	int maxBustTime = 15;

	//�q�̃^�C�v
	CheraType HeadType = CheraType::None;

	//�擪���ǂ���
	bool isMostFront = false;

	//�L�����t���O
	bool isactive = false;

	//�ҋ@����
	int waitTime = 0;
	const int MaxWaitTime = 1200;

	//�A�邩�ǂ���
	bool isGoHome = false;

	//����؂�ꂽ�E�����ꂽ���ǂ���
	bool isHairDestroy = false;

	//�ԈႦ�����ǂ���
	bool isFail = false;
	int FailCount = 0;
	RVector3 ShakeBacePos = {};
	float ShakeOffset = 1.0f;

	//�{���Ă��邩�ǂ���
	bool isAngree = false;

	//�{���Ă��鎞��
	int AngreeTime = 0;
	const int MaxAngreeTime = 300;
	int positionUpDown = -1;

	//�������邩�ǂ���
	bool isCounter = false;

	//�������I��������ǂ���
	bool isAllMoveFinish = false;

	//�v���C���[�|�C���^
	ProtoPlayer* playerPtr;

	//�N���[�}�[���ǂ���
	bool isKramer = false;

	//�r���^�t���O
	bool isSlap = false;

	//�r���^���ꂽ��
	int SlapCount = 0;

	//�r���^�̍ő��
	const int ManSlapCount = 5;

	//�C�[�W���O�p�ϐ�
	//�O�ɐi�ގ�
	bool isFrontEase = false;		//�O�ɐi�ނ�
	RVector3 FrontStart = {};
	RVector3 FrontEnd = {};
	int FrontEaseT = 0;		//����
	const float FrontLength = 4.5f;	//�ω���
	//�r���^���ꂽ�Ƃ�
	float SlapEaseT = 0.0f;			//����
	const float SlapLength = 1.0f;	//�ω���
};

