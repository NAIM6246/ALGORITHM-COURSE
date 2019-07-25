#include<bits/stdc++.h>
using namespace std;
typedef pair<int , int>Pair;
int main(){
int n,bag_size;
cin>>n;
vector<Pair>v,u,w;
int a,b;
for(int i=0;i<n;i++){
    cin>>a>>b;
    v.push_back({a,b});
    u.push_back({a/b,i});
}
sort(u.begin(),u.end());
cin>>bag_size;
int j=n-1,profit=0;
while(bag_size>0 && j>=0){
    int pos = u[j].second,value = u[j].first;
    if(v[pos].second <= bag_size){
        profit+=(v[pos].second * value);
        bag_size-=v[pos].second;
        w.push_back({pos,v[pos].second});
    }
    else{
        profit+=(bag_size * value);

        w.push_back({pos,bag_size});
        bag_size=0;
    }
j--;
}
cout<<profit<<endl;
for(int i=0;i<w.size();i++){
    cout<<w[i].first+1<<" "<<w[i].second<<endl;
}
return 0;
}
