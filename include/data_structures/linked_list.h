#pragma once

#include <iostream>
#include <exception>
#include <stddef.h>

namespace DataStructures
{
	template <typename T>
	class LinkedList
	{
	public:
		/// @brief Creates an empty sequence (numElts == 0) or
		///	a sequence of numElts items indexed from 0 ... (numElts - 1).
		/// @param sz number of elements to create the sequence with
		LinkedList(size_t sz = 0);

		/// @brief Creates a (deep) copy of sequence seq.
		/// @param s LinkedList to be copied
		LinkedList(const LinkedList &s);

		/// @brief Destroys all items in the sequence and release the memory associated
		/// with the sequence
		~LinkedList();

		/// @brief The current sequence is released and replaced by a (deep) copy of
		/// sequence (seq). A reference to the copied sequence is returned.
		/// @param s the sequence to be copied
		/// @return *this with elements from s copied into
		LinkedList &operator=(const LinkedList &s) const;

		/// @brief The position satisfies ( position >= 0 && position <= last_index( ) ).
		/// The return value is a reference to the item at index position in the sequence.
		/// throws an exception	if the position is outside the bounds of the sequence
		/// @param p position of item being accessed
		/// @return reference to the item at index position in the sequence
		T &operator[](size_t p) const;

		/// @brief The value of item is append to the sequence.
		/// @param v item to be added
		void push_back(const T &v);

		/// @brief The size of the sequence is greater than zero. Postcondition: The item
		/// at the end of the sequence is deleted and size of the sequence is reduced by one.
		void pop_back();

		/// @brief The position satisfies ( position >= 0 && position <= last_index( ) ).
		// The value of item is inserted at position and the size of sequence is increased
		// by one.
		/// throws an exception	if the position is outside the bounds of the sequence
		/// @param p position where to inset value in the sequence
		/// @param v the value being inserted
		void insert(size_t p, T v);

		/// @brief The size of the sequence is greater than zero
		/// throws an exception	if the sequence is empty
		/// @return a reference to the first item in the sequence.
		T &front() const;

		/// @brief The size of the sequence is greater than zero.
		/// throws an exception	if the sequence is empty
		/// @return a reference to the last item in the sequence.
		T &back() const;

		/// @brief A true return value indicates size of the sequence is zero.
		/// @return true if sequence is empty, false if sequence has size > 0
		bool empty() const;

		/// @brief The return value is the number of items in the sequence.
		/// @return number of items in the sequence
		size_t size() const;

		/// @brief All items in the sequence deleted and the memory associated with
		/// the sequence is released.
		void clear();

		/// @brief The position satisfies
		/// 	( position >= 0 && position + count - 1 <= last_index( ) )
		/// throws an exception	if the sequence when called with invalid position and/or count
		/// The positions / items in the sequence at
		/// 	( position ... (position + count - 1) )
		/// are deleted and their memory is released
		/// @param p position of first item to be erased
		/// @param n number of items to be erased
		void erase(size_t p, size_t n = 1);

		/// @brief printing method for entire sequence, outputs all elements
		/// 		ex: <4, 8, 15, 16, 23, 42>
		/// @param os the ostream to print to (ex: cout)
		void print(std::ostream &os) const;
		template <typename U>
		friend std::ostream &operator<<(std::ostream &os, const LinkedList<U> &s);
		// YOU CAN MODIFY the following private declarations as needed to implement your sequence class
	private:
		/// @brief private inner class for linked list nodes
		/// All data elements are public, since only class sequence can see SequenceNodes
		class SequenceNode
		{
		public:
			SequenceNode *next; // pointer to next Node. If node is the tail, next is nullptr
			SequenceNode *prev; // pointer to previous Node. If node is the head, prev is nullptr
			T elt;				// the element being stored in the node

			/// @brief empty constructor, ensure next and prev are nullptr
			SequenceNode() : next(nullptr), prev(nullptr)
			{
			}

			/// @brief parameterized constructor, next and prev are set to nullptr and the
			/// node's element is set to the given value
			/// @param item value the node's element will be set to
			SequenceNode(T item) : next(nullptr), prev(nullptr), elt(item)
			{
			}

			/// @brief node destructor. Think about what it would mean and whether anything
			/// should be done here
			~SequenceNode(){};
		};

		// MEMBER DATA.  These are the data items that each sequence object will contain.  For a
		// doubly-linked list, each sequence will have a head and tail pointer, and numElts
		SequenceNode *head;
		SequenceNode *tail;
		size_t numElts; // Number of elements in the sequence

		/**
		 * @brief Gets the node at position
		 *
		 * @param position index
		 * @return SequenceNode*
		 */
		SequenceNode *get(size_t position) const;
	}; // End of class LinkedList

}
