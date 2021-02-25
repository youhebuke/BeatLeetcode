# 21. 合并两个有序链表
# 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/

# 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

# 思路1：递归：终止条件、递归函数，选择两个list中当前头节点最小的，其next为其余节点的合并结果。

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        if not l1:
            return l2
        if not l2:
            return l1
        if l1.val<l2.val:
            l1.next = self.mergeTwoLists(l1.next,l2)
            return l1
        else:
            l2.next = self.mergeTwoLists(l1,l2.next)
            return l2


# 思路2：while循环

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        if not l1:
            return l2
        if not l2:
            return l1
        
        head = ListNode(-1)
        p = head
        while l1 and l2:
            if l1.val<l2.val:
                p.next = l1
                l1 = l1.next
            else:
                p.next = l2
                l2 = l2.next
            p = p.next 
        
        if l1:
            p.next = l1
        else:
            p.next = l2
        
        return head.next
