#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"

#include <NY_Object3DMgr.h>
#include <Sprite.h>

class TitleScene : public BaseScene {

public:
    TitleScene(ISceneChanger *changer);
    ~TitleScene() override;

    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override ;   //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;

    Sprite testsp;
    std::shared_ptr<Object3d> testobject;

};
