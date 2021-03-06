
//Accepted	308 ms	java
public class Solution {
    public int climbStairs(int n) {
    	int fir = 1;
    	int sec = 2;
    	if(n == 1) return 1;
    	if(n == 2) return 2;
    	
    	int count = 3;
    	int ans = fir+sec;
    	while(count < n)
    	{
    		count++;
    		fir = sec;
    		sec = ans;
    		ans = fir+sec;
    	}
    	return ans;
    }
}
