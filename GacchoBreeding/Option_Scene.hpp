//シーン関数
void startScene(MC& mc);
void mainScene(MC& mc);
void endScene(MC& mc);
void logoScene1(MC& mc);
void logoScene2(MC& mc);

//シーンID
enum :size_t {
	START_SCENE,
	MAIN_SCENE,
	END_SCENE,
	LOGO_SCENE1,
	LOGO_SCENE2,
};

//シーン読み込み
inline void sceneInit(MC& mc)
{
	mc.AddScene(START_SCENE, startScene);
	mc.AddScene(MAIN_SCENE, mainScene);
	mc.AddScene(END_SCENE, endScene);
	mc.AddScene(LOGO_SCENE1, logoScene1);
	mc.AddScene(LOGO_SCENE2, logoScene2);
}