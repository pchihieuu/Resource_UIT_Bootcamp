#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	//freopen("test.txt", "r", stdin);
	int N, B, H, W;
    while (cin >> N >> B >> H >> W){
        int res = B + 1;
        for (int h = 0; h < H; h++){
            int p;
            cin >> p;
            for (int w = 0; w < W; w++){
                int a;
                cin >> a;
                if (a >= N && p * N <= res)
                    res = p * N;
            }
        }
        if (res <= B)
            cout << res << endl;
        else
            cout << "stay home" << endl;
    }
	
}