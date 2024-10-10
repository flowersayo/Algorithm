#include <iostream>

using namespace std;
typedef struct box
{

    int x1;
    int y1;
    int x2;
    int y2;

} Box;

bool isPoint(Box box1, Box box2)
{

    if (box1.x1 == box2.x2 && box1.y2 == box2.y1)
    {
        return true;
    }

    if (box1.x2 == box2.x1 && box1.y2 == box2.y1)
    {
        return true;
    }

    if (box1.x1 == box2.x2 && box1.y1 == box2.y2)
    {
        return true;
    }

    if (box1.x2 == box2.x1 && box1.y1 == box2.y2)
    {
        return true;
    }

    return false;
}

// 한 축의 범위가 겹치고 나머지 한 축은 좌표가 같을 때
bool isLine(Box box1, Box box2)
{

    if (box1.x1 == box2.x2 && (box2.y1 <= box1.y2 && box1.y1 <= box2.y2))
    {
        return true;
    }

    if (box1.x2 == box2.x1 && (box2.y1 <= box1.y2 && box1.y1 <= box2.y2))
    {
        return true;
    }

    if (box1.y2 == box2.y1 && (box1.x1 <= box2.x2 && box2.x1 <= box1.x2))
    {
        return true;
    }

    if (box1.y1 == box2.y2 && (box2.x1 <= box1.x2 && box1.x1 <= box2.x2))
    {
        return true;
    }

    return false;
}

// 두 축의 범위가 모두 겹칠 때
bool isFace(Box box1, Box box2)
{

    if ((box2.x1 < box1.x2 && box1.x1 < box2.x2) && (box1.y1 < box2.y2 && box2.y1 < box1.y2))
    {
        return true;
    }

    return false;
}

// 두 축이 모두 겹치지 않음
bool isNULL(Box box1, Box box2)
{

    if (box2.x2 < box1.x1)
    {
        return true;
    }

    if (box1.x2 < box2.x1)
    {
        return true;
    }

    if (box2.y2 < box1.y1)
    {
        return true;
    }

    if (box1.y2 < box2.y1)
    {
        return true;
    }

    return false;
}

int main()
{
    Box box1;
    Box box2;

    cin >> box1.x1 >> box1.y1 >> box1.x2 >> box1.y2;
    cin >> box2.x1 >> box2.y1 >> box2.x2 >> box2.y2;

    if (isPoint(box1, box2))
    {
        cout << "POINT";
    }
    else if (isLine(box1, box2))
    {
        cout << "LINE";
    }
    else if (isFace(box1, box2))
    {
        cout << "FACE";
    }
    else if (isNULL(box1, box2))
    {
        cout << "NULL";
    }

    return 0;
}