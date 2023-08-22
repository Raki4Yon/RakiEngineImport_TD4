#include "GraphicManager.h"
#include "Raki_WinAPI.h"

void GraphicManager::Init()
{
	//�e�t�F�[�Y�̏�����
	NY_Object3DManager::Get()->CreateObject3DManager();
	SpriteManager::Get()->CreateSpriteManager(Raki_DX12B::Get()->GetDevice(),
		Raki_DX12B::Get()->GetGCommandList(),
		Raki_WinAPI::window_width,
		Raki_WinAPI::window_height);

	TexManager::InitTexManager();

	myImgui::InitializeImGui(Raki_DX12B::Get()->GetDevice(), Raki_WinAPI::GetHWND());

	//�f�B�t�@�[�h�����_�����O������
	m_deferredRender.Init(RAKI_DX12B_DEV, RAKI_DX12B_CMD);

	//�p�[�e�B�N���`�揉����
	m_particleDrawMgr.Init();
}

void GraphicManager::StartDraw()
{
	//�����_�[�^�[�Q�b�g�N���A�A�`��J�n
	RenderTargetManager::GetInstance()->CrearAndStartDraw();
}

void GraphicManager::StartDeferredDraw()
{
	//GBuffer�`��J�n
	NY_Object3DManager::Get()->SetCommonBeginDrawObject3D();
}

void GraphicManager::EndDefferdDraw()
{
	//GBuffer�`��I��
	NY_Object3DManager::Get()->CloseDrawObject3D();
	//�f�B�t�@�[�h�����_�����O���s�i�V���h�E�}�b�v���g�p�j
	m_deferredRender.Rendering(&NY_Object3DManager::Get()->m_gBuffer, nullptr);
}

void GraphicManager::StartForwardDraw3D()
{
	//�t�H���[�h�����_�����O�̃V�F�[�_�[��p�ӂ���܂ł͂��̊֐��͈Ӗ�����
}

void GraphicManager::StartParticleDraw3D()
{
	//
	m_particleDrawMgr.SetCommonBeginDrawParticle3D();
}

void GraphicManager::StartParticleDraw2D()
{
	//m_particleDrawMgr.SetCommonBeginDrawParticle2D();
}

void GraphicManager::StartSpriteDraw()
{
	SpriteManager::Get()->SetCommonBeginDraw();
}

void GraphicManager::FinishDraw()
{
	RenderTargetManager::GetInstance()->SwapChainBufferFlip();
}

void GraphicManager::GraphicDebugDraw()
{
	m_deferredRender.ShowImGui();
}
