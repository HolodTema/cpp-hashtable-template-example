#include <iostream>
#include "LinkedList.hpp"

void testLinkedListAdd() {
	std::cout << "#############\n";
	std::cout << "Test linked list add\n\n";

	LinkedList<std::string> list;
	list.pushFront("hello");
	list.pushFront("world");

	std::cout << list;
	std::cout << "\n";

	list.pushFront("summer");
	list.pushFront("winter");
	list.pushFront("autumn");

	std::cout << list;
	std::cout << "\n";
	std::cout << "#############\n";
}
void testLinkedListAddRemove() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked list add remove\n\n";
	LinkedList<std::string> list;
	list.pushFront("hello");
	list.pushFront("world");
	list.pushFront("apple");
	list.pushFront("banana");
	list.pushFront("summer");
	list.pushFront("winter");
	std::cout << list;
	std::cout << "\n";

	list.remove("apple");
	std::cout << list;
	std::cout << "\n";

	list.pushFront("autumn");
	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testLinkedListContains() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked list contains\n\n";

	LinkedList<std::string> list;
	list.pushFront("hello");
	list.pushFront("world");
	list.pushFront("apple");
	list.pushFront("banana");
	list.pushFront("summer");
	list.pushFront("winter");
	std::cout << list;
	std::cout << "\n";

	std::cout << list.contains("summer") << "\n";
	std::cout << "\n";

	std::cout << list.contains("foo") << "\n";
	std::cout << "\n";

	std::cout << list.contains("banana") << "\n";
	std::cout << "\n";

	list.remove("summer");
	std::cout << list.contains("summer") << "\n";
	std::cout << "\n";

	std::cout << list;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testLinkedListCopyConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked list copy constructor\n\n";

	LinkedList<std::string> list1;
	list1.pushFront("java");
	list1.pushFront("python");
	list1.pushFront("c++");
	list1.pushFront("kotlin");
	std::cout << list1;
	std::cout << "\n";

	LinkedList list2(list1);
	std::cout << list2;
	std::cout << "\n";

	list1.pushFront("rust");
	list1.remove("c++");
	list1.pushFront("ruby");

	std::cout << list1;
	std::cout << "\n";
	std::cout << list2;
	std::cout << "\n";

	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testLinkedListCopyOperator() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked list copy operator\n\n";

	LinkedList<std::string> list1;
	list1.pushFront("java");
	list1.pushFront("python");
	list1.pushFront("c++");
	list1.pushFront("kotlin");
	std::cout << list1;
	std::cout << "\n";

	LinkedList<std::string> list2;
	list2.pushFront("dog");
	list2.pushFront("cow");
	list2.pushFront("cat");
	list2.pushFront("horse");
	list2.pushFront("duck");
	list2.pushFront("tiger");
	std::cout << list2;
	std::cout << "\n";

	list1 = list2;
	std::cout << list1;
	std::cout << "\n";
	std::cout << list2;
	std::cout << "\n";


	list1.remove("tiger");
	list1.pushFront("bear");

	list2.pushFront("wolf");
	list2.remove("horse");

	std::cout << list1;
	std::cout << "\n";
	std::cout << list2;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
LinkedList<int> getIntLinkedList() {
	LinkedList<int> list;
	list.pushFront(10);
	list.pushFront(5);
	list.pushFront(15);
	list.pushFront(3);
	list.pushFront(30);
	return list;
}
void testLinkedListMoveConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked list move constructor\n\n";

	LinkedList list1(std::move(getIntLinkedList()));
	std::cout << list1;
	std::cout << "\n";

	list1.pushFront(100);
	list1.pushFront(200);
	list1.pushFront(300);

	list1.remove(15);

	std::cout << list1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testLinkedListMoveOperator() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked list move operator\n\n";

	LinkedList<int> list1;
	list1.pushFront(1);
	list1.pushFront(1000);
	list1.pushFront(2000);
	std::cout << list1;
	std::cout << "\n";

	list1 = std::move(getIntLinkedList());
	std::cout << list1;
	std::cout << "\n";

	list1.pushFront(-100);
	std::cout << list1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testLinkedListForEach() {
	std::cout << "#############\n";
	std::cout << "Test linked list for each\n\n";

	LinkedList<std::string> list;
	list.pushFront("hello");
	list.pushFront("world");
	list.pushFront("summer");
	list.pushFront("winter");
	list.pushFront("autumn");

	std::cout << list;
	std::cout << "\n";

	auto incrementor = [](std::string& str) {
		str = str + "_haha";
		if (str == "summer_haha") {
			return false;
		}
		return true;
	};
	list.forEach(incrementor);

	std::cout << list;
	std::cout << "\n";
	std::cout << "#############\n";
}

void linkedListTests() {
	testLinkedListAdd();
	testLinkedListAddRemove();
	testLinkedListContains();
	testLinkedListCopyConstructor();
	testLinkedListCopyOperator();
	testLinkedListMoveConstructor();
	testLinkedListMoveOperator();
	testLinkedListForEach();
}


void hashMapTests() {

}

int main() {
	linkedListTests();
}