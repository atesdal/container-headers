#ifndef DLIST_NODE_HPP
#define DLIST_NODE_HPP

/*
 * `D_ListNode` is a class of object used to compose the doubly linked-list. It has three
 * members: `data` contains the value at the given point in the list, 'next' is a pointer
 * to the next `D_ListNode` in the list and 'prev' is a pointer to the previous 'D_ListNode'
 */
template <typename T> class DListNode
{

public:

	// Construct a new `ListNode` with `data` containing `n`.
    DListNode(T n)
    {
        data = n;
        prev = nullptr;
        next = nullptr;
    }

	// Construct a new `ListNode` with `data` containing `n` and `next` as `succ` and 'prev' as 'pred'.
    DListNode(T n, DListNode *succ, DListNode *pred)
    {
        data = n;
        prev = pred;
        next = succ;
    }

	// Return true if this `D_ListNode` is the end of the `D_LinkedList`.
    bool isTail()
    {
        return (next == nullptr);
    }

    // Data members
    T data;
    DListNode *next;
    DListNode *prev;

};

#endif
