#include <iostream>
#include <vector>
#include <string>
#include<memory>

using namespace std;
class A
{   
public:
    
    A(string s)
    :_i(s)
    {
        cout<<"A() "<<_i<<endl;
    }
    ~A()
    {
        cout<<"~A() "<<_i<<endl;
    }

    string i()
    {
        return _i;
    }

private:
    string _i;
};

class B
{   
public:
    B()
    {
        cout<<"B()"<<endl;
    }
    ~B()
    {
        cout<<"~B()"<<endl;
    }
    void add(A a)
    {
        cout<<"start add value : ";
        _a.push_back(a);
        cout<<"end  add value : ";
        
    }
    void addp(A *a)
    {
        _ap.push_back(a);
    }

    void addasp(shared_ptr<A> a)
    {
        _asp.push_back(a);
    }

    void addturn(A *a)
    {
        _asp.push_back(make_shared<A>(*a));

    }
    

    void show()
    {   
        cout<<endl;
        for(int i = 0;i<_a.size();i++)
        {
            cout<<_a[i].i()<<" ";
        };

        cout<<endl;
        cout<<"point :"<<endl;
        

        for(int i = 0;i<_ap.size();i++)
        {   
            cout<<"point : "<<_ap[i]<<" value: "<<_ap[i]->i()<<endl;

        }
        cout<<endl;

        cout<<"shared_ptr :"<<endl;
        for(int i = 0;i<_asp.size();i++)
        {   
            cout<<"point : "<<_asp[i]<<" value: "<<_ap[i]->i()<<endl;

        }


    }

    vector<A> _a;
    vector<A*> _ap;
    vector<shared_ptr<A>> _asp;
};



int main()
{
    B b;
    cout<<endl;
    
    cout<<"add a"<<endl;
    b.add(A("I am value"));

    cout<<endl;
    cout<<"add ap in new"<<endl;

    b.addp(new A("I am new"));
 

    cout<<endl;
    cout<<"add ap in & "<<endl;

    A a("Im value but pass by &");
    b.addp(&a);

    cout<<"add ap in & in { }"<<endl;
    
    {
      cout<<endl;
    
        cout<<"{} start"<<endl;
        A a("Im value but pass by & in {}");
        b.addp(&a);
        cout<<"{} end"<<endl;
    }

    shared_ptr<A> asp = make_shared<A>("I am shared ptr");
    b.addasp(asp);    
    {
        shared_ptr<A> asp1 = make_shared<A>("I am shared ptr in {}");
        b.addasp(asp1); 

        A a("I am value pass by & ,but trun in func");
        b.addturn(&a);
    }

    
    cout<<endl<<"now show "<<endl;
    b.show();
    cout<<endl<<"end show  "<<endl;
    

}

