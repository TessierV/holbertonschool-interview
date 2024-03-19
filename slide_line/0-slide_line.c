#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
    size_t i;
    int j;
    int current, merged;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    for (i = 0; i < size; ++i)
    {
        if (line[i] == 0)
            continue;

        current = line[i];
        line[i] = 0;
        merged = 0;

        if (direction == SLIDE_LEFT)
        {
            for (j = (int)(i + 1); j < (int)size; ++j)
            {
                if (line[j] != 0)
                {
                    if (line[j] == current && merged == 0)
                    {
                        line[j] = 0;
                        current *= 2;
                        merged = 1;
                    }
                    break;
                }
            }
            line[(i > 0 ? i - 1 : i)] = current;
        }
        else
        {
            for (j = i; j >= 0; --j)
            {
                if (line[j] != 0)
                {
                    if (line[j] == current && merged == 0)
                    {
                        line[j] = 0;
                        current *= 2;
                        merged = 1;
                    }
                    break;
                }
            }
            line[(i < size - 1 ? i + 1 : i)] = current;
        }
    }

    return 1;
}
