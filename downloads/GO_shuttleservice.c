/*
    This is to certify that this project is my own work, based on my
    personal efforts in studying and applying the concepts learned. I
    have constructed the functions and their respective algorithms
    and corresponding code by myself. The program was run, tested, and
    debugged by my own efforts. I further certify that I have not
    copied in part or whole or otherwise plagiarized the work of other
    students and/or persons.
    Timothy Aaron s. Go
*/

/* 
    Description: This program is a shuttle service ticketing system which allows the agent
    to book tickets from Manila to Laguna and vice versa. It also allows the
    agent to cancel a booking and to update the shuttle service's schedule.
    Last modified: 11/26/2023 11:03 PM
*/

#include <stdio.h>

/*
    Function: displayBusLayout
    Description: Displays the bus' layout according to the picture.
    Preconditon: n/a
    @param n/a
    @return n/a
*/

void displayBusLayout() {
    printf("[1] [2] [5] [6] [11]\n");
    printf("    [3] [6] [9] [12]\n");
    printf("   [4] [7] [10] [13]\n");
    printf("                [14]\n");
}

/*
    Function: countAvailableSeats
    Description: This function counts the number of available seats based on a given seat bitstring.
    Precondition: seatBitstring is 0.
    @param seatBitstring An integer representing the seat availability, where each bit represents 
                        the status of a seat (1 for booked, 0 for available).
    @return The number of available seats.
*/

int countAvailableSeats(int seatBitstring) {
    int availableSeats = 0;

    // Iterate through each bit of the seat bitstring
    for (int i=0; i < 14; i++) {
        // Check if the current seat is available (bit is 0)
        if (seatBitstring % 2 == 0)
            availableSeats++;
        // Shift the bitstring to the right
        seatBitstring = seatBitstring >> 1;
    }

    return availableSeats;
}

int isSeatBooked(int seatBitstring, int seatNumber) {
    int chosenSeat = 1 << (seatNumber-1);
    return (seatBitstring & chosenSeat) > 0;
}

/*
    Function: displaySchedule
    Description: This function displays the bus schedule, including departure and arrival 
                times for trips between Manila and Laguna.
    Precondition: The variable 'currentHour' should be appropriately initialized before 
                calling this function.
    @param: departureTime is the time of departure set by the agent.
    @return: n/a
*/

void displaySchedule(int departureTime) {

    printf("Trip\tDepart Manila\tArrive Laguna\tDepart Laguna\tArrive Manila\n");

    int trip = 1;
    for (int hour = 4; hour <= 18; hour += 2) {
        // Display the schedule for Manila to Laguna only for hours other than 12 pm
        if (hour != 12) {
            // Display the schedule for Manila to Laguna
            printf("%-5d\t", trip);

            // Determine the status of the trip (past, current, or future) for Manila to Laguna
            if (hour < departureTime) {
                printf("(Past) ");
            } else if (hour == departureTime) {
                printf("(Current) ");
            } else {
                printf("(Future) ");
            }

            // Display the schedule for Manila to Laguna
            printf("%02d:00\t\t%02d:00\t", hour, hour + 1);

            if (hour + 1 < departureTime) {
                printf("(Past) ");
            } else if (hour + 1 == departureTime) {
                printf (" (Current) ");
            } else {
                printf(" (Future) ");
            }

            // Display the schedule for Laguna to Manila
            printf("%02d:00\t\t%02d:00\n", hour + 1, hour + 2);

            // Increment trip number
            trip++;
        }
    }
}

/*
    Function: isValidNewTIme
    Description: This function checks if the new hour is a valid input.
    Precondition: The input must be a positive whole number in the schedule.
    @param  newHour is the updated hour set by the agent.
            currentHour is the default hour and also the future hour once
            updated again.
    @return 1 if the time is valid, 0 if otherwise.
*/

int isValidNewTime(int newHour, int currentHour) {
    return newHour >= 4 && newHour <= 18 && newHour > currentHour;
}

/*
    Function: getStudentId
    Description: This function retrieves the student ID assigned to a specific seat.
    Precondition: The parameters 'seatNumber', 'studentSeat1' to 'studentSeat14' are assumed to be defined.
    @param seatNumber The seat number for which to retrieve the student ID.
    @param studentSeat1 to studentSeat14 The student IDs assigned to seats 1 to 14.
    @return Returns the student ID for the specified seat. Returns -1 if the seat number is invalid.
*/

long getStudentId(int seatNumber, int studentSeat1, int studentSeat2, 
                int studentSeat3, int studentSeat4, int studentSeat5, 
                int studentSeat6, int studentSeat7, int studentSeat8, 
                int studentSeat9, int studentSeat10, int studentSeat11, 
                int studentSeat12, int studentSeat13, int studentSeat14) {
                    long result = -1; // Default value for invalid seatNumber

                    switch (seatNumber) {
                    case 1:
                        result = studentSeat1;
                        break;
                    case 2:
                        result = studentSeat2;
                        break;
                    case 3:
                        result = studentSeat3;
                        break;
                    case 4:
                        result = studentSeat4;
                        break;
                    case 5:
                        result = studentSeat5;
                        break;
                    case 6:
                        result = studentSeat6;
                        break;
                    case 7:
                        result = studentSeat7;
                        break;
                    case 8:
                        result = studentSeat8;
                        break;
                    case 9:
                        result = studentSeat9;
                        break;
                    case 10:
                        result = studentSeat10;
                        break;
                    case 11:
                        result = studentSeat11;
                        break;
                    case 12:
                        result = studentSeat12;
                        break;
                    case 13:
                        result = studentSeat13;
                        break;
                    case 14:
                        result = studentSeat14;
                        break;
                    default:
                        break;
                    }
                    return result;
}

