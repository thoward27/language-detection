#pragma once

class Lang
{
private:
    int n;
    int len;
    int freq;
public:
    Lang(int n=3);
    ~Lang();

    void print();
};