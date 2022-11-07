#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
    public:
        virtual ~Observer() = default;
        virtual void update(double temp, double humidity, double perssure) = 0;
};

#endif  /*#ifndef OBSERVER_H*/