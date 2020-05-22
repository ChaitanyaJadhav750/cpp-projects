
#include <iostream>
#include <stdlib.h>

template<typename T> class ArrayList {
    struct structure {
        T data;
        struct structure *next;
    };
    typedef struct structure node;
    node *start = NULL;
public:
    bool add(T new_data); //append element at end
    bool add(int index, T element); //add element at index
    bool addAll(T elements[], int length); //add whole array to list
    bool addAll(int index, T elements[], int length);
    void clear(); //delete all elements from list
    bool contains(T old_data);
    T get(int index);
    int indexOf(T element);
    bool isEmpty();
    bool set(int index, T element);
    int size();
    void display();//print all elements of list
    void remove(int index);
};


template<typename T> bool ArrayList<T>::add(T new_data) {
    node *new_node, *pointer;
    new_node = (node*)malloc(sizeof(node));
    new_node -> data = new_data;
    new_node -> next = NULL;
    if(start == NULL) {
        start = new_node;
        return true;
    }
    else {
        pointer = start;
        while(pointer -> next)
            pointer = pointer -> next;
        pointer -> next = new_node;
        return true;
    }
    return false;
}

template<typename T> bool ArrayList<T>::add(int index, T element) {
    node *pre, *new_node, *post;
    new_node = (node*)malloc(sizeof(node));
    new_node->data = element;

    if(!index && !start) {
        start = new_node;
        new_node->next=NULL;
    }
    else {
        pre = start;
        for(int i=0;i<index-1;i++)
            pre=pre->next;
        post = pre->next;
        pre->next=new_node;
        new_node->next=post;
    }

}

template<typename T> bool ArrayList<T>::addAll(T elements[], int length) {
    for(int i=0;i<length;i++) {
        node *new_node, *p;
        new_node = (node*)malloc(sizeof(node));
        new_node -> data = elements[i];
        new_node -> next = NULL;
        if(!start)
            start = new_node;
        else {
            p = start;
            while(p -> next)
                p = p -> next;
            p -> next = new_node;
        }
    }
    return true;
}

template<typename T> bool ArrayList<T>::addAll(int index, T elements[], int length) {
    node *list = NULL, *new_node, *p, *pre, *post;
    for(int i=0;i<length;i++) {
        new_node = (node*)malloc(sizeof(node));
        new_node -> data = elements[i];
        new_node -> next = NULL;
        if(!list)
            list = new_node;
        else {
            p = list;
            while(p->next)
                p=p->next;
            p->next = new_node;
        }
    }

    if(!index && !start) {
        start = list;
    }
    else {
        pre = start;
        for(int i=0;i<index-1;i++)
            pre=pre->next;
        post = pre->next;
        pre->next=list;
        p = list;
        while(p->next)
            p=p->next;
        p->next=post;
    }


}

template<typename T> void ArrayList<T>::clear() {
    node *p = start;
    if(p){
        free(p);
        start = NULL;
    }
}

template<typename T> bool ArrayList<T>::contains(T old_data) {
    node *p = start;
    while(p) {
        if(p->data == old_data)
            return true;
        else p = p->next;
    }
    return false;
}

template<typename T> T ArrayList<T>::get(int index) {
    node *p = start;
    if(!index)
        return p->data;
    else{
        for(int i=0;i<index;i++)
            p=p->next;
        return p->data;
    }
}

template<typename T> int ArrayList<T>::indexOf(T element) {
    node *p = start;
    int i = 0;
    while(p->data!=element && p) {
        p=p->next;
        ++i;
    }
    if(p->data==element)
        return i;
    else return -1;
}

template<typename T> int ArrayList<T>::size() {
    node *p = start;
    int count = 0;
    while(p) {
        p = p -> next;
        count++;
    }
    return count;
}

template<typename T> bool ArrayList<T>::isEmpty() {
    if(start)
        return false;
    return true;
}

template<typename T> bool ArrayList<T>::set(int index, T element) {
    node *p = start;
    for(int i=0;i<index;i++)
        p = p->next;
    p->data = element;
}

template <typename T> void ArrayList<T>::display() {
    node *p = start;
    std::cout << std::endl << "[ ";
    while(p) {
        std::cout << p -> data << ", ";
        p = p->next;
    }
    std::cout << " ]" << std::endl;
}

template<typename T> void ArrayList<T>::remove(int index) {
    node *pre = start, *post, *p;
    if(!index) {
        start = pre->next;
        free(pre);
    }
    else {
        for(int i=0;i<index-1;i++)
            pre=pre->next;
        p = pre->next;
        post = p->next;
        pre->next=post;
        free(p);
    }
}








