#include <bits/stdc++.h>
using namespace std;

double getGPA(int score){
	if(score >= 95){
		return 4.3;
	}
	if(score >= 90){
		return 4.;
	}
	if(score >= 85){
		return 3.7;
	}
	if(score >= 80){
		return 3.3;
	}
	if(score >= 75){
		return 3;
	}
	if(score >= 70){
		return 2.7;
	}
	if(score >= 67){
		return 2.3;
	}
	if(score >= 65){
		return 2.0;
	}
	if(score >= 62){
		return 1.7;
	}
	if(score >= 60){
		return 1.;
	}
	return 0.;
}



const int N = 401;
double dp[N];

int main(){
	int test;
	cin >> test;
	for(int _ = 0; _ < test; _++){
		int score;
		cin >> score;
		memset(dp, 0, sizeof dp);
		for(int i = 0; i <= 100; i++){
			dp[i] = getGPA(i);
		}
		for(int i = 101; i <= score; i++){
			for(int j = 0; j < i; j++){
				dp[i] = max(dp[i], dp[i - j] + dp[j]);
			}
		}
		
		printf("%.1f\n", dp[score]);
	}
	return 0;
}