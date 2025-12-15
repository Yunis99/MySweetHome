#include "Storage.h"
#include <iostream>
#include <ctime>

// Initialize static instance pointer
Storage* Storage::instance = NULL;

Storage::Storage() : isOpen(false) {}

Storage* Storage::getInstance() {
    if (instance == NULL) {
        instance = new Storage();
    }
    return instance;
}

Storage::~Storage() {
    closeFile();
}

std::string Storage::getCurrentTimestamp() const {
    time_t now = time(0);
    char* dt = ctime(&now);
    std::string timestamp(dt);
    // Remove newline
    if (!timestamp.empty() && timestamp[timestamp.length()-1] == '\n') {
        timestamp.erase(timestamp.length()-1);
    }
    return timestamp;
}

bool Storage::openFile(const std::string& fname) {
    if (isOpen) {
        closeFile();
    }
    
    filename = fname;
    logFile.open(filename.c_str(), std::ios::out | std::ios::app);
    
    if (logFile.is_open()) {
        isOpen = true;
        log("========================================");
        log("Log file opened: " + filename);
        return true;
    }
    
    std::cerr << "[ERROR] Could not open log file: " << filename << std::endl;
    return false;
}

void Storage::closeFile() {
    if (isOpen) {
        log("Log file closed.");
        log("========================================");
        logFile.close();
        isOpen = false;
    }
}

bool Storage::isFileOpen() const {
    return isOpen;
}

void Storage::log(const std::string& message) {
    if (isOpen) {
        logFile << "[" << getCurrentTimestamp() << "] " << message << std::endl;
        logFile.flush();
    }
}

void Storage::logInfo(const std::string& message) {
    log("[INFO] " + message);
}

void Storage::logWarning(const std::string& message) {
    log("[WARNING] " + message);
}

void Storage::logError(const std::string& message) {
    log("[ERROR] " + message);
}

void Storage::logAlert(const std::string& message) {
    log("[ALERT] " + message);
}

void Storage::logMenuSelection(int option) {
    std::string optStr;
    char buffer[16];
    sprintf(buffer, "%d", option);
    optStr = buffer;
    logInfo("Menu option selected: " + optStr);
}

void Storage::logDeviceOperation(const std::string& deviceName, const std::string& operation) {
    logInfo("Device '" + deviceName + "': " + operation);
}

void Storage::logModeChange(const std::string& fromMode, const std::string& toMode) {
    logInfo("Mode changed: " + fromMode + " -> " + toMode);
}

void Storage::logStateChange(const std::string& fromState, const std::string& toState) {
    logInfo("State changed: " + fromState + " -> " + toState);
}

void Storage::logSystemStart() {
    log("");
    log("############################################");
    log("#       MY SWEET HOME SYSTEM START        #");
    log("############################################");
    log("");
}

void Storage::logSystemShutdown() {
    log("");
    log("############################################");
    log("#      MY SWEET HOME SYSTEM SHUTDOWN      #");
    log("############################################");
    log("");
}

std::string Storage::getFilename() const {
    return filename;
}
