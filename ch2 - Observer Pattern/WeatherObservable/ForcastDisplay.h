#ifndef FORCAST_DISPLAY
#define FORCAST_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"

#include <iostream>
using namespace std;


class ForcastDisplay : public Observer, public DisplayElement {

    double currentPressure = 29.92f;
    double prePressure = 0.0f;
    Subject *weatherData = nullptr;

    public:
        ForcastDisplay() = default;
        ForcastDisplay(Subject *wd) : weatherData(wd) { weatherData->registerObserver(this); }

        void update(double t, double h, double p) override;
        void display() const override;
};


inline
void ForcastDisplay::update(double t, double h, double p) {
    prePressure = currentPressure;
    currentPressure = p;
    display();
}

inline
void ForcastDisplay::display() const {
    cout << "Forcast: ";
  
    if (currentPressure > prePressure)
        cout << "Improving weather on the way!\n";
    else if (currentPressure == prePressure)
        cout << "Forcast: More of the same\n";
    else if (currentPressure < prePressure)
        cout << "Forcast: Watch out for cooler, rainy weather\n";
}

#endif /*#ifndef FORCAST_DISPLAY*/
