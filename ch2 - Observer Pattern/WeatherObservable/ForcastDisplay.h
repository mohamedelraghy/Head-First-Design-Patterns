#ifndef FORCAST_DISPLAY
#define FORCAST_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"
#include "DataObject.h"
#include "WeatherData.h"


#include <iostream>
using namespace std;


class ForcastDisplay : public Observer, public DisplayElement {

    double currentPressure = 29.92f;
    double prePressure = 0.0f;
    Subject *observalbe = nullptr;

    public:
        ForcastDisplay() = default;
        ForcastDisplay(Subject *sbj) : observalbe(sbj) { observalbe->addObserver(this); }

        void update(Subject *sbj, DataObject *arg = nullptr) override;
        void display() const override;
};


inline
void ForcastDisplay::update(Subject *sbj, [[maybe_unused]] DataObject *arg) {
	if (auto *wd = dynamic_cast<WeatherData *>(sbj)) { // sbj is not nullptr
		prePressure = currentPressure;
		currentPressure =  wd->getPressure();
		display();
	}
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
