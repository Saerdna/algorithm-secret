# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    # @return a ListNode
    def getValue(self, linkList):
        ptr = linkList.next
        arr = [linkList.val]
        while ptr != None:
            arr.append(ptr.val)
            ptr = ptr.next
        return int(''.join(map(str, arr[::-1])))
    def addTwoNumbers(self, l1, l2):
        num1 = self.getValue(l1)
        num2 = self.getValue(l2)
        ret = str(num1 + num2)
        linkList = None
        ptr = None
        for x in ret:
            if linkList == None:
                linkList = ListNode(int(x))
            else:
                head = ListNode(int(x))
                head.next = linkList
                linkList = head
        return linkList
                

l1 = ListNode(1)
l1.next = ListNode(8)
l2 = ListNode(0)
l3 = Solution().addTwoNumbers(l1, l2)
print l3.val, l3.next.val
