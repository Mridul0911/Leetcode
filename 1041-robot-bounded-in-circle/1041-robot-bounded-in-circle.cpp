class Solution {
public:
    bool isRobotBounded(string instructions) {
         int x=0;
            int y=0;
            char curr_dir='N';
            for(int i=0;i<instructions.length();i++)
            {
                    if(instructions[i]=='G')
                    {
                            y+=curr_dir=='N' ? 1:0;
                            y+=curr_dir=='S' ? -1:0;
                            x+=curr_dir=='E' ? 1:0;
                            x+=curr_dir=='W' ? -1:0;
                    }
                    else
                    {
                            char dir=instructions[i];
                            if(curr_dir=='N')
                            {
                                    if(dir=='L')
                                    {
                                            curr_dir='W';
                                    }
                                    else
                                    {
                                            curr_dir='E';
                                    }
                            }
                            else if(curr_dir=='W')
                            {
                                    if(dir=='L')
                                    {
                                            curr_dir='S';
                                    }
                                    else
                                    {
                                            curr_dir='N';
                                    }
                                    
                            }
                            else if(curr_dir=='E')
                            {
                                    if(dir=='L')
                                    {
                                            curr_dir='N';
                                    }
                                    else
                                    {
                                            curr_dir='S';
                                    }
                                            
                            }
                            else
                            {
                                if(dir=='L')
                                {
                                        curr_dir='E';
                                }
                                    else
                                    {
                                            curr_dir='W';
                                    }
                            }
                    }
            }
            if(x==0 && y==0 || curr_dir!='N')
            {
                    return true;
            }
            return false;
                
             
             
            
            
    }
};