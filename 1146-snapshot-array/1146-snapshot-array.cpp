class SnapshotArray {
public:
        map<int,map<int,int>> mp;
        int snap_idd=0;
    SnapshotArray(int length) {
        for(int i=0;i<length;i++)    
        {
                mp[i][0]=0;
        }
    }
    void set(int index, int val) {
            //cout<<index<<" "<<val<<" "<<snap_idd<<endl;
        mp[index][snap_idd]=val;
    }
    int snap() {
        return snap_idd++;
    }
    int get(int index, int snap_id) {
//             for(auto it:mp)
//             {
//                     cout<<it.first<<"-->";
//                     for(auto gg:it.second)
//                     {
//                             cout<<gg.first<<" "<<gg.second<<endl;
//                     }
                    
//             }
       auto gg=mp[index].upper_bound(snap_id);
            gg--;
       return mp[index][gg->first];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */