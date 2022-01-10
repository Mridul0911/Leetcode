class Solution {
public:
    bool isRobotBounded(string instructions) {
        
            vector<int> dir(2);
            dir[0]=0;
            dir[1]=1;
            vector<int> pos(2);
            pos[0]=0;
            pos[1]=0;
           for(int i=0;i<instructions.size();i++)
           {
                   if(instructions[i]=='R')
                   {
                        dir={dir[1],-dir[0]};
                   }
                   else if(instructions[i]=='L')
                   {
                         dir={-dir[1], dir[0]};
                   }
                   else
                   {
                           pos[0]=pos[0]+dir[0];
                           pos[1]=pos[1]+dir[1];
                   }
           }
            if(pos[0]==0 && pos[1]==0)
            {
                 return true;        
            }
            else if(dir[0]!=0 || dir[1]!=1)
            {
                    return true;
            }
            else
            {
                    return false;
            }
                   
            
                   
            
            
            
    }
};