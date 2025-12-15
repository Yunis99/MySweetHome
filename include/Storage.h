#ifndef STORAGE_H
#define STORAGE_H

#include <string>
#include <fstream>
#include <vector>

// Singleton Pattern for Storage/Logging
class Storage {
private:
    static Storage* instance;
    std::ofstream logFile;
    std::string filename;
    bool isOpen;
    
    // Private constructor for Singleton
    Storage();
    Storage(const Storage&);
    Storage& operator=(const Storage&);
    
    std::string getCurrentTimestamp() const;

public:
    static Storage* getInstance();
    ~Storage();
    
    bool openFile(const std::string& fname = "msh_log.txt");
    void closeFile();
    bool isFileOpen() const;
    
    // Logging methods
    void log(const std::string& message);
    void logInfo(const std::string& message);
    void logWarning(const std::string& message);
    void logError(const std::string& message);
    void logAlert(const std::string& message);
    
    // Operation logging
    void logMenuSelection(int option);
    void logDeviceOperation(const std::string& deviceName, const std::string& operation);
    void logModeChange(const std::string& fromMode, const std::string& toMode);
    void logStateChange(const std::string& fromState, const std::string& toState);
    void logSystemStart();
    void logSystemShutdown();
    
    std::string getFilename() const;
};

#endif // STORAGE_H
