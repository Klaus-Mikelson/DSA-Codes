#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000
#define USER_FILE "admin.txt"
#define EVENT_FILE "events.txt"


typedef struct Admin
{
    char username[50];
    char password[50];
} admin;


typedef struct User
{
    int id;
    char name[50];
    char contactNo[20];
    struct User *next;
} user;


typedef struct Event
{
    int id;
    char name[100];
    char date[20];
    char time[10];
    char location[100];
    char status[20];
    struct Event *next;
    user *attendees;
} event;


typedef struct HashNode
{
    user *user;
    event *event;
    struct HashNode *next;
} HashNode;


typedef struct HashMap
{
    int size;
    HashNode **table;
} HashMap;


void registerUser();
int loginUser();
int checkUserExists(const char *username);
unsigned int hashFunction(int, int);

void createEvent(HashMap *eventMap, int *eventIdCounter);
void viewEvents(HashMap *eventMap);
void registerForEvent(HashMap *eventMap, HashMap *userMap);
void viewAttendees(HashMap *eventMap);

HashMap *createHashMap(int size);
user *searchUser(HashMap *hashMap, int id);
event *searchEvent(HashMap *hashMap, int id);

void insertUser(HashMap *hashMap, user *usr);
void insertEvent(HashMap *hashMap, event *evt);
void changeEventStatus(HashMap* eventMap);
void saveEventsToFile(HashMap *eventMap);
void loadEventsFromFile(HashMap *eventMap, int *eventIdCounter);


