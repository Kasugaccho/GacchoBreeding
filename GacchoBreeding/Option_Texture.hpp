//�摜ID
enum :size_t {
	GAHAKU_TEXTURE,
	KURO_TEXTURE
};

//�摜�ǂݍ���
inline void textureInit(MC& mc)
{
	mc.textureAdd("gahaku.png");
	mc.textureAdd("kuro.png");
}