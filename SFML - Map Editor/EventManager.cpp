#include "EventManager.h"

void EventManager::RegisterEventCallback(const string& eventName, const function<void()>& callback)
{
	auto& callbackVec = callbacks[eventName];
	auto callbackIt = std::find_if(callbackVec.begin(), callbackVec.end(),
		[&](const function<void()>& f) { return f.target<void()>() == callback.target<void()>(); });
	if (callbackIt == callbackVec.end()) {
		callbackVec.push_back(callback);
	}
}

void EventManager::RemoveEventCallback(const string& eventName, const function<void()>& callback)
{
	auto it = callbacks.find(eventName);
	if (it != callbacks.end()) {
		auto& callbackVec = it->second;
		auto callbackIt = std::find_if(callbackVec.begin(), callbackVec.end(),
			[&](const function<void()>& f) { return f.target<void()>() == callback.target<void()>(); });
		if (callbackIt != callbackVec.end()) {
			callbackVec.erase(callbackIt);
		}
	}
}

void EventManager::TriggerEvent(const string eventName)
{
	auto it = callbacks.find(eventName);
	if (it != callbacks.end())
	{
		for (auto& callback : it->second)
		{
			callback();
		}
	}
}

