#include <iostream>
using namespace std;

class Activity {
public:
    virtual double calculateCaloriesBurned() = 0;
    virtual ~Activity() {}
};

class Running : public Activity {
private:
    double distance;
    double time;
public:
    Running(double dist, double t) {
        distance = dist;
        time = t;
    }

    double calculateCaloriesBurned() override {
        return distance * 60;
    }
};

class Cycling : public Activity {
private:
    double speed;
    double time;
public:
    Cycling(double spd, double t) {
        speed = spd;
        time = t;
    }

    double calculateCaloriesBurned() override {
        return speed * time * 30;
    }
};

int main() {
    Running run(5.0, 30.0);
    Cycling cycle(20.0, 1.0);

    cout << "Calories burned (Running): " << run.calculateCaloriesBurned() << endl;
    cout << "Calories burned (Cycling): " << cycle.calculateCaloriesBurned() << endl;

    return 0;
}
