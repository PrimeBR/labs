#ifndef _BST_HPP_
#define _BST_HPP_

#include <iostream>
#include <cstring>

template <class Type>
class BST {
    struct Node {
        Type data;
        Node* left;
        Node* right;
    };

    Node* root;

    void makeEmpty(Node* t) {              //Метод удаления дерева
        if(t == nullptr)
            return;
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
        return;
    }

    Node* insert(Type x, Node* t) {         //Метод вставки элемента в дерево
        if(t == nullptr) {
            t = new Node;
            t->data = x;
            t->left = t->right = 0;
            std::cout << std::endl;
        }
        else if(x < t->data) {
            std::cout << "Element \'" << x << "\' is less than " << t->data << " , go to the left subtree." << std::endl;
            t->left = insert(x, t->left);
        }
        else if(x > t->data) {
            std::cout << "Element \'" << x << "\' is more than " << t->data << " , go to the right subtree." << std::endl;
            t->right = insert(x, t->right);
        }

        return t;
    }

    Node* findMin(Node *t) {            //Метод нахождения минимального элемента в дереве
        if(!t)
            return 0;
        else if(!t->left)
            return t;
        else return findMin(t->left);
    }

    Node* findMax(Node* t) {            //Метод нахождения максимального элемента в дереве
        if(t = nullptr)
            return 0;
        else if(!t->right)
            return t;
        else return findMax(t->right);
    }

    Node* remove(Type x, Node* t) {     //Метод удаления элемента в дереве
        Node* temp;
        if(t == nullptr) {
             std::cout << "Element \'" << x << "\' wasn't found!" << std::endl;
            return 0;
        }
        else if(x < t->data) {
            std::cout << "Element \'" << x << "\' is less than " << t->data << " , go to the left subtree." << std::endl;
            t->left = remove(x, t->left);
        }
        else if(x > t->data) {
            std::cout << "Element \'" << x << "\' is more than " << t->data << " , go to the right subtree." << std::endl;
            t->right = remove(x, t->right);
        }
        else if (t->left && t->right) {
            std::cout << "Element \'" << x << "\' found, but he has two sons. Putting the minimal element in the right subtree in the place of the parent and remove it from the current position:" << std::endl;
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else {
            temp = t;
            if(!t->left) {
                std::cout << "Element \'" << x << "\' doesn't have left son. Putting the right son in the place of the parent." << std::endl;
                t = t->right;
            }
            else if(!t->right) {
                std::cout << "Element \'" << x << "\' doesn't have right son. Putting the left son in the place of the parent." << std::endl;
                t = t->left;
            }
            delete temp;
        }
        return t;
    }

    struct Trunk {
        Trunk *prev;
        std::string branch;
        Trunk(Trunk *prev, std::string branch) {
            this->prev = prev;
            this->branch = branch;
        }
    };

    void showTrunks(Trunk *p) {                 //Вспомогательный метод для печати ветвей бинарного дерева поиска
        if(p == nullptr)
            return;
        showTrunks(p->prev);
        std::cout << p->branch;
    }

    void inorder(Node* t, Trunk* prev, bool isRight) {      //Метод для печати бинарного дерева
        if(t == nullptr)
            return;
        std::string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);	//Новая ветка, хранящая указатель на предыдущую ветку и текущее значение ветки
        inorder(t->right, trunk, true);
        if(!prev)
            trunk->branch = "---";			//Если корень - то ответвление к нему имеет следующий вид
        else if(isRight) {				//Проверка на принадлежность узла правому дереву и
            trunk->branch = ".---";			//присвоения ему следующего вида
            prev_str = "   |";
        }
        else {						
            trunk->branch = "`---";
            prev->branch = prev_str;
        }
        showTrunks(trunk);				//Вызов функции, которая выводит ответвления к текущему элементу.
        std::cout << t->data << std::endl;

        if(prev)					//Проверка на имение родителя у текущего элемента
            prev->branch = prev_str;
        trunk->branch = "   |";				//Проверка на случай, если родителя у элемента нет и он не является корнем

        inorder(t->left, trunk, false);
        delete trunk;
    }

    Node* find(Type x, Node* t) {        //Метод поиска элемента в дереве
        if(t = nullptr)
            return 0;
        else if(x < t->data) 
            return find(x, t->left);
        else if(x > t->data)
            return find(x, t->right);
        else return t;
    }

    public:
        BST() {                         
            root = NULL;
        }

        ~BST() {                        
            makeEmpty(root);
        }

        void insert(Type x) {
            root = insert(x, root);
        }

        void remove(Type x) {
            root = remove(x, root);
        }

        void display() {        //Метод отображения дерева
            if(!root) {
                std::cout << "BST is empty!" << std::endl;
                return;
            }
            inorder(root, nullptr, false);
            std::cout << std::endl;
        }

        int search (Type x) {   //Метод поиска элемента в дереве
            Node* temp = find(x, root);
            if(temp) {
                std::cout << "Element was found!" << std::endl;
                return 1;
            }
            else return 0;
        }
};

#endif