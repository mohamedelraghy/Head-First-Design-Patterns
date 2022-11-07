#ifndef CURRENT_CONDITIONS_DISPLAY
#define CURRENT_CONDITIONS_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"
#include <iostream>


class CurrentConditionsDisplay : public Observer, public DisplayElement {
    double temperature;
    double humidity;
    Subject* weatherData = nullptr;

    public: 
        CurrentConditionsDisplay() = default;
        CurrentConditionsDisplay(Subject *wd) : weatherData(wd) { weatherData->registerObserver(this); }
        void update(double t, double h, double p) override;
        void display() const override;
};

inline 
void CurrentConditionsDisplay::update(double t, double h, [[maybe_unused]] double p){
    temperature = t;
	humidity = h;
	display();
}

inline
void CurrentConditionsDisplay::display() const {
	std::cout << "Current Conditions: " << temperature
		<< "F degree and " << humidity << "% humidity\n";

}


#endif /*#ifndef CURRENT_CONDITIONS_DISPLAY*/