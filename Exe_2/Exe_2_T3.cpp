#include <iostream>
#include <vector>
#include <time.h>
#include <fstream>
#include <cmath>
#include <chrono>
using namespace std;

double F1a(int a[], double x, int size)
{
    double result = 0;
    double x_last = 1;
    for (int i = 0; i < size; i++)
    {
        result += a[i] * x_last;
        x_last *= x;
    }
    return result;
}

double F2a(int a[], double x, int size)
{
    double result = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        result = result * x + a[i];
    }
    return result;
}

double F1b(int a[], double x, int size, int times = 0)
{
    if (times == size - 1)
    {
        return a[times] * pow(x, times);
    }
    return a[times] * pow(x, times) + F1b(a, x, size, times + 1);
}

double F2b(int a[], double x, int size, int times = 0)
{
    if (times == size - 1)
    {
        return a[size - 1];
    }

    return a[times] + x * F2b(a, x, size, times + 1);
}

double F3b(double x, int n)
{
    if (n == 0)
    {
        return 0;
    }

    double result = 1;
    double x_last = x;
    for (int i = 1; i < n; i++)
    {
        result += x_last / i;
        x_last *= x;
    }
    return result;
}

void test_4Func()
{
    string filename("time.csv");

    ofstream fileout;
    fileout.open(filename);
    vector<string> header = {"n ", "F1a", "F1b", "F2a", "F2b"};
    for (int i = 0; i < header.size(); i++)
    {
        fileout << header[i];
        if (i < header.size() - 1)
        {
            fileout << ",";
        }
    }
    fileout << "\n";
    int a[] = {1, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 60, 70, 80, 90, 100};
    srand(time(NULL));
    for (int i = 0; i < 16; i++)
    {
        volatile double assist = 0;
        vector<double> result;
        result.push_back(a[i]);
        int n = a[i];
        int size = n + 1;
        int a[size] = {0};
        for (int i = 0; i < size; i++)
        {
            a[i] = rand() % size;
        }

        auto start_time_1a = chrono::steady_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            assist = F1a(a, 2, size);
        }
        auto end_time_1a = chrono::steady_clock::now();
        auto duration = end_time_1a - start_time_1a;
        double time_us = chrono::duration<double, micro>(duration).count();
        cout << "time of F1a is " << fixed << (time_us /= 100000) << endl;

        auto start_time_2a = chrono::steady_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            assist = F2a(a, 2, size);
        }
        auto end_time_2a = chrono::steady_clock::now();
        auto duration_2a = end_time_2a - start_time_2a;
        auto time_us_2a = chrono::duration<double, micro>(duration_2a).count();
        cout << "time of F2a is " << fixed << (time_us_2a /= 100000) << endl;

        auto start_time_1b = chrono::steady_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            assist = F1b(a, 2, size);
        }
        auto end_time_1b = chrono::steady_clock::now();
        auto duration_1b = end_time_1b - start_time_1b;
        auto time_us_1b = chrono::duration<double, micro>(duration_1b).count();
        cout << "time of F1b is " << (time_us_1b /= 100000) << endl;

        auto start_time_2b = chrono::steady_clock::now();
        for (int i = 0; i < 100000; i++)
        {
            assist = F2b(a, 2, size);
        }
        auto end_time_2b = chrono::steady_clock::now();
        auto duration_2b = end_time_2b - start_time_2b;
        auto time_us_2b = chrono::duration<double, micro>(duration_2b).count();
        cout << "time of F2b is " << fixed << (time_us_2b /= 100000) << endl;

        result.push_back(time_us);
        result.push_back(time_us_1b);
        result.push_back(time_us_2a);
        result.push_back(time_us_2b);
        for (int i = 0; i < result.size(); i++)
        {
            fileout << result[i];
            if (i < header.size() - 1)
            {
                fileout << ",";
            }
        }
        fileout << "\n";
    }
}

void test_F3()
{

    cout << F3b(1.1, 6) << endl;
}

int main()
{

    test_F3();
    return 0;
}