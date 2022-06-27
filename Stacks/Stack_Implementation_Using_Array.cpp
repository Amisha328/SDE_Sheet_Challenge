// Stack Implementation Using Array
// Problem tag: stack, array

class Stack {    
public:
    int size, topEle;
    int arr[1000];
    Stack(int capacity) {
        size = capacity;
        topEle = -1;
    }

    void push(int num) {
        if(topEle != size-1)
        {
            topEle++;
            arr[topEle] = num;
        }   
    }

    int pop() {
        if(topEle == -1)
            return -1;
        int num = arr[topEle];
        topEle--;
        return num;
    }
    
    int top() {
        if(topEle == -1)
            return -1;
        return arr[topEle];
    }
    
    int isEmpty() {
        if(topEle == -1)
            return 1;
        return 0;
    }
    
    int isFull() {
        if(topEle == size-1)
            return 1;
        return 0;
    }
};