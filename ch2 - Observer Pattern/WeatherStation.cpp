#include "WeatherData.h"
#include "CurrentConditionsDisplay.h"

#include<iostream>
using namespace std;

int main(){
    auto weatherData = WeatherData();
    auto currentConditionsDisplay = CurrentConditionsDisplay(&weatherData);
    // auto statsDisplay = StatisticsDisplay(&weatherData); 
	// auto forcastDisplay = ForcastDisplay(&weatherData);
    
    weatherData.setMeasurements(80, 65, 30.4f);
    weatherData.setMeasurements(82, 70, 29.2f);
    weatherData.setMeasurements(78, 90, 29.2f);
    
}
