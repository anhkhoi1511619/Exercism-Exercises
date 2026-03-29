#include "allergies.h"

bool is_allergic_to(allergen_t allergen, int score)
{
   return (score & (1 << allergen)) != 0;
}

allergen_list_t get_allergens(int score)
{
    allergen_list_t result = {
        0,
        {false}
    };
    for (int i = 0; i < ALLERGEN_COUNT; i++)
    {
        if (is_allergic_to(i, score))
        {
            result.count++;
            result.allergens[i] = true;
            continue;
        }
        result.allergens[i] = false;
    }
    return result;
}