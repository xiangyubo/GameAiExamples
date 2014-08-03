#include"Girl.h"
Girl::Girl(string _name):FSM(*this),
						 name(_name),
						 tired_level(85),
						 hungry_level(0),
						 pee_level(20),
						 max_pee(MAX_PEE_LEVEL_NIGHT),
						 study_time(0),
						 play_time(0)
{
	FSM.InitState(Sleep::get_instence(), PlayGames::get_instence(), GirlsGlobalState::get_instence());
}

void Girl::update()
{
	FSM.excute();
}

bool Girl::handle_message(Message *msg)
{
	return FSM.get_curent_state()->hand_message(this, msg);
}