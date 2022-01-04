class Solution {
public:
        unsigned int find(unsigned int n)
        {
                vector<int> inp;
                while(n!=0)
                {
                        inp.push_back(n%2);
                        n=n/2;
                }
                reverse(inp.begin(), inp.end());
          for (int i = 0; i < inp.size(); i++) {
                if (inp[i] == 0)
                        inp[i] = 1;
                else
                    inp[i] = 0;
          }
    int two = 1;
    for (int i = inp.size() - 1; i >= 0; i--) {
        n = n + inp[i] * two;
        two = two * 2;
    }
         return n;       
}
    int bitwiseComplement(int n) 
    {
            if(n==0)
            {
                    return 1;
            }
        int x=find(n);
            return x;
    }
};