#include "NotificationSystem.h"
#include <iostream>

NotificationSystem::NotificationSystem() {
}

NotificationSystem::~NotificationSystem() {
}

void NotificationSystem::notify(const std::string& message) {
    // Direct notification (Strategy removed in V2.8)
    std::cout << "[NOTIFY] System Message: " << message << std::endl;
}

void NotificationSystem::update(Device* device, const std::string& message) {
    std::string fullMsg = "Device " + device->getName() + ": " + message;
    notify(fullMsg);
}

void NotificationSystem::displayStatus() const {
    std::cout << "--- NOTIFICATION SYSTEM ---" << std::endl;
    std::cout << "  Status: Active" << std::endl;
    std::cout << "  Method: Direct Output (No Strategy)" << std::endl;
}