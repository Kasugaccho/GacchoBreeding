//�摜ID
enum :size_t {
	GAHAKU_TEXTURE,
	KURO_TEXTURE,
	CHO_TEXTURE,
	EBIESA_TEXTURE,
};

//�摜�ǂݍ���
inline void textureInit(MC& mc)
{
	mc.textureAdd("gahaku.png");
	mc.textureAdd("kuro.png");
	mc.textureAdd("ebikari.png");
	mc.textureAdd("ebiesa.png");
}