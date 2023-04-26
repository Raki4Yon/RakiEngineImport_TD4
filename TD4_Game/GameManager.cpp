#include "GameManager.h"

#include "AfroHead.h"

#include <NY_Object3DMgr.h>

GameManager::GameManager()
{
	groundTex = TexManager::LoadTexture("Resources/asp3.png");

	groundObject = std::make_shared<Object3d>();
	groundObject.reset(NY_Object3DManager::Get()->CreateModel_Tile(500.f, 500.f, 10.f, 10.f, groundTex));

	groundObject->SetAffineParam(RVector3(1, 1, 1), RVector3(0, 0, 0), RVector3(0, 0, 0));

}

GameManager::~GameManager()
{
}

void GameManager::Init()
{

	player.Init();

	RVector3 easeOffset(0, 0, 50.f);
	int i = 0;
	for (auto& ep : easepos) {
		ep = easeOffset * float(i);
		i++;
	}

	FirstSpawn();

	//����
	time = 0;

	//�X�R�A
	score = 0;





}

void GameManager::Update()
{
	//�e�N���X�X�V
	for (auto& h : heads) {
		h->Update();
	}

	//�m�[�h��[�̓��ɑ΂��ăA�N�V���������s����
	player.Update(heads[0]);

	//���̐���
	SpawnManagement();

	//���̈ړ�
	if (headEaseFrame < 30) {
		headEaseFrame++;
		float rate = float(headEaseFrame / HEAD_EASE_FRAME);
	}

}

void GameManager::Draw()
{
	NY_Object3DManager::Get()->SetRestartObject3D();

	//��
	for (const auto& h : heads) { h->Draw(); }

	//��
	groundObject->DrawObject();

	NY_Object3DManager::Get()->CloseDrawObject3D();
}

void GameManager::UIDraw()
{
}

void GameManager::Finalize()
{
}

void GameManager::FirstSpawn()
{
	//5��X�|�[���A�ʒu�ݒ�
	for (int i = 0; i < 5; i++) {

		Head* ptr = HeadSpawn();
		
		heads.push_back(std::make_shared<Head>());
		heads[i].reset(ptr);
		heads[i]->Init();
		heads[i]->SetPlayer(&player);
		heads[i]->pos = easepos[i];
	}
}

void GameManager::SpawnManagement()
{
	//���̍폜 => �V�������̐��� => ���̈ړ� => �擪�̗L����

	bool isErasedHead = false;

	//�������E���𒴂�����A�����폜����
	if (heads.begin()->get()->pos.x < -100.f) {
		heads.erase(heads.begin());
		isErasedHead = true;
	}

	//�����폜����Ă�����
	if (isErasedHead) {
		//�V�������̐���
		Head* ptr = HeadSpawn();
		heads.push_back(std::make_shared<Head>());
		heads.back()->Init();
		heads.back()->pos = easepos[4];

		//�����ړ������邽�߂̃C�[�W���O�t���[����������
		headEaseFrame = 0;
	}

	//���̈ړ�������������
	if (headEaseFrame > HEAD_EASE_FRAME) {
		//�擪�̓���L����
		heads[0]->Activate();

	}



}

Head* GameManager::HeadSpawn()
{
	Head* head;

	//�����_���œ��𐶐�
	head = new AfroHead();

	return head;
}
