class Solution {
public:
    bool isRobotBounded(string instructions) {
        
     char current_dir = 'N';
        int x = 0, y= 0;
        for(int i=0;i<instructions.length();i++){ 
            if(instructions[i] == 'G')
            {
                y += current_dir =='N' ? 1 : 0;
				y += current_dir =='S' ? -1 : 0;
				x += current_dir == 'E' ? 1 : 0;
				x += current_dir == 'W' ? -1 : 0;
            }
            else
            {
                char incoming = instructions[i];
                if(current_dir == 'N'){
                    if(incoming=='L')
                    {
                            current_dir='W';
                    }
                    else
                    {
                                current_dir='E';
                    }
                 }
                else if(current_dir == 'W'){
                    if(incoming=='L')
                    {
                            current_dir='S';
                    }
                    else
                    {
                                current_dir='N';
                    }
                }
                else if(current_dir == 'S'){
                    if(incoming=='L')
                    {
                            current_dir='E';
                    }
                    else
                    {
                                current_dir='W';
                    }
          
                }
                else{
                                  if(incoming=='L')
                    {
                            current_dir='N';
                    }
                    else
                    {
                                current_dir='S';
                    }
           }
            } 
            
        }
        
        if(x==0 && y==0 || current_dir!='N')
            return true;
        
        return false;
            
            
    }
};