int main() {
    // Handle UI and data (including input)

    int seatBitstring = 0;
    int departureTime = 4;
    int totalBooked = 0;
    
    // Holds student number in booked seat
    long studentSeat1 = 0;
    long studentSeat2 = 0;
    long studentSeat3 = 0;
    long studentSeat4 = 0;
    long studentSeat5 = 0;
    long studentSeat6 = 0;
    long studentSeat7 = 0;
    long studentSeat8 = 0;
    long studentSeat9 = 0;
    long studentSeat10 = 0;
    long studentSeat11 = 0;
    long studentSeat12 = 0;
    long studentSeat13 = 0;
    long studentSeat14 = 0;

    // Menu
    int choice;
    do {
        // Display menu
        printf("\n");
        printf("Menu:\n");
        printf("1. Book a ticket\n");
        printf("2. Cancel a booking\n");
        printf("3. Display Schedule\n");
        printf("4. Update Departure Time\n");
        printf("5. Close application\n");
        printf("\n");
        
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        printf("\n");

        int seatNumber;
        long studentId;
        int chosenSeat;
        int newHour;
        switch (choice) {
        case 1:
            //Book a ticket
            printf("Booking a ticket...\n");

            // Output departure time, route, number of available seats
            displaySchedule(departureTime);
            
            printf("\nNo. of available seats: %d\n", countAvailableSeats(seatBitstring));
            
            printf("\n");
            displayBusLayout();

            printf("\nEnter seat choice (1-14): ");
            scanf("%d", &seatNumber);

            if (isSeatBooked(seatBitstring, seatNumber) || seatNumber < 1 || seatNumber > 14) {
                printf("\nSeat number is invalid\n");
                break;
            }

            chosenSeat = 1 << (seatNumber-1);
            seatBitstring |= chosenSeat;

            printf("Enter student ID: ");
            scanf("%ld", &studentId);

            switch (seatNumber) {
            case 1:
                studentSeat1 = studentId;
            case 2:
                studentSeat2 = studentId;
            case 3:
                studentSeat3 = studentId;
             case 4:
                studentSeat4 = studentId;
            case 5:
                studentSeat5 = studentId;
            case 6:
                studentSeat6 = studentId;
            case 7:
                studentSeat7 = studentId;
            case 8:
                studentSeat8 = studentId;
            case 9:
                studentSeat9 = studentId;
            case 10:
                studentSeat10 = studentId;
            case 11:
                studentSeat11 = studentId;
            case 12:
                studentSeat12 = studentId;
            case 13:
                studentSeat13 = studentId;
            case 14:
                studentSeat14 = studentId;
            }

            totalBooked++;
            printf("Seat %d booked successfully.\n", seatNumber);

            break;
        case 2:
            //Break early if there are no seats booked
            if (countAvailableSeats(seatBitstring) == 14){
                printf("No seats booked.\n");
                break;
            }

            // Cancel a booking
            printf("Cancel a booking.");

            if (countAvailableSeats(seatBitstring) == 14){
                printf("No seats booked.");
                break;
            }


            // Show booked seats
            printf("Booked Seats and Student IDs:\n");
            for (int i = 1; i <= 14; i++) {
                if (isSeatBooked(seatBitstring, i) != 0) {
                    printf("Seat %d: Student ID %ld\n", i, getStudentId(i, studentSeat1, studentSeat2, studentSeat3, 
                                                                        studentSeat4, studentSeat5, studentSeat6, 
                                                                        studentSeat7, studentSeat8, studentSeat9, 
                                                                        studentSeat10, studentSeat11, studentSeat12, 
                                                                        studentSeat13, studentSeat14));
                }
            }

            printf("\nEnter seat choice (1-14): ");
            scanf("%d", &seatNumber);

            if (!isSeatBooked(seatBitstring, seatNumber)) {
                printf("Seat %d is not booked. No booking to cancel.\n", seatNumber);
                break;
            }

            switch (seatNumber) {
            case 1:
                studentId = studentSeat1;
                break;
            case 2:
                studentId = studentSeat2;
                break;
            case 3:
                studentId = studentSeat3;
                break;
             case 4:
                studentId = studentSeat4;
                break;
            case 5:
                studentId = studentSeat5;
                break;
            case 6:
                studentId = studentSeat6;
                break;
            case 7:
                studentId = studentSeat7;
                break;
            case 8:
                studentId = studentSeat8;
                break;
            case 9:
                studentId = studentSeat9;
                break;
            case 10:
                studentId = studentSeat10;
                break;
            case 11:
                studentId = studentSeat11;
                break;
            case 12:
                studentId = studentSeat12;
                break;
            case 13:
                studentId = studentSeat13;
                break;
            case 14:
                studentId = studentSeat14;
                break;
            }
            
            chosenSeat = ~(1 << (seatNumber-1));
            seatBitstring &= chosenSeat;

            totalBooked--;
            printf("Booking for Seat %d (Student ID: %ld) cancelled successfully.\n", seatNumber, studentId);
            break;
        case 3:
            // Display Schedule
            displaySchedule(departureTime);
            break;
        case 4:
            // Update Departure Time

            do {
                printf("Enter the new departure hour: ");
                scanf("%d", &newHour);

                if (!isValidNewTime(newHour, departureTime))
                    printf("Please enter a valid hour.\n");

            } while(!isValidNewTime(newHour, departureTime));

            departureTime = newHour;
            seatBitstring = 0;

            printf("Departure time updated successfully!\n");
            break;
        case 5:
            // Close Application
            printf("Total booked: %d\n", totalBooked); //Displays total booked
            printf("Exiting the program. Goodbye!\n");
            printf("\n");
            break;
        default:
            printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}
