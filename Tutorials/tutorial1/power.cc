// This function assumes the exponent is going to be greater than or equal to 0
void power(int a, int b, int& c) {
    if (b == 0) {
        c = 1;
    } else {
        c = a;
        for (int i=1; i < b; i++) {
            c *= a;
        }
    }
}