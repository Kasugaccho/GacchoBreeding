#include "Option.hpp"

//�J�n���
void startScene(MC& mc)
{
	const char* const control_file_name = u8"gb.as";

	Control ct = asReadControl(control_file_name);
	while (mc.isLoop() && AsLoop())
	{

	}
	mc.loopEnd();
	asWriteControl(control_file_name, ct);
}

//���C�����
void mainScene(MC& mc)
{

	mc.draw4(GAHAKU2_TEXUI);

	//���߃��C���[
	if (mc.isTexUI_Touch(GAHAKU2_TEXUI)) mc.sceneSelect(LOGO_SCENE1);
}

//�I�����
void endScene(MC& mc)
{
	mc.draw4(GAHAKU_TEXUI);
}

//�^�C�g�����S1
void logoScene1(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, START_SCENE);
	//if (mc.isTouch()) mc.sceneSelect(START_SCENE);
}

void logoScene2(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
}

//���C���֐�
int32_t AsMain()
{
	//�Ǘ��N���X
	MC mc(u8"GacchoBreeding", asWindowSize({ 960,540 }), BG_COLOR);

	//�ǂݍ���
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//�����V�[��
	mc.sceneSelect(LOGO_SCENE1);

	//���C�����[�v
	while (mc.isLoop()) mc.scenePlay();

	//�I������
	asEnd();
	return 0;
}

//----------------------------------------------------------------------------------------------------
#if defined(ASLIB_INCLUDE_C)
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) { return int(AsMain()); }
#elif defined(ASLIB_INCLUDE_CPP)
void Main() { AsMain(); return; }
#else
int main() { return int(AsMain()); }
#endif