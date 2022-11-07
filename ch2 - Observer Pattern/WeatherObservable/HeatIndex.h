#ifndef HEAT_INDEX_DISPLAY
#define HEAT_INDEX_DISPLAY

#include "Observer.h"
#include "DisplayElement.h"
#include "Subject.h"
#include "DataObject.h"
#include "WeatherData.h"

#include <iostream>

double computeHeatIndex(const double &, const double &);

class HeatIndex : public Observer,  public DisplayElement {
    
    double heatIndex = 0.0f;
    Subject *weatherData;
    
    public:
        HeatIndex(Subject *wd) : weatherData(wd) { weatherData->addObserver(this); }
		void update(Subject *sbj, DataObject *arg) override;
		void display() const override;
};

inline
void HeatIndex::update(Subject *sbj, [[maybe_unused]] DataObject *arg) {
	if (auto *wd = dynamic_cast<WeatherData *>(sbj)) { // sbj is not nullptr
		heatIndex = computeHeatIndex(wd->getTemperature(), wd->getHumidity());
		display();
	}
}

inline
void HeatIndex::display() const { std::cout << "Heat Index is " << heatIndex << '\n'; }

inline
double computeHeatIndex(const double &t, const double &rh) {
	double index = (double)((16.923 + (0.185212 * t) + (5.37941 * rh) - (0.100254 * t * rh) 
				+ (0.00941695 * (t * t)) + (0.00728898 * (rh * rh)) 
				+ (0.000345372 * (t * t * rh)) - (0.000814971 * (t * rh * rh)) +
				(0.0000102102 * (t * t * rh * rh)) - (0.000038646 * (t * t * t)) + (0.0000291583 * 
					(rh * rh * rh)) + (0.00000142721 * (t * t * t * rh)) + 
				(0.000000197483 * (t * rh * rh * rh)) - (0.0000000218429 * (t * t * t * rh * rh)) +
				0.000000000843296 * (t * t * rh * rh * rh)) - (0.0000000000481975 * (t * t * t * rh * rh * rh)));

	return index;
}


#endif /*#ifndef HEAT_INDEX_DISPLAY*/