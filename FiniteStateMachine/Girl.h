#include"GameEntity.h"
#include"StateMachine.h"
#include"GirlState.h"
#include<string>
using std::string;
static const int MAX_TIRED_LEVEL = 120;
static const int MAX_HUNGRY_LEVEL = 40;
enum MAX_PEE_LEVEL
{
	MAX_PEE_LEVEL_DAY = 15,
	MAX_PEE_LEVEL_NIGHT = 85
};
static const int MAX_STUDY_TIME = 30;
static const int MAX_PLAY_TIME = 20;

class Girl:public GameEntity
{
public:
	string name;
	enum Handlable_Msg
	{
		GO_TO_STUDY,
		HAVE_A_REST,
	};
private:
	StateMachine<Girl>	FSM;
	int	tired_level;
	int hungry_level;
	int pee_level;
	MAX_PEE_LEVEL max_pee;
	int play_time;
	int study_time;
public:
	Girl(string _name = string("unknown"));
	virtual bool handle_message(Message *msg);
	void change_pee_model(MAX_PEE_LEVEL pee_model){max_pee = pee_model;}
	void being_tired(){++tired_level;}
	void get_rest(){--tired_level;if(tired_level < 0){tired_level = 0;}}
	bool is_tired(){return tired_level >= MAX_TIRED_LEVEL;}
	bool is_rested(){return tired_level <= 0;}
	void being_hungry(){++hungry_level;}
	void get_full(){hungry_level = 0;}
	bool is_hungryed(){return hungry_level >= MAX_HUNGRY_LEVEL;}
	void being_pee(){++pee_level;}
	bool is_have_to_pee(){return pee_level >= max_pee;}
	void get_pee(){pee_level = 0;}
	void being_study(){++study_time;}
	void stop_study(){study_time = 0;}
	bool is_just_start_study(){return study_time == 0;}
	bool is_study_enough(){return study_time >= MAX_STUDY_TIME;}
	void being_play(){++play_time;}
	void stop_play(){play_time = 0;}
	bool is_just_start_play(){return play_time == 0;}
	bool is_paly_enough(){return play_time >= MAX_PLAY_TIME;}
	StateMachine<Girl>* get_FSM() {return &FSM;}
	virtual void update();
};