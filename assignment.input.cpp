#include <iostream>
#include <string>
#include <limits>

using namespace std;

// Function to validate input of any type T
template <typename T>
T validateInput(const string &prompt)
{
    T value;
    while (true)
    {
        cout << prompt;
        if (cin >> value)
        {
            // Input is successful
            break;
        }
        else // Input is not of type T
        {
            cout << "Invalid input. Please enter a valid value of type " << typeid(T).name() << ".\n";
            cin.clear();                                         // clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        }
    }
    return value;
}

// Flight class
class Flight
{
private:
    // Private attributes
    int Flight_ID;
    string Model;
    int Capacity;
    string Airline;
    string Destination;
    string Departure_Time;
    double Ticket_Price;

public:
    // Parameterized constructor
    Flight(int id, string model, int capacity, string airline, string destination, string departure_time, double ticket_price)
        : Flight_ID(id), Model(model), Capacity(capacity), Airline(airline), Destination(destination), Departure_Time(departure_time), Ticket_Price(ticket_price) {}

    // Setters
    void setFlightID(int id) { Flight_ID = id; }
    void setModel(string model) { Model = model; }
    void setCapacity(int capacity) { Capacity = capacity; }
    void setAirline(string airline) { Airline = airline; }
    void setDestination(string destination) { Destination = destination; }
    void setDepartureTime(string departure_time) { Departure_Time = departure_time; }
    void setTicketPrice(double ticket_price) { Ticket_Price = ticket_price; }

    // Getters
    int getFlightID() { return Flight_ID; }
    string getModel() { return Model; }
    int getCapacity() { return Capacity; }
    string getAirline() { return Airline; }
    string getDestination() { return Destination; }
    string getDepartureTime() { return Departure_Time; }
    double getTicketPrice() { return Ticket_Price; }

    // Display flight information
    void displayFlightInfo()
    {
        cout << "Flight Information: " << endl
             << "-------------------" << endl
             << "Flight ID: " << Flight_ID << endl
             << "Model: " << Model << endl
             << "Capacity: " << Capacity << endl
             << "Airline: " << Airline << endl
             << "Destination: " << Destination << endl
             << "Departure Time: " << Departure_Time << endl
             << "Ticket Price: " << Ticket_Price << endl;
    }
};

// Generic Node Class
template <class T>
class Node
{
public:
    // Public attributes
    T data;
    Node *next;

    // Parameterized consctructor
    Node(T value) : data(value), next(nullptr) {}
};

// Linked List Class
template <class T>
class FlightList
{
private:
    // Private attributes
    Node<T> *head;

public:
    // constructor
    FlightList() : head(nullptr) {}

    // get the head of the linked list
    Node<T> *getHead() { return head; }

    // Add Flight to the end of the list
    void addFlight(T flight)
    {
        int newFlightID = flight.getFlightID();

        // Check if Flight with the same ID already exists
        Node<T> *current = head;
        while (current)
        {
            if (current->data.getFlightID() == newFlightID)
            {
                cout << "Flight with ID " << newFlightID << " already exists." << endl;
                return;
            }
            current = current->next;
        }

        // If not found, add the new Flight
        Node<T> *newNode = new Node<T>(flight);
        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Delete Flight by flightID
    void delFlight(int flightID)
    {
        if (head == nullptr)
        {
            cout << "Flight List is empty." << endl;
            return;
        }

        if (head->data.getFlightID() == flightID)
        {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            cout << "Flight with ID " << flightID << " deleted." << endl;
            return;
        }

        Node<T> *current = head;
        while (current->next != nullptr && current->next->data.getFlightID() != flightID)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node<T> *temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Flight with ID " << flightID << " deleted." << endl;
        }
        else
        {
            cout << "Flight with ID " << flightID << " not found." << endl;
        }
    }

    // Display all Flights in the linked list
    void displayAll()
    {
        if (!head)
        {
            cout << "Flight List is empty." << endl;
            return;
        }

        Node<T> *current = head;
        while (current)
        {
            current->data.displayFlightInfo();
            cout << "==========================" << endl;
            current = current->next;
        }
    }

    // Linked List Destructor
    ~FlightList()
    {
        Node<T> *current = head;
        while (current)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
};

// stack class
template <class T>
class FlightStack
{
private:
    // Private attributes
    Node<T> *top;

public:
    // constructor
    FlightStack() : top(nullptr) {}

    // get the top of the stack
    Node<T> *getTop() { return top; }

    // isEmpty function
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Push Flight to the end of the stack
    void pushFlight(T flight)
    {
        int newFlightID = flight.getFlightID();

        // Check if Flight with the same ID already exists
        Node<T> *current = top;
        while (current)
        {
            if (current->data.getFlightID() == newFlightID)
            {
                cout << "Flight with ID " << newFlightID << " already exists." << endl;
                return;
            }
            current = current->next;
        }

        // If not found, add the new Flight
        Node<T> *newNode = new Node<T>(flight);
        if (top == nullptr)
        {
            top = newNode;
        }
        else
        {
            newNode->next = top;
            top = newNode;
        }
    }

    // peek the top of the stack
    Flight peek()
    {
        // another way to peek the top from the stack
        if (top)
        {
            return top->data;
        }
        else
        {
            cerr << "Stack is empty.\n";
            exit(EXIT_FAILURE);
        }
        // this is another way to handling the errors in the peek function
        // else
        // {
        //     throw runtime_error("Stack is empty.");
        // }
    }

    // Delete Flight by Flight_ID
    void deleteFlight(int flightID)
    {
        if (top == nullptr)
        {
            cout << "Flight List is empty." << endl;
            return;
        }

        if (top->data.getFlightID() == flightID)
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
            cout << "Flight with ID " << flightID << " deleted." << endl;
            return;
        }

        Node<T> *current = top;
        while (current->next != nullptr && current->next->data.getFlightID() != flightID)
        {
            current = current->next;
        }

        if (current->next != nullptr)
        {
            Node<T> *temp = current->next;
            current->next = current->next->next;
            delete temp;
            cout << "Flight with ID " << flightID << " deleted." << endl;
        }
        else
        {
            cout << "Flight with ID " << flightID << " not found." << endl;
        }
    }

    // pop the top flight from the stack
    void popFlight()
    {
        if (!isEmpty())
        {
            Node<T> *temp = top;
            top = top->next;
            delete temp;
        }
        else
        {
            cout << "Flight stack is empty." << endl;
        }
    }

    // edit function
    void editFlight(int flightID)
    {
        // if the stack is empty
        if (isEmpty())
        {
            cout << "Flight stack is empty." << endl;
        }

        bool found = false;
        Node<Flight> *current = getTop();

        // if the stack is not empty
        while (current && !found)
        {
            // if the id of the user equal the id in the stack
            if (current->data.getFlightID() == flightID)
            {
                found = true;
                while (true)
                {
                    int editOption;
                    // switch to select the user an attribute to edit
                    cout << "Choose an option to edit for Flight ID " << flightID << ":" << endl
                         << "1. Capacity" << endl
                         << "2. Airline" << endl
                         << "3. Destination" << endl
                         << "4. Departure Time" << endl
                         << "5. Ticket Price" << endl
                         << "0. Stop editing" << endl;
                    cin >> editOption;

                    // switch to edit the selection attribute
                    switch (editOption)
                    {
                    case 1:
                    {
                        // edit capacity
                        int newCapacity;
                        cout << "Enter new Capacity: ";
                        cin >> newCapacity;
                        current->data.setCapacity(newCapacity);
                        break;
                    }
                    case 2:
                    {
                        // edit airline
                        string newAirline;
                        cout << "Enter new Airline: ";
                        cin >> newAirline;
                        current->data.setAirline(newAirline);
                        break;
                    }
                    case 3:
                    {
                        // edit destination
                        string newDestination;
                        cout << "Enter new Destination: ";
                        cin >> newDestination;
                        current->data.setDestination(newDestination);
                        break;
                    }
                    case 4:
                    {
                        // edit depature time
                        string newDepartureTime;
                        cout << "Enter new Departure Time: ";
                        cin >> newDepartureTime;
                        current->data.setDepartureTime(newDepartureTime);
                        break;
                    }
                    case 5:
                    {
                        // edit ticket price
                        double newTicketPrice;
                        cout << "Enter new Ticket Price: ";
                        cin >> newTicketPrice;
                        current->data.setTicketPrice(newTicketPrice);
                        break;
                    }
                    case 0:
                        // stop editing
                        cout << "Editing stopped for Flight ID " << flightID << "." << endl;
                        break;
                    default:
                        // default message if the user choose an invalid option
                        cout << "Invalid option. Please try again.\n";
                    }

                    if (editOption == 0)
                    {
                        break;
                    }
                }
            }

            current = current->next;
        }

        // if the id of the user not found in the flight stack
        if (!found)
        {
            // message to tell the user that the id is not found in the stack
            cout << "Flight with ID " << flightID << " not found in the stack." << endl;
        }
    }

    // print all the flights in the stack
    void printStack()
    {
        if (!top)
        {
            cout << "Flight stack is empty." << endl;
            return;
        }

        Node<T> *current = top;
        while (current)
        {
            current->data.displayFlightInfo();
            cout << "==========================" << endl;
            current = current->next;
        }
    }

    // Destructor
    ~FlightStack()
    {
        Node<T> *current = top;
        while (current)
        {
            Node<T> *next = current->next;
            delete current;
            current = next;
        }
    }
};

// main test
int main()
{
    // welcome message
    cout << "Welcome to the Flight Management System!" << endl;

    // linked list object
    FlightList<Flight> flightList;

    // stack object
    FlightStack<Flight> flightStack;

    // user option loop
    int option;
    do
    {
        // choose an option
        cout << "Choose an option:" << endl
             << "1. LinkedList" << endl
             << "2. Stack" << endl
             << "0. Exit" << endl;
        // cin >> option;
        option = validateInput<int>("Enter your choice: ");

        // switch of the program options
        switch (option)
        {
        case 1:
            // LinkedList operations
            int listOption;
            cout << "LinkedList Options:" << endl
                 << "1. Insert new flight" << endl
                 << "2. Delete Flight" << endl
                 << "3. Display All Flights" << endl
                 << "4. Back to main menu" << endl;
            // cin >> listOption;
            listOption = validateInput<int>("Enter your choice: ");

            // switch of the linked list options
            switch (listOption)
            {
            case 1:
            {
                // Insert new flight
                // this is way to handle the input validation
                int id = validateInput<int>("Enter Flight ID: ");
                string model = validateInput<string>("Enter Model: ");
                int capacity = validateInput<int>("Enter Capacity: ");
                string airline = validateInput<string>("Enter Airline: ");
                string destination = validateInput<string>("Enter Destination: ");
                string departure_time = validateInput<string>("Enter Departure Time: ");
                double ticket_price = validateInput<double>("Enter Ticket Price: ");

                // int id, capacity;
                // string model, airline, destination, departure_time;
                // double ticket_price;

                // cout << "Enter ID: ";
                // cin >> id;
                // cout << "Enter Model: ";
                // cin >> model;
                // cout << "Enter Capacity: ";
                // cin >> capacity;
                // cout << "Enter Airline: ";
                // cin >> airline;
                // cout << "Enter Destination: ";
                // cin >> destination;
                // cout << "Enter Departure Time: ";
                // cin >> departure_time;
                // cout << "Enter Ticket Price: ";
                // cin >> ticket_price;

                Flight newFlight(id, model, capacity, airline, destination, departure_time, ticket_price);
                flightList.addFlight(newFlight);
                break;
            }
            case 2:
            {
                // Delete Flight
                // this is way to handle the input validation
                int flightID = validateInput<int>("Enter Flight ID: ");

                // int flightID;
                // cout << "Enter Flight ID to delete: ";
                // cin >> flightID;
                flightList.delFlight(flightID);
                break;
            }
            case 3:
                // Display All Flights
                flightList.displayAll();
                break;
            case 4:
                // Back to the main menu
                break;
            default:
                // default message if the user choose an invalid option
                cout << "Invalid option. Please try again.\n";
            }
            break;

        case 2:
            // Stack operations
            int stackOption;
            cout << "Stack Options:\n"
                 << "1. Insert new flight\n"
                 << "2. Check the latest Added Flight\n"
                 << "3. Print all the flights\n"
                 << "4. Edit flight\n"
                 << "5. Delete flight\n"
                 << "6. Pop flight\n"
                 << "7. Back to main menu\n";
            cin >> stackOption;

            // switch of the stack options
            switch (stackOption)
            {
            case 1:
            {
                // Insert new flight
                // this is way to handle the input validation
                int id = validateInput<int>("Enter Flight ID: ");
                string model = validateInput<string>("Enter Model: ");
                int capacity = validateInput<int>("Enter Capacity: ");
                string airline = validateInput<string>("Enter Airline: ");
                string destination = validateInput<string>("Enter Destination: ");
                string departure_time = validateInput<string>("Enter Departure Time: ");
                double ticket_price = validateInput<double>("Enter Ticket Price: ");

                // int id, capacity;
                // string model, airline, destination, departure_time;
                // double ticket_price;

                // cout << "Enter Flight ID: ";
                // cin >> id;
                // cout << "Enter Model: ";
                // cin >> model;
                // cout << "Enter Capacity: ";
                // cin >> capacity;
                // cout << "Enter Airline: ";
                // cin >> airline;
                // cout << "Enter Destination: ";
                // cin >> destination;
                // cout << "Enter Departure Time: ";
                // cin >> departure_time;
                // cout << "Enter Ticket Price: ";
                // cin >> ticket_price;

                Flight newFlight(id, model, capacity, airline, destination, departure_time, ticket_price);
                flightStack.pushFlight(newFlight);
                break;
            }
            case 2:
            {
                // Check the latest Added Flight
                Flight latestFlight = flightStack.peek();
                latestFlight.displayFlightInfo();
                break;
            }
            case 3:
                // Print all the flights
                flightStack.printStack();
                break;
            case 4:
            {
                // Edit flight in the stack
                // this is way to handle the input validation
                int flightID = validateInput<int>("Enter Flight ID: ");

                // int flightID;
                // cout << "Enter Flight ID to edit: ";
                // cin >> flightID;
                flightStack.editFlight(flightID);
                break;
            }
            case 5:
            {
                // Delete flight
                // this is way to handle the input validation
                int flightID = validateInput<int>("Enter Flight ID: ");
                // int flightID;
                // cout << "Enter Flight ID to delete: ";
                // cin >> flightID;
                flightStack.deleteFlight(flightID);
                break;
            }
            case 6:
            {
                // Pop flight
                flightStack.popFlight();
                break;
            }
            case 7:
                // Back to main menu
                break;
            default:
                // default message if the user choose an invalid option
                cout << "Invalid option. Please try again.\n";
            }
            break;

        case 0:
            // exit the program
            cout << "Exiting the program.\n";
            break;

        default:
            // default message if the user choose an invalid option
            cout << "Invalid option. Please try again.\n";
        }
    } while (option != 0);

    // Cleanup memory for flights in the linked list
    Node<Flight> *currentList = flightList.getHead();
    while (currentList)
    {
        Node<Flight> *next = currentList->next;
        delete currentList;
        currentList = next;
    }

    // Cleanup memory for flights in the stack
    Node<Flight> *currentStack = flightStack.getTop();
    while (currentStack)
    {
        Node<Flight> *next = currentStack->next;
        delete currentStack;
        currentStack = next;
    }

    return 0;
}