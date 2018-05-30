//LIVE�X�e�[�^�XID
enum :uint8_t {
	//���܂�Ă��Ȃ�(��������)
	EMPTY_STATUS,
	//���܂����
	BORN_STATUS,
	//�����Ă�����
	LIVE_STATUS,
	//���ʏ��
	DEATH_STATUS,
};

//�y�b�g�̖��O���
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

//�y�b�g�̐������
constexpr size_t control_pet_max = 256;
using PetControl = Pet[control_pet_max];

class Control
{
public:
	
private:
	//�y�b�g�̐�����
	PetControl pet = {};
	//����
	int64_t now_time = 0;
	//�O��̎���
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