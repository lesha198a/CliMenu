#ifndef CLIMENU_CLIMENU_H
#define CLIMENU_CLIMENU_H

#include <vector>
#include <string>
#include <climits>

class CliMenu {
public:
    static unsigned int numMenu(const std::vector<std::string>& entries, const std::string& prompt, bool showLastEntryWithZero = false, const std::string& delimiter = " - ");

    static unsigned int getUInt(const std::string& entry, unsigned int min = 0, unsigned int max = UINT_MAX);
};

#endif//CLIMENU_CLIMENU_H
