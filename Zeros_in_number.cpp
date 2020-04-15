//returns number of zeros at end of number
//ex: 3628800 returns 2

func(int n){
	while(n%2==0){
		n = n/2;
	}
	while(n%3 == 0)
		n/=3;
	int count = 0;
	while(n%5 == 0){
		count++;
		n /= 5;
	}
	return count;
}
