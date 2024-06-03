#include "main.h"
#include "LinkListQueue.h"


//constructor
LinkListQueue::LinkListQueue(){
	frontNode = NULL;
	backNode = NULL;
}
//enqueue implementation
QueueNode* LinkListQueue::enQueue(QueueNode* node){
	if(frontNode == NULL){//Queue is empty	
		node->next = NULL;
		node->prev = NULL;
		frontNode = node;
		backNode = node;
	} else {// add node to end of the queue
		node->prev = NULL;
		node->next = backNode;
		backNode->prev = node;
		backNode = node;
	}
	return backNode;
}

//dequeue implementation
QueueNode* LinkListQueue::deQueue(){
	QueueNode* node = NULL;
	if(frontNode == NULL){// Queue is empty
		return NULL;
	} else {
		node = frontNode;
		frontNode = frontNode->prev;
		if(frontNode!=NULL) frontNode->next = NULL;
	}
	return node;
}

//get first node in queue
QueueNode* LinkListQueue::getFrontNode(){
	return frontNode;	
}

//get last node in queue
QueueNode* LinkListQueue::getBackNode(){
	return backNode;
}

QueueNode* LinkListQueue::removeNode(string strKey){
    QueueNode* node = getNode(strKey);
    QueueNode* prevNode = NULL;
    QueueNode* nextNode = NULL;
    
    if(node == NULL) return NULL;
    prevNode = node->prev;
    nextNode = node->next;
    if(prevNode != NULL) prevNode->next = node->next;
    if(nextNode != NULL) nextNode->prev = node->prev;
    
    return node;
}

QueueNode* LinkListQueue::getNode(string strKey){
    if(this->getBackNode() == NULL) return NULL; //return NULL if list is empty
    
    QueueNode* node = this->getBackNode();// Go to the back of the queue
    
    while(node != NULL){
        if(node->key.compare(strKey) == 0 ) break;//end loop early when node is found
        node = node->next;
    }
    return node;
}
void LinkListQueue::printAll(){
	if(this->getBackNode() == NULL) return; //return NULL if list is empty    
    QueueNode* node = this->getBackNode();// Go to the back of the queue
    
    while(node != NULL){
		cout <<"[Key="<<node->key<<" data="<<node->data<<"] ";
        node = node->next;
    }
	
}
