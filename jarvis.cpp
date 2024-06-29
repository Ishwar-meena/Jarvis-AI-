#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <windows.h>

using namespace std;
class Jarvis
{
private:
    string password = "password";

public:
    void speak(const string);
    int greet_time();
    void greet();
    void main_menu();
    void open_yt();
    void open_google();
    void open_app();
    void open_photo();
    void shut_down();
    void restart();
    void loading_bar();
    void verification();
    void play_game();
    void set_remainder();
};

void Jarvis :: set_remainder(){
    float hour,min;
    speak("Please set your remainder time");
    cout<<"Enter hour and minute : ";
    cin>>hour>>min;
     if (hour < 0 || hour >= 24 || min < 0 || min >= 60)
    {
        speak("Invalid time entered. Please try again.");
        return;
    }
    speak("remainder is set successfully");
    Sleep((hour*3600+min*60)*1000);
    speak("Your timer is end");
    speak("Please drink water");
}

void Jarvis ::play_game()
{
    int num = 3;
    int user_points = 0, bot_points = 0;
    string gameVar, gameVar2;
    srand(time(0));

    int user, bot, n;
    cout << "Welcome to Snake Water and Gun Game Let's play it...\n"
         << endl;
    int exit = 1;
    while (exit)
    {
        cout << "Please select an option\n1.Snake\n2.Water\n3.Gun\n0.Quit\n_____ ";
        cin >> user;
        bot = 1 + (rand() % num);
        // cout << user << " " << bot;
        if (bot == 1)
        {
            gameVar = "Snake";
        }
        else if (bot == 2)
        {
            gameVar = "Water";
        }
        else
        {
            gameVar = "Gun";
        }

        if (user == 1)
        {
            gameVar2 = "Snake";
        }
        else if (user == 2)
        {
            gameVar2 = "Water";
        }
        else
        {
            gameVar2 = "Gun";
        }

        if (user == bot)
        {
            cout << "Oh Sorry Match is draw!!!"
                 << endl;
        }
        else if (user == 1 && bot == 2 || user == 2 && bot == 3 || user == 3 && bot == 1)
        {
            cout << "Congrats You won the match!!!"
                 << endl;
            user_points += 10;
        }
        else if (user == 0)
        {
            exit = 0;
        }

        else
        {
            cout << "Oh Sorry you lose the match!!!"
                 << endl;
            bot_points += 10;
        }
        cout << "You choose : " << gameVar2 << " Bot choose : " << gameVar << endl;
        cout << "Your points : " << user_points << " Bot points : " << bot_points << endl
             << endl;
    }
}

void Jarvis ::verification()
{
    system("cls");

    string user_password;
    cout << "\n\n\n\n";
    cout << "\t\t\t\t\t\tEnter Password : ";
    speak("Please enter password");
    do
    {
        cin >> user_password;

        if (password != user_password)
        {
            cout << "\n\n\t\t\t\t\t\tPlease Enter a vailed password";
            speak("You entered wrong password");
            cout << "\n\t\t\t\t\t\tEnter Password : ";
        }
        else
        {
            cout << "\nYou successfully logged in";
        }
    } while (password != user_password);
}

void Jarvis ::loading_bar()
{
    system("cls");
    char a = 177, b = 219;
    cout << "\n\n\n\n";
    cout << "\n\t\t\t\t\t| Welcome to Jarvis Desktop A.I. Assistant |" << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tCreated By @HACKER X";
    cout << "\n\n\t\t\t\t\t\tLoading...";
    cout << "\n\n\t\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << a;
    }
    cout << "\r";
    cout << "\t\t\t\t\t\t";
    for (int i = 0; i < 26; i++)
    {
        cout << b;
        Sleep(100);
    }
    speak("This A.I. created by hacker x");
}

int Jarvis ::greet_time()
{
    time_t currentTime = time(nullptr);

    tm *localTime = localtime(&currentTime);

    int hour = localTime->tm_hour;
    return hour;
}

