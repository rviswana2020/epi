long long Reverse(int x) {
    // get digits from end and construct reversed number
    // since it is int type, it can be negative
    long long reversed = 0;
    int x_remaining = abs(x);

    while(x_remaining) {
        int cur_digit = x_remaining % 10;
        reversed = reversed * 10 + cur_digit;
        x_remaining /= 10;
    }

    return (x < 0 ? -reversed : reversed);
}
