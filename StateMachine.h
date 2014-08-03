#include"State.h"
#include<cassert>
template<typename Entity_type>
class StateMachine
{
private:
	Entity_type &entity;
	State<Entity_type>	*cur_state;
	State<Entity_type>	*pre_state;
	State<Entity_type>	*glo_state;
public:
	StateMachine(Entity_type &_entity):	entity(_entity),
										cur_state(nullptr),
										pre_state(nullptr),
										glo_state(nullptr)
	{}

	void InitState(State<Entity_type> *_cur, State<Entity_type> *_pre, State<Entity_type> *_glo)
	{
		cur_state = _cur;
		pre_state = _pre;
		glo_state = _glo;
	}

	void excute()
	{
		assert(cur_state != nullptr);
		cur_state->excute(&entity);
		assert(glo_state != nullptr);
		glo_state->excute(&entity);
	}

	void change_state(State<Entity_type> *state)
	{
		assert(cur_state != nullptr);
		cur_state->exit(&entity);
		pre_state = cur_state;
		cur_state = state;
		assert(state != nullptr);
		cur_state->enter(&entity);
	}	

	void recover_pre_state()
	{
		change_state(pre_state);
	}

	State<Entity_type> * get_curent_state() const
	{
		return cur_state;
	}

	State<Entity_type> * get_global_state() const
	{
		return glo_state;
	}

	State<Entity_type> * get_previous_state() const
	{
		return pre_state;
	}
};