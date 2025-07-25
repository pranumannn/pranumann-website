#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

// Linked List Node
struct ListNode {
    int data;
    ListNode* next;
    ListNode(int d) : data(d), next(nullptr) {}
};

// Linked List
class LinkedList { 
    ListNode* head;
public:
    LinkedList() : head(nullptr) {}

    void insert(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    void remove(int val) {
        ListNode* temp = head, *prev = nullptr;
        while (temp && temp->data != val) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            cout << "Value not found.\\n";
            return;
        }
        if (!prev) head = temp->next;
        else prev->next = temp->next;
        delete temp;
        cout << "Value removed.\\n";
    }

    void display() {
        ListNode* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\\n";
    }
};

// BST Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// BST
class BST {
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->val) node->left = insert(node->left, val);
        else node->right = insert(node->right, val);
        return node;
    }

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->val << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    void insert(int val) {
        root = insert(root, val);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }
};

// Sorting
void sortArray(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    cout << "Sorted array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
}

// Searching
int searchArray(const vector<int>& arr, int key) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) return i;
    }
    return -1;
}

void interactiveDSA() {
    LinkedList ll;
    BST bst;
    stack<int> s;
    queue<int> q;
    vector<int> arr;

    int choice;
    while (true) {
        cout << "\n---- DSA MENU ----\n";
        cout << "1. Linked List Insert\n2. Linked List Remove\n3. Linked List Display\n";
        cout << "4. BST Insert\n5. BST Display (Inorder)\n";
        cout << "6. Stack Push\n7. Stack Pop\n8. Stack Display\n";
        cout << "9. Queue Enqueue\n10. Queue Dequeue\n11. Queue Display\n";
        cout << "12. Input Array\n13. Sort Array\n14. Search Array\n";
        cout << "15. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int val;
            cout << "Enter value: ";
            cin >> val;
            ll.insert(val);
        } else if (choice == 2) {
            int val;
            cout << "Enter value to remove: ";
            cin >> val;
            ll.remove(val);
        } else if (choice == 3) {
            ll.display();
        } else if (choice == 4) {
            int val;
            cout << "Enter value to insert in BST: ";
            cin >> val;
            bst.insert(val);
        } else if (choice == 5) {
            bst.displayInorder();
        } else if (choice == 6) {
            int val;
            cout << "Enter value to push on stack: ";
            cin >> val;
            s.push(val);
        } else if (choice == 7) {
            if (s.empty()) cout << "Stack is empty.\\n";
            else {
                cout << "Popped: " << s.top() << endl;
                s.pop();
            }
        } else if (choice == 8) {
            stack<int> temp = s;
            cout << "Stack: ";
            while (!temp.empty()) {
                cout << temp.top() << " ";
                temp.pop();
            }
            cout << endl;
        } else if (choice == 9) {
            int val;
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.push(val);
        } else if (choice == 10) {
            if (q.empty()) cout << "Queue is empty.\\n";
            else {
                cout << "Dequeued: " << q.front() << endl;
                q.pop();
            }
        } else if (choice == 11) {
            queue<int> temp = q;
            cout << "Queue: ";
            while (!temp.empty()) {
                cout << temp.front() << " ";
                temp.pop();
            }
            cout << endl;
        } else if (choice == 12) {
            int n, val;
            cout << "Enter number of elements: ";
            cin >> n;
            arr.clear();
            for (int i = 0; i < n; ++i) {
                cout << "Enter element " << i + 1 << ": ";
                cin >> val;
                arr.push_back(val);
            }
        } else if (choice == 13) {
            sortArray(arr);
        } else if (choice == 14) {
            int key;
            cout << "Enter value to search: ";
            cin >> key;
            int idx = searchArray(arr, key);
            if (idx != -1) cout << "Found at index: " << idx << endl;
            else cout << "Not found.\\n";
        } else if (choice == 15) {
            break;
        } else {
            cout << "Invalid choice. Try again.\\n";
        }
    }
}

int main() {
        interactiveDSA();
        cout << "\nThank you for using the Interactive DSA Program!\n";
            
    return 0;
}
