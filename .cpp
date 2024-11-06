#include <iostream> 
#include <string> 
using namespace std; 

class Question { 
public: 
    string questionText; 
    string options[4]; 
    int correctOption; 
    
    Question(string text = "", string opts[] = nullptr, int correct = 0) { 
        questionText = text; 
        correctOption = correct; 
        if (opts != nullptr) { 
            for (int i = 0; i < 4; i++) { 
                options[i] = opts[i]; 
            } 
        } 
    } 

    void askQuestion() { 
        cout << "\n" << questionText << "\n"; 
        for (int i = 0; i < 4; i++) { 
            cout << i + 1 << ". " << options[i] << "\n"; 
        } 
        cout << "Enter your answer (1-4): "; 
    } 
}; 

class Node { 
public: 
    Question data; 
    Node* next; 

    Node(Question q) : data(q), next(nullptr) {} 
}; 

class LinkedList { 
private: 
    Node* head; 

public: 
    LinkedList() : head(nullptr) {} 

    void insert(Question q) { 
        Node* newNode = new Node(q); 
        if (!head) { 
            head = newNode; 
        } else { 
            Node* temp = head; 
            while (temp->next) { 
                temp = temp->next; 
            } 
            temp->next = newNode; 
        } 
    } 

    void startQuiz() { 
        Node* temp = head; 
        int score = 0; 
        int userAnswer; 

        while (temp != nullptr) { 
            temp->data.askQuestion(); 
            cin >> userAnswer; 
            while (userAnswer < 1 || userAnswer > 4) { 
                cout << "Invalid choice! Please enter a number between 1 and 4: "; 
                cin >> userAnswer; 
            } 
            if (userAnswer == temp->data.correctOption) { 
                score++; 
            } else { 
                cout << "Wrong answer! The correct answer is: " << temp->data.options[temp->data.correctOption - 1] << "\n"; 
            } 
            temp = temp->next; 
        } 
        cout << "Quiz finished! Your score is: " << score << "\n"; 
    } 

    ~LinkedList() { 
        Node* temp; 
        while (head) { 
            temp = head; 
            head = head->next; 
            delete temp; 
        } 
    } 
}; 

class Quiz { 
private: 
    LinkedList questionList; 

public: 
    void loadQuestions() { 
        string options1[] = { "O(1)", "O(n)", "O(log n)", "O(n^2)" }; 
        Question q1("What is the time complexity of searching in a binary search tree?", options1, 3); 
        questionList.insert(q1); 
        
        string options2[] = { "Stack", "Queue", "Array", "Linked List" }; 
        Question q2("Which data structure uses LIFO (Last In, First Out)?", options2, 1); 
        questionList.insert(q2); 
        
        string options3[] = { "Heap Sort", "Bubble Sort", "Quick Sort", "Insertion Sort" }; 
        Question q3("Which sorting algorithm has the best average time complexity?", options3, 3); 
        questionList.insert(q3); 
        
        string options4[] = { "Linked List", "Stack", "Queue", "Array" }; 
        Question q4("Which data structure is best suited for implementing recursion?", options4, 2); 
        questionList.insert(q4); 
        
        string options5[] = { "O(n)", "O(log n)", "O(n log n)", "O(n^2)" }; 
        Question q5("What is the time complexity of merge sort?", options5, 3); 
        questionList.insert(q5); 
        
        string options6[] = { "Queue", "Stack", "Array", "Heap" }; 
        Question q6("Which data structure is used in breadth-first search (BFS)?", options6, 1); 
        questionList.insert(q6); 
        
        string options7[] = { "O(n)", "O(n log n)", "O(log n)", "O(1)" }; 
        Question q7("What is the time complexity of binary search?", options7, 3); 
        questionList.insert(q7); 
        
        string options8[] = { "Inorder", "Preorder", "Postorder", "Level-order" }; 
        Question q8("Which traversal is used to search a binary search tree for a specific value?", options8, 1); 
        questionList.insert(q8); 
        
        string options9[] = { "Linked List", "Queue", "Stack", "Graph" }; 
        Question q9("Which data structure is used in depth-first search (DFS)?", options9, 3); 
        questionList.insert(q9); 
        
        string options10[] = { "Binary Search Tree", "Heap", "Queue", "Graph" }; 
        Question q10("Which data structure is used to implement priority queues?", options10, 2); 
        questionList.insert(q10); 
    } 

    void start() { 
        questionList.startQuiz(); 
    } 
}; 

int main() { 
    Quiz myQuiz; 
    myQuiz.loadQuestions(); 
    myQuiz.start(); 
    return 0; 
}
 
 
 
 
 
 
 
 










 
