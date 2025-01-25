# phone-directory-dsa-project
# Telephone Directory

## Overview
This project is a **Telephone Directory System** implemented in C++ as part of the DSA (Data Structures and Algorithms) coursework for BSCS-8-B. The system uses a Binary Search Tree (BST) to store, manage, and search contact information efficiently. It allows users to:

1. Add new contacts.
2. Delete existing contacts.
3. Search for a contact by first name.
4. Display all contacts in alphabetical order.
5. Save and load contact information from a file.

## Features
- **Binary Search Tree (BST):** Contacts are organized as nodes in a BST, ensuring fast retrieval and sorted traversal.
- **File Handling:** Contacts are stored persistently in a text file (`Contacts.txt`) to retain data between program runs.
- **Validation:** Input validation for phone numbers (must be 10 digits) and email addresses (must contain '@').

## How to Use

### Menu Options
1. **Add Contact**:
   - Input the first name, last name, phone number, and email address.
   - Phone numbers must be exactly 10 digits, and email addresses must be valid.

2. **Delete Contact**:
   - Enter the first name of the contact to delete.
   - The contact will be removed if it exists in the directory.

3. **Search Contact**:
   - Input the first name of the contact to search.
   - If found, the contact's details will be displayed.

4. **Show All Contacts**:
   - Displays all contacts in alphabetical order of their first names.

5. **Exit**:
   - Saves all contact data to `Contacts.txt` and exits the program.

### File Structure
- Contacts are saved in the `Contacts.txt` file in the following format:

  ```
  FirstName LastName PhoneNumber Email
  ```
  Example:
  ```
  John Doe 1234567890 john.doe@example.com
  Jane Smith 9876543210 jane.smith@example.com
  ```

## Setup Instructions

1. Clone or download the project files to your local machine.
2. Compile the C++ source file using a compiler (e.g., `g++`).
   ```
   g++ -o phone_directory phone_directory_refactor.cpp
   ```
3. Run the executable:
   ```
   ./phone_directory
   ```
4. Follow the on-screen menu to use the application.

## Code Structure

### Classes
1. **`contactNode`**:
   - Represents a single contact with attributes:
     - `fname`: First name
     - `lname`: Last name
     - `number`: Phone number
     - `email`: Email address
   - Contains pointers to left and right child nodes for the BST.

2. **`tree`**:
   - Manages the BST and provides methods for:
     - Adding, deleting, and searching contacts.
     - Displaying all contacts.
     - Validating input.
     - Saving/loading contacts to/from a file.

### Functions
- **`addContact`**: Adds a new contact to the BST.
- **`deleteContact`**: Deletes a contact by first name.
- **`searchContact`**: Searches for a contact by first name.
- **`showAllContacts`**: Performs an in-order traversal of the BST to display contacts.
- **`saveToFile`**: Saves the BST to a text file.
- **`loadFromFile`**: Loads contacts from the text file into the BST.

## Example Usage
### Adding a Contact
```
First Name: John
Last Name: Doe
Phone Number: 1234567890
Email-ID: john.doe@example.com
Contact added successfully!
```

### Searching for a Contact
```
Enter First Name of Contact to Search: John
Contact Details:
First Name: John	Last Name: Doe
Phone Number: 1234567890	Email-ID: john.doe@example.com
```

### Deleting a Contact
```
Enter First Name of Contact to Delete: John
Contact deleted successfully.
```

## Future Enhancements
- **Improved Search**: Enable searching by last name, phone number, or email.
- **GUI Integration**: Develop a graphical user interface for easier use.
- **Enhanced Validation**: Add more robust validation for names and other inputs.
- **Backup System**: Automatically back up contacts periodically.

## Acknowledgments
This project was developed as part of the Data Structures and Algorithms course. Contributions were made by:
- **Your Name (Your Roll Number)**

## License
This project is open-source and free to use for educational purposes. If reused or modified, proper attribution to the original developer(s) is appreciated.

---
Thank you for using the Telephone Directory System!

