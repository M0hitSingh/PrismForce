#include <bits/stdc++.h>
using namespace std;
#define int long long

// IMPORTANT POINTS
// circles  - k1 , k2 , ... k11 
// starting power = p
// can skip = a times
// recharge power = b times


/* TESTCASE - 1
 circle = 10 12 5 7 6 0 2 0 13 7 19
 p = 30
 skip = 4
 b = 0
*/

/* TESTCASE - 2
 circle = 2 2 2 1 2 2 2 1 2 2 2
 p = 8
 skip = 2
 b = 1
*/

bool solve(vector < int > &circle, int p, int skip, int b){
    int power = p;
    // updating final circle power of enemy by adding 3rd and 7th enemy half power to next circle
    for(int i = 0; i < circle.size(); i++){
        if(i==3 || i == 7) circle[i] += circle[i-1]/2; 
    }

    // sorting to final power of enemy in decreasing order
    sort(circle.rbegin(),circle.rend());

    // skipping the most powerful enemy
    for(int i = skip; i < circle.size(); i++){
        if(circle[i] <= power){                             // kill the enemy 
            power -= circle[i];
        }
        else if(b){
            b--;                                    
            power = p;                                      // recharging power to full
            if(circle[i]> power) return false;              // cannot kill the enemy
            power -= circle[i];                             // kill the enemy
        }
        else return false;                                  // cannot recharge
    }
    return true;                                            // killed all enemy
}

signed main(){
    vector < int > circle(11);
    for(int i = 0 ; i < 11; i++) cin >> circle[i];
    int p, skip, b;
    cin >> p >> skip >> b;
    if(solve(circle, p, skip, b)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}