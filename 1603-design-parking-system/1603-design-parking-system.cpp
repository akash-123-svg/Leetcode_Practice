class ParkingSystem {
public:
    int b, m, s;
    ParkingSystem(int big, int medium, int small) {
        b=big;
        m=medium;
        s=small;
    }
    
    bool addCar(int carType) {
        if((carType==1 && b==0) || (carType==2 && m==0) || (carType==3 && s==0)){
            return false;
        }
        if(carType==1) b--;
        else if(carType==2) m--;
        else if(carType==3) s--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */