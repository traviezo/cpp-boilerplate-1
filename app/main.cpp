#include <iostream>
#include "PIDController.h"

int main()
{
    PIDController controller = PIDController(1.1, 2.2, 3.3);
    std::cout << controller.compute(0, 100) << std::endl;
}
