#include<iostream>
#include<stdint.h>


struct Node
{
    int m_data;
    Node * m_next;
    Node* m_head;
    
    
    Node():m_data(0),m_head(nullptr) {}
    
    void insertFront(const int& p_data) 
    {
        Node* temp = new Node;
        temp -> m_data = p_data; 
        temp -> m_next = m_head;
        m_head = temp;
    }
    
    void printList()
    {
        Node* ptr = m_head;
        while(ptr != 0)
        {
            std::cout << ptr->m_data << " ";
            ptr = ptr -> m_next;
        }
        std::cout << std::endl;
    }
    
    void pushBack(const int& p_data)
    {
        // Create the new node & add only data
        Node* temp = new Node;
        temp -> m_data = p_data;
       
        //Go to the last element
        Node* ptr = m_head;
        while(ptr->m_next != nullptr)
        {
            ptr = ptr -> m_next;    
        }
        
        ptr -> m_next = temp;
        temp -> m_next = nullptr;
    }
    void randomAfterNode(int p_cData, int p_nData)
    {
        Node* ptr = m_head;
        
        while(ptr->m_data != p_cData)
        {
            
            ptr = ptr->m_next;
            
        }
          
        //Crate the new node
        Node* temp = new Node;
        temp -> m_data = p_nData;
        
        // Establis the links
        temp -> m_next = ptr-> m_next;
        
        ptr-> m_next = temp;
        
    }
    
    void reverse()
    {
        // starting node
        Node* start = m_head; 
        
        // ending node
        Node* end = m_head;
        while(end -> m_next != nullptr)
        {
            end = end -> m_next;
        } 
        
        while(start != end)
        {
           if(end -> m_next == start) 
           {
                break;    
           }
            // Swap the start and end  
            int temp = start -> m_data;
            start -> m_data = end -> m_data;
            end -> m_data = temp;
            
            // Increment the start and decrement the end
            start = start -> m_next;
            
            Node* tPtr = m_head;
            while(tPtr -> m_next != end)
            {
                tPtr = tPtr -> m_next; 
            }
            end = tPtr;
        }
    }
    
    void reverse2()
    {
        Node* cur = m_head;
        Node* prev = nullptr;
        Node* later = nullptr;
        
        while(cur != nullptr)
        {
            later = cur -> m_next;
            cur -> m_next = prev;
            prev = cur;
            cur = later;
        }
        
        m_head = prev;
    }
    
    void deleteNodeByValue(int p_data)
    {
        Node *cur = m_head;
        Node *prev = nullptr;
        
        // Handle the first node deletion
        if(m_head->m_data == p_data)
        {
            m_head = cur->m_next; 
            return;
        }
        
        while(cur -> m_data != p_data)
        {
            prev = cur;
            cur = cur -> m_next;    
        }
        
        // Remove the link
        prev -> m_next = cur -> m_next;
        
        delete cur;
    }
    
    void deleteNodeWithoutHead(Node* ptr) 
    {
        
        if(ptr == nullptr)
        {
           //delete ptr; 
            return;
        }
        else if( ptr -> m_next == nullptr)
        {
            std::cout << "This is last node, hence it can't be deleted with the head" << std::endl;
            return;
        }
        else
        {
            ptr->m_data = (ptr->m_next)->m_data;
            Node* prev = ptr;
            ptr = ptr->m_next;
            prev->m_next = ptr->m_next;
            delete ptr;
        }
    }
        
};


int main()
{
    
    Node list;
    list.insertFront(2);
    list.insertFront(1);
    list.pushBack(3);
    list.pushBack(12);
    list.pushBack(14);
    list.randomAfterNode(2, 10);
    list.printList();
    list.reverse();
    list.printList();
    
    list.deleteNodeByValue(1);
    list.deleteNodeByValue(10);
    list.deleteNodeByValue(14);
    list.printList();
    list.reverse2();
    list.printList();
    
    list.deleteNodeWithoutHead(list.m_head->m_next); 
    list.deleteNodeWithoutHead(list.m_head->m_next); 
    list.printList();
    
}
