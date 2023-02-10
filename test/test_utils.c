#include "utils.h"
#include <assert.h>
#include <stdio.h>

/**
 * @brief Test the string_trim function
 */
int test_string_trim(void)
{
    char input[] = "  \t  hello  \t  ";
    char expected[] = "hello";
    string_trim(input);
    assert(strcmp(input, expected) == 0);

    return 0;
}

int main(void)
{
    test_string_trim();
    return 0;
}

