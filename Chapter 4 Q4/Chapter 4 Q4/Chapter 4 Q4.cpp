#include <iostream>

int getHeight()
{
    std::cout << "Enter the height of the tower in meters: ";
    int height = {};
    std::cin >> height;
    return height;
}

double getBallPos(int seconds, float height, float gravAccel)
{
    double ballPos = height - (gravAccel / 2) * seconds * seconds;
    return ballPos;
}

void printHeightMessage(int seconds, double ballPos)
{
    if (ballPos == 0 or ballPos < 0)
        std::cout << "At " << seconds << " seconds, the ball is on the ground. \n";
    else
        std::cout << "At " << seconds << " seconds, the ball is at height: " << ballPos << " meters \n";
}

int main()
{
    constexpr double gravAccel = { 9.81 };
    const int height = { getHeight() };

    printHeightMessage(0, getBallPos(0, height, gravAccel));
    printHeightMessage(1, getBallPos(1, height, gravAccel));
    printHeightMessage(2, getBallPos(2, height, gravAccel));
    printHeightMessage(3, getBallPos(3, height, gravAccel));
    printHeightMessage(4, getBallPos(4, height, gravAccel));
    printHeightMessage(5, getBallPos(5, height, gravAccel));

    return 0;
}

