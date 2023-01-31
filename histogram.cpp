#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerToRight(vector<int> &heights){
        stack<int> st;
        vector<int> res(heights.size());

        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            res[i]=(st.empty() ? heights.size(): st.top());
            st.push(i);
        }
        return res;
    }
    vector<int> nextSmallerToLeft(vector<int> &heights){
        stack<int> st;
        vector<int> res(heights.size());

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            res[i]=(st.empty() ? -1: st.top());
            st.push(i);
        }
        return res;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector<int> left;
        vector<int> right;
        left=nextSmallerToLeft(heights);
        right=nextSmallerToRight(heights);
        int ans=0;
        for(auto i:left){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:right){
            cout<<i<<" ";
        }
        cout<<endl;

        for(int i=0;i<heights.size();i++){
            ans=max(ans,(((right[i])-(left[i])-1)*heights[i]));
        }
        return ans;
    }
};