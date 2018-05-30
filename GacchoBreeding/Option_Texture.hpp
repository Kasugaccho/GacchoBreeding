//‰æ‘œID
enum :size_t {
	GAHAKU_TEXTURE,
	KURO_TEXTURE
};

//‰æ‘œ“Ç‚İ‚İ
inline void textureInit(MC& mc)
{
	mc.textureAdd("gahaku.png");
	mc.textureAdd("kuro.png");
}