#include <iostream>
using namespace std;

int main()
{
    cout<<"Saloni Garg\n";
    cout<<"0905CS211149\n";
    int n;
    cout << "enter no. process : ";
    cin >> n;

    int at[n],bt[n],priority[n],x[n],wt[n], tat[n], ct[n];
    int i, j, smallest, count = 0, time;
    double avg = 0, tt = 0, end;


    for (i = 0; i < n; i++)
    {
        cout << "Enter arrival time, burst time,priority : ";
        cin >> at[i] >> bt[i] >> priority[i];
    }

    for (i = 0; i < n; i++)
        x[i] = bt[i];

    priority[n] = 10;
    for (time = 0; count != n; time++)
    {

        smallest = n;
        for (i = 0; i < n; i++)
        {
            if (at[i] <= time && priority[i] < priority[smallest] && bt[i] > 0)
                smallest = i;
        }
        bt[smallest]--;

        if (bt[smallest] == 0)
        {
            count++;
            end = time + 1;
            ct[smallest] = end;
            wt[smallest] = end - at[smallest] - x[smallest];
            tat[smallest] = end - at[smallest];
        }
    }

    cout<<"Process"<< "BT"<< "\t"<< "AT"<< "\t"<< "WT"<< "\t"<< "TAT"<< "\t"<< "CT"<< "\t"<< "Priority" << endl;

    for (i = 0; i < n; i++)
    {

        cout << "p" << i + 1 << "\t" << x[i] << "\t" << at[i] << "\t" << wt[i] << "\t" << tat[i] << "\t" << ct[i] << "\t" << priority[i] << endl;
        avg = avg + wt[i];
        tt = tt + tat[i];
    }
    cout<<"\n\nAverage waiting time = "<<avg/n;
    cout<<"\nAverage turnaround time = "<<tt/n<< endl;
}