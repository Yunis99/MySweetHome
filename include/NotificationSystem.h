/**
 * @file NotificationSystem.h
 * @brief Context for Notification Strategy pattern
 * @authors
 * - 220201023: Notification System & Integration
 * 
 * @patterns Strategy, Observer (Observer impl)
 */

#ifndef NOTIFICATIONSYSTEM_H
#define NOTIFICATIONSYSTEM_H

#include "Device.h" // For IDeviceObserver
#include <string>

class NotificationSystem : public IDeviceObserver {
public:
    NotificationSystem();
    virtual ~NotificationSystem();
    
    void notify(const std::string& message);
    
    // Observer update method
    virtual void update(Device* device, const std::string& message);
    
    void displayStatus() const;
};

#endif // NOTIFICATIONSYSTEM_H