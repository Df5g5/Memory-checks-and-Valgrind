#include <iostream>
template<typename T>
class SmartPtr{
    class Control{
	    uint8_t count;
	    public:
	    Control():count(1){};
	    void inc(){count++;};
	    uint8_t dec(){return --count;}
    }* control;
    T* data_;
public:
    SmartPtr(T* in){
	 data_=in;
	 control=new Control;
    }
    SmartPtr(SmartPtr & o){
	data_=o.data_;
    	control=o.control;
	control->inc();
    }
    SmartPtr operator=(SmartPtr & o){
        data_=o.data_;
    	control=o.control;
	control->inc(); 
    }
    ~SmartPtr(){
	    if(!control->dec()){
		    delete data_;
		    delete control;
	    }
    }
    T* data(){return data_;}
};

int main()
{
	int *p=new int(13);
	{
	 SmartPtr<int> s(p);
	 std::cout<< *(s.data())<<std::endl;
	 auto s2=s;

	 std::cout<< *(s2.data())<<std::endl;
	}
	std::cout<<"p pointer is alive:"<<std::endl<<"address: "<<p<<std::endl<<"value: "<<*p<<std::endl;
}
