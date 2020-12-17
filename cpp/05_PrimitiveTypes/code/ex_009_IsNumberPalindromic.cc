bool IsPalindromeNumber(int x) {
    // TODO - you fill in here.
    // corner case: if x < 0, return false

    if(x <= 0) {
        return x == 0;
    }

    // Find the number of digits
    const int num_digits = static_cast<int>(floor(log10(x))) + 1;
    
    // find mask to get last digit
    int mask = static_cast<int>(pow(10, num_digits - 1));

    for(int i = 0; i < num_digits/2; ++i) {
        int first_digit = x % 10;
        int last_digit = x / mask;

        if(first_digit != last_digit)
            return false;

        x %= mask;
        x /= 10;
        mask /= 100;
    }

    return true;
}
