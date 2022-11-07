#ifndef CURRENT_CONDITIONS_DISPLAY
#define CURRENT_CONDITIONS_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"
#include "DataObject.h"
#include "WeatherData.h"

#include <iostream>


class CurrentConditionsDisplay : public Observer, public DisplayElement {
    
    double temperature = 0.0f;
	double humidity = 0.0f;
	Subject *observable;

    public: 
        CurrentConditionsDisplay() = default;
        CurrentConditionsDisplay(Subject *sbj) : observable(sbj) { observable->addObserver(this); }
        void update(Subject *sbj, DataObject *arg) override;
        void display() const override;
};

inline 
void CurrentConditionsDisplay::update(Subject *sbj, DataObject *arg){
    if (auto *wd = dynamic_cast<WeatherData *>(sbj)) { // sbj is not nullptr
		temperature = wd->getTemperature();
		humidity = wd->getHumidity();
		display();
	}
}

inline
void CurrentConditionsDisplay::display() const {
	std::cout << "Current Conditions: " << temperature
		<< "F degree and " << humidity << "% humidity\n";

}


#endif /*#ifndef CURRENT_CONDITIONS_DISPLAY*/