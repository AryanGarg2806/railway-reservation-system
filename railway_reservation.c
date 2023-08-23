#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ticket {
    int ticket_number;
    char passenger_name[50];
    char train_name[50];
};

struct Ticket tickets[100];
int ticket_count = 0;

void bookTicket() {
    if (ticket_count < 100) {
        struct Ticket ticket;
        printf("Enter passenger name: ");
        scanf("%s", ticket.passenger_name);
        printf("Enter train name: ");
        scanf("%s", ticket.train_name);
        
        ticket.ticket_number = ticket_count + 1;
        tickets[ticket_count] = ticket;
        ticket_count++;
        
        printf("Ticket booked successfully. Ticket number: %d\n", ticket.ticket_number);
    } else {
        printf("Sorry, all tickets are booked.\n");
    }
}

void displayTickets() {
    printf("Ticket Number\tPassenger Name\tTrain Name\n");
    for (int i = 0; i < ticket_count; i++) {
        printf("%d\t\t%s\t\t%s\n", tickets[i].ticket_number, tickets[i].passenger_name, tickets[i].train_name);
    }
}

int main() {
    int choice;
    
    do {
        printf("\nRailway Reservation System\n");
        printf("1. Book Ticket\n");
        printf("2. Display Tickets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                bookTicket();
                break;
            case 2:
                displayTickets();
                break;
            case 3:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
    
    return 0;
}
