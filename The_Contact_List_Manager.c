#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Contact
typedef struct Contact
{
    char name[50];
    char phone[15];
    struct Contact *prev, *next;
} Contact;

Contact *head = NULL; // Head of the doubly linked list

// Function to add a new contact
void addContact() 
{
    Contact *newContact = (Contact *)malloc(sizeof(Contact));
    printf("\nEnter Name: ");
    scanf(" %49[^\n]", newContact->name);
    printf("Enter Phone Number: ");
    scanf(" %14s", newContact->phone);
    
    newContact->prev = NULL;
    newContact->next = head;
    if (head != NULL) 
    {
        head->prev = newContact;
    }
    head = newContact;
    printf("✅ Contact Added Successfully!\n");
}

// Function to display all contacts
void displayContacts() 
{
    if (head == NULL) 
    {
        printf("\n❌ No contacts available.\n");
        return;
    }
    Contact *temp = head;
    printf("\n📞 Contact List:\n");
    while (temp != NULL) 
    {
        printf("Name: %s, Phone: %s\n", temp->name, temp->phone);
        temp = temp->next;
    }
}

// Function to search for a contact
void searchContact() 
{
    if (head == NULL) 
    {
        printf("\n❌ No contacts available.\n");
        return;
    }
    char searchName[50];
    printf("\nEnter Name to Search: ");
    scanf(" %49[^\n]", searchName);
    
    Contact *temp = head;
    while (temp != NULL) 
    {
        if (strcmp(temp->name, searchName) == 0) 
        {
            printf("✅ Contact Found: Name: %s, Phone: %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("❌ Contact Not Found.\n");
}

// Function to delete a contact
void deleteContact() 
{
    if (head == NULL) 
    {
        printf("\n❌ No contacts available to delete.\n");
        return;
    }
    char deleteName[50];
    printf("\nEnter Name to Delete: ");
    scanf(" %49[^\n]", deleteName);
    
    Contact *temp = head;
    while (temp != NULL) 
    {
        if (strcmp(temp->name, deleteName) == 0) 
        {
            if (temp->prev != NULL) 
            {
                temp->prev->next = temp->next;
            } 
            else 
            {
                head = temp->next;
            }
            if (temp->next != NULL) 
            {
                temp->next->prev = temp->prev;
            }
            free(temp);
            printf("✅ Contact Deleted Successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("❌ Contact Not Found.\n");
}

// Function to edit a contact
void editContact() 
{
    if (head == NULL) 
    {
        printf("\n❌ No contacts available to edit.\n");
        return;
    }
    char searchName[50];
    printf("\nEnter Name to Edit: ");
    scanf(" %49[^\n]", searchName);
    
    Contact *temp = head;
    while (temp != NULL) 
    {
        if (strcmp(temp->name, searchName) == 0)
        {
            printf("Enter New Phone Number: ");
            scanf(" %14s", temp->phone);
            printf("✅ Contact Updated Successfully!\n");
            return;
        }
        temp = temp->next;
    }
    printf("❌ Contact Not Found.\n");
}

// Function to move forward through the contact list
void moveForward() 
{
    if (head == NULL) 
    {
        printf("\n❌ No contacts available.\n");
        return;
    }
    Contact *temp = head;
    int count = 1;
    printf("\n➡ Moving Forward:\n");
    while (temp != NULL) 
    {
        printf("[%d] Name: %s, Phone: %s\n", count++, temp->name, temp->phone);
        temp = temp->next;
    }
}

// Function to move backward through the contact list
void moveBackward() 
{
    if (head == NULL) 
    {
        printf("\n❌ No contacts available.\n");
        return;
    }
    Contact *temp = head;
    
    // Move to the last contact
    while (temp->next != NULL) 
    {
        temp = temp->next;
    }

    int count = 1;
    printf("\n⬅ Moving Backward:\n");
    while (temp != NULL) 
    {
        printf("[%d] Name: %s, Phone: %s\n", count++, temp->name, temp->phone);
        temp = temp->prev;
    }
}

// Function to display menu
void menu() 
{
    int choice;
    while (1) 
    {
        printf("\n📞 Contact Manager\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Edit Contact\n");
        printf("5. Delete Contact\n");
        printf("6. Move Forward\n");
        printf("7. Move Backward\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) 
        {
            case 1: addContact(); break;
            case 2: displayContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: moveForward(); break;
            case 7: moveBackward(); break;
            case 8: printf("👋 Exiting Contact Manager. Goodbye!\n"); return;
            default: printf("❌ Invalid choice. Please try again.\n");
        }
    }
}

int main() 
{
    menu();
    return 0;
}