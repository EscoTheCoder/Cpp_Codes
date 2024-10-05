#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int missingNumber(vector<int>& nums) {

    int n=nums.size();
    int k;
    for(int i=0; i<=n; i++){
        int cnt=count(nums.begin(), nums.end(), i);
        if(cnt==0){
            k=i;
        }
    }
    return k;
}

int main() {

    vector<int> nums={3,0,1};
    cout<<missingNumber(nums);

    return 0;
}
