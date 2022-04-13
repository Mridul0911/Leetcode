class Solution {
public:
    string intToRoman(int num) {
            ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        map<int,string> m={{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"},{4,"IV"},{9,"IX"},{40,"XL"},{90,"XC"},{400,"CD"},{900,"CM"}};
            string s="";
            int res;
            int x;
         while(num!=0)
         {
                 if((num/1000)!=0)
                 {
                        res=num;
                         x=res/1000;
                         num=num%1000;
                         for(int i=0;i<x;i++)
                         {
                                 s+=m[1000];
                         }
                         continue;
                 }
                 else if((num/900)!=0)
                 {
                         s+=m[900];
                         num=num%900;
                         continue;
                 }
                 else if((num/500)!=0)
                 {
                         res=num;
                         x=res/500;
                         num=num%500;
                         for(int i=0;i<x;i++)
                         {
                                 s+=m[500];
                         }
                         continue;
                 }
                 else if((num/400)!=0)
                 {
                         s+=m[400];
                         num=num%400;
                         continue;
                 }
                 else if((num/100)!=0)
                 {
                        res=num;
                         x=res/100;
                         num=num%100;
                         for(int i=0;i<x;i++)
                         {
                                 s+=m[100];
                         }
                         continue;
                 }
                 else if((num/90)!=0)
                 {
                         s+=m[90];
                         num=num%90;
                         continue;
                 }
                 else if((num/50)!=0)
                 {
                                 res=num;
                         x=res/50;
                         num=num%50;
                         for(int i=0;i<x;i++)
                         {
                                 s+=m[50];
                         }
                         continue;
                
                 }
                 else if((num/40)!=0)
                 {
                         s+=m[40];
                         num=num%40;
                         continue;
                 }
                 else if((num/10)!=0)
                 {
                                 res=num;
                         x=res/10;
                         num=num%10;
                         for(int i=0;i<x;i++)
                         {
                                 s+=m[10];
                         }
                         continue;
                  }
                 else if((num/9)!=0)
                 {
                         s+=m[9];
                         num=num%9;
                         continue;
                 }
                 else if((num/5)!=0)
                 {
                           res=num;
                         x=res/5;
                         num=num%5;
                         for(int i=0;i<x;i++)
                         {
                                 s+=m[5];
                         }
                         continue;
                 }
                 else if((num/4)!=0)
                 {
                         s+=m[4];
                         num=num%4;
                         continue;
                 }
                 else
                 {
                         for(int i=0;i<num;i++)
                         {
                                 s+=m[1];
                         }
                         break;
                 }
         }
            return s;
            
    }
};