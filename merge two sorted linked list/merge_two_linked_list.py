class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def merging(list1:Node, list2:Node):
    head = Node(-1)
    curr = head
    while(list1  and list2):
        if(list1.data <= list2.data):
            curr.next = list1
            list1 = list1.next
        else:
            curr.next = list2
            list2 = list2.next
        curr = curr.next

    if(list1):
        curr.next  = list1
    if(list2):
        curr.next  = list2

    return head.next


if __name__ == "__main__":
    head1 = Node(1)
    head1.next = Node(10)
    head1.next.next = Node(30)
    head1.next.next.next = Node(35)
    head1.next.next.next.next = Node(40)

    head2 = Node(3)
    head2.next = Node(29)
    head2.next.next = Node(33)
    head2.next.next.next = Node(39)

    head = merging(head1, head2)

    curr = head
    while(curr):
        print(curr.data , end=" -> ")
        curr = curr.next
    print("end")