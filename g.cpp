#include <iostream>
template<typename T>
class SmartPtr;

template<typename T>
SmartPtr<T>  make_smart();

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
    SmartPtr(T* in){
	 data_=in;
	 control=new Control;
    }
public:
    SmartPtr(){data_=nullptr;control=nullptr;}
    SmartPtr(SmartPtr & o){
	data_=o.data_;
    	control=o.control;
	control->inc();
    }
    SmartPtr(SmartPtr && o){
	    control=std::move(o.control);
	    data_=std::move(o.data_);
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
    friend SmartPtr<T> make_smart<T>();
};
template<typename T>
SmartPtr<T>  make_smart(){
	///SmartPtr<T> t;
	///t.data_=(new T());
	///return t;
	return SmartPtr<T>(new T());

}
int main()
{
	int *p=new int(13);
	{
	 auto s=make_smart<int>();
	 std::cout<< *(s.data())<<std::endl;
	 auto s2=s;

	 std::cout<< *(s2.data())<<std::endl;
	}
	delete p;
}
