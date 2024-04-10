#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* cur = prehead;
        int carry = 0;
        // 循环体是l1||l2
        while (l1 || l2) {
            int n1 = l1?l1->val:0;
            int n2 = l2?l2->val:0;
            int sum = n1 + n2 + carry;
            int num = sum % 10;
            carry = sum / 10;
            cur->next = new ListNode(num);
            cur = cur->next;
            if (l1)l1 = l1->next;
            if (l2)l2 = l2->next;
        }
        // 进位不要忘
        if (carry) cur->next = new ListNode(carry);
        return prehead->next;
    }
};

int main() {
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l2);

    return 0;
}

//哈希表（值，下标）
//哈希表找键用find，返回迭代器