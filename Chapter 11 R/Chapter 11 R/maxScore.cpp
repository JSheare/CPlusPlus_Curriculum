#include <iostream>
#include <iterator> // for std::size

#if 0
int main()
{
    constexpr int scores[]{ 84, 92, 76, 81, 56 };

    int maxScoreIndex{ 0 }; 

    // now look for a larger score in the full array
    for (int student{ 0 }; student < static_cast<int>(std::size(scores)); ++student)
    {
        if (scores[student] > scores[maxScoreIndex])
        {
            maxScoreIndex = student;
        }
    }

    std::cout << "The best score was " << scores[maxScoreIndex] << '\n';

    return 0;
}
#endif