
//���[���h���W�e�N�X�`��

//�J�������_���W�X�^ b0
cbuffer cbuff0 : register(b0)
{
    float3 eyePos;
    float3 cameraDir;
}

struct DirectionalLight
{
    float4 lightDir;
    uint isActive;
    uint isUseSpecular;
};

cbuffer cbuff1 : register(b1)
{
    DirectionalLight lightStatus[4];
}


struct VSOutput
{
    float4 svpos : SV_POSITION; //�V�X�e���p���_���W
    float2 uv : TEXCOORD; //uv�l
};