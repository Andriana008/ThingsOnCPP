/*7. Написати програму TRAIN з використанням шаблону ADAPTER. Отож, у нас є ноутбук. Припустимо вас відправили у відрядження на міжнародну олімпіаду у м.Київ. Ви сідаєте у поїзд. І тут у вас виникає бажання повторити ООАП(Шаблони проектування) і включивши ноутбук у вас сідає батарея. На скільки ви знаєте Укрзаліниця оновлює свій парк вагонів, але це робиться дуже повільно. В одному з вагонів у нас все сучасне, тобто новий вагон, тому NewVagonSystem має метод MatchSocket, яким ми просто можемо скористатися(заряджаєм ноутбук). В іншому вагоні у нас проблемки(вагон старий і старі радянські розетки є вузькі, тому штекер від ноутбука не підходить), тобто OldVagonSytem має тільки метод ThinSocket. Нажаль замінити розетки у вагоні ми не можемо. Натомість, ми можемо взяти адаптер, який надає можливість користуватися тією ж функціональністю споживання електричного струму, але із старої системи.
*/
/*
#include <iostream>

using namespace std;

class NewVagonSystem//target
{
public:
    virtual void MatchSocket()
    {
        cout<<"New system";
    }
};

class OldVagonSystem//adaptee
{
public:
    virtual void ThinSocket()
    {
        cout<<"Old system";
    }
};

class Client
{
public:
    void ChargeLeptop(NewVagonSystem*o)
    {
        o->MatchSocket();
    }
};

class Adapter:public NewVagonSystem
{
private:
    OldVagonSystem* n;
public:
    Adapter(OldVagonSystem*nn)
    {
        n=nn;
    }
    void MatchSocket()
    {
        n->ThinSocket();
    }
};

int main()
{
    NewVagonSystem* adapter = new Adapter(new OldVagonSystem());
    adapter->MatchSocket();
    
    return 0;
}
*/
/*
8. Реалізувати bridge-будильник Нехай інтерфейс будильника — AlarmClock, вміє запускатися (start), зупинятися (stop) и будити (toWake), інтерфейс реалізації — AlarmClockImpl, описує два методи — задзвонити (ring) і повідомити (notify). Метод toWake буде почергово викликати ці два методи з реалізації. Спочатку — повідомить про те, що «час прийшов», потім задзвонить.  Об’єднати дані інтерфейси мостом (посилання  на AlarmClockImpl всередині AlarmClock). Далі напишіть уточнення AlarmClock — як «зависаючий будильник» (LockupAlarmClock), який подає сигнал деякий час і дві реализації AlarmClockImpl — будильник який грає MP3 і будильник, який  видає просте пікання. Продемонструвати роботу на конкретних будильниках.
*/
/*
#include <iostream>

using namespace std;

class AlarmClockImpl//class for bridge
{
public:
    virtual void ring()=0;
    virtual void notify()=0;
    
};

class AlarmClock
{
protected:
    AlarmClockImpl * a;
public:
    AlarmClock(AlarmClockImpl* i) : a(i) { }
    virtual void start()=0;
    virtual void stop()=0;
    virtual void toWake()=0;
};

class AlarmClockImplMP3:public AlarmClockImpl
{
public:
    void ring()
    {
        cout << "paly music \n";
    }
    
    void notify()
    {
        cout << "be ready , after 3 min you will hear music \n";
    }
};

class AlarmClockImplSimple:public AlarmClockImpl
{
public:
    void ring()
    {
        cout << " pick \n";
    }
    
    void notify()
    {
        cout << "be ready , after 3 min you will hear simple pick \n";
    }
};

class LockUpAlrmClock : public AlarmClock
{
public:
    LockUpAlrmClock(AlarmClockImpl* i) : AlarmClock(i) {  }
    
    
    void  start()
    {
        toWake();
    }
    
    void stop()
    {
        cout << "alarm stop! \n";
    }
    
    void toWake()
    {
        a->notify();
        a->ring();
        stop();
        cout << "\n";
    }
};

int main()
{
    
    AlarmClock* clock = new LockUpAlrmClock(new AlarmClockImplMP3());
    clock->start();
    
    clock = new LockUpAlrmClock(new AlarmClockImplSimple());
    clock->start();
    
}
*/


























