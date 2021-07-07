#include <iostream>
#include <fstream>
#include <string>

bool isLoggedIn()
{
    std::string username, password, user, pass;

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;

    std::ifstream read("data\\" + username + ".txt");
    getline(read, user);
    getline(read, pass);

    if (user == username && pass == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void registerUser()
{
    std::string username, password;

    std::cout << "Type your username: ";
    std::cin >> username;
    std::cout << "Type your password: ";
    std::cin >> password;

    std::ofstream file;
    file.open("data\\" + username + ".txt");
    file << username << std::endl << password;
    file.close();
}

int main()
{
    int choice;

    std::cout << "Welcome into LoginSystem! To log in you will need to provide valid username and password." << std::endl;
    std::cout << "Choose your option:\n\t1. Register\n\t2. Log in\n\t3. Exit program" << std::endl;

    std::cin >> choice;
    if(choice == 1) {
        registerUser();
        main();
    } else if (choice == 2) {
        bool loginStat = isLoggedIn();
        if(!loginStat) {
            std::cout << "Incorrect login or password! Try again!" << std::endl;
            system("PAUSE");
            return 0;
        }
        else
        {
            std::cout << "Logged in successfully!" << std::endl;
            system("PAUSE");
            return 1;
        }
    } else if (choice == 3) {
        exit(0);
    } else {
        std::cout << "You choose wrong option or it does not exist! Try again!" << std::endl;
        main();
    }
}