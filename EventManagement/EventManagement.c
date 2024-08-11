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
    char category[50];
    char description[500];
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
void filterEventsByCategory(HashMap *eventMap);
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

void readLine(char *buffer, int size);

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
        getchar(); // Consume newline character

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
        printf("3. Filter Events by Category\n");
        printf("4. Register for Event\n");
        printf("5. View Attendees\n");
        printf("6. Change Event Status\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice)
        {
        case 1:
            createEvent(eventMap, &eventIdCounter);
            break;
        case 2:
            viewEvents(eventMap);
            break;
        case 3:
            filterEventsByCategory(eventMap);
            break;
        case 4:
            registerForEvent(eventMap, userMap);
            break;
        case 5:
            viewAttendees(eventMap);
            break;
        case 6:
            changeEventStatus(eventMap);
            saveEventsToFile(eventMap);
            break;
        case 7:
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
    readLine(ad.username, sizeof(ad.username));

    if (checkUserExists(ad.username))
    {
        printf("Username already exists. Please try logging in.\n");
        return;
    }

    printf("Enter password: ");
    readLine(ad.password, sizeof(ad.password));

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
    readLine(username, sizeof(username));
    printf("Enter password: ");
    readLine(password, sizeof(password));

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
    readLine(newEvent->name, sizeof(newEvent->name));
    printf("Enter event date (YYYY-MM-DD): ");
    readLine(newEvent->date, sizeof(newEvent->date));
    printf("Enter event time (HH:MM): ");
    readLine(newEvent->time, sizeof(newEvent->time));
    printf("Enter event location: ");
    readLine(newEvent->location, sizeof(newEvent->location));
    printf("Enter event category: ");
    readLine(newEvent->category, sizeof(newEvent->category));
    printf("Enter event description: ");
    readLine(newEvent->description, sizeof(newEvent->description));
    strcpy(newEvent->status, "scheduled");
    newEvent->attendees = NULL;

    insertEvent(eventMap, newEvent);
    printf("Event created successfully!\n");
}

void viewEvents(HashMap *eventMap)
{
    int i, eventFound = 0;
    printf("Events:\n");
    for (i = 0; i < eventMap->size; i++)
    {
        HashNode *current = eventMap->table[i];
        while (current != NULL)
        {
            if (current->event)
            {
                eventFound = 1;
                int attendeeCount = 0;
                user *attendee = current->event->attendees;
                while (attendee != NULL)
                {
                    attendeeCount++;
                    attendee = attendee->next;
                }

                printf("ID: %d, Name: %s, Date: %s, Time: %s, Location: %s, Category: %s, Description: %s, Status: %s, Attendees: %d\n",
                       current->event->id, current->event->name, current->event->date, current->event->time,
                       current->event->location, current->event->category, current->event->description, current->event->status, attendeeCount);
            }
            current = current->next;
        }
    }
    if (!eventFound)
    {
        printf("Currently, no events are available.\n");
    }
}

void filterEventsByCategory(HashMap *eventMap)
{
    int i, eventFound = 0;
    char category[50];
    printf("Enter event category to filter: ");
    readLine(category, sizeof(category));

    printf("Events in category '%s':\n", category);
    for (i = 0; i < eventMap->size; i++)
    {
        HashNode *current = eventMap->table[i];
        while (current != NULL)
        {
            if (current->event && strcmp(current->event->category, category) == 0)
            {
                eventFound = 1;
                int attendeeCount = 0;
                user *attendee = current->event->attendees;
                while (attendee != NULL)
                {
                    attendeeCount++;
                    attendee = attendee->next;
                }

                printf("ID: %d, Name: %s, Date: %s, Time: %s, Location: %s, Category: %s, Description: %s, Status: %s, Attendees: %d\n",
                       current->event->id, current->event->name, current->event->date, current->event->time,
                       current->event->location, current->event->category, current->event->description, current->event->status, attendeeCount);
            }
            current = current->next;
        }
    }
    if (!eventFound)
    {
        printf("No events found in category '%s'.\n", category);
    }
}

void registerForEvent(HashMap *eventMap, HashMap *userMap)
{
    int eventId, userId;
    event *evt;
    user *usr;

    printf("Enter event ID to register: ");
    scanf("%d", &eventId);
    getchar(); // Consume newline character
    evt = searchEvent(eventMap, eventId);
    if (evt == NULL)
    {
        printf("Event not found!\n");
        return;
    }

    printf("Enter user ID: ");
    scanf("%d", &userId);
    getchar(); // Consume newline character
    usr = searchUser(userMap, userId);
    if (usr == NULL)
    {
        usr = (user *)malloc(sizeof(user));
        usr->id = userId;
        printf("Enter user name: ");
        readLine(usr->name, sizeof(usr->name));
        printf("Enter contact number: ");
        readLine(usr->contactNo, sizeof(usr->contactNo));
        usr->next = NULL;
        insertUser(userMap, usr);
    }

    user *current = evt->attendees;
    while (current != NULL)
    {
        if (current->id == userId)
        {
            printf("User already registered for this event!\n");
            return;
        }
        current = current->next;
    }

    usr->next = evt->attendees;
    evt->attendees = usr;
    printf("User registered for event successfully!\n");
}

void viewAttendees(HashMap *eventMap)
{
    int eventId;
    printf("Enter event ID to view attendees: ");
    scanf("%d", &eventId);
    getchar(); // Consume newline character

    event *evt = searchEvent(eventMap, eventId);
    if (evt == NULL)
    {
        printf("Event not found!\n");
        return;
    }

    if (evt->attendees == NULL)
    {
        printf("No attendees registered for event ID %d.\n", eventId);
        return;
    }

    user *attendee = evt->attendees;
    printf("Attendees for event ID %d:\n", eventId);
    while (attendee != NULL)
    {
        printf("User ID: %d, Name: %s, Contact No: %s\n", attendee->id, attendee->name, attendee->contactNo);
        attendee = attendee->next;
    }
}

void changeEventStatus(HashMap *eventMap)
{
    int eventId;
    printf("Enter event ID to change status: ");
    scanf("%d", &eventId);
    getchar(); // Consume newline character

    event *evt = searchEvent(eventMap, eventId);
    if (evt == NULL)
    {
        printf("Event not found!\n");
        return;
    }

    printf("Enter new status for event ID %d (scheduled, live, cancelled, finished): ", eventId);
    readLine(evt->status, sizeof(evt->status));
    printf("Event status updated successfully!\n");
}

void saveEventsToFile(HashMap *eventMap)
{
    FILE *file = fopen(EVENT_FILE, "w");
    if (file == NULL)
    {
        printf("Error opening file for saving events!\n");
        return;
    }
int i;
    for (i = 0; i < eventMap->size; i++)
    {
        HashNode *current = eventMap->table[i];
        while (current != NULL)
        {
            if (current->event)
            {
                event *evt = current->event;
                fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s\n", evt->id, evt->name, evt->date, evt->time, evt->location, evt->category, evt->description, evt->status);
                user *attendee = evt->attendees;
                while (attendee != NULL)
                {
                    fprintf(file, "%d,%s,%s\n", attendee->id, attendee->name, attendee->contactNo);
                    attendee = attendee->next;
                }
                fprintf(file, "END_EVENT\n");
            }
            current = current->next;
        }
    }

    fclose(file);
    printf("Events saved to file successfully!\n");
}

void loadEventsFromFile(HashMap *eventMap, int *eventIdCounter)
{
    FILE *file = fopen(EVENT_FILE, "r");
    if (file == NULL)
    {
        return;
    }

    event *currentEvent = NULL;
    user *lastAttendee = NULL;

    char line[1000];
    while (fgets(line, sizeof(line), file))
    {
        if (strncmp(line, "END_EVENT", 9) == 0)
        {
            currentEvent = NULL;
            lastAttendee = NULL;
        }
        else if (currentEvent == NULL)
        {
            currentEvent = (event *)malloc(sizeof(event));
            sscanf(line, "%d,%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,]", &currentEvent->id, currentEvent->name, currentEvent->date, currentEvent->time,
                   currentEvent->location, currentEvent->category, currentEvent->description, currentEvent->status);
            currentEvent->attendees = NULL;
            insertEvent(eventMap, currentEvent);
            if (currentEvent->id >= *eventIdCounter)
            {
                *eventIdCounter = currentEvent->id + 1;
            }
        }
        else
        {
            user *newAttendee = (user *)malloc(sizeof(user));
            sscanf(line, "%d,%[^,],%s", &newAttendee->id, newAttendee->name, newAttendee->contactNo);
            newAttendee->next = NULL;
            if (currentEvent->attendees == NULL)
            {
                currentEvent->attendees = newAttendee;
            }
            else
            {
                lastAttendee->next = newAttendee;
            }
            lastAttendee = newAttendee;
        }
    }

    fclose(file);
}

void readLine(char *buffer, int size)
{
    if (fgets(buffer, size, stdin) != NULL)
    {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
        {
            buffer[len - 1] = '\0';
        }
    }
}

