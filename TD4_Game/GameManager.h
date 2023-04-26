#pragma once

#include <vector>
#include <memory>
#include <array>
#include <NY_Object3dMgr.h>

#include "Head.h"
#include "ProtoPlayer.h"

//�Q�[���t���[�Ǘ��N���X
class GameManager
{
public:

	GameManager();
	~GameManager();

	void Init();

	void Update();

	void Draw();

	void UIDraw();

	void Finalize();

	//�X�|�[���Ǘ��֐�

	//����X�|�[��
	void FirstSpawn();
	//�Q�[�����X�|�[���Ǘ�
	void SpawnManagement();




private:
	//�����̓A���t�@�ŃN���X��������

	/// �X�|�[���Ǘ�

	Head* HeadSpawn();
	
	//���R���e�i
	std::vector<std::shared_ptr<Head>> heads;

	//�\���ő吔
	const int HEAD_DISPLAY_MAX = 5;
	//�C�[�W���O�p���W
	std::array<RVector3, 5> easepos;


	/// �X�R�A




	/// �^�C��




	/// �Q�[���V�[��




	//���̑�
	std::shared_ptr<Object3d> groundObject;

	UINT groundTex;

};
