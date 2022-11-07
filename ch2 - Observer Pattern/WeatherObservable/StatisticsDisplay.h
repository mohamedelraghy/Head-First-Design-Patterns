#ifndef STATISTICS_DISPLAY
#define STATISTICS_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"
#include "DataObject.h"
#include "WeatherData.h"

#include <iostream>

class StatisticsDisplay: public Observer, public DisplayElement {
    double minTemp = 200.0f;
    double maxTemp = 0.0f;
    double tempSum = 0.0f;
    int numberOfReadings = 0;
    Subject *weatherData = nullptr;

    public: 
        StatisticsDisplay() = default;
		StatisticsDisplay(Subject *wd) : weatherData(wd) { weatherData->addObserver(this); }
		void update(Subject *sbj, DataObject *arg) override;
		void display() const override;

};

inline
void StatisticsDisplay::update(Subject *sbj, [[maybe_unused]] DataObject *arg) {
	
	if (auto *wd = dynamic_cast<WeatherData *>(sbj)) { // sbj is not nullptr
		auto temp = wd->getTemperature();
		tempSum += temp;
		++numberOfReadings;
		if (temp < minTemp)
			minTemp = temp;
		if (temp > maxTemp)
			maxTemp = temp;
		display();
	}
}

inline
void StatisticsDisplay::display() const {
	std::cout << "Avg/Max/Min Temperature = " <<
		tempSum / numberOfReadings << "/" << maxTemp << "/" << minTemp << '\n';
}

#endif /*#ifndef STATISTICS_DISPLAY*/