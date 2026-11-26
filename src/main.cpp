#include <cstdlib>
#include <iostream>
#include <string>

namespace msh
{
    constexpr std::size_t max_input_size = 4096;

    enum class ReadResult
    {
        line,
        end_of_input,
        too_long
    };

    ReadResult read_line(std::string& input)
    {
        input.clear();
        bool exceeded_limit = false;
        char ch = '\0';

        while (std::cin.get(ch))
        {
            if (ch == '\n')
                return exceeded_limit ? ReadResult::too_long : ReadResult::line;

            if (input.size() < max_input_size)
                input.push_back(ch);
            else
                exceeded_limit = true;
        }

        if (exceeded_limit)
            return ReadResult::too_long;

        if (input.empty())
            return ReadResult::end_of_input;

        return ReadResult::line;
    }
}

int main()
{
    std::string input;

    while (true)
    {
        std::cout << "msh$ " << std::flush;

        const msh::ReadResult result = msh::read_line(input);

        if (result == msh::ReadResult::end_of_input)
            break;

        if (result == msh::ReadResult::too_long)
        {
            std::cerr << "msh: input exceeds maximum length (4096 characters)\n";
            continue;
        }

        if (input.empty())
            continue;

        if (input == "exit")
            break;

        std::cout << "msh: command processing not implemented yet\n";
    }

    return EXIT_SUCCESS;
}
