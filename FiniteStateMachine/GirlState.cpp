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
		cout<<entity->name<<"���������ˣ�׼��˯������~"<<endl;
		entity->change_pee_model(MAX_PEE_LEVEL_NIGHT);
	}
	else
	{
		cout<<entity->name<<"���ҿɰ��Ĵ�������Ҳ��Ҫ�뿪����~"<<endl;
	}
}

void Sleep::excute(Girl *entity)
{
	entity->get_rest();
	cout<<entity->name<<"��z...z...Z..."<<endl;
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
		cout<<entity->name<<"�����ÿ���������..."<<endl;
	}
	else
	{
		cout<<entity->name<<"���÷���...�һ���������..."<<endl;
	}
}

bool Sleep::hand_message(Girl *entity, Message *msg) const
{
	cout<<"����������˯�����������ң���"<<endl;
	return false;
}

Eat * Eat::get_instence()
{
	static Eat instence;
	return &instence;
}

void Eat::enter(Girl *entity)
{
	cout<<entity->name<<"���Ҷ���..."<<endl;
}

void Eat::excute(Girl *entity)
{
	entity->get_full();
	cout<<entity->name<<"����Ҫ���������Ҫ���Ǹ�����Ҫ���������Ҫ���Ǹ�����ѽ���Բ�������~"<<endl;
	transform(entity);
}

void Eat::transform(Girl *entity)
{
	entity->get_FSM()->recover_pre_state();
}

void Eat::exit(Girl *entity)
{
	cout<<entity->name<<"���Ա���~������ĸо�~~"<<endl;
}

bool Eat::hand_message(Girl *entity, Message *msg) const
{
	if(msg->getMsgId() == GO_TO_STUDY)
	{
		cout<<"���������ڳԷ��������ȥѧϰ����"<<endl;
	}
	else if(msg->getMsgId() == HAVE_A_REST)
	{
		cout<<"�Է�Ҳ����Ϣ��~~"<<endl;
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
		cout<<entity->name<<"������˵��ÿ�춼���������ҲҪ����Σ�"<<endl;
	}
	else
	{
		cout<<entity->name<<"����˵�һ��������ģ���������...��..."<<endl;
	}
}

void Study::excute(Girl *entity)
{
	entity->being_tired();
	entity->being_study();
	entity->being_hungry();
	cout<<entity->name<<"��good good study, day day up"<<endl;
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
		cout<<entity->name<<"������ô�ã�����ѽ...���뿴��..."<<endl;
		entity->stop_study();
	}
	else
	{
		cout<<entity->name<<"���һ��ǰ�ѧϰ��...��û�����أ����ϻ������ſ�"<<endl;
	}
}

bool Study::hand_message(Girl *entity, Message *msg) const
{
	if(msg->getMsgId() == GO_TO_STUDY)
	{
		cout<<"�㿴����������ѧϰ�𣿣�"<<endl;
	}
	else if(msg->getMsgId() == HAVE_A_REST)
	{
		cout<<"�ð��ð�����ȥ�����~~"<<endl;
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
		cout<<entity->name<<"���ðɣ��ҳ����һ��Ǹ�ϲ�������Ϸ~~"<<endl;
	}
	else
	{
		cout<<entity->name<<"���Ҹ����浵�ˣ���ȥ�����~~"<<endl;
	}
}

void PlayGames::excute(Girl *entity)
{
	entity->being_play();
	entity->being_tired();
	entity->being_hungry();
	cout<<entity->name<<"���������Ϸ�أ���������"<<endl;
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
		cout<<entity->name<<"����ʵ�һ�������������...��Ҫ�����뿪�ҵĵ��԰�~~"<<endl;
	}
}

bool PlayGames::hand_message(Girl *entity, Message *msg) const
{
	if(msg->getMsgId() == GO_TO_STUDY)
	{
		if(rand() % 100 <= 40)
		{
			cout<<"�ðɣ�ż�����������...��ȥ���鿩..."<<endl;
			entity->get_FSM()->change_state(Study::get_instence());
		}
		else
		{
			cout<<"��������ø����أ���ȥ��ȥ����"<<endl;
		}
		
	}
	else if(msg->getMsgId() == HAVE_A_REST)
	{
		cout<<"��������һ��Ǻ��Ծ�����~~"<<endl;
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
	cout<<entity->name<<"����ʲô���˼�Ҫȥ����������"<<endl;
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