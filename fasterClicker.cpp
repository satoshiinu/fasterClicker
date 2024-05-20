#include <Windows.h>
#include <stdio.h>
#include <ppl.h>
#include <bitset>
#include <ctime>

static void lClick()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
static void rClick()
{
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}
static void lClickAt(int x, int y)
{
    SetCursorPos(x, y);
    lClick();
}
static void rClickAt(int x, int y)
{
    SetCursorPos(x, y);
    rClick();
}
static void wheel(int w)
{
    mouse_event(MOUSEEVENTF_WHEEL, 0, 0, w, 0);
}
static bool isEnd(time_t startTime, int clickMs) {
    time_t timeNow = time(NULL);
    return startTime * 1000 + clickMs <= timeNow * 1000;
}
int main()
{
    char typeChar;
    int curX;
    int curY;
    int clickcount;
    int clickinterval = 3000;
    printf("type? p=positioned f=free\n");
    scanf_s("%c", &typeChar);
    if (typeChar == 'p') {
        printf("position? (xpos ypos)\n");
        scanf_s("%d %d", &curX, &curY);
    }
    printf("click count?\n");
    scanf_s("%d", &clickcount);


    printf("click after %dms\n", clickinterval);
    Sleep(clickinterval);

    if (typeChar == 'p')
        concurrency::parallel_for(0, clickcount, [curX, curY](int num) {lClickAt(curX, curY);});
    else
        concurrency::parallel_for(0, clickcount, [](int num) {lClick();});


    printf("clicked");

    Sleep(3000);

    return 0;
}
