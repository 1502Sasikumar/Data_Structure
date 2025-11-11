// Device node
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct devicenode {
    int deviceid;
    char *devicename;
    struct devicenode *prev;
    struct devicenode *next;
};

struct devicenode *head = NULL;
struct devicenode *tail = NULL;

void Adddevice(int deviceid, char *devicename) {
    struct devicenode *newdevice = (struct devicenode *)malloc(sizeof(struct devicenode));
    newdevice->devicename = (char *)malloc(strlen(devicename) + 1);
    strcpy(newdevice->devicename, devicename);
    newdevice->deviceid = deviceid;
    newdevice->next = NULL;

    if (head == NULL) {
        head = tail = newdevice;
        newdevice->prev = NULL;
    } else {
        tail->next = newdevice;
        newdevice->prev = tail;
        tail = newdevice;
    }
}

void removeDevice(int deviceid) {
    struct devicenode *temp = head;

    while (temp != NULL && temp->deviceid != deviceid) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Device ID %d not found.\n", deviceid);
        return;
    }

    if(temp==head){
        head=temp->next;
        free(temp);
    }
    else if(temp==tail)
    {
        tail=tail->prev;
        free(temp->next);
        temp->next=NULL;
    }
    else
    {
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
    }

    printf("Removed Device ID %d\n", deviceid);
   
}

void display() {
    struct devicenode *temp = head;
    while (temp != NULL) {
        printf("Device ID: %d, Device Name: %s\n", temp->deviceid, temp->devicename);
        temp = temp->next;
    }
}

int main() {
    Adddevice(1, "Mouse");
    Adddevice(2, "Keyboard");
    Adddevice(3, "Speaker");

    printf("Device list:\n");
    display();

    printf("Removing device ID 2:\n");
    removeDevice(2);

    printf("Device list after removal:\n");
    display();

    return 0;
}
