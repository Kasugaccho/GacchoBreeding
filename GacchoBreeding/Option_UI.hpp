//�摜UI��ID
enum :size_t {
	GAHAKU_TEXUI,
	GAHAKU2_TEXUI
};

//�摜�ǂݍ���
inline void UI_Init(MC& mc)
{
	mc.textureUI_Add(KURO_TEXTURE, 200, { 200,200,500,500 });
	mc.textureUI_Add(GAHAKU_TEXTURE, 255, { 0,0,200,200 });
}