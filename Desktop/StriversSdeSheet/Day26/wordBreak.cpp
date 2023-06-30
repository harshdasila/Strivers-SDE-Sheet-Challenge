#include <bits/stdc++.h> 
unordered_map<string, bool>um;
bool solve(vector<string>&arr, int n, string target)
{
    if(target.length() == 0)
        return true;

    if(um.find(target) != um.end())
        return um[target];
    
    for(auto &itr: arr)
    {
        if(itr == target.substr(0, itr.length()))
        {
            bool ans = solve(arr, n, target.substr(itr.length()));
            if(ans)
                return um[target] = true;
        }
    }

    return um[target] = false;
}

bool wordBreak(vector < string > & arr, int n, string & target) 
{
    um.clear();
    return solve(arr, n, target);
}