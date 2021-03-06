
//Accepted	1196 ms	java

public class Solution {
    public int ladderLength(String start, String end, HashSet<String> dict) {
        dict.add(start);
        dict.add(end);
        Pretreatment(dict);
        Queue<node> Q = new LinkedList<node>();
        Q.add(new node(1,start));
        vis[M.get(start)] = true;
        while(!Q.isEmpty())
        {
            node now = Q.poll();
            for(int i=0;i<now.buf.length();i++)
            {
                for(char j = 'a';j<='z';j++)
                {
                    if(now.buf.charAt(i) == j) continue;
                    StringBuilder sb = new StringBuilder(now.buf);
                    sb.setCharAt(i, j);
                    if(sb.toString().equals(end)) return now.step+1;
                    if(dict.contains(sb.toString()) && !vis[M.get(sb.toString())] )
                    {
                        vis[M.get(sb.toString())] = true;
                        Q.add(new node(now.step+1 , sb.toString() ));
                    }
                }
            }
        }
        return 0;
    }

    public void Pretreatment(HashSet<String> dict)
    {
        M = new HashMap<String,Integer>();
        n = 1;
        for(String str : dict)
        {
            M.put(str, n);
            n++;
        }
        vis = new boolean[n];
    }
    
    class node {
        public node(int s, String b) {
            step = s;
            buf = b;
        }

        int step;
        String buf;
    }

    private Map<String, Integer> M;
    private boolean vis[];
    private int n;
}

