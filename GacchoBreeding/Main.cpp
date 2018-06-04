#define ASLIB_INCLUDE_DL
#include "Option.hpp"

inline void textureOption(MC& mc, Control& ct)
{
	for (size_t i = 0; i < control_pet_max; ++i) {
		if (ct.petLive(i) == BORN_STATUS) {
			mc.texture_main_data_render[CHO_TEXTURE].draw(Pos4(ct.petPos(i)));
		}
	}
}

//開始画面
void startScene(MC& mc)
{
	//セーブネーム
	const char* const control_file_name = u8"gb.as";

	Control ct = asReadControl(control_file_name);
	ct.timeUpdate().timeEvent().fieldSet(mc.windowSize());
	while (mc.isLoop() && AsLoop())
	{
		ct.randMove(6);
		textureOption(mc, ct);
	}
	mc.loopEnd();
	ct.timeSet();
	//セーブデータ保存
	asWriteControl(control_file_name, ct);
}

//メイン画面
void mainScene(MC& mc)
{

	mc.texture(GAHAKU2_TEXUI);

	//命令レイヤー
	if (mc.touchTex(GAHAKU2_TEXUI)) mc.scene(LOGO_SCENE1);
}

//終了画面
void endScene(MC& mc)
{
	mc.texture(GAHAKU_TEXUI);
}

//タイトルロゴ1
void logoScene1(MC& mc)
{
	mc.logoTex(GAHAKU_TEXTURE, 1000, 2000, 3000, START_SCENE);
	//if (mc.isTouch()) mc.sceneSelect(START_SCENE);
}

void logoScene2(MC& mc)
{
	mc.logoTex(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
}

//メイン関数
int32_t AsMain()
{
	//管理クラスの宣言
	MC mc(u8"GacchoBreeding", asSP_FullScreenSize({ 1920,1080 }), BG_COLOR);

	//読み込み
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//初期シーン
	mc.scene(LOGO_SCENE1);

	//メインループ
	while (mc.isLoop()) mc.scenePlay();
	return 0;
}

