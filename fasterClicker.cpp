#include <Windows.h>
#include <stdio.h>
#include <ppl.h>


using namespace concurrency;

static void lclick(int x, int y)
{
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}
static void rclick(int x, int y)
{
    SetCursorPos(x, y);
    mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
    mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
}
static void wheel(int w)
{
    mouse_event(MOUSEEVENTF_WHEEL, 0, 0, w, 0);
}
static void click(int N)
{
    printf("a");
}
int main()
{
    int curX;
    int curY;
    int clickcount;
    int clickinterval = 3000;
    Sleep(100);
    printf("cursor X?");
    scanf_s("%X", &curX);
    Sleep(100);
    printf("cursor Y?");
    scanf_s("%X", &curY);
    Sleep(100);
    printf("click count?");
    scanf_s("%X", &clickcount);
    printf("click after %xms", clickinterval);
    Sleep(clickinterval);

    parallel_for(0, clickcount, [curX, curY](int num) {lclick(curX, curY);});

    printf("clicked");

    Sleep(3000);

    return 0;
}
