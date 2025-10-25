#include <bits/stdc++.h>
using namespace std;

string warnaLampu(int t){
    int dur_green = 20;
    int dur_yellow = 3;
    int dur_red = 80;
    int cycle = dur_green + dur_yellow + dur_red;

    int t0 = 25;

    int s = (t - t0) % cycle;
    if (s < 0) s += cycle;

    if (s >= 0 && s < dur_green)
        return "Hijau";
    else if (s >= dur_green && s < dur_green + dur_yellow)
        return "Kuning";
    else
        return "Merah";
}

int main(){
    int n; cin>>n;
    int times[n];
    for(int i = 0; i < n; i++){
        cin>>times[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout<<"Warna lampu pada detik ke-"<<times[i]<<" : "<<warnaLampu(times[i])<<endl;
    }
    
    return 0;
}