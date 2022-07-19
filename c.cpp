#include <iostream>
template<typename T>
class SmartPtr{
    class Control{
	    uint8_t count;
	    public:
	    Control():count(0){};
	    void inc(){count++;};
	    uint8_t dec(){return --count;}
    }* control;
    T* data;
public:
    SmartPtr(T* in){
	 data=in;
    }
    SmartPtr(SmartPtr & o){
	data=o.data;
    	control=o.control();
	control.inc();
    }
    SmartPtr operator=(SmartPtr & o){
        data=o.data;
    	control=o.control();
	control.inc(); 
    }
    ~SmartPtr(){
	    if(!control->dec()){
		    delete data;
		    delete control;
	    }
    }

};

int main()
{
	int i=13;
	SmartPtr<int> s(&i);
}
