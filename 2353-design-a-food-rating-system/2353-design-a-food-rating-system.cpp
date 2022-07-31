class FoodRatings {
public:
       map<string,set<pair<int,string>>> mp; 
        unordered_map<string,string> footocui;
        unordered_map<string,int> foodToRa;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings)     {
            for(int i=0;i<foods.size();i++)
            {
                    mp[cuisines[i]].insert({-ratings[i],foods[i]});
                    footocui[foods[i]]=cuisines[i];
                    foodToRa[foods[i]]=ratings[i];
            }
    }
    void changeRating(string food, int newRating) {
       int rating=foodToRa[food];
            string cui=footocui[food];
            mp[cui].erase({-rating,food});
            mp[cui].insert({-newRating,food});
            foodToRa[food]=newRating;
    }
    string highestRated(string cuisine) {
        auto it=*mp[cuisine].begin();
            return it.second; 
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */