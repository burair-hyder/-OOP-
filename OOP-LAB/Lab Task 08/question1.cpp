#include <iostream>
#include <string>
using namespace std;

class DeviceManagement {
protected:
    int deviceCode;
    string deviceCategory;
    double devicePower;
    bool deviceState;

public:
    DeviceManagement(int code, string category, double power) {
        deviceCode = code;
        deviceCategory = category;
        devicePower = power;
        deviceState = false;
    }

    virtual void enableDevice() {
        deviceState = true;
    }

    virtual void disableDevice() {
        deviceState = false;
    }

    virtual double calculateEnergy(int duration) {
        return 0;
    }

    string fetchCategory() {
        return deviceCategory;
    }

    bool isDeviceActive() {
        return deviceState;
    }
};

class Light : public DeviceManagement {
public:
    Light(int code, string category, double power) : DeviceManagement(code, category, power) {
    }

    double calculateEnergy(int duration) override {
        return devicePower * duration;
    }
};

class Fan : public DeviceManagement {
    int rotationSpeed;

public:
    Fan(int code, string category, double power, int speed) : DeviceManagement(code, category, power) {
        rotationSpeed = speed;
    }

    double calculateEnergy(int duration) override {
        return devicePower * duration * rotationSpeed;
    }
};

class AC : public DeviceManagement {
    double currentTemp;
    double targetTemp;

public:
    AC(int code, string category, double power, double currTemp, double targTemp) : DeviceManagement(code, category, power) {
        currentTemp = currTemp;
        targetTemp = targTemp;
    }

    void enableDevice() override {
        deviceState = true;
        cout << "AC started. Cooling to " << targetTemp << "°C." << endl;
    }

    void disableDevice() override {
        deviceState = false;
        cout << "AC stopped." << endl;
    }

    double calculateEnergy(int duration) override {
        return devicePower * duration * (1 - (currentTemp - targetTemp) / 100);
    }
};

class SecuritySystem : public DeviceManagement {
    friend class MaintenanceTool;

public:
    SecuritySystem(int code, string category, double power) : DeviceManagement(code, category, power) {
    }

    void enableDevice() override {
        deviceState = true;
        cout << "Security System activated." << endl;
    }

    void disableDevice() override {
        string passcode;
        cout << "Enter authorization code to deactivate security: ";
        cin >> passcode;
        if (passcode == "1234") {
            deviceState = false;
            cout << "Security System deactivated." << endl;
        } else {
            cout << "Incorrect code! Security remains active." << endl;
        }
    }

    double calculateEnergy(int duration) override {
        if (deviceState) {
            cout << "[Security Log] Active for " << duration << " hours." << endl;
            return devicePower * duration;
        }
        return 0;
    }

    friend void reviewSecurityLogs(SecuritySystem& sys, string accessRole);
};

void reviewSecurityLogs(SecuritySystem& sys, string accessRole) {
    if (accessRole == "Maintenance Staff") {
        cout << "Security Logs Access:" << endl;
        cout << "Current State: " << (sys.isDeviceActive() ? "ACTIVE" : "INACTIVE") << endl;
    } else {
        cout << "Access Denied: Unauthorized role." << endl;
    }
}

class MaintenanceTool {
public:
    void clearSecurityAlerts(SecuritySystem& sys) {
        sys.deviceState = false;
        cout << "MaintenanceTool: Security alerts cleared." << endl;
    }
};

class User {
    string userIdentifier;
    string userRole;
    int privilegeLevel;

public:
    User(string id, string role, int level) {
        userIdentifier = id;
        userRole = role;
        privilegeLevel = level;
    }

    void listAccessibleDevices(DeviceManagement* deviceArray[], int totalDevices) {
        cout << "Devices accessible by " << userIdentifier << " (" << userRole << "):" << endl;
        for (int i = 0; i < totalDevices; i++) {
            string cat = deviceArray[i]->fetchCategory();
            if (userRole == "Maintenance Staff" || cat == "Light" || cat == "Fan") {
                cout << "- " << cat << endl;
            }
        }
    }

    string getUserRole() {
        return userRole;
    }
};

int main() {
    Light light1(1, "Light", 50);
    Fan fan1(2, "Fan", 75, 3);
    AC ac1(3, "AC", 1500, 30, 22);
    SecuritySystem sec1(4, "SecuritySystem", 100);

    DeviceManagement* devices[] = { &light1, &fan1, &ac1, &sec1 };
    int deviceCount = 4;

    User user1("user123", "Regular User", 1);
    User user2("admin456", "Maintenance Staff", 2);

    // Device operations
    light1.enableDevice();
    fan1.enableDevice();
    ac1.enableDevice();
    sec1.enableDevice();

    // Energy calculation
    cout << "Energy Used (Light, 5hrs): " << light1.calculateEnergy(5) << " Wh" << endl;
    cout << "Energy Used (Fan, 5hrs): " << fan1.calculateEnergy(5) << " Wh" << endl;
    cout << "Energy Used (AC, 5hrs): " << ac1.calculateEnergy(5) << " Wh" << endl;
    cout << "Energy Used (Security, 5hrs): " << sec1.calculateEnergy(5) << " Wh" << endl;

    // User device access
    user1.listAccessibleDevices(devices, deviceCount);
    user2.listAccessibleDevices(devices, deviceCount);

    // Security log check
    reviewSecurityLogs(sec1, user1.getUserRole());
    reviewSecurityLogs(sec1, user2.getUserRole());

    // Maintenance tool demo
    MaintenanceTool maint;
    maint.clearSecurityAlerts(sec1);

    sec1.disableDevice();  // Requires code
    return 0;
}
