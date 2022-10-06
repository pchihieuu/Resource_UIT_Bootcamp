#include <bits/stdc++.h>                                                       

constexpr double EPSILON = 1e-4;

inline bool isNearlyEqual (double a, double b){
    return std::abs(a - b) < EPSILON;
}

int main()
{
    int nm, dr; // number of months and depreciation records
    double dp, la; // down payment and loan payment
    while(std::cin >> nm >> dp >> la >> dr){
        if(nm < 0) break;
        std::vector <double> drv(nm, 0.0);
        for(int i = 0 ; i < dr ; ++i){
            int month; std::cin >> month;
            std::cin >> drv[month];
        }
        for(int i = 0 ; i < drv.size() ; ++i){
            if(isNearlyEqual(drv[i], 0.0)){
                drv[i] = drv[i - 1];
            }
        }
        int months = 0;
        double monthly_payment = la / nm;
        double car_value = (la + dp) * (1 - drv[0]);
        int index = 1;
        while(la - car_value > EPSILON){
            car_value *= (1 - drv[index++]);
            la -= monthly_payment;
            ++months;
        }
        std::cout << months << " month";
        if(months != 1) std::cout << "s";
        std::cout << '\n';
    }
    return 0;
}