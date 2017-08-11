#ifndef SOASHAREDPTR
#define SOASHAREDPTR

#include <mutex>
#include <memory>

using std::mutex;

template<class T>
class soa_shared_ptr
{
    template<class U>
    friend class soa_shared_ptr;

public:
    soa_shared_ptr()
	{}

    explicit soa_shared_ptr(T* s)
    	: payload(s)
    {}

    soa_shared_ptr(const soa_shared_ptr& s)
    	: payload(s.payload)
    {}


    template<class U>
    soa_shared_ptr(const soa_shared_ptr<U>& s)
		: payload(::std::dynamic_pointer_cast<T>(s.payload))
	{}

    template<class U>
	soa_shared_ptr(const soa_shared_ptr<U>& s, T* _p)
		: payload(s.payload, _p)
	{}

    soa_shared_ptr& operator=(const soa_shared_ptr& s)
    {
		if(this!=&s) {
			payload = s.payload;
		}
		return *this;
    }

    T* get() const
    {
    	return payload.get();
    }

    T* operator->() const
    {
    	return payload.get();
    }

    T& operator*() const
    {
    	return *payload;
    }

private:
    std::shared_ptr<T> payload;
};

#endif
