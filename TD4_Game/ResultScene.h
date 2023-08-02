#pragma once
#pragma once
#include "BaseScene.h"
#include "ISceneChanger.h"
#include "FbxLoader.h"
#include "RankingManager.h"
#include <DirectXMath.h>
#include <cmath>

#include <Raki_Input.h>
#include <NY_Object3DMgr.h>
#include <Sprite.h>

const int scrollCountMax = 180;

class ResultScene : public BaseScene
{
public:
	ResultScene(ISceneChanger* changer, SceneChangeDirection* scd);
	~ResultScene() override;

    void Initialize() override;    //�������������I�[�o�[���C�h�B
    void Finalize() override;   //�I���������I�[�o�[���C�h�B
    void Update() override;        //�X�V�������I�[�o�[���C�h�B
    void Draw() override;          //�`�揈�����I�[�o�[���C�h�B
    void Draw2D() override;
    void DrawImgui() override;
    const int& SelectRank();

    void SceneScroll();
    void Animation();

    Sprite spriteReview;
    Sprite spriteScore;
    Sprite spriteReviewTex;
    Sprite spriteScoreTex;
    Sprite spriteRank;

    std::shared_ptr<Object3d> resultPlayer;

    const int animationCountMax = 600;
    int animationCount = 0;
    bool starIsDraw;
    bool starSpriteIsDraw;
    bool scoreTexIsDraw;
    bool scoreTexSpriteIsDraw;
    bool rankIsDraw;

    enum Rank{
        D,C,B,A,S
    };

    //�����I�ȃX�R�A
    float totalScore;
    //�����I�ȃ��r���[
    float totalReview;
    //���΂�����
    int handleNum;

    int scrollCount = 0;

    bool isScroll = false;

    XMFLOAT2 starPos;
    XMFLOAT2 reviewSpritePos;
    XMFLOAT2 scoreSpritePos;
    XMFLOAT2 rankPos;
    XMFLOAT2 HANDLE_POS = { -638,450 };
    XMFLOAT2 TOTALREVIEW_POS = { -638,64 };

    //�J�������̈ʒu
    float SCORE_POS_X = -385.0f;
    float SCORE_POS_X2 = -353.0f;
    float SCORE_POS_X3 = -321.0f;
    const float SCORE_POS_Y = 360.0f;

    //�����L���O�V�X�e��
    RankingManager rankingSystem;
};