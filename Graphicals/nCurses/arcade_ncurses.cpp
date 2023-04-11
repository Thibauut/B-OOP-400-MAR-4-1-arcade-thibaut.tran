/*
** EPITECH PROJECT, 2022
** Visual Studio Live Share (Workspace)
** File description:
** arcade_ncurses.cpp
*/

#include "Ncurse.hpp"
#include <cstring>

#define MENU_HEIGHT 5
#define MENU_WIDTH  30

extern "C" void __attribute__((constructor)) init_ncurses() {
    printf("[arcade_ncurses] Loading ncurses library...\n");
    Ncurses *ncurses = new Ncurses();
}

extern "C" arcade::IDisplayModule *entryPoint()
{
    printf("[arcade_ncurses] entryPoint ncurses library\n");
    return new Ncurses();
}

extern "C" void __attribute__((destructor)) clean_ncurses() {
    printf("[arcade_ncurses] ncurses closing...\n");
}

Ncurses::Ncurses()
{
    _info = "Ncurses";
    _state = STATES::GAME;
}

Ncurses::~Ncurses() = default;

void print_title() {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);
    int start_y = 0;
    int start_x = max_x / 2 - 33;
    mvprintw(start_y + 1, start_x, "                                                                ");
    mvprintw(start_y + 1, start_x, " .d888888   888888ba   a88888b.  .d888888  888888ba   88888888b ");
    mvprintw(start_y + 2, start_x, "d8'    88   88    `8b d8'   `88 d8'    88  88    `8b  88        ");
    mvprintw(start_y + 3, start_x, "88aaaaa88a a88aaaa8P' 88        88aaaaa88a 88     88 a88aaaa    ");
    mvprintw(start_y + 4, start_x, "88     88   88   `8b. 88        88     88  88     88  88        ");
    mvprintw(start_y + 5, start_x, "88     88   88     88 Y8.   .88 88     88  88    .8P  88        ");
    mvprintw(start_y + 6, start_x, "88     88   dP     dP  Y88888P' 88     88  8888888P   88888888P ");
    mvprintw(start_y + 7, start_x, "                                                                ");
}

void Ncurses::menu()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    const char* options[] = {"  SNAKE  ", " PAC-MAN ", "  LEAVE  "};
    int selected_option = 0;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    while (true)
    {
        print_title();
        int menu_width = MENU_WIDTH;
        for (int i = 0; i < 3; i++)
        {
            int option_length = strlen(options[i]);
            if (option_length > menu_width) {
                menu_width = option_length;
            }
        }
        int start_col = (COLS - menu_width) / 2;
        for (int i = 0; i < 3; i++)
        {
            int option_length = strlen(options[i]);
            int option_col = start_col + (menu_width - option_length) / 2;
            attron(i == selected_option ? COLOR_PAIR(1) : COLOR_PAIR(2));
            mvprintw((LINES - MENU_HEIGHT) / 2 + i, option_col, "%s", options[i]);
            attroff(i == selected_option ? COLOR_PAIR(1) : COLOR_PAIR(2));
        }
        refresh();
        int ch = getch();
        switch (ch)
        {
            case KEY_UP:
                selected_option = (selected_option - 1 + 3) % 3;
                break;
            case KEY_DOWN:
                selected_option = (selected_option + 1) % 3;
                break;
            case '\n':
                if (selected_option == 0) {
                    // start the SNAKE game
                }
                else if (selected_option == 1) {
                    // start the PACMAN game
                }
                else {
                    endwin();
                    exit(0);
                }
                break;
        }
    }
}

