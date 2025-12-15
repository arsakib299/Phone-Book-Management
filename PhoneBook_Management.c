#include <stdio.h>
#include <string.h>

#define MAX 100

char name[MAX][50];
char phone[MAX][20];
char email[MAX][50];

int count = 0;

void addContact()
{
    if (count >= MAX)
    {
        printf("Phonebook is full!\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^\n]", name[count]);

    printf("Enter Phone: ");
    scanf(" %[^\n]", phone[count]);

    printf("Enter Email: ");
    scanf(" %[^\n]", email[count]);

    count++;
    printf("Contact added successfully!\n");
}

void displayContacts()
{
    if (count == 0)
    {
        printf("No contacts to display.\n");
        return;
    }

    printf("\n---- Contact List ----\n");
    for (int i = 0; i < count; i++)
    {
        printf("%d. Name : %s\n", i + 1, name[i]);
        printf("   Phone: %s\n", phone[i]);
        printf("   Email: %s\n", email[i]);
    }
}

void searchContact()
{
    if (count == 0)
    {
        printf("No contacts to search.\n");
        return;
    }

    char key[50];
    printf("Enter Name or Phone to search: ");
    scanf(" %[^\n]", key);

    int found = 0;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(key, name[i]) == 0 || strcmp(key, phone[i]) == 0)
        {
            printf("\nContact Found:\n");
            printf("Name : %s\n", name[i]);
            printf("Phone: %s\n", phone[i]);
            printf("Email: %s\n", email[i]);
            found = 1;
        }
    }

    if (!found)
        printf("Contact not found.\n");
}

void updateContact()
{
    if (count == 0)
    {
        printf("No contacts to update.\n");
        return;
    }

    char key[50];
    printf("Enter Name or Phone to update: ");
    scanf(" %[^\n]", key);

    int idx = -1;

    for (int i = 0; i < count; i++)
    {
        if (strcmp(key, name[i]) == 0 || strcmp(key, phone[i]) == 0)
        {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        printf("Contact not found.\n");
        return;
    }

    printf("Updating Contact...\n");

    printf("Enter new Name: ");
    scanf(" %[^\n]", name[idx]);

    printf("Enter new Phone: ");
    scanf(" %[^\n]", phone[idx]);

    printf("Enter new Email: ");
    scanf(" %[^\n]", email[idx]);

    printf("Contact updated successfully!\n");
}

void saveToFile()
    {
    FILE *f = fopen("contacts.txt", "w");

    if (f == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(f, "%s,%s,%s\n", name[i], phone[i], email[i]);
    }

    fclose(f);
    printf("Contacts saved to contacts.txt\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n--- Phonebook Menu ---\n");
        printf("1. Add Contact\n");
        printf("2. Display Contacts\n");
        printf("3. Search Contact\n");
        printf("4. Update Contact\n");
        printf("5. Save to File\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: addContact(); 
            break;
            case 2: displayContacts(); 
            break;
            case 3: searchContact(); 
            break;
            case 4: updateContact(); 
            break;
            case 5: saveToFile(); 
            break;
            case 6: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}
