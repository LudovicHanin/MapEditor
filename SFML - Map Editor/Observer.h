#ifndef OBSERVER
#define OBSERVER

template <typename... Args>
class Observer
{
public:
	virtual void Update(Args... args) = 0;
};

#endif // !OBSERVER

