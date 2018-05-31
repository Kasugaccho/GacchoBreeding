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

	mc.draw4(GAHAKU2_TEXUI);

	//命令レイヤー
	if (mc.isTexUI_Touch(GAHAKU2_TEXUI)) mc.sceneSelect(LOGO_SCENE1);
}

//終了画面
void endScene(MC& mc)
{
	mc.draw4(GAHAKU_TEXUI);
}

//タイトルロゴ1
void logoScene1(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, START_SCENE);
	//if (mc.isTouch()) mc.sceneSelect(START_SCENE);
}

void logoScene2(MC& mc)
{
	mc.drawLogoInOut(GAHAKU_TEXTURE, 1000, 2000, 3000, LOGO_SCENE2);
}

//メイン関数
int32_t AsMain()
{
	//管理クラス
	MC mc(u8"GacchoBreeding", asWindowSize({ 1920,1080 }), BG_COLOR);

	//読み込み
	sceneInit(mc);
	textureInit(mc);
	UI_Init(mc);

	//初期シーン
	mc.sceneSelect(LOGO_SCENE1);

	//メインループ
	while (mc.isLoop()) mc.scenePlay();

	//終了処理
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