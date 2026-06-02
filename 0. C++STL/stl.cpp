// PAIR

#include <bits/stdc++.h>
using namespace std;

void pair_example() {
    pair<int, string> p1; // Default constructor
    p1.first = 1;
    p1.second = "Hello";

    pair<int, string> p2(2, "World"); // Parameterized constructor

    pair<int, string> p3 = make_pair(3, "C++"); // Using make_pair

    cout << "Pair 1: " << p1.first << ", " << p1.second << endl;
    cout << "Pair 2: " << p2.first << ", " << p2.second << endl;
    cout << "Pair 3: " << p3.first << ", " << p3.second << endl;

    // Swapping pairs
    swap(p1, p2);
    cout << "After swapping Pair 1 and Pair 2:" << endl;
    cout << "Pair 1: " << p1.first << ", " << p1.second << endl;
    cout << "Pair 2: " << p2.first << ", " << p2.second << endl;


   // nested pairs
    pair<int, pair<string, double>> nested_pair(4, make_pair("Nested", 3.14));
    cout << "Nested Pair: " << nested_pair.first << ", " << nested_pair.second.first << ", " << nested_pair.second.second << endl;
}


void explain_vector() {
    vector<int> v; // Default constructor
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int> v2(5, 10); // Parameterized constructor (size, value)

    vector<int> v3 = {4, 5, 6}; // Initializer list

    cout << "Vector 1: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Vector 2: ";
    for (int i : v2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "Vector 3: ";
    for (int i : v3) {
        cout << i << " ";
    }
    cout << endl;


    // push_back and pop_back
    v.push_back(4);
    cout << "After push_back(4), Vector 1: ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
    v.pop_back();
    cout << "After pop_back(), Vector 1: "; 
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // size and capacity
    // difference between size and capacity is that size is the number of elements in the vector and capacity is the number of elements that can be stored in the vector without resizing.
    cout << "Size of Vector 1: " << v.size() << endl;   
    cout << "Capacity of Vector 1: " << v.capacity() << endl;

    // clear and empty functions: 
    v.clear();
    cout << "After clear(), Vector 1 is empty: " << v.empty() << endl; 
    
    // iterators
    vector<int> v4 = {7, 8, 9}; 
    cout << "Vector 4 using iterators: ";
    for (auto it = v4.begin(); it != v4.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;   
   
    // rev and end iterators
    // reverse iterators are used to iterate through the vector in reverse order. They are defined as rbegin() and rend() functions.
    cout << "Vector 4 in reverse using reverse iterators: ";
    for (auto it = v4.rbegin(); it != v4.rend(); it++) {
        cout << *it << " ";
    }   
    cout << endl;

    // insert and erase functions
    v4.insert(v4.begin() + 1, 10); // Insert 10 at index 1
    cout << "After insert(10) at index 1, Vector 4: ";

    for (int i : v4) {
        cout << i << " ";
    }

    cout << endl;
    v4.erase(v4.begin() + 2); // Erase element at index 2
    cout << "After erase() at index 2, Vector 4: ";     
    for (int i : v4) {
        cout << i << " ";
    }
    cout << endl;

    // swap function
    vector<int> v5 = {11, 12, 13};
    cout << "Vector 5 before swap: ";
    for (int i : v5) {
        cout << i << " ";
    }
    cout << endl;
    swap(v4, v5);
    cout << "Vector 4 after swap: ";
    for (int i : v4) {
        cout << i << " ";
    }   

    cout << endl;
    cout << "Vector 5 after swap: ";    
    for (int i : v5) {
        cout << i << " ";
    }

    cout << endl;

    // max element in vector
    cout << "Max element in Vector 4: " << *max_element(v4.begin(), v4.end()) << endl;

    // min element in vector
    cout << "Min element in Vector 4: " << *min_element(v4.begin(), v4.end()) << endl;

    // sort function
    sort(v4.begin(), v4.end());

    // reverse function
    reverse(v4.begin(), v4.end());

}

void list_example() {

    // difference between list and vector is that list is a doubly linked list and vector is a dynamic array. List allows for efficient insertion and deletion of elements, while vector allows for efficient random access to elements.

    list<int> l; // Default constructor
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    list<int> l2(5, 10); // Parameterized constructor (size, value)

    list<int> l3 = {4, 5, 6}; // Initializer list

    cout << "List 1: ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;

    cout << "List 2: ";
    for (int i : l2) {
        cout << i << " ";
    }
    cout << endl;

    cout << "List 3: ";
    for (int i : l3) {
        cout << i << " ";
    }
    cout << endl;

    // push_back and pop_back
    l.push_back(4); 
    cout << "After push_back(4), List 1: ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;
    l.pop_back();
    cout << "After pop_back(), List 1: ";
    for (int i : l) {
        cout << i << " ";
    }   
    cout << endl;

    // push_front and pop_front
    l.push_front(0);
    cout << "After push_front(0), List 1: ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;
    l.pop_front();
    cout << "After pop_front(), List 1: ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;

    // size and empty functions
    cout << "Size of List 1: " << l.size() << endl;
    cout << "List 1 is empty: " << l.empty() << endl;
    
    // emplace_back and emplace_front
    // example of emplace_back and emplace_front functions in list. 
    // The emplace_back function is used to insert an element at the end of the list,
    // while the emplace_front function is used to insert an element at the beginning of the list. These functions are more efficient than push_back and push_front because they construct the element in place, avoiding unnecessary copying.
    l.emplace_back(5);
    cout << "After emplace_back(5), List 1: ";
    for (int i : l) {
        cout << i << " ";
    }
    cout << endl;
    l.emplace_front(-1);
    cout << "After emplace_front(-1), List 1: ";
    for (int i : l) {   
        cout << i << " ";
    }

}

// HASH MAP

void hash_map_example() {
    // A hash map is a data structure that stores key-value pairs. It uses a hash function to compute an index into an array of buckets or slots, from which the desired value can be found.

    unordered_map<string, int> umap; // Default constructor

    umap["one"] = 1;
    umap["two"] = 2;
    umap["three"] = 3;

    cout << "Hash Map: " << endl;
    for (const auto& pair : umap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Accessing values
    cout << "Value for key 'two': " << umap["two"] << endl;

    // Checking if a key exists
    if (umap.find("four") != umap.end()) {
        cout << "Key 'four' exists in the hash map." << endl;
    } else {
        cout << "Key 'four' does not exist in the hash map." << endl;
    }

    // Erasing a key-value pair from the hash map 
    // example of erasing a key-value pair from the hash map. The erase function takes the key as an argument and removes the corresponding key-value pair from the hash map. After erasing, we can iterate through the hash map to see the remaining key-value pairs.
    umap.erase("one");
    cout << "After erasing key 'one': " << endl;
    for (const auto& pair : umap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // count function
    // example of count function in hash map. The count function is used to check if a key exists in the hash map. It returns 1 if the key exists and 0 if it does not exist. We can use this function to check for the presence of a key before accessing its value.
    if (umap.count("two") > 0) {
        cout << "Key 'two' exists in the hash map." << endl;
    } else {
        cout << "Key 'two' does not exist in the hash map." << endl;
    }

    // nested hash maps
    unordered_map<string, unordered_map<string, int>> nested_umap;
    nested_umap["outer"]["inner"] = 42;
    cout << "Nested Hash Map: " << nested_umap["outer"]["inner"] << endl;

    // nested hash maps using pairs
    unordered_map<string, pair<int, string>> nested_umap_pair;
    nested_umap_pair["key"] = make_pair(1, "value");
    cout << "Nested Hash Map with Pair: " << nested_umap_pair["key"].first << ", " << nested_umap_pair["key"].second << endl;

    // time complexity of hash map operations
    // The average time complexity of hash map operations (insertion, deletion, and access) is O(1) due to the use of a hash function that distributes keys uniformly across the buckets.
    // However, in the worst case, when there are many collisions (i.e., multiple keys hash to the same bucket), the time complexity can degrade to O(n) for all operations, where n is the number of key-value pairs in the hash map. To mitigate this, modern hash map implementations use techniques like chaining or open addressing to handle collisions efficiently.

    // ordered map data structure
    // An ordered map is a data structure that stores key-value pairs in a sorted order based on the keys. It is typically implemented using a balanced binary search tree (like a Red-Black Tree) to maintain the order of keys while allowing for efficient insertion, deletion, and access operations.
    // ordered map time complexity 
    // The average time complexity of ordered map operations (insertion, deletion, and access) is O(log n) due to the underlying balanced binary search tree structure (like Red-Black Tree). This allows for efficient searching, insertion, and deletion while maintaining the order of keys.

}

// SET

void set_example() {
    // A set is a data structure that stores unique elements in a sorted order. It is typically implemented using a balanced binary search tree (like a Red-Black Tree) to maintain the order of elements while allowing for efficient insertion, deletion, and access operations.

    set<int> s; // Default constructor

    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(2); // Duplicate element, will not be added

    cout << "Set: ";
    for (int i : s) {
        cout << i << " ";
    }
    cout << endl;

    // Checking if an element exists
    if (s.find(2) != s.end()) {
        cout << "Element 2 exists in the set." << endl;
    } else {
        cout << "Element 2 does not exist in the set." << endl;
    }

    // Erasing an element from the set
    s.erase(1);
    cout << "After erasing element 1, Set: ";
    for (int i : s) {
        cout << i << " ";
    }
    cout << endl;

    // count function
    if (s.count(3) > 0) {
        cout << "Element 3 exists in the set." << endl;
    } else {
        cout << "Element 3 does not exist in the set." << endl;
    }

    // Time complexity of set operations
    // The average time complexity of set operations (insertion, deletion, and access) is O(log n) due to the underlying balanced binary search tree structure (like Red-Black Tree). This allows for efficient searching, insertion, and deletion while maintaining the order of elements.
    // unordered_set data structure
    // An unordered_set is a data structure that stores unique elements in an unordered manner. It is typically implemented using a hash table to allow for efficient insertion, deletion, and access operations without maintaining any specific order of elements.
    // unordered_set time complexity
    // The average time complexity of unordered_set operations (insertion, deletion, and access)    
    // is O(1) due to the use of a hash function that distributes elements uniformly across the buckets. However, in the worst case, when there are many collisions (i.e., multiple elements hash to the same bucket), the time complexity can degrade to O(n) for all operations, where n is the number of elements in the unordered_set. To mitigate this, modern unordered_set implementations use techniques like chaining or open addressing to handle collisions efficiently. 

}

// QUEUE

void queue_example() {
    // A queue is a data structure that follows the First In First Out (FIFO) principle. It allows for efficient insertion at the back and deletion from the front.

    queue<int> q; // Default constructor

    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Queue: ";
    while (!q.empty()) {
        cout << q.front() << " "; // Access the front element
        q.pop(); // Remove the front element
    }
    cout << endl;

    // Time complexity of queue operations
    // The time complexity of queue operations (insertion, deletion, and access) is O(1) for each operation, as they involve only a constant amount of work to add an element to the back, remove an element from the front, or access the front element.

}

// STACK

void stack_example() {
    // A stack is a data structure that follows the Last In First Out (LIFO) principle. It allows for efficient insertion and deletion at the top.

    stack<int> s; // Default constructor

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Stack: ";
    while (!s.empty()) {
        cout << s.top() << " "; // Access the top element
        s.pop(); // Remove the top element
    }
    cout << endl;

    // Time complexity of stack operations
    // The time complexity of stack operations (insertion, deletion, and access) is O(1) for each operation, as they involve only a constant amount of work to add an element to the top, remove an element from the top, or access the top element.

}






int main() {
    pair_example();
    explain_vector();
    list_example();
    set_example();
    queue_example();
    stack_example();    
    return 0;
}