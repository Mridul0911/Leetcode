class TextEditor {
        list<char> dl;
        list<char>:: iterator cursorPoint;
public:
        
    TextEditor() {
             ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
        dl.push_back('|');
            cursorPoint=dl.begin();
    }
   // L E E T C O D E | 
   // 0 1 2 3 4 5 6 7 8
    //  void printList()
    // {
    //         for(auto it:dl)
    //         {
    //                 cout<<it;
    //         }
    //      cout<<endl;   
    // }
            
    void addText(string text) {
        for(int i=0;i<text.size();i++)
        {
                dl.insert(cursorPoint,text[i]);
        }
            //printList();
    }
        
   // L E E T C O D E | 
   // 0 1 2 3 4 5 6 7 8
    int deleteText(int k) {
        auto itr=cursorPoint;
            int TotalDeleted=k;
            if(itr==dl.begin()) return 0;
            itr--;
           // cout<<"HELLO";
            while(k && itr!=dl.begin())
            {
                    auto itr2=itr;
                    itr2--;
                    dl.erase(itr);
                    itr=itr2;
                    k--;
            }
            if(k)
            {
                    k--;
                    dl.erase(dl.begin());
            }
          //  printList();
            return TotalDeleted-k;
    }
    // L E E T C O D E | 
   // 0 1 2 3 4 5 6 7 8
    string cursorLeft(int k) {
        auto itr=cursorPoint;
            auto prev=itr;
            while(itr!=dl.begin() && k)
            {
                    itr--;
                    k--;
            }
            cursorPoint=dl.insert(itr,'|');
            dl.erase(prev);
            return makeString();
            
    }
    string makeString()
    {
           string ans="";
            auto itr=cursorPoint;
            int x=10;
           if(itr==dl.begin()) return "";
            itr--;
            while(itr!=dl.begin() && x)
            {
                    ans=ans+(*itr);
                    itr--;
                    x--;
            }
            if(x)
            {
                    ans+=(*dl.begin());
            }
            reverse(ans.begin(),ans.end());
            cout<<"Value of cursor right is"<<" "<<ans<<endl;
            return ans;
    }
    string cursorRight(int k) 
    {
        auto itr=cursorPoint;
            auto prev=itr;
          if(itr==dl.end())
          {
                  return makeString();
          }
          else
          {
                  itr++;
                  while(k && itr!=dl.end())
                  {
                          itr++;
                          k--;
                  }
                  cursorPoint=dl.insert(itr,'|');
                  dl.erase(prev);
                  return makeString();
          }
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */