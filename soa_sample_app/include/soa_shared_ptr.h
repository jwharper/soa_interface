#ifndef SOASHAREDPTR
#define SOASHAREDPTR

#include <mutex>
//#include <iostream>

using std::mutex;

template<class T>
class soa_shared_ptr
{
    template<class U>
    friend class soa_shared_ptr;

public:
    soa_shared_ptr() :p(NULL), c(NULL), m(NULL) {

    }

    explicit soa_shared_ptr(T* s) :p(s), c(new unsigned(1)), m(new mutex()) {

    }

    soa_shared_ptr(const soa_shared_ptr& s) :p(s.p), c(s.c), m(s.m) {
	if(m){
		m->lock();
 		if(c){
			++*c; 
		}
		m->unlock();
	}
    }

    soa_shared_ptr& operator=(const soa_shared_ptr& s){ 
	if(this!=&s) {
		clear(); 
		p=s.p; 
		c=s.c; 
		m=s.m;

		if(m){
			m->lock();
			if(c){
				++*c;
			} 
			m->unlock();
		}
	} 
	return *this; 
    }

    template<class U>
    soa_shared_ptr(const soa_shared_ptr<U>& s) :p(s.p), c(s.c), m(s.m)
	{
		if(m){
			m->lock();
			if(c){
				 ++*c;
			}
			m->unlock();
		}
    }

    template<class U>
	soa_shared_ptr(const soa_shared_ptr<U>& s, T* _p) :p(_p), c(s.c), m(s.m)
	{
		if(m){
			m->lock();
			if(c){
				 ++*c;
			}
			m->unlock();
		}
	}

    ~soa_shared_ptr() { 
	clear(); 
    }

    void clear() 
    { 
	if(m){
		m->lock();
    		if(c){	
			--*c;
           	 	
			if(*c==0){
				delete p;
				delete c;
				m->unlock();
				delete m;
				return;
		    	}
 	       	} 
		m->unlock();
	}
    }

    T* get() const { 
	return (c)? p: 0; 
    }

    T* operator->() const { 
	return get(); 
    }

    T& operator*() const { 
	return *get(); 
    }

private:
    T* p;
    unsigned* c;
    mutex* m;
};

#endif
