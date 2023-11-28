#pragma once

template <class E> class ListNode
{
public:
	E value;
	ListNode* next;

	ListNode(const E& value, ListNode* nextNode = nullptr) : value(value), next(nextNode) {};
	ListNode(ListNode* nextNode = nullptr) :next(nextNode) {};

private:
};
