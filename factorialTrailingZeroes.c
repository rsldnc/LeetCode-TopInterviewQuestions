int trailingZeroes(int n)
{
    int count = 0;
    int c_n = n;

    while (c_n >= 5) {
        c_n /= 5;
        count += c_n;
    }
    
    return count;
}