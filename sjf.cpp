#include <iostream>
using namespace std;

int main()
{
    cout << "Saloni Garg\n";
    cout << "0905CS211149\n";
    int n;
    cout << "Enter the No. of processes : ";
    cin >> n;

    int i, p[n], min, k = 1, btime = 0;
    int bt[n], temp, j, arr[n], wait[n], turn[n], ta = 0, sum = 0;
    float wavg = 0, tavg = 0, tsum = 0, wsum = 0;

    cout << "Enter the AT and BT of the processes: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr[i] >> bt[i];
        p[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
                temp = bt[j];
                bt[j] = bt[i];
                bt[i] = temp;
            }
        }
    }
    for (j = 0; j < n; j++)
    {
        btime = btime + bt[j];
        min = bt[k];
        for (i = k; i < n; i++)
        {
            if (btime >= arr[i] && bt[i] < min)
            {
                temp = p[k];
                p[k] = p[i];
                p[i] = temp;
                temp = arr[k];
                arr[k] = arr[i];
                arr[i] = temp;
                temp = bt[k];
                bt[k] = bt[i];
                bt[i] = temp;
            }
        }
        k++;
    }
    wait[0] = 0;
    for (i = 1; i < n; i++)
    {
        sum = sum + bt[i - 1];
        wait[i] = sum - arr[i];
        wsum = wsum + wait[i];
    }
    wavg = (wsum / n);
    for (i = 0; i < n; i++)
    {
        ta = ta + bt[i];
        turn[i] = ta - arr[i];
        tsum = tsum + turn[i];
    }
    tavg = (tsum / n);

    printf("\n");
    printf("p\tBT\tAT\tWT\tTAT\n");
    for (i = 0; i < n; i++)
        cout << "p" << p[i] << "\t" << bt[i] << "\t" << arr[i] << "\t" << wait[i] << "\t" << turn[i] << "\n";
    cout << "\n\nAVERAGE WAITING TIME : " << wavg;
    cout << "\nAVERAGE TURN AROUND TIME : " << tavg;

    return 0;
}