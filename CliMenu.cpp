#include "CliMenu.h"

#include <climits>
#include <iostream>

unsigned int CliMenu::numMenu(const std::vector<std::string> &entries, const std::string &prompt, bool showLastEntryWithZero, const std::string &delimiter) {
    while (true) {
        unsigned int size = entries.size();

        if (size == 0 || size >= UINT_MAX) {
            return -1;
        } else if (size != 1 && showLastEntryWithZero) {
            size--;
        } else {
            showLastEntryWithZero = false;
        }

        unsigned int num = showLastEntryWithZero ? 1 : 0;

        for (int i = 0; i < size; ++i, ++num) {
            std::cout << num << delimiter << entries[i] << std::endl;
        }

        if (showLastEntryWithZero) {
            std::cout << 0 << delimiter << entries.back() << std::endl;
        }

        std::cout << std::endl
                  << prompt << std::endl;

        std::string buf;
        std::cin >> buf;

        unsigned int res = -1;

        try {
            unsigned long res_long = std::stoul(buf);
            if (res_long >= UINT_MAX) {
                throw std::out_of_range("");
            }
            res = static_cast<unsigned int>(res_long);
        } catch (std::exception &ex) {
            std::cout << "Error, try again" << std::endl;
            continue;
        }

        return res;
    }
}

unsigned int CliMenu::getUInt(const std::string& entry, unsigned int min, unsigned int max) {
    while (true) {
        std::cout << entry << std::endl;

        std::string buf;
        std::cin >> buf;

        unsigned int res = -1;

        try {
            unsigned long res_long = std::stoul(buf);
            if (res_long < min || res_long > max) {
                throw std::out_of_range("");
            }
            res = static_cast<unsigned int>(res_long);
        } catch (std::exception &ex) {
            std::cout << "Error, try again" << std::endl;
            continue;
        }

        return res;

    }
}
