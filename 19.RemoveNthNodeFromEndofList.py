# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        prev, slow, fast = dummy, head, head
        for _ in range(n):
            fast = fast.next
        while fast:
            prev = prev.next
            slow = slow.next
            fast = fast.next
        prev.next = slow.next
        return dummy.next
