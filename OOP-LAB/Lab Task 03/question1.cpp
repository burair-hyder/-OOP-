#include<iostream>
#include <iomanip> 

using namespace std;

class Duration
{
    private:
        int hrs;
        int mins;
        int secs;
    
    public:
        Duration() : hrs(0), mins(0), secs(0) {}

        Duration(int h, int m, int s)
        {
            hrs = h;
            mins = m;
            secs = s;
        }

        void showTime() const
        {
            cout << hrs << ":" << setw(2) << setfill('0') << mins << ":" << setw(2) << setfill('0') << secs << endl;
        }

        void combineTime(const Duration& d1, const Duration& d2)
        {
            secs = d1.secs + d2.secs;
            if (secs >= 60)
            {
                secs -= 60;
                mins++;
            }

            mins += d1.mins + d2.mins;
            if (mins >= 60)
            {
                mins -= 60;
                hrs++;
            }

            hrs += d1.hrs + d2.hrs;
        }
};

int main()
{
    Duration timeA(21, 40, 21), timeB(16, 30, 54), timeC;

    cout << "Time A: ";
    timeA.showTime();
    cout << "Time B: ";
    timeB.showTime();

    timeC.combineTime(timeA, timeB);
    cout << "Time C after combining Time A and Time B: ";
    timeC.showTime();
}
