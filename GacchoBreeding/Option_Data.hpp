//LIVEステータスID
enum :uint8_t {
	//生まれていない(生成無し)
	EMPTY_STATUS,
	//生まれる場面
	BORN_STATUS,
	//生きている場面
	LIVE_STATUS,
	//死ぬ場面
	DEATH_STATUS,
};

//ペットの名前上限
constexpr size_t pet_string_max = 32;
using PetString = char[pet_string_max];

struct Pet
{
	Pos2 pos;
	uint8_t hp;
	uint8_t water;
	uint8_t live_status = EMPTY_STATUS;
	PetString name = {};
};

//ペットの生成上限
constexpr size_t control_pet_max = 256;
using PetControl = Pet[control_pet_max];

class Control
{
public:
	
private:
	//ペットの生成数
	PetControl pet = {};
	//時間
	int64_t now_time = 0;
	//前回の時間
	int64_t past_time = 0;
};

Control asReadControl(const char* const file_name)
{
	Control ct = {};
	asRead(file_name, &ct, sizeof(ct), 1);
	return ct;
}

inline int32_t asWriteControl(const char* const file_name, Control& add_control)
{
	return asWrite(file_name, &add_control, sizeof(add_control), 1);
}