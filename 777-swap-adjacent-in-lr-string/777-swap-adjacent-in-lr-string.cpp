class Solution {
public:
    bool canTransform(string start, string end) {
       for (int i = 0, j = 0;;)
       {
        if (start[i] == 'X')
        {
                ++i;
        }
        else if (end[j] == 'X')
        {
                ++j;
        }
        else if (end[j] != start[i])
        {
                return false;
        }
        else if (end[j] == 0)
        {
                return true; 
        }
        else if (end[j] == 'L' and i < j) 
        {
                return false;
        }
        else if (end[j] == 'R' and i > j) 
        {
                return false;
        }
        else
        {
                ++i, ++j;
        }
       }
    }
};