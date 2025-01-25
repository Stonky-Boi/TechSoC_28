#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <termios.h>
using namespace std;

class Snake
{
public:
    vector<pair<int, int>> snake_body;
    char movement_direction;
    Snake()
    {
        movement_direction = 'd';
        snake_body.push_back(make_pair(0, 0));
    }
    Snake(int start_x, int start_y)
    {
        snake_body.push_back(make_pair(start_x, start_y));
        movement_direction = 'd';
    }
    void move_snake()
    {
        pair<int, int> head = snake_body.front();
        switch (movement_direction)
        {
        case 'w':
            head.second--;
            break; // Up
        case 's':
            head.second++;
            break; // Down
        case 'a':
            head.first--;
            break; // Left
        case 'd':
            head.first++;
            break; // Right
        }
        snake_body.insert(snake_body.begin(), head);
        snake_body.pop_back();
    }
    void grow_snake()
    {
        pair<int, int> newSegment = snake_body.back();
        snake_body.push_back(newSegment);
    }
    void set_direction(char new_direction)
    {
        movement_direction = new_direction;
    }
};

class Food
{
public:
    pair<int, int> food_position;
    Food()
    {
        food_position.first = 0;
        food_position.second = 0;
    }
    Food(int food_width, int food_height)
    {
        food_position.first = rand() % food_width;
        food_position.second = rand() % food_height;
    }
    void generate_new_food(int food_width, int food_height)
    {
        food_position.first = rand() % food_width;
        food_position.second = rand() % food_height;
    }
};

class Game
{
private:
    int food_width, food_height;
    Snake snake;
    Food food;
    bool game_over;

public:
    Game(int w, int h)
    {
        food_width = w;
        food_height = h;
        snake = Snake(w / 2, h / 2);
        food = Food(w, h);
        game_over = false;
    }
    void draw_grid()
    {
        system("clear");
        for (int i = 0; i < food_width + 2; i++)
            cout << "#"; // Top border
        cout << endl;
        for (int y = 0; y < food_height; y++)
        {
            for (int x = 0; x < food_width; x++)
            {
                if (x == 0)
                    cout << "#"; // Left border
                if (x == food_width - 1)
                    cout << "#"; // Right border
                bool printed = false;
                for (auto segment : snake.snake_body)
                {
                    if (segment.first == x && segment.second == y)
                    {
                        cout << "*"; // Snake snake_body
                        printed = true;
                    }
                }
                if (food.food_position.first == x && food.food_position.second == y)
                {
                    cout << "$"; // Food
                    printed = true;
                }
                if (!printed)
                    cout << " "; // Empty space
            }
            cout << endl;
        }
        for (int i = 0; i < food_width + 2; i++)
            cout << "#"; // Bottom border
        cout << endl;
    }
    void input()
    {
        char current = get_input();
        if (current == 'w' || current == 'a' || current == 's' || current == 'd')
            snake.set_direction(current);
        if (current == 'x')
            game_over = true;
    }
    void logic()
    {
        snake.move_snake();
        // Check for collision with food
        if (snake.snake_body.front() == food.food_position)
        {
            snake.grow_snake();
            food.generate_new_food(food_width, food_height);
        }
        // Check for collision with walls or self
        if (snake.snake_body.front().first == 0 || snake.snake_body.front().first == food_width - 1 ||
            snake.snake_body.front().second == 0 || snake.snake_body.front().second == food_height - 1)
            game_over = true;
        for (int i = 1; i < snake.snake_body.size(); i++)
        {
            if (snake.snake_body[i] == snake.snake_body.front())
                game_over = true;
        }
    }
    void run()
    {
        while (!game_over)
        {
            draw_grid();
            input();
            logic();
            usleep(100000); // Sleep for 100 milliseconds (macOS/Linux)
        }
        cout << "Game Over!" << endl;
    }
    // Function to handle non-blocking input
    char get_input()
    {
        struct termios oldt, newt;
        char ch;
        tcgetattr(STDIN_FILENO, &oldt); // Get current terminal settings
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);        // Disable buffering and echoing
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings
        ch = getchar();                          // Read a single character
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore old terminal settings
        return ch;
    }
};

int main()
{
    srand(time(0));
    Game game(20, 20); // 20x20 grid
    game.run();
    return 0;
}
