#include "LIT_OBJHeader.hlsli"

//	2�p�X�ڏo�͗p�V�F�[�_�[�i�\��j
//	�����_�ł́AGBuffer�摜���o�͂��邾��

//�A���x�h�e�N�X�`��
Texture2D<float4> albedoTex : register(t0);
//�@���e�N�X�`��
Texture2D<float4> normalTex : register(t1);
//���[���h���W�e�N�X�`��
Texture2D<float4> worldTex  : register(t2);
//�[�x���e�N�X�`��
Texture2D<float4> LdepthTex : register(t3);

Texture2D<float4> metalTex : register(t4);

Texture2D<float4> specularTex : register(t5);

Texture2D<float4> roughTex : register(t6);
//�T���v���[�͕ύX�Ȃ�
SamplerState smp : register(s0);

//�s�N�Z����z�l�����C�g��Ԃ̍��W�ɕϊ�����

//���s�����̌v�Z
float3 DirectionalShadeing(float4 lStatus, float3 normal, float3 worldPos, float3 color, uint useSpecular)
{
    float3 result;

    float t = max(0.0f, dot(normal, lStatus.xyz) * -1.0f);
    result = color * t;
    
    //�X�y�L����
    if (useSpecular)
    {
        float3 toEye = normalize(eyePos - worldPos);
        float3 r = reflect(lStatus.xyz, normal);
        t = max(0.0f, dot(toEye, r));
        t = pow(t, 5.0f);
        result += color * t;
    }
    
    return result * lStatus.w;
}

//ue4���g�U����
float3 BRDF(float NdotL,float NdotV,float metal,float3 baseColor)
{
    if (NdotL < 0 || NdotV < 0)
    {
        return float3(0, 0, 0);
    }
    
    float diffref = 1.0f / 3.14f;
    
    float3 result = diffref * NdotL * baseColor * (1 - metal);
    
    return result;
}

float DistributionGGX(float alpha,float NdotH)
{
    float alpha2 = alpha * alpha;
    float t = NdotH * NdotH * (alpha2 - 1.0f) + 1.0f;
    return alpha2 / (3.14f * t * t);
}



float3 UE4Specular(float NdotL,float NdotV, float NdotH, float LdotH,float rough)
{
    //D��
    float   D = DistributionGGX(rough * rough, NdotH);
    //F��
    float3  F = float3(1, 1, 1);
    //G��
    float   G = 0.1f;
    //m��
    float   m = 4.0f * NdotL * NdotV;
    
    return D * F * G / m;
}


float4 main(VSOutput input) : SV_TARGET
{
    //�A���x�h�����擾
    float4 albedo = albedoTex.Sample(smp, input.uv);
    //�@�����擾
    float3 normal = normalTex.Sample(smp, input.uv).rgb;
    //���[���h���W�擾
    float3 worldPos = worldTex.Sample(smp, input.uv).xyz;
    //�[�x���擾
    float4 depth = LdepthTex.Sample(smp, input.uv);
    //�X�y�L�������x�擾
    float specPower = normalTex.Sample(smp, input.uv).a;
    //�����x
    float metalness = metalTex.Sample(smp, input.uv).x;
    float specular = specularTex.Sample(smp, input.uv).x;
    float roughness = roughTex.Sample(smp, input.uv).x;
    
    //�@�����𕜌�
    normal = (normal * 2.0f) - 1.0f;

    float3 color = float3(1.0f, 1.0f, 1.0);
    
    float4 resultColor = float4(0, 0, 0, albedo.w);
    
    float3 lig = float3(0, 0, 0);
    
    //���s�����̌v�Z����
    //for (int i = 0; i < 4; i++)
    //{
    //    if (lightStatus[i].isActive)
    //    {
    //        float3 l = float3(0, 0, 0);
    //        float3 d = float3(0, 0, 0);
    //        d = DirectionalShadeing(lightStatus[i].lightDir, normal, worldPos, color, lightStatus[i].isUseSpecular);
    //        l = (albedo.xyz * d);
    //        resultColor.xyz += l;
    //    }
    //}
    
    //�g�U���˂��v�Z
    //float3 lig = 0.0f;
    //float t = max(0.0f, dot(normal, lightStatus[0].xyz) * -1.0f);
    //lig = color * t;
    
    ////�X�y�L����
    //float3 toEye = normalize(eyePos - worldPos);
    //float3 r = reflect(lightStatus[0].xyz, normal);
    //t = max(0.0f, dot(toEye, r));
    //t = pow(t, 5.0f);
    //lig += color * t;
    
    //resultColor = albedo;
    //resultColor.xyz *= lig;
    
    float3 camdir = normalize(eyePos - cameraDir);
    
    for (int i = 0; i < 4; i++)
    {
        if (lightStatus[i].isActive)
        {
            //���C�g�ƃJ�����̃n�[�t�x�N�g��
            float3 H = normalize(lightStatus[i].lightDir.xyz + camdir);
            //�e�n�[�t�x�N�g���Ƃ̓���
            float NdotL = dot(normal.xyz, lightStatus[i].lightDir.xyz);
            float NdotV = dot(normal.xyz, camdir);
            float NdotH = dot(normal.xyz, H);
            float LdotH = dot(lightStatus[i].lightDir.xyz, H);
        
            float3 diffuseColor = BRDF(NdotL, NdotV, metalness, albedo.xyz);
            float3 specularColor = UE4Specular(NdotL, NdotV, NdotH, LdotH, roughness);
        
            resultColor.xyz += (diffuseColor + specularColor);
        }
    }

    return resultColor;
}