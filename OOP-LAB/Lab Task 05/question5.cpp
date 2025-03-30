#include <iostream>
#include <string>

using namespace std;

class Engine {
private:
    string model;
public:
    Engine(string model) : model(model) {}  
    void showDetails() const {
        cout << "Engine Model: " << model << endl;
    }
};

class Wheel {
private:
    int diameter;
public:
    Wheel(int diameter) : diameter(diameter) {}  
    void showDetails() const {
        cout << "Wheel Diameter: " << diameter << " inches" << endl;
    }
};

class Headlight {
private:
    string intensity;
public:
    Headlight(string intensity) : intensity(intensity) {}  
    void showDetails() const {
        cout << "Headlight Intensity: " << intensity << endl;
    }
};

class Steering {
private:
    string mechanism;
public:
    Steering(string mechanism) : mechanism(mechanism) {}  
    void showDetails() const {
        cout << "Steering Mechanism: " << mechanism << endl;
    }
};

class Car {
private:
    Engine* engine;
    Wheel* tires[4];
    Headlight lights[2];
    Steering control;

public:
    Car(Engine* eng, Wheel* t1, Wheel* t2, Wheel* t3, Wheel* t4, string light1, string light2, string steerMech)
        : engine(eng), lights{Headlight(light1), Headlight(light2)}, control(steerMech) {
        tires[0] = t1;
        tires[1] = t2;
        tires[2] = t3;
        tires[3] = t4;
    }

    ~Car() {
        cout << "Car instance is being destroyed...\n";
    }

    void showDetails() const {
        cout << "Car Specifications:\n";
        engine->showDetails();
        for (int i = 0; i < 4; i++) {
            tires[i]->showDetails();
        }
        for (int i = 0; i < 2; i++) {
            lights[i].showDetails();
        }
        control.showDetails();
    }
};

int main() {
    Engine myEngine("V6 Turbo");
    Wheel tire1(19), tire2(19), tire3(19), tire4(19);

    Car myCar(&myEngine, &tire1, &tire2, &tire3, &tire4, "High Beam", "Low Beam", "Electronic Power Steering");

    myCar.showDetails();

    return 0;
}
