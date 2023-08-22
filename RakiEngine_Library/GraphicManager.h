#pragma once

#include "NY_Object3DMgr.h"
#include "SpriteManager.h"
#include "RenderTargetManager.h"
#include "DifferrdRenderingMgr.h"
#include "ParticleManager.h"
#include "RTex.h"

//�`�揇���w�肵�ĕ`���������
class GraphicManager
{
public:
	GraphicManager() = default;
	~GraphicManager() = default;

	void Init();

	void StartDraw();

	void StartDeferredDraw();

	void EndDefferdDraw();

	void StartForwardDraw3D();

	void StartParticleDraw3D();

	void StartParticleDraw2D();

	void StartSpriteDraw();

	void FinishDraw();

	void GraphicDebugDraw();

private:

	DiferredRenderingMgr m_deferredRender;

	ParticleDrawManager m_particleDrawMgr;





};

