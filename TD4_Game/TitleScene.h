#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"
#include <DirectXMath.h>
#include <cmath>

#include <Raki_Input.h>
#include <NY_Object3DMgr.h>
#include <Sprite.h>

//�A�j���[�V�����̃g�[�^������
const int animationCountMax = 600;
const int ScrollCountMax = 60;
//�^�C�g���X�v���C�g�̍ŏI�ʒu
const float titleLastPos = -50.0f;

class TitleScene : public BaseScene {

public:
    TitleScene(ISceneChanger *changer, SceneChangeDirection *scd);
    ~TitleScene() override;

    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;   //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;

    void Animation();

    void SceneScroll();

    Sprite testsp;
    Sprite startsp;
    Sprite tutorialsp;
    Sprite buttonAsp;
    Sprite buttonBsp;

    std::shared_ptr<Object3d> titleHage;
    std::shared_ptr<Object3d> titlePlayer;
    std::shared_ptr<Object3d> titleAfro;
    std::shared_ptr<Object3d> titleIppon;

    Rv3Ease::Rv3Easing titleEase;

    int animationCount = 0;
    int scrollCount = 0;

    bool isScroll;
    bool isTitleScroll;

    XMFLOAT2 titleSpritePos;

    RVector3 titleObjPos;
    RVector3 titlePlayerPos;
    RVector3 titleHagePos;
};