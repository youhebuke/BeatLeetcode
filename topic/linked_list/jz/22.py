# 22_链表中倒数第k个节点
# 链接：https://leetcode-cn.com/problems/lian-biao-zhong-dao-shu-di-kge-jie-dian-lcof/

# 解法1
# 思路：双指针法，第一个指针走k次，第二个指针开始走，直到第一个指针走到链表末尾。

# code

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        
        num = 0
        p = head
        while p:
            p = p.next
            num += 1
            if num==k:
                break
        if num<k:
            return None
        while p:
            p = p.next
            head = head.next
        
        return head
      
 
# 解法2
# 思路：双指针法，第一个指针走k次，第二个指针开始走，直到第一个指针走到链表末尾。

# code

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        
        num = 0
        p = head
        while p:
            p = p.next
            num += 1
            if num==k:
                break
        if num<k:
            return None
        while p:
            p = p.next
            head = head.next
        
        return head
