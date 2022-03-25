#include <iostream>
#include <cmath>
#include <ctime>
#include <windows.h>

struct Treasure 
{
    int treasureX;
    int treasureY;
};

struct GridObject
{
    int x;
    int y;
    std::string name = "Blank";
    int HPMax = 100;
    int damage = 0;
    int HPCurrent = 100;
    int stamina = 100;
    bool hasCompass = false;
};

struct Compass
{
    int compassX;
    int compassY;
};

struct healthDamage
{
    int hdX;
    int hdY;
    std::string HDname;
    int HD;

};

struct Grid 
{
    int totalX;
    int totalY;

    void Render(GridObject obj, Treasure treasure, Compass compass, healthDamage landMine) 
    {   
        for (int row = 0; row < totalY; row++)
        {
    
            for (int col = 0; col < totalX; col++) 
            {
                if (obj.x == col && obj.y == row)
                {
                    std::cout << "P";
                }
                else if (landMine.hdX == col && landMine.hdY == row)
                {
                    std::cout << "L";
                }
                else if (compass.compassX == col && compass.compassY == row)
                {
                    std::cout << "O";
                }
                else
                {
                std::cout << ".";
                }
        }

    std::cout << std::endl;
    }        
    }
};

struct PlayerInput 
{
    std::string yourString;

    char GetInput()
    {
        std::cout << "Your input: ";
        std::cin >> yourString;

        std::cout << std::endl;

        std::cin.clear(); //clear erro flags

        std::cout << std::endl;

        return yourString[0];
    }
    
};

double distance (GridObject obj, Treasure treasure)
    {
        if (obj.hasCompass = true)
        {
        return sqrt(pow((treasure.treasureY - obj.y), 2) + pow((treasure.treasureX - obj.x), 2));
        }
        else
        {
        std::cout << "Find compass!" << std::endl;
        }
    }; 

    char restart = 'Y';

