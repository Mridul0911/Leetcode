class Solution {
public:
    bool winnerOfGame(string colors) {
            if(colors.size()==2)
            {
                    return false;
            }
        int alice=0;
            int bob=0;
            for(int i=1;i<colors.size();i++)
            {
                    if(colors[i]=='A' && colors[i-1]=='A' && colors[i+1]=='A')
                    {
                            alice++;
                    }
                    else if(colors[i]=='B' && colors[i-1]=='B' && colors[i+1]=='B')
                    {
                            bob++;
                    }
            }
            if(alice==bob || alice<bob)
                return false;
            else
                return true;
    }
};