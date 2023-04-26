#pragma once
#include <RVector.h>
#include <memory>

#include "ProtoPlayer.h"

class ProtoPlayer;

class Head
{
public:

	Head() {};
	virtual ~Head() {};

	virtual void Init() {};

	virtual void Update() {};

	virtual void Draw() {};

	virtual void Finalize() {};

	void SetPlayer(ProtoPlayer *ptr) {
		this->ptr = ptr;
	}

	void Activate() {
		isactive = true;
	}

	virtual void HairCut() {};

	virtual void Slap() {};

public:
	//�A�t�B���ϊ�
	RVector3 pos, rot, scale;

	//�L�����t���O
	bool isactive = false;
	bool isSlaped = false;

	//�v���C���[�|�C���^
	ProtoPlayer *ptr;

};

