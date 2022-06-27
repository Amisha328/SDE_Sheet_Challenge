// LFU Cache

#include <bits/stdc++.h> 
struct Node
{
    int key, value, count; // count to store feq
    Node *next, *prev;
    Node(int _key, int _value)
    {
        key = _key;
        value = _value;
        count = 1;
    }
};
struct List
{
    int size;
    Node *head, *tail;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    void addFront(Node *node)
    {
        node->next = head->next; // as first element is (0,0)
        node->next->prev = node;
        node->prev = head;
        head->next = node;
        size++;
    }
    void removeNode(Node *node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
        size--;
    }
};
class LFUCache
{
public:
    map<int, Node*> keyNode;  // key, node
    map<int, List*> freqList;  // freq, freq List
    int minFreq, maxSize, currSize;
    LFUCache(int capacity)
    {
        maxSize = capacity;
        minFreq = currSize = 0;
    }
    void updateFreqList(Node *node)
    {
        keyNode.erase(node->key);
        freqList[node->count]->removeNode(node);
        // if the node was in min freq list and after removing the node that list becomes empty then we shift it in the new list with next greater frequency
        if(node->count == minFreq && freqList[node->count]->size == 0)
            minFreq++;
        List *nextHigherFreqList = new List();
        // check if next greater frequency list already exist
        if(freqList.find(node->count+1) != freqList.end())
            nextHigherFreqList = freqList[node->count+1];
        // increment the frequency count
        node->count += 1;
        // add the node in the next greater frequency list
        nextHigherFreqList->addFront(node);
        freqList[node->count] = nextHigherFreqList;
        keyNode[node->key] = node;
    }
    int get(int key)
    {
        if(keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            int val = node->value;
            updateFreqList(node);
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if(maxSize == 0) return;
        if(keyNode.find(key) != keyNode.end())
        {
            Node *node = keyNode[key];
            node->value = value;
            updateFreqList(node);
        }
        else
        {
            if(currSize == maxSize)
            {
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqList[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            minFreq = 1;
            List *list = new List();
            if(freqList.find(minFreq) != freqList.end())
                list = freqList[minFreq];
            Node *node = new Node(key, value);
            list->addFront(node);
            keyNode[key] = node;
            freqList[minFreq] = list;
        }
    }
};
