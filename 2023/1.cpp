#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int sum = 0;

    std::vector<std::string> numbers{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    for (std::string line; std::getline(std::cin, line);)
    {

        auto minPosition = line.find_first_of("123456789");
        auto maxPosition = line.find_last_of("123456789");

        std::tuple<std::size_t, int> minNumber{std::string::npos, 0};
        std::tuple<std::size_t, int> maxNumber{0, 0};
        for (int i = 0; i < numbers.size(); ++i)
        {
            auto number1 = line.find(numbers.at(i));

            if (number1 < std::get<0>(minNumber) && number1 != std::string::npos)
            {
                std::get<0>(minNumber) = number1;
                std::get<1>(minNumber) = i + 1;
            }

            auto number2 = line.rfind(numbers.at(i));
            if (number2 > std::get<0>(maxNumber) && number2 != std::string::npos)
            {
                std::get<0>(maxNumber) = number2;
                std::get<1>(maxNumber) = i + 1;
            }
        }

        int min;
        if (minPosition != std::string::npos)
        {
            min = minPosition < std::get<0>(minNumber) ? (line.at(minPosition) - '0') : std::get<1>(minNumber);
        }
        else
        {
            min = std::get<1>(minNumber);
        }

        int max;
        if (maxPosition != std::string::npos)
        {
            max = maxPosition >= std::get<0>(maxNumber) ? (line.at(maxPosition) - '0') : std::get<1>(maxNumber);
        }
        else
        {
            max = std::get<1>(maxNumber);
        }

        sum += std::stoi(std::to_string(min) + std::to_string(max));
    }

    std::cout << sum << std::endl;

    return 0;
}