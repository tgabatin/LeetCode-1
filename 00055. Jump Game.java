
//Accepted	376 ms	java
public class Solution {
    public boolean canJump(int[] A) {
        int limit = A.length-1;
        for(int i=A.length-2;i>-1;i--)
            if(i+A[i] >= limit) limit = i;
        if(limit == 0) return true;
        
        return false;
    }
}
