#include<bits/stdc++.h>
using namespace std;


void insertAtBottom(stack<int> &st,int n){
    if(st.empty()){
        st.push(n);
        return ;
    }
        int temp=st.top();
        st.pop();
        insertAtBottom(st,n);
        st.push(temp);
    
}
void reverse(stack<int> &st){
    if(st.empty()){
        return;
    }
    else{
        int temp=st.top(); 
        st.pop();
        reverse(st);
        insertAtBottom(st,temp);
        
    }
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    // cout<<endl;
    int n=0;
    // insertAtBottom(st,n);
    
    reverse(st);
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    return 0;
}