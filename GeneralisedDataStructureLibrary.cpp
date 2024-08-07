#include <iostream>
using namespace std;

///////////////////////////////////////////
///
/// Code of Singly Linear Linked List
///
///////////////////////////////////////////
template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
public:
    struct nodeSL<T> *First;
    int iCount;

    SinglyLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> *temp = First;
    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> *newn = NULL;

    newn = new nodeSL<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> *newn = NULL;
    struct nodeSL<T> *temp = NULL;

    newn = new nodeSL<T>;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> *newn = NULL;
    int i = 0;
    struct nodeSL<T> *temp = First;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int i = 0;
    struct nodeSL<T> *temp1 = NULL;
    struct nodeSL<T> *temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

///////////////////////////////////////////
///
/// Code of Singly Circular Linked List
///
///////////////////////////////////////////

template <class T>
struct nodeSCL
{
    T data;
    struct nodeSCL *next;
};

template <class T>
class SinglyCLL
{
public:
    struct nodeSCL<T> *First;
    struct nodeSCL<T> *Last;
    T iCount;

    SinglyCLL();

    void Display();
    T Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void SinglyCLL<T>::Display() // return value classname <T> :: functionname
{
    struct nodeSCL<T> *temp = First;

    if ((First == NULL) && (Last == NULL))
    {
        cout << "L is empty" << endl;
        ;
        return;
    }
    cout << "->";
    do
    {
        cout << "| " << First->data << " |-> ";
        First = First->next;
    } while (First != Last->next);
}

template <class T>
T SinglyCLL<T>::Count()
{
    T iCnt = 0;

    if ((First == NULL) && (Last == NULL))
    {
        return 0;
    }
    do
    {
        iCnt++;
        First = First->next;
    } while (First != Last->next);
    return iCnt;
}

template <class T>
void SinglyCLL<T>::InsertFirst(T No)
{
    struct nodeSCL<T> *newn = NULL;

    newn = new nodeSCL;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertLast(T No)
{

    struct nodeSCL<T> *newn = NULL;
    struct nodeSCL<T> *temp = NULL;

    newn = new nodeSCL;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    iCount++;
}

template <class T>
void SinglyCLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSCL<T> *newn = NULL;
    T i = 0;
    struct nodeSCL<T> *temp = First;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeSCL;
        newn->data = No;
        newn->next = NULL;
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++; // else chya aat ahe karan first two if aani else if already iCount++ kelay mg te double hoil mhanun fqt else madhe ch iCount++ yeil
    }
}

template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    struct nodeSCL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        Last->next = First;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteLast()
{
    struct nodeSCL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        while (temp->next != Last)
        {
            temp = temp->next;
        }
        delete (Last);
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
    T i = 0;
    struct nodeSCL<T> *temp1 = NULL;
    struct nodeSCL<T> *temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 0; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        delete temp2;

        iCount--;
    }
}

///////////////////////////////////////////
///
/// Code of Doubly Linear Linked List
///
///////////////////////////////////////////
template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T>
class DoublyLL
{
public:
    struct nodeDL<T> *First;
    T iCount;

    DoublyLL();