int main()
{
    do
    {
    char restart;
    system("cls");

    int moves = 0;
    
    Grid grid;
    grid.totalX = 20;
    grid.totalY = 20;

    GridObject obj;
    obj.x = grid.totalX/2;
    obj.y = grid.totalY/2;

    srand(time(NULL));

    Compass compass;
    //compass.compassX = rand() % grid.totalX;
    //compass.compassY = rand() % grid.totalY;

    if (compass.compassX == obj.x && compass.compassY == obj.y)
    {
        compass.compassX += rand() % (grid.totalX/4);
        compass.compassY += rand() % (grid.totalY/4);
    }

    Treasure treasure;
    treasure.treasureX = rand() % grid.totalX;
    treasure.treasureY = rand() % grid.totalY;
    if (treasure.treasureX == obj.x && treasure.treasureY == obj.y)
    {
        treasure.treasureX += rand() % (grid.totalX/2);
        treasure.treasureY += rand() % (grid.totalY/2);
    }


    healthDamage landMine {rand() % grid.totalX, rand() % grid.totalY, "land mine", -70};
    if (landMine.hdX == obj.x && landMine.hdY == obj.y)
    {
        landMine.hdX += rand() % (grid.totalX/3);
        landMine.hdY += rand() % (grid.totalY/3);
    }
    //healthDamage landMine2 {rand() % grid.totalX, rand() % grid.totalY, "land mine", -70};
    //healthDamage landMine3 {rand() % grid.totalX, rand() % grid.totalY, "land mine", -70};


    PlayerInput playerInput;
    char input = 0;
    std::string terrain;

    std::cout << "Hello there adventurer, what is your name?" << std::endl;
    std::cin >> obj.name;
    system("cls");
    std::cout << obj.name << ", you are tasked with finding the treasure. Find and use the golden compass to navigate. Good luck" << std::endl; 

    system("pause");
    system("cls");
    std::cout << "*****Instructions*****" << std::endl;
    std::cout << std::endl;
    std::cout << "Navigation:" << std::endl;
    std::cout << "w: North" << std::endl;
    std::cout << "a: West" << std::endl;
    std::cout << "d: East" << std::endl;
    std::cout << "s: South" << std::endl;
    std::cout << std::endl;
    std::cout << "Options: " << std::endl;
    std::cout << "r: Sleep" << std::endl;
    std::cout << "p: Player info/stats" << std::endl;
    std::cout << "q: Quit Game" << std::endl;

    system("pause");
    system("cls");



    while(input != 'q' && distance(obj, treasure) != 0 && obj.HPCurrent >0 && obj.stamina >0)
    {
        if (obj.x == compass.compassX && obj.y == compass.compassY)
        {
            system("cls");
            std::cout << "You have found the compass. Use this to navigate to the treasure.";
            obj.hasCompass = true;
            compass.compassX = -100;
            compass.compassY = -100;
            Sleep(3500);
        }
        if (obj.stamina > 100)
        {
            system("cls");
            std::cout << "You are fully rested" << std::endl;
            Sleep(2000);
            obj.stamina = 100;
        }

        system("cls");
        grid.Render(obj, treasure, compass, landMine);

        if (obj.hasCompass == true)
        {
            std::cout << "Distance to treasure: " << distance(obj, treasure) << std::endl;
        }
        else {
            std::cout << "Find compass!" << std::endl;
        }

        if (obj.x <= 5 && obj.y <= 3)
        {
            terrain = "Forest";
        }
        else if (obj.y <= 6)
        {
            terrain = "Rocky";
        }
        else
        {
            terrain = "Desert";
        }

        std::cout << "Terrain: " << terrain << std::endl;
        std::cout << "Health: " << obj.stamina << std::endl;
        std::cout << "Instructions (enter 'i')" << std::endl;
        if (obj.stamina <= 20)
        {
            std::cout << "Warning! Health low, remember to sleep" << std::endl;
        }
        input = playerInput.GetInput();


        if (input == 'a')
        {
            obj.x -= 1;
            moves++;
        }
        else if (input == 'd')
        {
            obj.x += 1;
            moves++;
        }
        else if (input == 'w') 
        {
            obj.y -= 1;
            moves++;
        }
        else if (input == 's')
        {
            obj.y += 1;
            moves++;
        }
        else if (input == 'p')
        {
            system("cls");
            std::cout << "Character Name: " << obj.name << std::endl;
            std::cout << "Terrain: " << terrain << std::endl;
            std::cout << "Moves: " << moves << std::endl;
            std::cout << "Health: " << obj.stamina << std::endl;
            system("pause");
            
        }
        else if (input == 'i')
        {
            system("cls");
            std::cout << "*****Instructions*****" << std::endl;
            std::cout << std::endl;
            std::cout << "Navigation:" << std::endl;
            std::cout << "w: North" << std::endl;
            std::cout << "a: West" << std::endl;
            std::cout << "d: East" << std::endl;
            std::cout << "s: South" << std::endl;
            std::cout << std::endl;
            std::cout << "Options: " << std::endl;
            std::cout << "r: Sleep" << std::endl;
            std::cout << "p: Player info/stats" << std::endl;
            std::cout << "q: Quit Game" << std::endl;
            system("pause");
                
        }
        else if (input == 'r')
        {
            std::cout << "Sleeping..." << std::endl;
            Sleep(3000);
            obj.stamina += 50;
            moves++;
        }
        else 
        {
            system("cls");
            std::cout << "Invalid input." << std::endl;
            Sleep(1500);
            
        }
        

        if(terrain == "Forest" && (input == 'w' || input == 'a' || input == 's' || input == 'd'))
        {
            obj.stamina -= 1;           
        }
        else if (terrain == "Rocky" && (input == 'w' || input == 'a' || input == 's' || input == 'd'))
        {
            obj.stamina -= 3;
        }
        else if (terrain == "Desert" && (input == 'w' || input == 'a' || input == 's' || input == 'd'))
        {
            obj.stamina -= 5;
        }
        
        
        if (obj.x >= grid.totalX)
        {
            obj.x = 0;
        }
        if (obj.x < 0)
        {
            obj.x = grid.totalX-1;
        }
        if (obj.y >= grid.totalY)
        {
            obj.y = 0;
        }
        if (obj.y < 0)
        {
            obj.y = grid.totalY-1;
        }

       if (obj.x == landMine.hdX && obj.y == landMine.hdY)
        {
            system("cls");
            std::cout << "You happened upon a " << landMine.HDname << ". " << landMine.HD << " health." << std::endl;
            obj.stamina += landMine.HD;
            landMine.hdX = -50;
            landMine.hdY = -50;
            Sleep(3000);
        }
    } ;

    system("cls");

    if (obj.x == treasure.treasureX && obj.y == treasure.treasureY)
    {
        std::cout << "Well done! You have reached the treasure in " << moves << " moves." << std::endl;
    }
    else if (obj.HPCurrent <= 0)
    {
        std::cout << "You died :(" << std::endl;

    }
    else if (obj.stamina <= 0)
    {
        std::cout << "Your health ran out and you died :( Better luck next time" << std::endl;
    }
    else
    {
        std::cout << "You quit. Game over";
    }

    Sleep(3000);

    system("cls");
    std::cout << "Would you like to restart? (Y/N)" << std::endl;
    std::cin >> restart;
    obj.stamina == 100;
    input = '0';
    moves = 0;
    obj.x = grid.totalX/2;
    obj.y = grid.totalY/2;
    } while (restart == 'Y');
    return 0;
}