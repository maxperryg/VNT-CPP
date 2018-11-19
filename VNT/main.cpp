//
//  main.cpp
//  VNT
//
//  Created by Maxwell Perry Grossman on 11/14/18.
//  Copyright © 2018 Maxwell Perry Grossman. All rights reserved.
//
#include <iostream>
#include "VNT.cpp"
using namespace std;
int main(){
    
    VNT a(5,6);
    
    for(int i=0;i<31;i++){
        a.add(i*i);
    }
    if(a.find(25)){
        cout<<"Found 25 int VNT table\n";
    }
    if(!a.find(26)){
        cout<<"26 is not in the VNT table\n";
    }
    cout<<"The minimum value in VNT table is: "<<a.getMin()<<endl;
    
    int arr[10]= {2,6,9,0,3,1,8,4,7,5};
    cout<<"Unsorted array is:\n";
    for(auto e:arr)
        cout<<e<<" ";
    cout<<endl;
    
    a.sort(arr,10);
    cout<<"Sorted Array is:\n";
    for(auto e:arr)
        cout<<e<<" ";
    cout<<endl;
    
    return 0;
}
