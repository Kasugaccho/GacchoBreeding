//LIVE�X�e�[�^�XID
enum :uint8_t {
	//���܂�Ă��Ȃ�(��������)
	EMPTY_STATUS,
	//���܂����
	BORN_STATUS,
	//�����Ă�����
	LIVE_STATUS,
	//�H����
	EAT_STATUS,
	//���ʏ��
	DEATH_STATUS,
};

//�y�b�g�̖��O���
constexpr size_t pet_string_max = 32;
using PetString = char[pet_string_max];

const int64_t START_TIME_64 = int64_t(std::time(nullptr));

struct Pet
{
	//�ʒu
	PosA4 pos = { 0,0,120,120 };
	uint8_t hp=0;
	uint8_t water = 0;
	uint8_t live_status = EMPTY_STATUS;
	PetString name = {};
};

//�y�b�g�̐������
constexpr size_t control_pet_max = 256;
constexpr size_t control_pet_var = control_pet_max - size_t(1);
using PetControl = Pet[control_pet_max];

class Control
{
public:
	Control& timeUpdate();
	Control& timeEvent();
	Control& bornEvent(const size_t);
	Control& fieldSet(const Pos2& add_pos) { this->field = add_pos; return *this; };
	Control& timeSet() { this->now_time = int64_t(std::time(nullptr)); return *this; };
	Control& randMove(const uint32_t move);

	//�o��
	Pos2 Field() const { return this->field; };
	int64_t subTime() const { return this->sub_time; };
	int64_t pastTime() const { return this->past_time; };
	int64_t nowTime() const { return this->now_time; };
	Pet petShow(const size_t pet_id) const { return pet[pet_id]; };
	uint8_t petLive(const size_t pet_id) const { return pet[pet_id].live_status; };
	PosA4 petPos(const size_t pet_id) const { return pet[pet_id].pos; };

private:
	//�y�b�g�̐�����
	PetControl pet = {};
	//����
	int64_t now_time = 0;
	//�O��̎���
	int64_t past_time = 0;
	//��
	int64_t sub_time = 0;
	//�t�B�[���h�T�C�Y
	Pos2 field = { 1000,1000 };
};

inline Control& Control::randMove(const uint32_t move)
{
	for (size_t i = 0; i < control_pet_max; ++i) {
		pet[i].pos.randPlus(move);
	}
	return *this;
}

inline Control& Control::bornEvent(const size_t born_id)
{
	pet[born_id].live_status = BORN_STATUS;
	pet[born_id].pos.rand(this->field);
	return *this;
}

inline Control& Control::timeEvent()
{
	const size_t add_born = size_t(rand32(int32_t(this->sub_time >> int64_t(1)) & INT32_MAX));
	for (size_t i = 0; i < add_born; ++i) {
		for (size_t j = 0; j < control_pet_max; ++j) {
			if (pet[j].live_status == EMPTY_STATUS) {
				this->bornEvent(j);
				break;
			}
			if (j == control_pet_var) {
				i = add_born;
				break;
			}
		}
	}
	this->sub_time = 0;
	return *this;
}

inline Control& Control::timeUpdate()
{
	const int64_t get_time = int64_t(std::time(nullptr));
	if (this->now_time > get_time) return *this;

	if (this->now_time == 0) this->now_time = get_time;
	this->sub_time = get_time - this->now_time;
	this->past_time = this->now_time;
	this->now_time = get_time;
	return *this;
}

//�ǂݍ���
Control asReadControl(const char* const file_name)
{
	Control ct = {};
	ct.timeSet();
	asRead(file_name, &ct, sizeof(ct), 1);
	return ct;
}

//��������
inline int32_t asWriteControl(const char* const file_name, Control& add_control)
{
	return asWrite(file_name, &add_control, sizeof(add_control), 1);
}