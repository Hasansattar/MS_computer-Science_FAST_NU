#include<bits/stdc++.h>
using namespace std;
class traffic{
deque<int> north;
deque<int> south;
public:
void addCar(int dir){
if(dir == 1){
north.push_back(1);
}
else if(dir == 2){
south.push_back(1);
}
}
void removeCar(int dir){
if(dir == 1){
north.pop_back();
}
else if(dir == 2){
south.pop_back();
}
if(north.size() == 0 && south.size() == 0){
cout<<"Traffic is clear\n";
}
}
}