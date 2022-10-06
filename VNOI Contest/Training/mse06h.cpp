/**
 Ví dụ có một số điểm cần nối, ta muốn biết xem có bao nhiêu cạnh cắt qua cạnh XY
 Nếu ta tính được, thì với mỗi cạnh ta có thể tính được và từ đó đưa ra đáp án
 		. . . . X . . . . . . .
		. . . . . . . Y . . . . 

Thuật toán:

Có 2 hướng:
	Hướng 1: Xét mỗi cạnh, đếm xem có bao nhiêu cạnh cắt qua nó
		Các cạnh mà có đỉnh nằm bên TRÁI X nối với các đỉnh bên PHẢI Y
		Các cạnh mà có đỉnh nằm bên PHẢI X nối với các đỉnh bên TRÁI Y

	Hướng 2: Xét mỗi cạnh, đếm xem có bao nhiêu cạnh không cắt qua nó, 
	sau đó lấy tổng số cạnh trừ đi:
		Các cạnh mà có đỉnh nằm bên TRÁI X và Y
		Các cạnh mà có đỉnh nằm bên PHẢI X và Y

Nhận xét: Hướng 2 thì X và Y nó cùng hướng nên nhìn có vẻ dễ tính hơn, nên thuật
toán này sẽ làm bằng cách 2, cách 1 em có thể tự suy nghĩ thêm

TH1: Các cạnh mà có đỉnh nằm bên TRÁI X và Y
		Ta sort tăng dần theo X và Y, sau đó gặp một cạnh XY ta đếm xem có bao nhiêu cạnh UV
	mà U <= X và V <= Y (như vậy để cạnh UV nằm hoàn toàn bên trái X, Y).
		Ta có thể duyệt theo chiều X hoặc chiều Y tăng dần sau đó chỉ cần đếm 1 chiều còn lại,
	Ta có số cạnh là N * N, mà khi cố định duyệt theo một chiều thì đếm chiều còn lại vẫn mất N,
	nên ta dùng cây BIT để đếm nhanh thao tác này (chỉ mất O(logN)), có thể dùng segment tree nhưng
	cài đặt lâu hơn, tốn nhiều thời gian hơn (số cạnh lớn, và multitest nên có thể TLE).
		ĐPT O(T * N * N * log(N))
TH2: Các cạnh mà có đỉnh nằm bên PHẢI X và Y
		Tương tự TH1, nhưng ta sort giảm, sau đó duyệt giảm dần một chiều cố định


								CÁCH CÀI ĐẶT 1:
	CÁCH NÀY ĐÚNG NHƯNG KHÁ MẤT THỜI GIAN, NÊN ĐỌC QUA ĐỂ BIẾT THUẬT TOÁN
	ĐÃ CẢI TIẾN Ở CÁCH CÀI ĐẶT 2 PHÍA DƯỚI.


#include<bits/stdc++.h>
using namespace std;

#define int long long //Chú ý số cạnh cắt qua mỗi cạnh là N * N mà có N * N => tràn int

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n, m, k;
vector<int> a[N];
int bit[N];

int Test = 0;

//update tăng (TH1)
void update1(int x, int val){
	for(; x < N; x += x&-x){
		bit[x] += val;
	}
}

//get giảm (TH1)
int get1(int x){
	int val = 0;
	for(; x >= 1; x -= x&-x){
		val += bit[x];
	}
	return val;
}

//update giảm (TH2)
void update2(int x, int val){
	for(; x >= 1; x -= x&-x){
		bit[x] += val;
	}
}

//get tăng (TH2)
int get2(int x){
	int val = 0;
	for(; x < N; x += x&-x){
		val += bit[x];
	}
	return val;
}

void solve(){
	
	cin >> n >> m >> k;

	//multitest nên cần clear dữ liệu
	for(int i = 1; i <= n; i++){
		a[i].clear();
	}

	//Có thể dùng mảng 1 chiều, nhưng nối cạnh theo kiểu đồ thị như này cũng được
	for(int i = 1; i <= k; i++){
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
	}

	//Số cạnh không cắt trúng
	int res = 0;

	/// ------------------>
	for(int i = 1; i <= n; i++){
		sort(a[i].begin(), a[i].end());
	}
	for(int i = 1; i < N; i++){
		bit[i] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j: a[i]){
			res += get1(j);
			update1(j, 1);
		}
	}

	/// <-----------------
	for(int i = n; i >= 1; i--){
		sort(a[i].begin(), a[i].end(), greater<int>() );
	}
	for(int i = 1; i < N; i++){
		bit[i] = 0;
	}

	for(int i = n; i >= 1; i--){
		for(int j: a[i]){
			res += get2(j);
			update2(j, 1);
		}
	}

	cout << "Test case " << ++Test << ": ";

	//Tổng số cạnh có thể cắt nhau
	int sum = k * (k - 1);
	
	//Trừ đi là ra đáp án
	cout << (sum - res) / 2 << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}
}
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long //Chú ý số cạnh cắt qua mỗi cạnh là N * N mà có N * N => tràn int

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int n, m, k;
vector<int> a[N];
int bit[N];

int Test = 0;

//update tăng
void update(int x, int val){
	for(; x < N; x += x&-x){
		bit[x] += val;
	}
}

//get giảm
int get(int x){
	int val = 0;
	for(; x >= 1; x -= x&-x){
		val += bit[x];
	}
	return val;
}


void solve(){
	
	cin >> n >> m >> k;

	//multitest nên cần clear dữ liệu
	for(int i = 1; i <= n; i++){
		a[i].clear();
	}

	//Có thể dùng mảng 1 chiều, nhưng nối cạnh theo kiểu đồ thị như này cũng được
	for(int i = 1; i <= k; i++){
		int u, v;
		cin >> u >> v;
		a[u].pb(v);
	}

	//Số cạnh không cắt trúng
	int res = 0;

	for(int i = 1; i <= n; i++){
		sort(a[i].begin(), a[i].end());
	}
	for(int i = 1; i < N; i++){
		bit[i] = 0;
	}

	for(int i = 1; i <= n; i++){
		for(int j: a[i]){
			res += get(j);
			update(j, 1);
		}
	}

	cout << "Test case " << ++Test << ": ";

	//Tổng số cạnh có thể cắt nhau là C(2, k)
	int sum = k * (k - 1) / 2; //Khác cài đặt 1 ở chỗ này
	
	//Trừ đi là ra đáp án
	cout << sum - res << '\n';
}


int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T; cin >> T; while(T--){solve();}	
}