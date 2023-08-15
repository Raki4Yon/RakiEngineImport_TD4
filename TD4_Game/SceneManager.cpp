#include "SceneManager.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "EngineDebugScene.h"
#include "ResultScene.h"
#include"TutorialScene.h"

//Raki_DX12B         *SceneManager::dx12b  = nullptr;
//NY_Object3DManager *SceneManager::objmgr = nullptr;
//SpriteManager      *SceneManager::spmgr  = nullptr;

SceneManager::SceneManager() :mNextScene(eScene_None) {
    if (!mSceneChangeDirection) { 
        mSceneChangeDirection.reset(new SceneChangeDirection());
        mSceneChangeDirection->Init();
    }

    //�e�V�[���̃C���X�^���X����
    nowScene = (BaseScene *) new EngineDebugScene(this,mSceneChangeDirection.get());
    Initialize();
}

SceneManager::~SceneManager()
{
    delete nowScene;
    nowScene = nullptr;
}

void SceneManager::Initialize()
{
    //�V�[���̏�����
	nowScene->Initialize();
}

void SceneManager::Finalize()
{
    nowScene->Finalize();
}

void SceneManager::Update()
{
    //�f�o�b�O���[�h
    if (Input::Get()->isKeyTrigger(DIK_F12)) { mNextScene = eScene_Debug; }
    if(Input::Get()->isKeyTrigger(DIK_F1)) { mNextScene = eScene_Title; }

    if (mNextScene != eScene_None) {    //���̃V�[�����Z�b�g����Ă�����

        if (!isChangeDirectioning) {
            //�V�[���I�����o���Đ�
            mSceneChangeDirection->PlayOutDirection();
            isChangeDirectioning = true;
        }
        //�V�[�����o�I����
        if (mSceneChangeDirection->GetDirectionStatus() == DIRECTION_ENDED && isChangeDirectioning) {
            delete nowScene;
            nowScene = nullptr;

            switch (mNextScene) {       //�V�[���ɂ���ď����𕪊�
            case eScene_Title:        //���̉�ʂ����j���[�Ȃ�
                nowScene = (BaseScene*) new TitleScene(this, mSceneChangeDirection.get());
                break;//�ȉ���
            case eScene_Tutorial:
                nowScene = (BaseScene*) new TutorialScene(this, mSceneChangeDirection.get());
                break;
            case eScene_Game:
                nowScene = (BaseScene*) new GameScene(this, mSceneChangeDirection.get());
                break;
            case eScene_Result:
                nowScene = (BaseScene*) new ResultScene(this, mSceneChangeDirection.get());
                break;
            case eScene_Debug:
                nowScene = (BaseScene*) new EngineDebugScene(this, mSceneChangeDirection.get());
                break;
            }
            if (mNextScene != eScene_Debug) {
                mSceneChangeDirection->PlayInDirection();
            }

            mNextScene = eScene_None;    //���̃V�[�������N���A
            isChangeDirectioning = false;
            nowScene->Initialize();
        }
    }

    nowScene->Update(); //�V�[���̍X�V

    mSceneChangeDirection->Update();
}

void SceneManager::Draw()
{
    //���݃V�[���̕`�揈�������s
    nowScene->Draw();
}

void SceneManager::Draw2D()
{
    nowScene->Draw2D();

    mSceneChangeDirection->Draw();
}

void SceneManager::DrawImgui()
{
    nowScene->DrawImgui();
}

void SceneManager::DrawParticle()
{
    nowScene->DrawParticle();
}

void SceneManager::ChangeScene(eScene NextScene)
{
    //���̃V�[���ԍ����Z�b�g
    mNextScene = NextScene;
}
