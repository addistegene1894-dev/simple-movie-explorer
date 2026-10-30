
#include <iostream>
#include <string>
using namespace std;

struct Movie {
    string title;
    string genre;
    int year;
};

Movie movies[100];
int count = 0;

// Function to add a movie
void addMovie() {
    if (count >= 100) {
        cout << "Movie list is full!\n";
        return;
    }

    cout << "Enter movie title: ";
    getline(cin, movies[count].title);

    cout << "Enter movie genre: ";
    getline(cin, movies[count].genre);

    cout << "Enter release year: ";
    cin >> movies[count].year;
    cin.ignore();

    count++;

    cout << "Movie added successfully!\n";
}

// Function to display all movies
void displayMovies() {
    if (count == 0) {
        cout << "No movies available!\n";
        return;
    }

    cout << "\n--- Movie List ---\n";

    for (int i = 0; i < count; i++) {
        cout << "\nMovie " << i + 1 << endl;
        cout << "Title: " << movies[i].title << endl;
        cout << "Genre: " << movies[i].genre << endl;
        cout << "Year: " << movies[i].year << endl;
    }
}

// Function to search for a movie
void searchMovie() {
    string searchTitle;
    bool found = false;

    cout << "Enter movie title to search: ";
    getline(cin, searchTitle);

    for (int i = 0; i < count; i++) {
        if (movies[i].title == searchTitle) {
            cout << "\nMovie found!\n";
            cout << "Title: " << movies[i].title << endl;
            cout << "Genre: " << movies[i].genre << endl;
            cout << "Year: " << movies[i].year << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Movie not found!\n";
    }
}

// Function to delete a movie
void deleteMovie() {
    string deleteTitle;
    bool found = false;

    cout << "Enter movie title to delete: ";
    getline(cin, deleteTitle);

    for (int i = 0; i < count; i++) {
        if (movies[i].title == deleteTitle) {

            for (int j = i; j < count - 1; j++) {
                movies[j] = movies[j + 1];
            }

            count--;
            found = true;

            cout << "Movie deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "Movie not found!\n";
    }
}

// Main function
int main() {
    int choice;

    do {
        cout << "\n===== MOVIE EXPLORER =====\n";
        cout << "1. Add Movie\n";
        cout << "2. Display Movies\n";
        cout << "3. Search Movie\n";
        cout << "4. Delete Movie\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addMovie();
                break;

            case 2:
                displayMovies();
                break;

            case 3:
                searchMovie();
                break;

            case 4:
                deleteMovie();
                break;

            case 5:
                cout << "Exiting Movie Explorer...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}