    void Display();
    T Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void DoublyLL<T>::Display() // return value classname <T> :: functionname
{
    struct nodeDL<T> *temp = First;

    while (temp != NULL)
    {
        cout << "| " << temp->data << " |-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

template <class T>
T DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> *newn = NULL;

    newn = new nodeDL;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> *newn = NULL;
    struct nodeDL<T> *temp = NULL;

    newn = new nodeDL;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
        newn->next = NULL;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> *newn = NULL;
    T i = 0;
    struct nodeDL<T> *temp = First;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else
    {
        newn = new nodeDL;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;
        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next->prev = newn;
        newn->next = temp->next;
        temp->next = newn;
        newn->prev = temp;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    struct nodeDL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        First = First->next;
        First->prev = NULL;
        delete temp;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "LL is empty" << endl;
    }
    else if (First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete (temp->next);
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    T i = 0;
    struct nodeDL<T> *temp1 = NULL;
    struct nodeDL<T> *temp2 = NULL;

    if ((iPos < 1) || (iPos > iCount))
    {
        cout << "Invalid position" << endl;
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for (i = 0; i < iPos - 1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        temp2->next->prev = temp1;
        delete temp2;

        iCount--;
    }
}

///////////////////////////////////////////
///
/// Code of Doubly Circular Linked List
///
///////////////////////////////////////////
template <class T>
struct nodeDCL
{
    T data;
    struct nodeDCL *next;
    struct nodeDCL *prev;
};

template <class T>
class DoublyCL
{
private:
    struct nodeDCL<T> *First;
    struct nodeDCL<T> *Last;
    int iCount;

public:
    DoublyCL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
};

template <class T>
DoublyCL<T>::DoublyCL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void DoublyCL<T>::Display()
{
    if ((First == NULL) && (Last == NULL))
    {
        cout << "Linked list is empty\n";
        return;
    }
    cout << "<=> ";
    do
    {
        cout << "| " << First->data << " | <=> ";
        First = First->next;
    } while (Last->next != First);
    cout << "\n";
}

template <class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCL<T>::InsertFirst(T No)
{
    struct nodeDCL<T> *newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCL<T>::InsertLast(T No)
{

    struct nodeDCL<T> *newn = NULL;

    newn = new nodeDCL<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if ((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        Last->next = newn;
        newn->next = Last;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;

    iCount++;
}

template <class T>
void DoublyCL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDCL<T> *newn = NULL;
    int i = 0;
    struct nodeDCL<T> *temp = NULL;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(No);
    }
    else if (iPos == iCount + 1)
    {
        InsertLast(No);
    }
    else // adhi right side jodaychi
    {
        newn = (struct nodeDCL<T> *)malloc(sizeof(nodeDCL<T>));
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        temp = First;

        for (i = 0; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->prev = temp;

        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

template <class T>
void DoublyCL<T>::DeleteFirst()
{
    if ((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single nodeDCL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one nodeDCL
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
        First->prev = Last;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteLast()
{
    if ((First == NULL) && (Last == NULL)) // Empty LL
    {
        return;
    }
    else if (First == Last) // Single nodeDCL
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else // More than one nodeDCL
    {
        Last = Last->prev;
        delete (First->prev);
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    struct nodeDCL<T> *temp = NULL;
    int i = 0;

    if ((iPos < 1) || (iPos > iCount + 1))
    {
        cout << "Invalid position";
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iCount)
    {
        DeleteLast();
    }
    else // adhi right side jodaychi
    {
        temp = First;

        for (i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

///////////////////////////////////////////
///
/// Code of Stack
///
///////////////////////////////////////////
template <class T>
struct nodeStack
{
    T data;
    struct nodeStack *next;
};

template <class T>
class Stack
{
public:
    struct nodeStack<T> *First;
    T iCount;

public:
    Stack();

    void Display();
    T Count();
    void Push(T No);
    T Pop();
};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Stack<T>::Display()
{
    cout << "Elements of stack are : " << endl;
    struct nodeStack<T> *temp = NULL;
    temp = First;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <class T>
T Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::Push(T No)
{
    struct nodeStack<T> *newn = new nodeStack;
    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
T Stack<T>::Pop()
{
    T iValue = 0;
    struct nodeStack<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to delete as stack is empty" << endl;
        return -1;
    }
    else if (First->next == NULL)
    {
        delete (First);
        First = NULL;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;
        iCount--;
    }
    return iValue;
}

///////////////////////////////////////////
///
/// Code of Queue
///
///////////////////////////////////////////
template <class T>
struct nodeQueue
{
    T data;
    struct nodeQueue *next;
};

template <class T>
class Queue
{
public:
    struct nodeQueue<T> *First;
    T iCount;

public:
    Queue();

    void Display();
    T Count();
    void EnQueue(T No);
    T DeQueue();
};

template <class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;
}

template <class T>
void Queue<T>::Display()
{
    cout << "Elements of Queue are : " << endl;
    struct nodeQueue<T> *temp = NULL;
    temp = First;

    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

template <class T>
T Queue<T>::Count()
{
    return iCount;
}

template <class T>
void Queue<T>::EnQueue(T No)
{
    struct nodeQueue<T> *newn = NULL;
    struct nodeQueue<T> *temp = NULL;

    newn = new nodeQueue;

    newn->data = No;
    newn->next = NULL;

    if (First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
T Queue<T>::DeQueue()
{
    T iValue = 0;
    struct nodeQueue<T> *temp = NULL;

    if (First == NULL)
    {
        cout << "Unable to delete as Queue is empty" << endl;
        return -1;
    }
    else if (First->next == NULL)
    {
        delete (First);
        First = NULL;
    }
    else
    {
        temp = First;

        iValue = First->data;
        First = First->next;
        delete temp;
        iCount--;
    }
    return iValue;
}

///////////////////////////////////////////
///
/// Code of BST
///
///////////////////////////////////////////

template <class T>
struct nodeBST
{
    T data;
    struct nodeBST *lchild;
    struct nodeBST *rchild;
};

template <class T>
class BST
{
public:
    struct nodeBST<T> *Root;
    T iCount;

public:
    BST();

    T Count();
    void Insert(T No);
    void Inorder(struct nodeBST<T> *Root);
    void Preorder(struct nodeBST<T> *Root);
    void Postorder(struct nodeBST<T> *Root);
    bool Search(T No);
    T CountLeaf(struct nodeBST<T> *Root);
    T CountParent(struct nodeBST<T> *Root);
    T CountAll(struct nodeBST<T> *Root);
};

template <class T>
BST<T>::BST()
{
    Root = NULL;
    iCount = 0;
}

template <class T>
T BST<T>::Count()
{
    return iCount;
}

template <class T>
void BST<T>::Insert(T No)
{
    struct nodeBST<T> *newn = new nodeBST<T>;

    newn->data = No;
    newn->lchild = NULL;
    newn->rchild = NULL;

    if (Root == NULL) // Tree is empty
    {
        Root = newn;
    }
    else // Tree contains at least one nodeBST
    {
        struct nodeBST<T> *temp = Root;

        while (1) // Unconditional loop
        {
            if (temp->data == No)
            {
                cout << "Unable to insert nodeBST as element is already present" << endl;
                delete newn;
                break;
            }
            else if (No > temp->data)
            {
                if (temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if (No < temp->data)
            {
                if (temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
}

template <class T>
void BST<T>::Inorder(struct nodeBST<T> *Root)
{
    if (Root != NULL)
    {
        Inorder(Root->lchild);
        cout << Root->data << " ";
        Inorder(Root->rchild);
    }
}

template <class T>
void BST<T>::Preorder(struct nodeBST<T> *Root)
{
    if (Root != NULL)
    {
        cout << Root->data << " ";
        Preorder(Root->lchild);
        Preorder(Root->rchild);
    }
}

template <class T>
void BST<T>::Postorder(struct nodeBST<T> *Root)
{
    if (Root != NULL)
    {
        Postorder(Root->lchild);
        Postorder(Root->rchild);
        cout << Root->data << " ";
    }
}

template <class T>
bool BST<T>::Search(T No)
{
    struct nodeBST<T> *temp = Root;

    while (temp != NULL)
    {
        if (temp->data == No)
        {
            return true;
        }
        else if (No > temp->data)
        {
            temp = temp->rchild;
        }
        else
        {
            temp = temp->lchild;
        }
    }
    return false;
}

template <class T>
T BST<T>::CountLeaf(struct nodeBST<T> *Root)
{
    if (Root == NULL)
        return 0;

    if (Root->lchild == NULL && Root->rchild == NULL)
        return 1;

    return CountLeaf(Root->lchild) + CountLeaf(Root->rchild);
}

template <class T>
T BST<T>::CountParent(struct nodeBST<T> *Root)
{
    if (Root == NULL)
        return 0;

    if (Root->lchild != NULL || Root->rchild != NULL)
        return 1 + CountParent(Root->lchild) + CountParent(Root->rchild);

    return 0;
}

template <class T>
T BST<T>::CountAll(struct nodeBST<T> *Root)
{
    if (Root == NULL)
        return 0;

    return 1 + CountAll(Root->lchild) + CountAll(Root->rchild);
}

///////////////////////////////////////////
///
/// Code of Searching
///
///////////////////////////////////////////
template <typename T>
void Accept(int iSize, T Arr[])
{
    cout << "Enter the elements: \n";
    for (int i = 0; i < iSize; ++i)
    {
        cin >> Arr[i];
    }
}

template <typename T>
void Display(int iSize, T Arr[])
{
    cout << "The elements are: \n";
    for (int i = 0; i < iSize; ++i)
    {
        cout << Arr[i] << endl;
    }
}

template <typename T>
bool LinearSearch(int iSize, T Arr[], T Value)
{
    bool flag = false;
    int i = 0;

    for (i = 0; i < iSize; i++)
    {
        if (Arr[i] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <typename T>
bool BiDirectionalSearch(int iSize, T Arr[], T Value)
{
    bool flag = false;
    int iStart = 0;
    int iEnd = 0;

    for (iStart = 0, iEnd = (iSize - 1); iStart <= iEnd; iStart++, iEnd--)
    {
        if (Arr[iStart] == Value || Arr[iEnd] == Value)
        {
            flag = true;
            break;
        }
    }
    return flag;
}

template <typename T>
bool BinarySearch(int iSize, T Arr[], T Value)
{
    int iStart = 0, iEnd = 0, iMid = 0;
    bool flag = false;

    iStart = 0;
    iEnd = iSize - 1;
    while (iStart <= iEnd)
    {
        iMid = iStart + ((iEnd - iStart) / 2);

        if ((Arr[iMid] == Value) || (Arr[iStart] == Value) || (Arr[iEnd] == Value))
        {
            flag = true;
            break;
        }
        else if (Value < Arr[iMid])
        {
            iEnd = iMid - 1;
        }
        else if (Value > Arr[iMid])
        {
            iStart = iMid + 1;
        }
    }

    return flag;
}

///////////////////////////////////////////
///
/// Code of Sorting
///
///////////////////////////////////////////

template <class T>
void Accept(int iSize, T Arr[])
{
    int i = 0;

    cout << "Enter the elements: " << endl;
    for (i = 0; i < iSize; i++)
    {
        cin >> Arr[i] >> endl;
    }
}

template <class T>
void Display(int iSize, T Arr[])
{
    int i = 0;

    cout << "The elements are: \n"
         << endl;
    for (i = 0; i < iSize; i++)
    {
        cout << Arr[i] << endl;
    }
}

template <class T>
void BubbleSort(int iSize, T Arr[])
{
    int i, j, temp;
    for (i = 0; i < iSize - 1; i++)
    {
        for (j = 0; j < iSize - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
            }
        }
    }
}

template <class T>
void BubbleSortEfficient(int iSize, T Arr[])
{
    bool flag = false;
    int temp;
    for (int i = 0; i < iSize - 1; i++)
    {
        flag = false;
        for (int j = 0; j < iSize - 1 - i; j++)
        {
            if (Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp;
                flag = true;
            }
        }
        if (flag == false)
        {
            break;
        }
    }
}

template <class T>
void SelectionSort(int iSize, T Arr[])
{
    int i = 0, j = 0, min_index = 0;
    int temp;

    for (i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for (j = i + 1; j < iSize; j++)
        {
            if (Arr[j] < Arr[min_index])
            {
                min_index = j;
            }
        }
        temp = Arr[i];
        Arr[i] = Arr[min_index];
        Arr[min_index] = temp;
    }
}

template <class T>
void InsertionSort(int iSize, T Arr[])
{
    int i = 0, j = 0;
    int selected;

    for (i = 1; i < iSize; i++)
    {
        for (j = i - 1; (j >= 0) && (Arr[j] > selected); j--)
        {
            Arr[j + 1] = Arr[j];
        }
        Arr[j + 1] = selected;
    }
}

int main()
{
    return 0;
}