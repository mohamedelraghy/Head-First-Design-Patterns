#ifndef WEATHER_DATA
#define WEATHER_DATA

#include "Subject.h"
#include "Observer.h"

#include <list>

using namespace std;

typedef list<Observer *> vo;


class WeatherData : public Subject{
    double temperature;
    double humidity;
    double pressure;
    vo observers = { };

    public:
        WeatherData() = default;
        void registerObserver(Observer *o) override { observers.push_back(o); }
        void removeObserver(Observer *o) override;
        void notifyObservers() override; 

        void measurementChanged() { notifyObservers(); } 
        void setMeasurements(const double &temp, const double &h, const double &p);

};

inline
void WeatherData::removeObserver(Observer *o){
    if(!observers.empty()) {
        for(auto itr = observers.begin();
        itr != observers.end(); itr++){
            if(*itr == o) observers.erase(itr);
        }
    }
}

inline
void WeatherData::notifyObservers() {
	for (auto o : observers)
		o->update(temperature, humidity, pressure);
}

inline
void WeatherData::setMeasurements(const double &t, const double &h, const double &p) {
	temperature = t;
	humidity = h;
	pressure = p;
	measurementChanged();
}

#endif  /*#ifndef WEATHER_DATA*/