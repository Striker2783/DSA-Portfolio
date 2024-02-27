
#include "linked_list.h"
namespace DataStructures
{
    /**
     * @brief Construct a new LinkedList:: LinkedList object
     *
     * @param sz Size of the sequence
     */
    LinkedList::LinkedList(size_type sz)
    {
        numElts = sz;
        // If the size is 0, set head and tail to null and exit
        if (sz == 0)
        {
            head = tail = nullptr;
            return;
        };
        SequenceNode *curr = new SequenceNode();
        head = curr;
        // Loop sz - 1 times to create new nodes and at them at the end
        // sz - 1 because we already created a node
        for (; sz > 1; sz--)
        {
            SequenceNode *newN = new SequenceNode();
            curr->next = newN;
            newN->prev = curr;
            curr = newN;
        }
        // Sets the tail to the last element in the list
        tail = curr;
    }

    /**
     * @brief Copy Constructor
     *
     * @param s LinkedList to be copied
     */
    LinkedList::LinkedList(const LinkedList &s)
    {
        // Head is null so that the clear method skips the loop
        head = nullptr;
        *this = s;
    }

    /**
     * @brief Destroy the LinkedList:: LinkedList object
     *
     */
    LinkedList::~LinkedList()
    {
        clear();
    }
    /**
     * @brief Sets the current sequence to s
     *
     * @param s LinkedList to be copied
     * @return LinkedList&
     */
    LinkedList &LinkedList::operator=(const LinkedList &s)
    {
        // Clears the data in the sequence
        clear();
        // Loops through s' nodes and put it at the tail
        for (SequenceNode *curr = s.head; curr; curr = curr->next)
        {
            push_back(curr->elt);
        }
        return *this;
    }
    /**
     * @brief Indexes the sequence
     *
     * @param position index to get
     * @throw Index < 0 or Index >= size of the sequence
     * @return LinkedList::value_type&
     */
    LinkedList::value_type &LinkedList::operator[](size_type position)
    {
        return get(position)->elt;
    }
    /**
     * @brief Inserts a node at the end of the sequence
     *
     * @param value value to be inserted
     */
    void LinkedList::push_back(const value_type &value)
    {
        SequenceNode *newTail = new SequenceNode(value);
        // If empty, then set head and tail to a new node.
        if (empty())
        {
            head = tail = newTail;
        }
        else
        // Else add a new node at the back of the sequence
        {
            newTail->prev = tail;
            tail->next = newTail;
            tail = newTail;
        }
        numElts++;
    }
    /**
     * @brief Removes an an element from the end of the sequence
     * @throws The sequence is empty
     */
    void LinkedList::pop_back()
    {
        if (empty())
        {
            throw std::exception();
        }
        // If there is one element, then clear the data
        else if (numElts == 1)
        {
            delete head;
            head = tail = nullptr;
            numElts = 0;
            return;
        }
        // Gets what the tail will be at the end
        SequenceNode *finalTail = tail->prev;
        delete tail;
        tail = finalTail;
        finalTail->next = nullptr;

        numElts--;
    }

    /**
     * @brief Inserts an element at position
     *
     * @param position Index to be inserted
     * @param value Value to be inserted
     * @throw If position >= size of sequence
     */
    void LinkedList::insert(size_type position, value_type value)
    {
        if (position < 0 || position >= numElts)
        {
            throw std::exception();
        }
        // If position is 0, then insert at head
        if (position == 0)
        {
            SequenceNode *newHead = new SequenceNode(value);
            newHead->next = head;
            // Since numElts != 0, head exists
            head->prev = newHead;
            head = newHead;
        }
        // Else insert the node in between position - 1 and position
        else
        {
            // Gets the node after the insert
            SequenceNode *after = get(position);
            // Gets the node right before the insert
            SequenceNode *curr = after->prev;
            SequenceNode *newN = new SequenceNode(value);
            // Inserts newN between after and curr
            newN->next = after;
            after->prev = newN;
            curr->next = newN;
            newN->prev = curr;
        }
        numElts++;
    }

