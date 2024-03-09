/*
 * List.cpp
 * AvlTree tutan liste yapisi
 * 1.Ogretim B gurubu
 * 2. Odev
 * 08.11.2023
 * Uğur Can Çelik, ugur.celik16@ogr.sakarya.edu.tr
 */
#include "List.hpp"

List::List()
{
    head = 0;
    fillFromTxt();
}

List::~List()
{
}

void List::add(AvlTree* data)
{
    Node* newNode = new Node(data);

    if (head == 0)
    {
        head = newNode;
        return;
    }

    Node* tmp = head;

    while (tmp->next != 0)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

void List::removeNode(Node* data)
{
    Node* tmp = head;
    Node* pre = nullptr;

    while (tmp != nullptr)
    {
        if (tmp == data)
        {
            if (pre == nullptr)
            {
                head = tmp->next;
            }
            else
            {
                pre->next = tmp->next;
            }

            delete tmp;
            break;
        }

        pre = tmp;
        tmp = tmp->next;
    }
}


void List::printAscii()
{
    Node* tmp = head;

    while (tmp != NULL)
    {   
        char ascii = tmp->data->ascii;
        cout << ascii;

        tmp = tmp->next;
    }
}

void List::compareAndRemove()
{
    Node* bigger;
    Node* smaller;
    bool single = false;
    
    printAscii();

    while(head->next != NULL)
    {     
        if(single == true)
        {
            bigger = biggerStackTop();
            bigger->data->stack->pop();
            single = false;

            if (bigger->data->stack->isEmpty())
            {
                removeNode(bigger);
                stacksReload();
                system("cls");
                printAscii();
                single = false;
            }
        }
        else
        {
            smaller = smallerStackTop();
            smaller->data->stack->pop();
            single = true;

            if (smaller->data->stack->isEmpty())
            {
                removeNode(smaller);
                stacksReload();
                system("cls");
                printAscii();
                single = false;
            }
        }   
    } 

    system("cls");
    cout << "------------------------------" << endl;
    cout << "|     " << left << setw(10) << "Last Character: " << setw(7) << (char)head->data->ascii << "|" << endl;
    cout << "|     " << left << setw(10) << "    AvlTree No: " << setw(7) << head->data->avlNo << "|" << endl;
    cout << "------------------------------" << endl;
    
    char exit;
    cout << "Press any key for exit: ";
    cin>>exit;
}

void List::stacksReload()
{
    Node* tmp = head;

    while (tmp!=nullptr)
    {
        tmp->data->stack->stackReload();
        tmp = tmp->next;
    }
}

Node* List::biggerStackTop()
{
    if (head == nullptr) {
        return nullptr; 
    }

    Node* tmp = head;
    Node* bigger = head;

    while (tmp != nullptr)
    {
        if (tmp->data->stack->top() > bigger->data->stack->top())
        {
            bigger = tmp;
        }

        tmp = tmp->next;
    }

    return bigger;
}

Node* List::smallerStackTop()
{
    if (head == nullptr) {
        return nullptr; 
    }

    Node* tmp = head;
    Node* smaller = head;

    while (tmp != nullptr)
    {
        if (tmp->data->stack->top() < smaller->data->stack->top())
        {
            smaller = tmp;
        }

        tmp = tmp->next;
    }

    return smaller;
}

void List::fillFromTxt()
{
    ifstream readingFile;

    readingFile.open("text.txt");

    if (readingFile.is_open())
    {
        int avlNo = 1;
        string line;
        while (getline(readingFile, line))
        {
            istringstream iss(line);
            string kelime;
            AvlTree* tree = new AvlTree();

            while (iss >> kelime)
            {
                int num = stoi(kelime);
                tree->Add(num);
            }
            
            tree->postorder();
            tree->leaf();
            tree->ascii = (tree->totalExceptLeafs % 26) + 65;
            tree->avlNo = avlNo;
            this->add(tree);

            avlNo++;
        }

        readingFile.close();
    }
    
}

