#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	for (int i = 2; i < n; i++) {
		if (i % 2 != 0) {
            int tmp = n;
            tmp/=i;
			if (n % i == 0&&tmp-(i/2)>0) {
				answer++;
			}
		}
		else {
			int tmp = n;
            tmp-=i/2;
            if(tmp%i==0&&(tmp/i)-(i/2)+1>0){
                answer++;
            }
            
		}
	}
	answer++;
	return answer;
}