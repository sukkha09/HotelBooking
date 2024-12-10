#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Room {
    int roomNumber;
    bool isAvailable;
    string guestName;
};


class Hotel {
private:
    vector<Room> rooms;
    
public:
    
    Hotel(int totalRooms) {
        for (int i = 1; i <= totalRooms; ++i) {
            Room room;
            room.roomNumber = i;
            room.isAvailable = true;  
            rooms.push_back(room);
        }
    }

    
    void displayRooms() {
        cout << "Available Rooms:\n";
        for (const auto& room : rooms) {
            if (room.isAvailable) {
                cout << "Room " << room.roomNumber << " is available.\n";
            }
        }
    }

    
    void bookRoom() {
        int roomNumber;
        string guestName;
        cout << "Enter the room number you want to book: ";
        cin >> roomNumber;
        
        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number.\n";
            return;
        }
        
        Room &room = rooms[roomNumber - 1];
        
        if (room.isAvailable) {
            cout << "Enter guest name: ";
            cin.ignore();
            getline(cin, guestName);
            room.isAvailable = false;
            room.guestName = guestName;
            cout << "Room " << roomNumber << " booked successfully for " << guestName << ".\n";
        } else {
            cout << "Room " << roomNumber << " is already booked.\n";
        }
    }

    
    void cancelBooking() {
        int roomNumber;
        cout << "Enter the room number to cancel the booking: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number.\n";
            return;
        }

        Room &room = rooms[roomNumber - 1];
        
        if (!room.isAvailable) {
            cout << "Booking for room " << roomNumber << " under guest " << room.guestName << " is cancelled.\n";
            room.isAvailable = true;
            room.guestName = "";
        } else {
            cout << "Room " << roomNumber << " is not booked.\n";
        }
    }

    
    void checkIn() {
        int roomNumber;
        cout << "Enter the room number to check-in: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number.\n";
            return;
        }

        Room &room = rooms[roomNumber - 1];
        
        if (room.isAvailable) {
            cout << "Room " << roomNumber << " is available for check-in.\n";
        } else {
            cout << "Room " << roomNumber << " is already booked by " << room.guestName << ".\n";
        }
    }

    
    void checkOut() {
        int roomNumber;
        cout << "Enter the room number to check-out: ";
        cin >> roomNumber;

        if (roomNumber < 1 || roomNumber > rooms.size()) {
            cout << "Invalid room number.\n";
            return;
        }

        Room &room = rooms[roomNumber - 1];

        if (!room.isAvailable) {
            cout << "Guest " << room.guestName << " checked out from room " << roomNumber << ".\n";
            room.isAvailable = true;
            room.guestName = "";
        } else {
            cout << "Room " << roomNumber << " is not booked.\n";
        }
    }

    
    void displayBookingDetails() {
        cout << "Room Booking Details:\n";
        for (const auto& room : rooms) {
            if (!room.isAvailable) {
                cout << "Room " << room.roomNumber << " is booked by " << room.guestName << ".\n";
            }
        }
    }
};

int main() {
    int totalRooms = 5;  
    Hotel hotel(totalRooms);
    int choice;

    do {
        
        cout << "\nHotel Booking System\n";
        cout << "1. Display available rooms\n";
        cout << "2. Book a room\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Check-in\n";
        cout << "5. Check-out\n";
        cout << "6. View booking details\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                hotel.displayRooms();
                break;
            case 2:
                hotel.bookRoom();
                break;
            case 3:
                hotel.cancelBooking();
                break;
            case 4:
                hotel.checkIn();
                break;
            case 5:
                hotel.checkOut();
                break;
            case 6:
                hotel.displayBookingDetails();
                break;
            case 7:
                cout << "Exiting the system. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}
