#ifndef EVENTMANAGER_H
#define EVENTMANAGER_H

#include <vector>
#include <functional>
#include <map>
#include <algorithm>

using namespace std;

#endif // !EVENTMANAGER_H


class EventManager
{
public:
	static EventManager& GetInstance()
	{
		static EventManager instance;
		return instance;
	}

	void RegisterEventCallback(const string& eventName, const function<void()>& callback);
	void RemoveEventCallback(const string& eventname, const function<void()>& callback);
	void TriggerEvent(const string eventName);

private:
	map<string, vector<function<void()>>> callbacks;

	EventManager() {}

	EventManager(EventManager const&) = delete;
	void operator=(EventManager const&) = delete;
};

