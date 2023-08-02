#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "NY_Object3DMgr.h"
#include "Raki_Input.h"
#include "GameManager.h"

#include <NY_Object3DMgr.h>
#include <Sprite.h>

class GameScene : public BaseScene {
public:
    GameScene(ISceneChanger *changer, SceneChangeDirection* scd);
    ~GameScene() override;
    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;        //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;            //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;
    void DrawParticle() override;

    Sprite testsp;
    Sprite spriteTimer;
    Sprite gameSet;
    //std::shared_ptr<Object3d> testobject;

    GameManager gmgr;
    //���Ԑ���
    float timer;
    const int MAX_TIMER = 61;
    XMFLOAT2 timerSize;
    XMFLOAT2 timerPos;
    XMFLOAT4 timerColor;
    bool timerFlag;
    int timerTime;
    bool gameSetFlag;
    XMFLOAT2 gameSetSize;


    int GameFrame;
};

