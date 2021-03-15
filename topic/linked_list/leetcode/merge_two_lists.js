/* 21. 合并两个有序链表
 链接：https://leetcode-cn.com/problems/merge-two-sorted-lists/

 将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */

/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * 迭代法:
 * 新建一个链表，用于表示结果，一个用于遍历的指针；
 * 如果两个链表都不是空的时候，比较两个链表的当前值，将结果链表的指针下一个指向较小值节点，并分别移动结果链表指针 和 较小值节点所在链表的指针
 * 最后将结果指针的下一个指向剩余的非空链表后，返回除头节点的剩余链表
 *  */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var mergeTwoLists = function (l1, l2) {
  const result = new ListNode()

  let current = result
  while (l1 !== null && l2 !== null) {
    if (l1.val <= l2.val) {
      current.next = l1
      l1 = l1.next
    } else {
      current.next = l2
      l2 = l2.next
    }

    current = current.next
  }

  current.next = l1 === null ? l2 : l1

  return result.next
}
