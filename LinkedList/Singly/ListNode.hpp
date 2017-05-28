#ifndef LIST_NODE_HPP
#define LIST_NODE_HPP

/*
 * `ListNode` is a class of object used to compose the linked list. It has two
 * members, `data` contains the value at the given point in the list, while
 * `next` is a pointer to the next `ListNode` in the list.
 */
template <typename T> class ListNode
{

public:

	// Construct a new `ListNode` with `data` containing `n`.
    ListNode(T n)
    {
        data = n;
        next = nullptr;
    }

	// Construct a new `ListNode` with `data` containing `n` and `node` as `next`.
    ListNode(T n, ListNode<T> *node)
    {
        data = n;
        next = node;
    }

	// Return true if this `ListNode` is the end of the `LinkedList`.
    bool isTail()
    {
        return (next == nullptr);
    }

    T data;

    ListNode *next;

};

#endif
