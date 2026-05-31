class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long sum = mass;
        for(auto&it : asteroids) {
            if(it > sum) return false;
            sum += it;
        }
        return true;
    }
};