void Jarvis ::main_menu()
{
    system("cls");
    int choose;
    cout << "\n\n\n\n\n\n\t\t\t\t\t\t\tPlease choose an option\n";
    cout << "\n\n\t\t\t\t\t\t\t1.Open Youtube\n\n\t\t\t\t\t\t\t2.Open Google\n\n\t\t\t\t\t\t\t3.Open An App\n\n\t\t\t\t\t\t\t4.Open Photos\n\n\t\t\t\t\t\t\t5.Shut Down PC\n\n\t\t\t\t\t\t\t6.Restart PC\n\n\t\t\t\t\t\t\t7.Play A Game\n\n\t\t\t\t\t\t\t8.Set Remainder\n\n\t\t\t\t\t\t\t9.Quit\n\t\t\t\t\t\t\t\t____";
    cin >> choose;
    cin.ignore();
    switch (choose)
    {
    case 1:
        open_yt();
        main_menu();
        break;
    case 2:
        open_google();
        main_menu();
        break;
    case 3:
        open_app();
        main_menu();
        break;
    case 4:
        open_photo();
        main_menu();
        break;
    case 5:
        shut_down();
        break;
    case 6:
        restart();
        break;
    case 7:
        play_game();
        break;
    case 8:
        set_remainder();
        break;
    case 9:
        exit(0);
    default:
        main_menu();
        break;
    }
}

void Jarvis ::speak(const string text)
{
    string command = "espeak \"" + text + "\"";
    system(command.c_str());
}

void Jarvis ::greet()
{
    int time = greet_time();
    if (time > 0 && time < 12)
    {
        speak("Good Morning Sir !");
    }
    else if (time >= 12 && time < 14)
    {
        speak("Good Noon Sir !");
    }
    else if (time >= 14 && time < 18)
    {
        speak("Good After Noon Sir !");
    }
    else if (time >= 18 && time < 20)
    {
        speak("Good Evening Sir !");
    }
    else
    {
        speak("Good Night Sir !");
    }
}

void Jarvis ::open_google()
{
    const char *path = "C:\\Users\\heman\\OneDrive\\Desktop\\Brave.lnk";
    const char *url = "https://www.google.com";
    ShellExecute(NULL, "open", path, url, NULL, SW_SHOWNORMAL);
    speak("Google is open");
}

void Jarvis ::open_yt()
{
    string query;
    const char *path = "C:\\Users\\heman\\OneDrive\\Desktop\\Brave.lnk";
    cout << "\t\t\t\tWhat do you want search on Youtube : ";
    speak("What do you want search on Youtube : ");
    getline(cin, query);
    speak(query);
    speak("Search on youtube");
    string url = "https://www.youtube.com/results?search_query=";
    for (char c : query)
    {
        url += (c== ' ')?'+':c;
    }
    url += "&autoplay=1"; // play first video automatically sometimes work;

    ShellExecute(NULL, "open", path, url.c_str(), NULL, SW_SHOWNORMAL);
    speak("Youtube is open");
}

void Jarvis ::open_app()
{
    string app_name;
    const char *path;
    cout << "\t\t\t\tWhich app do you want open : ";
    speak("Which app do you want open : ");
    getline(cin, app_name);
    if (app_name == "word" || app_name == "ms word")
    {
        path = "C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
    }
    else if (app_name == "excel" || app_name == "ms excel")
    {
        path = "C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";

    }
    else if (app_name == "powerpoint" || app_name == "ms powerpoint")
    {
        path = "C:\\Program Files\\Microsoft Office\\root\\Office16\\POWERPNT.EXE";
        
    }

    else if (app_name == "video player" || app_name == "vlc player")
    {
        path = "C:\\Users\\Public\\Desktop\\VLC media player.lnk";
    }
    else
    {
        speak("app not found");
    }
    ShellExecute(NULL,"open",path,NULL,NULL,SW_SHOWNORMAL);
    speak(app_name+"is open");
}

void Jarvis ::open_photo()
{
    const char *path = "C:\\Users\\heman\\OneDrive\\Pictures\\Daily Wallpaper\\en-WW-HD-20221202.jpg";
    ShellExecute(NULL, "open", path, NULL, NULL, SW_SHOWNORMAL);
    speak("Photos is open");
}

void Jarvis ::shut_down()
{
    string user;
    cout << "\t\t\t\tAre you sure to shut down pc : ";
    speak("Are you sure to shut down pc");
    cin >> user;
    if (user == "yes" || user == "Yes")
    {
        system("C:\\WINDOWS\\System32\\shutdown -s -t 10"); // it shut down pc in 10secs;
    }
    else
    {
        main_menu();
    }
}
void Jarvis ::restart()
{
    string user;
    cout << "\t\t\t\tAre you sure to restart pc : ";
    speak("Are you sure to restart pc");
    cin >> user;
    if (user == "yes" || user == "Yes")
    {
        system("C:\\WINDOWS\\System32\\shutdown -r -t 10"); // it restart pc in 10secs;
    }
    else
    {
        main_menu();
    }
}

int main()
{
    Jarvis user_1;
    user_1.loading_bar();
    user_1.verification();
    user_1.greet();
    user_1.main_menu();
    return 0;
}