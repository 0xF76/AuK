#include "event_manager.h"
#include <stddef.h>
#include <stdbool.h>
#include <string.h>

// First element on the event list or NULL if list if empty
static Event* head = NULL;


void EVENT_MANAGER_Init(void) {
	head = NULL;
}


bool EVENT_MANAGER_RegisterEvent(Event* event, OnEventHandler onEvent, void* context) {
	if(event == NULL || onEvent == NULL) {
		return false;
	}

	Event* current = head;

	if(current == NULL) {
		head = event;
		event->next = NULL;
		event->onEvent = onEvent;
		event->context = context;
		return true;
	} else {
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = event;
		event->next = NULL;
		event->onEvent = onEvent;
		event->context = context;
		return true;
	}

	return false;
}


void EVENT_MANAGER_UnregisterEvent(Event* event) {
	if(event == NULL) {
		return;
	}

	Event* current = head;

	if(current == event) {
		head = current->next;
	} else {
		while(current->next != NULL && current->next != event) {
			current = current->next;
		}
		if(current->next == event) {
			current->next = event->next;
		}
	}
}


bool EVENT_MANAGER_ScheduleEvent(Event* event, uint64_t time) {
	if(event == NULL) {
		return false;
	}

	Event* current = head;
	while(current != NULL) {
		if(current == event) {
			event->scheduledTime = time;
			event->isScheduled = true;
			return true;
		}
		current = current->next;
	}

	return false;
}


void EVENT_MANAGER_Proc(uint64_t currentTime) {
	Event* current = head;
	while(current != NULL) {
		if(current->isScheduled && current->scheduledTime <= currentTime) {
			current->isScheduled = false;
			current->onEvent(current, current->scheduledTime, current->context);
		}
		current = current->next;
	}
}

