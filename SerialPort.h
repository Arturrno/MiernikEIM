#pragma once
#include <iostream>
#include <windows.h>

//"VOLT1 3.141\n"       - ustawienie napi�cia SEM1 w[ V ]
//"MEAS:CURR? (@1)\n"   - pomiar pr�du w kan. 1, czyli SEM1

//"VOLT2 6.284\n"       - ustawienie napi�cia SEM2 w[ V ]
//"MEAS:CURR? (@2)\n"   - pomiar pr�du w kan. 2, czyli SEM2

//"CURR 2.721\n"        - ustawienie pr�du SPM w[ mA ]
//"MEAS:VOLT? (@3)\n"   - pomiar napi�cia w kan. 3, czyli na SPM

//"MEAS:VOLT? (@4)\n"   - pomiar napi�cia w kan. 4, czyli wej AUX

class SerialPort {
private:
    HANDLE _hSerial;
    char* portName;

public:
    SerialPort(char* port);
    ~SerialPort();

    bool openSerialPort();
    void writeOrder(const char* order);
    double getMeasValue(int n_max, double t_delay, const char* order, double prec);
};