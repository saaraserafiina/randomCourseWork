#ifndef DRIVER_H
#define DRIVER_H

#include <string>


class Driver {

    private:
        std::string name;
        int licenseYear;

    public:
        std::string getName() const;
        int getLicenseYear() const;
        std::string toString() const;

};


#endif
