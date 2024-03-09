#include "AvlTree.hpp"

AvlNode* AvlTree::SearchAndAdd(AvlNode*& subNode, const int& newItem)
{
    if (subNode == NULL)
    {
        subNode = new AvlNode(newItem);
    }
    else if (newItem == subNode->data)
    {
        subNode->data = newItem;
    }
    else if (newItem < subNode->data)
    {
        subNode->left = SearchAndAdd(subNode->left, newItem);
        if (Height(subNode->left) == Height(subNode->right) + 2)
        {
            if (newItem < subNode->left->data)
            {
                subNode = SwapWithLeftChild(subNode);
            }
            else
            {
                subNode->left = SwapWithRightChild(subNode->left);
                subNode = SwapWithLeftChild(subNode);
            }
        }
    }
    else
    {
        subNode->right = SearchAndAdd(subNode->right, newItem);

        if (Height(subNode->right) == Height(subNode->left) + 2)
        {
            if (newItem > subNode->right->data)
            {
                subNode = SwapWithRightChild(subNode);
            }
            else
            {
                subNode->right = SwapWithLeftChild(subNode->right);
                subNode = SwapWithRightChild(subNode);
            }
        }
    }

    subNode->height = Height(subNode);
    return subNode;
}

AvlNode* AvlTree::SwapWithLeftChild(AvlNode* subNode)
{
    AvlNode* temp = subNode->left;
    subNode->left = temp->right;
    temp->right = subNode;

    subNode->height = Height(subNode);
    temp->height = 1 + max(Height(temp->left), subNode->height);

    return temp;
}

AvlNode* AvlTree::SwapWithRightChild(AvlNode* subNode)
{
    AvlNode* temp = subNode->right;
    subNode->right = temp->left;
    temp->left = subNode;

    subNode->height = Height(subNode);
    temp->height = 1 + max(Height(temp->right), subNode->height);

    return temp;
}

bool AvlTree::SearchAndDelete(AvlNode*& subNode, const int& data)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == data)
        return DeleteNode(subNode);
    else if (data < subNode->data)
        return SearchAndDelete(subNode->left, data);
    else
        return SearchAndDelete(subNode->right, data);
}

bool AvlTree::DeleteNode(AvlNode*& subNode)
{
    AvlNode* DelNode = subNode;

    if (subNode->right == NULL)
        subNode = subNode->left;
    else if (subNode->left == NULL)
        subNode = subNode->right;
    else
    {
        DelNode = subNode->left;
        AvlNode* parent = subNode;
        while (DelNode->right != NULL)
        {
            parent = DelNode;
            DelNode = DelNode->right;
        }
        subNode->data = DelNode->data;
        if (parent == subNode)
            subNode->left = DelNode->left;
        else
            parent->right = DelNode->left;
    }
    delete DelNode;
    return true;
}

void AvlTree::postorder(AvlNode* subNode)
{
    if (subNode != NULL)
    { 
        postorder(subNode->left);
        postorder(subNode->right);
        if(subNode->left != NULL || subNode->right != NULL)
        {
            totalExceptLeafs += subNode->data;
        }
    }
}

void AvlTree::leaf(AvlNode* subNode) 
{
    if (subNode != NULL) {
        leaf(subNode->left);
        if (subNode->left == NULL && subNode->right == NULL)
            stack->push(subNode->data);
        leaf(subNode->right);
    }
}



int AvlTree::Height(AvlNode* subNode)
{
    if (subNode == NULL)
        return -1;
    return 1 + max(Height(subNode->left), Height(subNode->right));
}

void AvlTree::PrintLevel(AvlNode* subNode, int level)
{
    if (subNode == NULL)
        return;
    if (level == 0)
        cout << subNode->data << " ";
    else
    {
        PrintLevel(subNode->left, level - 1);
        PrintLevel(subNode->right, level - 1);
    }
}

bool AvlTree::Search(AvlNode* subNode, const int& item)
{
    if (subNode == NULL)
        return false;
    if (subNode->data == item)
        return true;
    if (item < subNode->data)
        return Search(subNode->left, item);
    else
        return Search(subNode->right, item);
}

bool AvlTree::isEmpty() const
{
    return root == NULL;
}

void AvlTree::Add(const int& newItem)
{
    root = SearchAndAdd(root, newItem);
}

void AvlTree::Delete(const int& data)
{
    if (SearchAndDelete(root, data) == false)
        throw "Item not found.";
}

void AvlTree::postorder()
{
    postorder(root);
}

void AvlTree::leaf()
{
    leaf(root);
}

void AvlTree::levelorder()
{
    int h = Height();
    for (int level = 0; level <= h; level++)
    {
        PrintLevel(root, level);
    }
}

int AvlTree::Height()
{
    return Height(root);
}

bool AvlTree::Search(const int& item)
{
    return Search(root, item);
}

void AvlTree::Clear()
{
    delete stack;
    
    while (!isEmpty())
        DeleteNode(root);
}