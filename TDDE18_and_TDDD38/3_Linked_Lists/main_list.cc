#include "Sorted_List.h"
#include <string>

List::List() : head{ nullptr } {}

List::List(List const& other) {
	Node* curr = other.head;
	while (curr != nullptr) {
		insert(curr->value);
		curr = curr->next;
	}
}

List::List(List&& other) {
	head = other.head;
	other.head = nullptr;
}

List& List::operator=(List const& rhs) {
	this->~List();
	if (rhs.size() == 0) return *this;
	Node* other = rhs.head->next;
	Node* newNode = new Node();
	newNode->value = rhs.head->value;
	head = newNode;
	while (other != nullptr) {
		Node* n = new Node();
		n->value = other->value;
		newNode->next = n;
		newNode = newNode->next;
		other = other->next;
	}
	return *this;
}

List& List::operator=(List&& rhs) {
	this->~List();
	head = rhs.head;
	rhs.head = nullptr;
	return *this;
}


bool List::is_empty() const{
	if (head == nullptr) return true;
	return false;
}

std::string List::to_string() const {
	std::string str{};
	Node* curr = head;
	while (curr != nullptr) {
		str += std::to_string(curr->value) + " ";
		curr = curr->next;
	}
	return str;
}

void List::remove(int n) {
	Node* curr = head;
	while (curr->next != nullptr && head->value != n && curr->next->value != n) {
		curr = curr->next;
	}
	if (head->value == n) {
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	else {
		Node* temp = curr->next;
		curr->next = curr->next->next;
		delete temp;
	}
}

int List::size() const {
	if (head == nullptr) {
		return 0;
	}
	if (head->next == nullptr) {
		return 1;
	}
	int n = 0;
	Node* curr = head;
	while (curr != nullptr) {
		n += 1;
		curr = curr->next;
	}
	return n;
}

List::~List() {
	Node* curr = head;
	while (curr != nullptr) {
		Node* del = curr;
		curr = curr->next;
		delete del;
	}
	head = nullptr;
}

void List::insert(int n) {
	if (this->is_empty()) {
		Node* new_node = new Node();
		new_node->value = n;
		new_node->next = nullptr;
		head = new_node;
	}
	else {
		if (size() == 1) {
			Node* curr = head;
			Node* next = head->next;
			if (head->value >= n) {
				Node* new_node = new Node();
				new_node->value = n;
				new_node->next = curr;
				head = new_node;
			}
			else {
				Node* new_node = new Node();
				new_node->value = n;
				new_node->next = nullptr;
				head->next = new_node;
			}
		}
		else {
				Node* curr = head;
				while (curr->next != nullptr && curr->next->value < n && head->value < n) {
					curr = curr->next;
				}
				if (head->value >= n) {
					Node* new_node = new Node();
					new_node->value = n;
					new_node->next = curr;
					head = new_node;
				}
				else if (curr->next == nullptr) {
					Node* new_node = new Node();
					new_node->value = n;
					new_node->next = nullptr;
					curr->next = new_node;
				}
				else {
					Node* new_node = new Node();
					new_node->value = n;
					new_node->next = curr->next;
					curr->next = new_node;
				}
			}
		}
	}