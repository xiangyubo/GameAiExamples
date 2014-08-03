#include"Girl.h"
#include"Message.h"
#include"MessageType.h"
#include<iostream>
#include <ctime>
using std::cout;
using std::endl;
Sleep * Sleep::get_instence()
{
	static Sleep instence;
	return &instence;
}

void Sleep::enter(Girl *entity)
{
	if(entity->is_tired() == true)
	{
		cout<<entity->name<<"：累死我了，准备睡觉觉哒~"<<endl;
		entity->change_pee_model(MAX_PEE_LEVEL_NIGHT);
	}
	else
	{
		cout<<entity->name<<"：我可爱的床，我再也不要离开你了~"<<endl;
	}
}

void Sleep::excute(Girl *entity)
{
	entity->get_rest();
	cout<<entity->name<<"：z...z...Z..."<<endl;
	transform(entity);
}

void Sleep::transform(Girl *entity)
{
	if(entity->is_rested() == true)
	{
		if(rand() % 100 <= 30)
		{
			entity->get_FSM()->change_state(PlayGames::get_instence());
		}
		else
		{
			entity->get_FSM()->change_state(Study::get_instence());
		}
		entity->change_pee_model(MAX_PEE_LEVEL_DAY);
	}
}

void Sleep::exit(Girl *entity)
{
	if(entity->is_rested() == true)
	{
		cout<<entity->name<<"：晓得咯，起来哒..."<<endl;
	}
	else
	{
		cout<<entity->name<<"：好烦啊...我还不想起来..."<<endl;
	}
}

bool Sleep::hand_message(Girl *entity, Message *msg) const
{
	cout<<"老娘我正在睡觉！别来烦我！！"<<endl;
	return false;
}

Eat * Eat::get_instence()
{
	static Eat instence;
	return &instence;
}

void Eat::enter(Girl *entity)
{
	cout<<entity->name<<"：我饿了..."<<endl;
}

void Eat::excute(Girl *entity)
{
	entity->get_full();
	cout<<entity->name<<"：我要吃这个，我要吃那个，我要吃这个，我要吃那个，哎呀，吃不过来啦~"<<endl;
	transform(entity);
}

void Eat::transform(Girl *entity)
{
	entity->get_FSM()->recover_pre_state();
}

void Eat::exit(Girl *entity)
{
	cout<<entity->name<<"：吃饱了~好满足的感觉~~"<<endl;
}

bool Eat::hand_message(Girl *entity, Message *msg) const
{
	if(msg->getMsgId() == GO_TO_STUDY)
	{
		cout<<"老娘我正在吃饭，你叫我去学习？！"<<endl;
	}
	else if(msg->getMsgId() == HAVE_A_REST)
	{
		cout<<"吃饭也算休息啦~~"<<endl;
	}
	return true;
}

Study * Study::get_instence()
{
	static Study instence;
	return &instence;
}

void Study::enter(Girl *entity)
{
	if(entity->is_just_start_study() == true)
	{
		cout<<entity->name<<"：别老说我每天都在玩儿，我也要看书滴！"<<endl;
	}
	else
	{
		cout<<entity->name<<"：都说我会继续看书的，还不信我...切..."<<endl;
	}
}

void Study::excute(Girl *entity)
{
	entity->being_tired();
	entity->being_study();
	entity->being_hungry();
	cout<<entity->name<<"：good good study, day day up"<<endl;
	transform(entity);
}

void Study::transform(Girl *entity)
{
	if(entity->is_hungryed() == true)
	{
		entity->get_FSM()->change_state(Eat::get_instence());
	}
	else if(entity->is_tired() == true)
	{
		entity->get_FSM()->change_state(Sleep::get_instence());
	}
	else if(entity->is_study_enough() == true)
	{
		entity->get_FSM()->change_state(PlayGames::get_instence());
	}
}

void Study::exit(Girl *entity)
{
	if(entity->is_study_enough() == true)
	{
		cout<<entity->name<<"：看这么久，好累呀...不想看了..."<<endl;
		entity->stop_study();
	}
	else
	{
		cout<<entity->name<<"：我还是爱学习的...还没看完呢，马上回来接着看"<<endl;
	}
}

bool Study::hand_message(Girl *entity, Message *msg) const
{
	if(msg->getMsgId() == GO_TO_STUDY)
	{
		cout<<"你看不见我正在学习吗？！"<<endl;
	}
	else if(msg->getMsgId() == HAVE_A_REST)
	{
		cout<<"好哎好哎，我去玩儿了~~"<<endl;
		entity->get_FSM()->change_state(PlayGames::get_instence());
	}
	return true;
}

PlayGames * PlayGames::get_instence()
{
	static PlayGames instence;
	return &instence;
}

void PlayGames::enter(Girl *entity)
{
	if(entity->is_just_start_play() == true)
	{
		cout<<entity->name<<"：好吧，我承认我还是更喜欢玩儿游戏~~"<<endl;
	}
	else
	{
		cout<<entity->name<<"：我刚忘存档了，我去存个档~~"<<endl;
	}
}

void PlayGames::excute(Girl *entity)
{
	entity->being_play();
	entity->being_tired();
	entity->being_hungry();
	cout<<entity->name<<"：在玩儿游戏呢！别来烦我"<<endl;
	transform(entity);
}

void PlayGames::transform(Girl *entity)
{
	if(entity->is_hungryed() == true)
	{
		entity->get_FSM()->change_state(Eat::get_instence());
	}
	else if(entity->is_tired() == true)
	{
		entity->get_FSM()->change_state(Sleep::get_instence());
	}
	else  if(entity->is_paly_enough() == true)
	{
		entity->get_FSM()->change_state(Study::get_instence());
	}
}

void PlayGames::exit(Girl *entity)
{
	if(entity->is_paly_enough() == true)
	{
		entity->stop_play();
		cout<<entity->name<<"：其实我还想再玩儿会儿的...不要让我离开我的电脑啊~~"<<endl;
	}
}

bool PlayGames::hand_message(Girl *entity, Message *msg) const
{
	if(msg->getMsgId() == GO_TO_STUDY)
	{
		if(rand() % 100 <= 40)
		{
			cout<<"好吧，偶尔还是听你的...我去看书咯..."<<endl;
			entity->get_FSM()->change_state(Study::get_instence());
		}
		else
		{
			cout<<"我正玩儿得高兴呢！不去不去！！"<<endl;
		}
		
	}
	else if(msg->getMsgId() == HAVE_A_REST)
	{
		cout<<"对于玩儿我还是很自觉的啦~~"<<endl;
	}
	return true;
}

VisitWashroom * VisitWashroom::get_instence()
{
	static VisitWashroom instence;
	return &instence;
}

void VisitWashroom::enter(Girl *entity)
{
	cout<<entity->name<<"：看什么！人家要去厕所啊！！"<<endl;
}

void VisitWashroom::excute(Girl *entity)
{
	entity->get_pee();
	transform(entity);
}

void VisitWashroom::transform(Girl *entity)
{
	entity->get_FSM()->recover_pre_state();
}

bool VisitWashroom::hand_message(Girl *entity, Message *msg) const
{
	return false;
}

GirlsGlobalState * GirlsGlobalState::get_instence()
{
	static GirlsGlobalState instence;
	return &instence;
}

void GirlsGlobalState::excute(Girl *entity)
{
	entity->being_pee();
	if(entity->is_have_to_pee() == true)
	{
		entity->get_FSM()->change_state(VisitWashroom::get_instence());
	}
}