/**
 * 两个有序数组，查找中位数
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        auto A = nums1.begin();
        auto B = nums2.begin();
        if (m > n) { // to ensure m<=n
            auto temp = A;
            A = B;
            B = temp;
            int tmp = m;
            m = n;
            n = tmp;
        }
        int iMin = 0;
        int iMax = m;
        int halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j-1] > A[i]) {
                iMin = i + 1; // i is too small
            } else if (i > iMin && A[i-1] > B[j]) {
                iMax = i - 1; // i is too big
            } else { // i is perfect
                int maxLeft = 0;
                if (i == 0) {
                    maxLeft = B[j-1];
                } else if (j == 0) {
                    maxLeft = A[i-1];
                } else {
                    maxLeft = max(A[i-1], B[j-1]);
                }
                if ( (m + n) % 2 == 1 ) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == m) { 
                    minRight = B[j];
                } else if (j == n) {
                    minRight = A[i];
                } else {
                    minRight = min(B[j], A[i]);
                }
                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

/**
 * Definition for singly-linked list.
 * K 个一组翻转链表
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k <= 1) {
            return head;
        }
        ListNode* cur = head;
        int count = 0;
        while (cur != nullptr) {
            ++count;
            cur = cur->next;
        }
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int tmpDiv = count / k;
        ListNode* tmpPre = dummy;
        ListNode* tmpCur = head;
        ListNode* tmpNext;       
        for (int i = 0; i < tmpDiv; ++i) {
            for (int j = 0; j < k - 1; ++j) {
                tmpNext = tmpCur->next;
                tmpCur->next = tmpNext->next;
                tmpNext->next = tmpPre->next;
                tmpPre->next = tmpNext;
            }
            tmpPre = tmpCur;
            tmpCur = tmpPre->next;
        }
        return dummy->next;
    }
};