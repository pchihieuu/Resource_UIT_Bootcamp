#include<bits/stdc++.h>
using namespace std;

#define int long long

int d;
long double a[11 + 5];

long double val(long double m){
	long double v = 0, x = 1;
	for(int i = 0; i <= d; i++){
		v = v + a[i] * x;
		x = x * m;
	}
	return v;
}

int32_t main(){
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> d;
	for(int i = 0; i <= d; i++){
		cin >> a[i];
	}

	/*
	Nhận xét: Đây là hàm số đồng biến hoặc nghịch biến liên tục trên D = [-1e6; 1e6]
	=> Ta có thể chặt nhị phân
	*/

	double l = -1e6, r = 1e6;
	if(val(l) > val(r)){ //Nếu hàm giảm thì đổi dấu để thành hàm tăng
		for(int i = 0; i <= d; i++){
			a[i] *= -1;
		}
	}

	//Dựa vào mid ta dồn l và r lại gần nhau
	while(abs(val((l + r) / 2)) > 1e-3){
	// Do có sai số nên ta thay "> 0" thành "> 0.001"
	// Nếu nghiệm là số vô tỉ mà ta để "> 0" thì sẽ bị TLE
	//Trong khi độ chính xác chỉ cần 3 chữ sô thập phân, nên ta chỉ cần xét tận 1e-3 là đủ rồi
		long double m = (l + r) / 2;
		long double v = val(m);
		if(v > 0){
			r = m; //Không cần để r = m - 1, bởi vì ta đang xét số thực chứ không phải số nguyên
		}
		else{
			l = m; //Không để l = m + 1 lí do tương tự với r
		}
	}
	cout << (int)((l + r) / 2 * 1000);
}