int main()
{
    int choice;
    int eventIdCounter = 1;

    int size = 10;
    HashMap *userMap = createHashMap(size);
    HashMap *eventMap = createHashMap(size);
    loadEventsFromFile(eventMap, &eventIdCounter);

    while (1)
    {
        printf("\t\tWelcome to Event Management System\n");
        printf("\t\t\t1. Register\n");
        printf("\t\t\t2. Login\n");
        printf("\t\t\t3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            if (loginUser())
            {
                printf("Login successful!\n");
                break;
            }
            else
            {
                printf("Login failed. Please register first or check your credentials.\n");
            }
        }
        else if (choice == 3)
        {
            return 0;
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }

    while (1)
    {
        printf("\n\nMain Menu\n");
        printf("1. Create Event\n");
        printf("2. View Events\n");
        printf("3. Register for Event\n");
        printf("4. View Attendees\n");
        printf("5. Change Event Status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createEvent(eventMap, &eventIdCounter);
            break;
        case 2:
            viewEvents(eventMap);
            break;
        case 3:
            registerForEvent(eventMap, userMap);
            break;
        case 4:
            viewAttendees(eventMap);
            break;
        case 5:
            changeEventStatus(eventMap);
            saveEventsToFile(eventMap);
            break;
        case 6:
            saveEventsToFile(eventMap);
            return 0;
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }
}


void registerUser()
{
    admin ad;
    FILE *file;

    printf("Enter admin name: ");
    scanf("%s", ad.username);

    if (checkUserExists(ad.username))
    {
        printf("Username already exists. Please try logging in.\n");
        return;
    }

    printf("Enter password: ");
    scanf("%s", ad.password);

    file = fopen(USER_FILE, "a");

    fprintf(file, "%s %s\n", ad.username, ad.password);
    fclose(file);

    printf("User registered successfully!\n");
}

int loginUser()
{
    char username[50], password[50];
    admin ad;
    FILE *file;
    int found = 0;

    printf("Enter name: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    file = fopen(USER_FILE, "r");
    if (file == NULL)
    {
        return 0;
    }

    while (fscanf(file, "%s %s", ad.username, ad.password) != EOF)
    {
        if (strcmp(ad.username, username) == 0 && strcmp(ad.password, password) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}

int checkUserExists(const char *username)
{
    admin ad;
    FILE *file;
    int found = 0;

    file = fopen(USER_FILE, "r");
    if (file == NULL)
    {
        return 0;
    }

    while (fscanf(file, "%s %s", ad.username, ad.password) != EOF)
    {
        if (strcmp(ad.username, username) == 0)
        {
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}

unsigned int hashFunction(int id, int size)
{
    return id % size;
}

HashMap *createHashMap(int size)
{
	int i;
    HashMap *hashMap = (HashMap *)malloc(sizeof(HashMap));
    hashMap->size = size;
    hashMap->table = (HashNode **)malloc(size * sizeof(HashNode *));
    for (i = 0; i < size; i++)
    {
        hashMap->table[i] = NULL;
    }
    return hashMap;
}

void insertUser(HashMap *hashMap, user *usr)
{
    int index = hashFunction(usr->id, hashMap->size);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->user = usr;
    newNode->event = NULL;
    newNode->next = hashMap->table[index];
    hashMap->table[index] = newNode;
}

void insertEvent(HashMap *hashMap, event *evt)
{
    int index = hashFunction(evt->id, hashMap->size);
    HashNode *newNode = (HashNode *)malloc(sizeof(HashNode));
    newNode->event = evt;
    newNode->user = NULL;
    newNode->next = hashMap->table[index];
    hashMap->table[index] = newNode;
}

user *searchUser(HashMap *hashMap, int id)
{
    int index = hashFunction(id, hashMap->size);
    HashNode *current = hashMap->table[index];
    while (current != NULL)
    {
        if (current->user && current->user->id == id)
        {
            return current->user;
        }
        current = current->next;
    }
    return NULL;
}

event *searchEvent(HashMap *hashMap, int id)
{
    int index = hashFunction(id, hashMap->size);
    HashNode *current = hashMap->table[index];
    while (current != NULL)
    {
        if (current->event && current->event->id == id)
        {
            return current->event;
        }
        current = current->next;
    }
    return NULL;
}

void createEvent(HashMap *eventMap, int *eventIdCounter)
{
    event *newEvent = (event *)malloc(sizeof(event));
    newEvent->id = (*eventIdCounter)++;
    printf("Enter event name: ");
    scanf("%s", newEvent->name);
    printf("Enter event date (YYYY-MM-DD): ");
    scanf("%s", newEvent->date);
    printf("Enter event time (HH:MM): ");
    scanf("%s", newEvent->time);
    printf("Enter event location: ");
    scanf("%s", newEvent->location);
    strcpy(newEvent->status, "scheduled");
    newEvent->attendees = NULL;

    insertEvent(eventMap, newEvent);
    printf("Event created successfully!\n");
}

void viewEvents(HashMap *eventMap)
{
	int i;
    printf("Events:\n");
    for (i = 0; i < eventMap->size; i++)
    {
        HashNode *current = eventMap->table[i];
        while (current != NULL)
        {
            if (current->event)
            {
                int attendeeCount = 0;
                user *attendee = current->event->attendees;
                while (attendee != NULL)
                {
                    attendeeCount++;
                    attendee = attendee->next;
                }

                printf("Event ID: %d, Name: %s, Date: %s, Time: %s, Location: %s, Status: %s, Attendees: %d\n",
                       current->event->id, current->event->name, current->event->date, current->event->time,
                       current->event->location, current->event->status, attendeeCount);
            }
            current = current->next;
        }
    }
}

void viewAttendees(HashMap *eventMap)
{
    int eventId;
    printf("Enter event ID: ");
    scanf("%d", &eventId);

    event *evt = searchEvent(eventMap, eventId);
    if (evt == NULL)
    {
        printf("Event not found!\n");
        return;
    }

    printf("Attendees for Event ID %d:\n", eventId);
    user *attendee = evt->attendees;
    while (attendee != NULL)
    {
        printf("User ID: %d, Name: %s, Contact No: %s\n", attendee->id, attendee->name, attendee->contactNo);
        attendee = attendee->next;
    }
}

void registerForEvent(HashMap *eventMap, HashMap *userMap)
{
    int eventId, userId;
    user *usr = (user *)malloc(sizeof(user));

    printf("Enter event ID: ");
    scanf("%d", &eventId);
    event *evt = searchEvent(eventMap, eventId);

    if (evt == NULL)
    {
        printf("Event not found!\n");
        free(usr);
        return;
    }

    printf("Enter user ID: ");
    scanf("%d", &userId);
    printf("Enter user name: ");
    scanf("%s", usr->name);
    printf("Enter contact number: ");
    scanf("%s", usr->contactNo);

    usr->id = userId;
    usr->next = evt->attendees;
    evt->attendees = usr;

    insertUser(userMap, usr);
    printf("User registered for the event successfully!\n");
}

void changeEventStatus(HashMap *eventMap)
{
    int eventId;
    char status[20];

    printf("Enter event ID to change status: ");
    scanf("%d", &eventId);
    event *evt = searchEvent(eventMap, eventId);

    if (evt == NULL)
    {
        printf("Event not found!\n");
        return;
    }

    printf("Enter new status (scheduled/live/cancelled/finished): ");
    scanf("%s", status);
    strcpy(evt->status, status);

    printf("Event status updated successfully!\n");
}

void saveEventsToFile(HashMap *eventMap)
{
    FILE *file = fopen(EVENT_FILE, "w");
    int i;
    for (i = 0; i < eventMap->size; i++)
    {
        HashNode *current = eventMap->table[i];
        while (current != NULL)
        {
            if (current->event)
            {
                event *evt = current->event;
                fprintf(file, "%d %s %s %s %s %s\n", evt->id, evt->name, evt->date, evt->time, evt->location, evt->status);
            }
            current = current->next;
        }
    }

    fclose(file);
}

void loadEventsFromFile(HashMap *eventMap, int *eventIdCounter)
{
    FILE *file = fopen(EVENT_FILE, "r");
    if (file == NULL)
    {
        return;
    }

    while (!feof(file))
    {
        event *evt = (event *)malloc(sizeof(event));
        fscanf(file, "%d %s %s %s %s %s", &evt->id, evt->name, evt->date, evt->time, evt->location, evt->status);
        evt->attendees = NULL;
        insertEvent(eventMap, evt);
        if (evt->id >= *eventIdCounter)
        {
            *eventIdCounter = evt->id + 1;
        }
    }

    fclose(file);
}
