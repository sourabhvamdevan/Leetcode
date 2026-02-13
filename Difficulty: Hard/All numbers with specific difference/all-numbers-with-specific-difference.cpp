class Solution {
  public:
  
  
  bool isGreater(int val, int d) {
	int digitSum = 0, tmp = val;
	while (tmp>0) {
		digitSum += tmp%10;
		tmp /= 10;
	}

	return val - digitSum >= d;
}



int getCount(int n, int d)

{
	

	int mini = n + 1;
	int s = 1, e = n;
	
	while (s<=e) {
		int mid = s + (e-s)/2;
        
		if (isGreater(mid, d)) {
			mini = mid;
			e = mid - 1;
		}
		else s = mid + 1;
	}
    
   
	return n+1-mini;
}
  
 
  
  
  
};