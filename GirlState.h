#include"State.h"
class Girl;
class Sleep:public State<Girl>
{
public:
	static Sleep * get_instence();
	virtual void enter(Girl *entity);
	virtual void excute(Girl *entity);
	virtual void exit(Girl *entity);
	virtual bool hand_message(Girl *entity, Message *msg) const;
private:
	Sleep(){}
	Sleep(const Sleep &){}
	Sleep & operator = (const Sleep &){}
	virtual void transform(Girl *entity);
};

class Eat:public State<Girl>
{
public:
	static Eat * get_instence();
	virtual void enter(Girl *entity);
	virtual void excute(Girl *entity);
	virtual void exit(Girl *entity);
	virtual bool hand_message(Girl *entity, Message *msg) const;
private:
	Eat(){}
	Eat(const Eat &){}
	Eat & operator = (const Eat &){}
	virtual void transform(Girl *entity);
};

class Study:public State<Girl>
{
public:
	static Study * get_instence();
	virtual void enter(Girl *entity);
	virtual void excute(Girl *entity);
	virtual void exit(Girl *entity);
	virtual bool hand_message(Girl *entity, Message *msg) const;
private:
	Study(){}
	Study(const Study &){}
	Study & operator = (const Study &){}
	virtual void transform(Girl *entity);
};

class PlayGames:public State<Girl>
{
public:
	static PlayGames * get_instence();
	virtual void enter(Girl *entity);
	virtual void excute(Girl *entity);
	virtual void exit(Girl *entity);
	virtual bool hand_message(Girl *entity, Message *msg) const;
private:
	PlayGames(){}
	PlayGames(const PlayGames &){}
	PlayGames & operator = (const PlayGames &){}
	virtual void transform(Girl *entity);
};

class VisitWashroom:public State<Girl>
{
public:
	static VisitWashroom * get_instence();
	virtual void enter(Girl *entity);
	virtual void excute(Girl *entity);
	virtual void exit(Girl *entity){};
	virtual bool hand_message(Girl *entity, Message *msg) const;
private:
	VisitWashroom(){}
	VisitWashroom(const VisitWashroom &){}
	VisitWashroom & operator = (const VisitWashroom &){}
	virtual void transform(Girl *entity);
};

class GirlsGlobalState:public State<Girl>
{
public:
	static GirlsGlobalState * get_instence();
	virtual void enter(Girl *entity){};
	virtual void excute(Girl *entity);
	virtual void exit(Girl *entity){};
	virtual bool hand_message(Girl *entity, Message *msg) const{return false;};
private:
	GirlsGlobalState(){}
	GirlsGlobalState(const GirlsGlobalState &){}
	GirlsGlobalState & operator = (const GirlsGlobalState &){}
	virtual void transform(Girl *entity){};
};