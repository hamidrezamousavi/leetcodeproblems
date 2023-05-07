import "fmt"
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func lenList(head *ListNode) int{
    lenList := 0 
    for  head.Next != nil  {
               lenList++
               head = head.Next
        }
    return lenList + 1
    
}
func rotateRight(head *ListNode, k int) *ListNode {
    
   
    if head == nil || head.Next == nil{
        return head
    }
    rotation := k % lenList(head) 
    for i:= 0 ; i < rotation; i++{
        listHead := head
        tempNode := head 
        
        for  head.Next != nil  {
               tempNode = head 
               head = head.Next
        } 
        head = tempNode.Next
        head.Next =listHead
        tempNode.Next = nil
       
        }
    return head
}