    /**
     * @brief Gets the first element of the sequence
     *  @throw LinkedList is empty
     * @return const LinkedList::value_type&
     */
    const LinkedList::value_type &LinkedList::front() const
    {
        if (empty())
        {
            throw std::exception();
        }
        return head->elt;
    }
    /**
     * @brief Gets the last element of the sequence
     *  @throw LinkedList is empty
     * @return const LinkedList::value_type&
     */
    const LinkedList::value_type &LinkedList::back() const
    {
        if (empty())
        {
            throw std::exception();
        }
        return tail->elt;
    }
    /**
     * @brief Returns if the sequence is empty
     *
     * @return true if sequence is empty\
     * @return false if sequence is not empty
     */
    bool LinkedList::empty() const
    {
        return numElts == 0;
    }
    /**
     * @brief Returns the size of the sequence
     *
     * @return LinkedList::size_type
     */
    LinkedList::size_type LinkedList::size() const
    {
        return numElts;
    }
    /**
     * @brief Clears the sequence's fields and frees its memory
     *
     */
    void LinkedList::clear()
    {
        SequenceNode *curr = head;
        // Loops through all nodes and destroys them
        while (curr)
        {
            SequenceNode *temp = curr->next;
            delete curr;
            curr = temp;
        }
        // Clears the fields
        head = tail = nullptr;
        numElts = 0;
    }
    /**
     * @brief Removes count elements starting at position
     *  @throw position + count > numElts
     *  @throw sequence is empty
     * @param position index to start erasing
     * @param count number of elements to remove
     */
    void LinkedList::erase(size_type position, size_type count)
    {
        if (position + count > numElts || empty())
        {
            throw std::exception();
        }
        // The node to be erased
        // At the end, it is the node after all the erased nodes
        SequenceNode *curr = get(position);
        // The node before the erasure
        SequenceNode *first = curr->prev;
        // Loops count times and deletes the nodes
        for (int i = 0; i < count; i++)
        {
            SequenceNode *next = curr->next;
            delete curr;
            curr = next;
        }
        // If first exists, then set its next to curr
        if (first)
        {
            first->next = curr;
        }
        // Else, set curr as the head because the head has been deleted
        else
        {
            head = curr;
        }
        // If curr exists, set its prev to first
        if (curr)
        {
            curr->prev = first;
        }
        // Else set the tail to first because the tail has been deleted
        else
        {
            tail = first;
        }
        numElts -= count;
    }

    /**
     * @brief Prints s to os
     *
     * @param os ostream
     * @param s sequence
     * @return ostream&
     */
    std::ostream &operator<<(std::ostream &os, const LinkedList &s)
    {
        s.print(os);
        return os;
    }
    /**
     * @brief Prints LinkedList to os
     *
     * @param os
     */
    void LinkedList::print(std::ostream &os) const
    {
        os << "<";
        // If there is no head, then exit
        if (head == nullptr)
        {
            os << ">";
            return;
        }
        SequenceNode *curr = head;
        // Loops through each node and prints it
        for (; curr->next; curr = curr->next)
        {
            os << curr->elt << ", ";
        }
        // Print the last node
        os << curr->elt << ">";
    }
    /**
     * @brief Gets the element at position
     *
     * @param position index
     * @throw sequence is empty
     * @throw position >= number of elements
     * @return LinkedList::SequenceNode*
     */
    LinkedList::SequenceNode *LinkedList::get(size_type position)
    {
        if (empty() || position >= numElts)
        {
            throw std::exception();
        }
        // If position is in the lower half of elements, travel via next
        if (position < numElts / 2)
        {
            SequenceNode *curr = head;
            // Loops position times and move curr to next
            for (; position > 0; position--)
            {
                curr = curr->next;
            }
            return curr;
        }
        // Else travel via prev
        else
        {
            // How many times to travel backwards
            position = numElts - position - 1;
            SequenceNode *curr = tail;
            // Loop position times and move curr to prev
            for (; position > 0; position--)
            {
                curr = curr->prev;
            }
            return curr;
        }
    }
}