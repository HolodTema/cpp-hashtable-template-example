#include <iostream>
#include <bits/shared_ptr.h>

#include "HashMap.hpp"
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


void testHashMapAdd() {
	std::cout << "#############\n";
	std::cout << "Test hash map add\n\n";

	HashMap<std::string, int> map(5);
	map.insert("hello", 25);
	map.insert("world", 10);

	std::cout << map;
	std::cout << "\n";

	map.insert("summer", 10);
	map.insert("winter", 25);
	map.insert("autumn", 11);
	map.insert("autumn", 11);
	map.insert("autumn", 12);

	std::cout << map;
	std::cout << "\n";
	std::cout << "#############\n";
}

void testHashMapAddRemove() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test linked map add remove\n\n";
	HashMap<int, std::string> map(100);
	map.insert(1, "hello");
	map.insert(10, "world");
	map.insert(100, "apple");
	map.insert(1000, "banana");
	map.insert(10000, "summer");
	map.insert(0, "winter");
	std::cout << map;
	std::cout << "\n";

	map.remove(100);
	std::cout << map;
	std::cout << "\n";

	map.insert(-1, "autumn");
	std::cout << map;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testHashMapContains() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test hash map contains\n\n";

	HashMap<char, double> map(2);
	map.insert('a', 2.0);
	map.insert('b', 5.1);
	map.insert('c', -7.3);
	map.insert('d', 44.8);
	map.insert('e', 27.340);
	std::cout << map;
	std::cout << "\n";

	std::cout << map.contains('d') << "\n";
	std::cout << "\n";

	std::cout << map.contains('x') << "\n";
	std::cout << "\n";

	std::cout << map.contains('b') << "\n";
	std::cout << "\n";

	map.remove('c');
	std::cout << map.contains('c') << "\n";
	std::cout << "\n";

	std::cout << map;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testHashMapCopyConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test hash map copy constructor\n\n";

	HashMap<std::string, std::string> map1(100);
	map1.insert("java", "javavalue");
	map1.insert("python", "pythonvalue");
	map1.insert("c++", "c++value");
	map1.insert("kotlin", "kotlinvalue");
	std::cout << map1;
	std::cout << "\n";

	HashMap map2(map1);
	std::cout << map2;
	std::cout << "\n";

	map1.insert("rust", "rustvalue");
	map1.remove("c++");
	map1.insert("ruby", "rubyvalue");

	std::cout << map1;
	std::cout << "\n";
	std::cout << map2;
	std::cout << "\n";

	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}

void testHashMapCopyOperator() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test hash map copy operator\n\n";

	HashMap<std::string, int> map1(10);
	map1.insert("java", 1);
	map1.insert("python", 2);
	map1.insert("c++", 3);
	map1.insert("kotlin", 4);
	std::cout << map1;
	std::cout << "\n";

	HashMap<std::string, int> map2(20);
	map2.insert("dog", 100);
	map2.insert("cow", 200);
	map2.insert("cat", 300);
	map2.insert("horse", 400);
	map2.insert("duck", 100);
	map2.insert("tiger", 200);
	std::cout << map2;
	std::cout << "\n";

	map1 = map2;
	std::cout << map1;
	std::cout << "\n";
	std::cout << map2;
	std::cout << "\n";


	map1.remove("tiger");
	map1.insert("bear", 0);

	map2.insert("wolf", 0);
	map2.remove("horse");

	std::cout << map1;
	std::cout << "\n";
	std::cout << map2;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
HashMap<int, int> getIntHashMap() {
	HashMap<int, int> map(6);
	map.insert(10, 10);
	map.insert(5, 5);
	map.insert(15, 15);
	map.insert(3, 3);
	map.insert(30, 30);
	return map;
}
void testHashMapMoveConstructor() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test hash map move constructor\n\n";

	HashMap map1(std::move(getIntHashMap()));
	std::cout << map1;
	std::cout << "\n";

	map1.insert(100, 0);
	map1.insert(200, 0);
	map1.insert(300, 0);

	map1.remove(15);

	std::cout << map1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testHashMapMoveOperator() {
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
	std::cout << "Test hash map move operator\n\n";

	HashMap<int, int> map1(9);
	map1.insert(1, 0);
	map1.insert(1000, 0);
	map1.insert(2000, 0);
	std::cout << map1;
	std::cout << "\n";

	map1 = std::move(getIntHashMap());
	std::cout << map1;
	std::cout << "\n";

	map1.insert(-100, -100);
	std::cout << map1;
	std::cout << "~~~~~~~~~~~~~~~~~~~~~\n";
}
void testHashMapForEach() {
	std::cout << "#############\n";
	std::cout << "Test hash map for each\n\n";

	HashMap<std::string, char> map(3);
	map.insert("hello", 'h');
	map.insert("world", 'w');
	map.insert("summer", 's');
	map.insert("winter", 'a');
	map.insert("autumn", 'd');

	std::cout << map;
	std::cout << "\n";

	auto incrementor = [](HashMap<std::string, char>::Pair& pair) {
		if (pair.key == "autumn") {
			return false;
		}
		pair.value = '~';
		return true;
	};
	map.forEach(incrementor);

	std::cout << map;
	std::cout << "\n";
	std::cout << "#############\n";
}


void hashMapTests() {
	testHashMapAdd();
	testHashMapAddRemove();
	testHashMapContains();
	testHashMapCopyConstructor();
	testHashMapCopyOperator();
	testHashMapMoveConstructor();
	testHashMapMoveOperator();
	testHashMapForEach();
}

int main() {
	linkedListTests();
	hashMapTests();
}