inline void textureOption(MC& mc, Control& ct)
{
	for (size_t i = 0; i < control_pet_max; ++i) {
		if (ct.petLive(i) == BORN_STATUS) {
			mc.texture_main_data_render[CHO_TEXTURE].draw(Pos4(ct.petPos(i)));
		}
	}
}

//�J�n���
void startScene(MC& mc)
{
	//�Z�[�u�l�[��
	const char* const control_file_name = u8"gb.as";
	//�T�u�Ǘ�
	Control ct = asReadControl(control_file_name);
	ct.timeUpdate().timeEvent().fieldSet(mc.windowSize());


	while (mc.isLoop() && AsLoop())
	{
		//�����̓���
		ct.randMove(6);
		//�`��
		textureOption(mc, ct);
	}
	mc.loopEnd();
	ct.timeSet();
	//�Z�[�u�f�[�^�ۑ�
	asWriteControl(control_file_name, ct);
}

//���C�����
void mainScene(MC& mc)
{

	mc.texture(GAHAKU2_TEXUI);

	//���߃��C���[
	if (mc.touchTex(GAHAKU2_TEXUI)) mc.scene(LOGO_SCENE1);
}

//�I�����
void endScene(MC& mc)
{
	//mc.texture(GAHAKU_TEXUI);
}

//�^�C�g�����S1
void logoScene1(MC& mc)
{
	mc.logoTex(GAHAKU_TEXTURE, 1000, 2000, 3000, START_SCENE);
	if (mc.isUp0()) mc.scene(START_SCENE);
}

void logoScene2(MC& mc)
{
	//mc.logoTex(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
}