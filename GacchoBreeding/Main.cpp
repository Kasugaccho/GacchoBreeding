#define ASLIB_INCLUDE_DL
#include "Option.hpp"

//���C���֐�
int32_t AsMain()
{
	//�Ǘ��N���X�̐錾
	MC mc(u8"GacchoBreeding", { 1920,1080 }, BG_COLOR);

	//�ǂݍ���
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//�����V�[��
	mc.scene(LOGO_SCENE1);

	//���C�����[�v
	while (mc.isLoop()) mc.scenePlay();
	return 0;
}

