class FileSelectionDialog;

class Widget
{
public:
    Widget(FileSelectionDialog *mediator, char *name)
    {
        _mediator = mediator;
        strcpy(_name, name);
    }
    virtual void changed();
    virtual void updateWidget() = 0;
    virtual void queryWidget() = 0;
protected:
    char _name[20];
private:
    FileSelectionDialog * _mediator;
};

class List : public Widget
{
public:
    List(FileSelectionDialog *dir, char *name) : Widget(dir, name){}
    void queryWidget()
    {
        cout << "     " << _name << " list queried " << '\n';
    }
    void updateWidget()
    {
        cout << "     " << _name << " list updated " << '\n';
    }
};

class Edit : public Widget
{
public:
    Edit(FileSelectionDialog *dir, char *name) : Widget(dir, name){}
    void queryWidget()
    {
        cout << "     " << _name << " edit queried " << '\n';
    }
    void updateWidget()
    {
        cout << "     " << _name << " edit updated " << '\n';
    }
};

class FileSelectionDialog
{
public:
    enum Widgets
    {
        FilterEdit, DirList, FileList, SelectionEdit
    };
    FileSelectionDialog()
    {
        _components[FilterEdit] = new Edit(this, "filter");
        _components[DirList] = new List(this, "dir");
        _components[FileList] = new List(this, "file");
        _components[SelectionEdit] = new Edit(this, "selection");
    }
    virtual ~FileSelectionDialog();
    void handleEvent(int which)
    {
        _components[which]->changed();
    }
    virtual void widgetChanged(Widget *theChangedWidget)
    {
        if (theChangedWidget == _components[FilterEdit])
        {
            _components[FilterEdit]->queryWidget();
            _components[DirList]->updateWidget();
            _components[FileList]->updateWidget();
            _components[SelectionEdit]->updateWidget();
        }
        else if (theChangedWidget == _components[DirList])
        {
            _components[DirList]->queryWidget();
            _components[FileList]->updateWidget();
            _components[FilterEdit]->updateWidget();
            _components[SelectionEdit]->updateWidget();
        }
        else if (theChangedWidget == _components[FileList])
        {
            _components[FileList]->queryWidget();
            _components[SelectionEdit]->updateWidget();
        }
        else if (theChangedWidget == _components[SelectionEdit])
        {
            _components[SelectionEdit]->queryWidget();
            cout << "     file opened" << '\n';
        }
    }
private:
    Widget * _components[4];
};
FileSelectionDialog::~FileSelectionDialog()
{
    for (int i = 0; i < 4; i++)
    {
        delete _components[i];
    }
}
void Widget::changed()
{
    _mediator->widgetChanged(this);
}
//auto main()    -> int
//{
//    FileSelectionDialog fileDialog;
//    int i;
//    cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
//    cin >> i;
//    while (i)
//    {
//        fileDialog.handleEvent(i - 1);
//        cout << "Exit[0], Filter[1], Dir[2], File[3], Selection[4]: ";
//        cin >> i;
//    }
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
using namespace std;

class MA
{
public:
    virtual MA* clone() = 0;
    virtual void collect_data() = 0;
};
class Factory
{
public:
    static MA* make_ma(int selection);
private:
    static MA* s_prototypes[4];
};

class CA0 : public MA
{
    MA* clone() { return new CA0; }
    void collect_data()
    {
        cout << "CA0: collect data memory 0\n";
    }
};
class CA1 : public MA
{
    MA* clone() { return new CA1; }
    void collect_data()
    {
        cout << "CA1: collect data memory 1\n";
    }
};
class CA2 : public MA
{
    MA* clone() { return new CA2; }
    void collect_data()
    {
        cout << "CA2: collect data memory2\n";
    }
};
MA* Factory::s_prototypes[] = { 0, new CA0, new CA1, new CA2 };
MA* Factory::make_ma(int selection){ return s_prototypes[selection]->clone(); }
//
//
//
///
//
//
//
//
//
//
using namespace std;

class GlobalClass
{
    int i_value;
    static GlobalClass *s_instance;
    GlobalClass(int d = 1)
    {
        i_value = d;
    }
public:
    int get_value()
    {
        return i_value;
    }
    void set_value(int d)
    {
        i_value = d;
    }
    static GlobalClass *instance()
    {
        if (!s_instance)
        {
            s_instance = new GlobalClass;
        }
        return s_instance;
    }
};

