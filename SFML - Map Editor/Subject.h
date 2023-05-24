#ifndef SUBJECT
#define SUBJECT

#include <vector>
#include "Observer.h"

template <typename... Args>
class Subject
{
public:
	void AddObserver(Observer<Args...>* observer)
	{
		m_observers.push_back(observer);
	}

	void RemoveObserver(Observer<Args...>* observer)
	{
		auto it = std::find(m_observers.begin(), m_observers.end(), observer);
		if (it != m_observers.end())
		{
			m_observers.erase(it);
		}
	}

	void NotifyObservers(Args... args)
	{
		for (auto observer : m_observers)
		{
			observer->Update(args...);
		}
	}

private:
	std::vector<Observer<Args...>*> m_observers;
};

#endif // !SUBJECT



