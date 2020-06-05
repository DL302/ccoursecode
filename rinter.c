//program to calculate coordinates of where 2 rectangles intersect
#include <stdio.h>

typedef struct rect_tag
{
    float lowerX;
    float lowerY;
    float upperX;
    float upperY;
} rectangle;

rectangle makeRect(float x1, float y1, float x2, float y2)
{
    rectangle rect;
    rect.lowerX = x1;
    rect.lowerY = y1;
    rect.upperX = x2;
    rect.upperY = y2;
    return rect;
}

float max(float a, float b)
{
    if (a >= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
float min(float a, float b)
{
    if (a <= b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
rectangle calculateRect(rectangle rect1, rectangle rect2)
{
    rectangle result;
    result.lowerX = max(rect1.lowerX, rect2.lowerX);
    result.lowerY = max(rect1.lowerY, rect2.lowerY);
    result.upperX = min(rect1.upperX, rect2.upperX);
    result.upperY = min(rect1.upperY, rect2.upperY);
    return result;
}
int main()
{
    rectangle firstRect;
    rectangle secondRect;
    firstRect = makeRect(-1.0, -1.0, 6.0, 3.0);
    secondRect = makeRect(-2.0, -1.0, 4.0, 4.0);
    rectangle intersectRect = calculateRect(firstRect, secondRect);
    printf("The rectangle formed by the intersection of the 2 rectangles has coordinates (%f, %f) and (%f, %f)\n", intersectRect.lowerX, intersectRect.lowerY, intersectRect.upperX, intersectRect.upperY);
    printf("firstRect: (%.2f, %.2f) (%.2f, %.2f)\n", firstRect.lowerX, firstRect.lowerY, firstRect.upperX, firstRect.upperY);
    printf("secondRect: (%.2f, %.2f) (%.2f, %.2f)\n", secondRect.lowerX, secondRect.lowerY, secondRect.upperX, secondRect.upperY);
    return 0;
}