void Ncurses::pauseMenu()
{
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    const char* options[] = {"  RESUME  ", "  RETURN TO MENU  ", "  SWITCH LIBRARY  ", "  LEAVE  "};
    int selected_option = 0;
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    while (true)
    {
        print_title();
        int menu_width = MENU_WIDTH;
        for (int i = 0; i < 4; i++)
        {
            int option_length = strlen(options[i]);
            if (option_length > menu_width) {
                menu_width = option_length;
            }
        }
        int start_col = (COLS - menu_width) / 2;
        for (int i = 0; i < 3; i++)
        {
            int option_length = strlen(options[i]);
            int option_col = start_col + (menu_width - option_length) / 2;
            attron(i == selected_option ? COLOR_PAIR(1) : COLOR_PAIR(2));
            mvprintw((LINES - MENU_HEIGHT) / 2 + i, option_col, "%s", options[i]);
            attroff(i == selected_option ? COLOR_PAIR(1) : COLOR_PAIR(2));
        }
        refresh();
        int ch = getch();
        switch (ch)
        {
            case KEY_UP:
                selected_option = (selected_option - 1 + 4) % 4;
                break;
            case KEY_DOWN:
                selected_option = (selected_option + 1) % 4;
                break;
            case '\n':
                if (selected_option == 0) {
                    // resume the game
                }
                else if (selected_option == 1) {
                    // return to menu
                }
                else if (selected_option == 2) {
                    // switch library
                }
                else {
                    endwin();
                    exit(0);
                }
                break;
        }
    }
}


void Ncurses::init()
{
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);
    nodelay(stdscr, TRUE);
}

arcade::Input Ncurses::handleEvent()
{
    int ch = getch();
    if (ch == KEY_UP)
        return arcade::Input::ARROW_UP;
    if (ch == KEY_DOWN)
        return arcade::Input::ARROW_DOWN;
    if (ch == KEY_LEFT)
        return arcade::Input::ARROW_LEFT;
    if (ch == KEY_RIGHT)
        return arcade::Input::ARROW_RIGHT;
    if (ch == ' ')
        return arcade::Input::SPACE;
    if (ch == arcade::ESCAPE)
        return arcade::Input::ESCAPE;
    if (ch == 'g')
        return arcade::Input::SWITCH_LIB;
    if (ch == 'h')
        return arcade::Input::SWITCH_GAME;
    if (ch == 'p')
        return arcade::Input::PAUSE_1;
    return arcade::Input::NONE;
}

void Ncurses::stop()
{
    endwin();
}

void Ncurses::clearw()
{
    clear();
}

void Ncurses::refreshw(arcade::AllObjects *AllObjects)
{
    if (_state == STATES::MENU) {
        menu();
    }
    if (_state == STATES::GAME) {
        for (int i = 0; i < AllObjects->_map.size(); i++) {
            for (int j = 0; j < AllObjects->_map[i].size(); j++) {
                mvprintw(i, j, "%c", AllObjects->_map[i][j]);
            }
        }
        if (!AllObjects->_food.empty()) {
            for (auto &i : AllObjects->_food) {
                mvprintw(i->_posy, i->_posx, "%c", '*');
            }
        }
        if (!AllObjects->_player.empty()) {
            for (auto &i : AllObjects->_player) {
                if (i->_type == arcade::Object::Type::HEAD) {
                    mvprintw(i->_posy, i->_posx, "%c", 'O');
                }
                if (i->_type == arcade::Object::Type::BODY) {
                    mvprintw(i->_posy, i->_posx, "%c", 'o');
                }
                if (i->_type == arcade::Object::Type::PACMAN) {
                    mvprintw(i->_posy, i->_posx, "%c", 'O');
                }
            }
        }
        if (!AllObjects->_enemy.empty()) {
            for (auto &i : AllObjects->_enemy) {
                if (i->_type == arcade::Object::Type::CLYDE) {
                    mvprintw(i->_posy, i->_posx, "%c", 'C');
                }
                if (i->_type == arcade::Object::Type::BLINKY) {
                    mvprintw(i->_posy, i->_posx, "%c", 'B');
                }
                if (i->_type == arcade::Object::Type::PINKY) {
                    mvprintw(i->_posy, i->_posx, "%c", 'P');
                }
                if (i->_type == arcade::Object::Type::INKY) {
                    mvprintw(i->_posy, i->_posx, "%c", 'I');
                }
            }
        }
        refresh();
    }
}

void Ncurses::drawBackground(const std::string &background) {}

void Ncurses::drawElement(arcade::Object *object) {}

void Ncurses::displayScore(int score) {

    mvprintw(10, 70, "Score: %d", score);
}

void Ncurses::playSound(const std::string &path, int volume, bool loop) {}
