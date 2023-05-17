#include "GameScene.h"

GameScene::GameScene(ISceneChanger *changer) : BaseScene(changer) {

	UINT testTex = TexManager::LoadTexture("Resources/asp3.png");

	testobject = std::make_shared<Object3d>();
	testobject.reset(NY_Object3DManager::Get()->CreateModel_Box(50.f, 10.f, 10.f, testTex));

	testobject->SetAffineParam(RVector3(1, 1, 1), RVector3(0, 0, 0), RVector3(0, 0, 0));

	testsp.Create(testTex);
}

GameScene::~GameScene()
{
	if (testobject) {
		std::cout << "Object deleted" << endl;
	}
}

//初期化
void GameScene::Initialize() {
	gmgr.Init();
}

void GameScene::Finalize()
{
}

//更新
void GameScene::Update() {
	if (Input::Get()->isKeyTrigger(DIK_1)) {
		mSceneChanger->ChangeScene(eScene_Title);
	}

	if (Input::Get()->isKeyTrigger(DIK_2)) {
		mSceneChanger->ChangeScene(eScene_Result);
	}

	gmgr.Update();
}

//描画
void GameScene::Draw() {
	//testobject->DrawObject();

	gmgr.Draw();
}

void GameScene::Draw2D()
{
	testsp.DrawSprite(640, 360);
	//testsp.Draw();

	gmgr.UIDraw();
}

void GameScene::DrawImgui()
{
}
