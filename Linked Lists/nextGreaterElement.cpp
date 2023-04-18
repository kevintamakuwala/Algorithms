/*
    Problem Link: https://leetcode.com/problems/next-greater-node-in-linked-list/

    You are given the head of a linked list with n nodes.
    For each node in the list, find the value of the next greater node. 
    That is, for each node, find the value of the first node that is next to it 
    and has a strictly larger value than it.
    Return an integer array answer where answer[i] is the value of the next greater 
    node of the ith node (1-indexed). If the ith node does not have a next greater node, 
    set answer[i] = 0.
*/
class Solution {
public:
vector<int> nextLargerNodes(ListNode* h) 
{
    vector<int> res, stack;
        
    for (auto p = h; p != nullptr; p = p->next) 
      res.push_back(p->val);
        
    for (int i = res.size() - 1; i >= 0; --i) 
    {
        auto val = res[i];
        
        while (!stack.empty() && stack.back() <= res[i]) 
            stack.pop_back();
        
        res[i] = stack.empty() ? 0 : stack.back();
        stack.push_back(val);
    }
    return res;
          
}
};