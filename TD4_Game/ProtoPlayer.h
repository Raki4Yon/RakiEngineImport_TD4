#pragma once

#include <vector>
#include <memory>
#include <array>
#include <Sprite.h>
#include <NY_Object3D.h>
#include <NY_Object3dMgr.h>
#include "Raki_Input.h"
#include <Audio.h>

using namespace Rv3Ease;

enum CheraType
{
	None, SkinHead, Thinning, Afro,
};
enum ItemType
{
	Hand, Scissors, Clippers
};

class ProtoPlayer
{
public:
	ProtoPlayer();
	~ProtoPlayer();

	void Init();

	void Update();

	void Draw();

	void DrawUI();

	void Attack();

	void Finalize();

	//ビンタ
	void HandAttack();

	//髪を切る
	void CutHair();

	//バリカン
	void Clip();

	//左手のアイテムを切り替える
	void ChangeItem();

	ItemType GetItemType();

	static void setIsStop(bool stop);

	/// <summary>
	/// 退職金(HP)
	/// </summary>
	int RetirementMoney = 0;

	/// <summary>
	/// 退職金の最大値
	/// </summary>
	const int MaxRetirementMoney = 500;

private:

	static bool isStop;

	RVector3 HandPositionOffset;
	RVector3 HandRotationOffset;
	RVector3 HandScaleOffset;

	RVector3 CutPositionOffset;
	RVector3 CutRotationOffset;
	RVector3 CutScaleOffset;

	RVector3 ClipPositionOffset;
	RVector3 ClipRotationOffset;
	RVector3 ClipScaleOffset;

	int enemyType = SkinHead;
	ItemType handItemType = Hand;

	std::unique_ptr<Object3d> handObject = nullptr;
	std::unique_ptr<Object3d> barikanObject = nullptr;
	std::unique_ptr<Object3d> scissorsObject = nullptr;

	UINT modelPlayer;
	UINT modelScissor;

	UINT UITexHand;
	UINT UITexClip;
	UINT UITexScis;
	Sprite handUI;
	Sprite clipUI;
	Sprite scisUI;

	XMFLOAT2 uiOffsetHand;
	XMFLOAT2 uiOffsetClip;
	XMFLOAT2 uiOffsetScis;

	//-------------------音-------------------
	std::unique_ptr<SoundData> slapSE;
	std::unique_ptr<SoundData> cutSE;
	std::unique_ptr<SoundData> clipSE;

	//-------------------曲線補間-------------------
	//ビンタ
	Rv3Spline SlapSpline;
	bool isSlapSpline = false;
	RVector3 SlapRot = { 90,0,0 };
	std::array<RVector3, 6> SlapControlPoint;

	//ハサミ
	Rv3Spline ClipSpline;
	bool isClipSpline = false;
	RVector3 ClipRot = { 90,0,0 };
	std::array<RVector3, 6> ClipControlPoint;

	//バリカン
	Rv3Spline CutSpline;
	bool isCutSpline = false;
	RVector3 CutRot = { 90,0,0 };
	std::array<RVector3, 6> CutControlPoint;

};