GlobalClass *GlobalClass::s_instance = 0;

void a(void)
{
    GlobalClass::instance()->set_value(10);
    cout << "a: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}

void b(void)
{
    GlobalClass::instance()->set_value(100);
    cout << "b: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
}


//auto main() -> int
//{
//    cout << "m: global_ptr is " << GlobalClass::instance()->get_value() << '\n';
//    a();
//    b();
//    getchar();
//}


using namespace std;
enum class State {
    OffHook,
    Connecting,
    Connected,
    OnHold
};
inline ostream& operator<<(ostream& os, const State& s)
{
    switch (s)
    {
        case::State::OffHook:
            os << "off the hook";
            break;
        case::State::Connecting:
            os << "connecting";
            break;
        case::State::Connected:
            os << "connected";
            break;
        case::State::OnHold:
            os << "on hold";
            break;
    }
    return os;
}

enum class Trigger {
    CallDialed,
    HungUp,
    CallConnected,
    PlacedOnHold,
    TakenOffHold,
    LeftMessage
};

inline ostream& operator<<(ostream& os, const Trigger& t)
{
    switch (t)
    {
        case::Trigger::CallDialed:
            os << "call dialed";
            break;
        case::Trigger::HungUp:
            os << "hung up";
            break;
        case::Trigger::CallConnected:
            os << "call connected";
            break;
        case::Trigger::TakenOffHold:
            os << "taken off hold";
            break;
        case::Trigger::LeftMessage:
            os << "get it done";
            break;
        default: break;
    }
    return os;
}

//auto main()    -> int
//{
//    map<State, vector<pair<Trigger, State>>> rules;
//    rules[State::OffHook] = {
//        {
//            Trigger::CallDialed, State::Connecting
//        }
//    };
//    rules[State::Connecting] = {
//        {
//            Trigger::HungUp, State::OffHook
//        },
//        {
//            Trigger::CallConnected, State::Connected
//        }
//    };
//    rules[State::Connected] = {
//        {
//            Trigger::LeftMessage, State::OffHook
//        },
//        {
//            Trigger::HungUp, State::OffHook
//        },
//        {
//            Trigger::PlacedOnHold, State::OnHold
//        }
//    };
//    rules[State::OnHold] = {
//        {
//            Trigger::TakenOffHold, State::Connected
//        },
//        {
//            Trigger::HungUp, State::OffHook
//        }
//    };
//
//    State currentState{ State::OffHook };
//    while (true)
//    {
//        cout << "phone is currently " << currentState << '\n';
//        select_trigger:
//        cout << "select a trigger: " << '\n';
//
//        int i = 0;
//        for (auto item : rules[currentState])
//        {
//            cout << i++ << ". " << item.first << '\n';
//        }
//        int input;
//        cin >> input;
//        if (input < 1 || (input + 1) > rules[currentState].size())
//        {
//            cout << "incorrect option. give it another shot.\n";
//            goto select_trigger;
//        }
//        currentState = rules[currentState][input].second;
//    }
//    cout << "done using the phone" << '\n';
//}


enum class OutputFormat
{
    HTML,
    Markdown
};

struct ListStrategy
{
    virtual ~ListStrategy() = default;
    virtual void add_list_item(ostringstream& oss, const string& item) = 0;
    virtual void start(ostringstream& oss) = 0;
    virtual void end(ostringstream& oss) = 0;
};

struct MarkdownListStrategy : ListStrategy
{
    void start(ostringstream& oss) override
    {
    }
    
    void end(ostringstream& oss) override
    {
    }
    
    void add_list_item(ostringstream& oss, const string& item) override
    {
        oss << " * " << item << endl;
    }
};

struct HtmlListStrategy : ListStrategy
{
    void start(ostringstream& oss) override
    {
        oss << "<ul>" << endl;
    }
    
    void end(ostringstream& oss) override
    {
        oss << "</ul>" << endl;
    }
    
    void add_list_item(ostringstream& oss, const string& item) override
    {
        oss << "<li>" << item << "</li>" << endl;
    }
};

struct TextProcessor
{
    void clear()
    {
        oss.str("");
        oss.clear();
    }
    void append_list(const vector<string> items)
    {
        list_strategy->start(oss);
        for (auto& item : items)
            list_strategy->add_list_item(oss, item);
        list_strategy->end(oss);
    }
    
    void set_output_format(OutputFormat format)
    {
        switch (format)
        {
            case OutputFormat::Markdown:
                list_strategy = make_unique<MarkdownListStrategy>();
                break;
            case OutputFormat::HTML:
                list_strategy = make_unique<HtmlListStrategy>();
                break;
            default:
                throw runtime_error("unsupported strategy.");
        }
    }
    string str() const { return oss.str(); }
private:
    ostringstream oss;
    unique_ptr<ListStrategy> list_strategy;
};



//auto main() -> int
//{
//    TextProcessor tp;
//    tp.set_output_format(OutputFormat::Markdown);
//    tp.append_list({ "a", "b", "c" });
//    cout << tp.str() << endl;
//    tp.clear();
//    tp.set_output_format(OutputFormat::HTML);
//    tp.append_list({ "a", "b", "c" });
//    cout << tp.str() << endl;
//}



using namespace std;

class Stack
{
    int items[10];
    int sp;
public:
    friend class StackIter;
    Stack()
    {
        sp = -1;
    }
    void push(int in)
    {
        items[++sp] = in;
    }
    int pop()
    {
        return items[sp--];
    }
    bool IsEmpty()
    {
        return (sp == -1);
    }
    StackIter *createIterator()const;
};
class StackIter
{
    const Stack *stk;
    int index;
public:
    StackIter(const Stack *s)
    {
        stk = s;
    }
    void first()
    {
        index = 0;
    }
    void next()
    {
        index++;
    }
    bool isDone()
    {
        return index == stk->sp + 1;
    }
    int currentItem()
    {
        return stk->items[index];
    }
};

StackIter *Stack::createIterator() const
{
    return new StackIter(this);
}

bool operator == (const Stack &l, const Stack &r)
{
    StackIter *itl = l.createIterator();
    StackIter *itr = r.createIterator();
    
    for (itl->first(), itr->first(); !itl->isDone(); itl->next(), itr->next())
        if (itl->currentItem() != itr->currentItem()){
            break;
        }
    bool ans = itl->isDone() && itr->isDone();
    delete itr;
    delete itl;
    return ans;
}
//auto main()    -> int
//{
//    Stack s1;
//    for (int i = 1; i < 5; i++)
//    {
//        s1.push(i);
//    }
//    Stack s2(s1), s3(s1), s4(s1), s5(s1);
//    s3.pop();
//    s5.pop();
//    s4.push(2);
//    s5.push(9);
//    cout << "1 == 2 is " << (s1 == s2) << '\n';
//    cout << "1 == 3 is " << (s1 == s3) << '\n';
//    cout << "1 == 4 is " << (s1 == s4) << '\n';
//    cout << "1 == 5 is " << (s1 == s5) << '\n';
//
//    getchar();
//}

using namespace std;
using namespace boost;

typedef uint32_t key;

struct User
{
    User(const string& first_name, const string& last_name) :
    first_name(add(first_name)), last_name(add(last_name))
    {
    }
    const string& get_first_name()
    {
        return names.left.find(first_name)->second;
    }
    const string& get_last_name()
    {
        return names.left.find(last_name)->second;
    }
    
    friend ostream& operator<<(ostream& os, User& obj)
    {
        return os
        << "first name: " << obj.first_name << " " << obj.get_first_name()
        << " last name: " << obj.last_name << " " << obj.get_last_name();
    }
    
protected:
    static bimap<key, string> names;
    static int seed;
    key add(string s)
    {
        auto it = names.right.find(s);
        if (it == names.right.end())
        {
            key id = ++seed;
            names.insert(bimap<key, string>::value_type(seed, s));
            return id;
        }
        return it->second;
    }
    key first_name, last_name;
};

int User::seed = 0;
bimap<key, string> User::names{};

//auto main() -> int
//{
//    User hanna_fox{ "Hanna", "Fox" };
//    User maria_fox{ "Maria", "Fox" };
//    User sophia_fox{ "Sophia", "Fox" };
//
//    cout << "Hanna " << hanna_fox << '\n';
//    cout << "Maria " << maria_fox << '\n';
//    cout << "Sophia " << sophia_fox << '\n';
//    getchar();
//}
