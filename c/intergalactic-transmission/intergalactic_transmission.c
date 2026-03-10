#include "intergalactic_transmission.h"
static int get_7bits(const uint8_t* message, uint8_t start_bit, int message_length);
int transmit_sequence(uint8_t *buffer, const uint8_t *message, int message_length)
{
    if (message_length == 0)
    {
        printf("message = NULL\n");
        return 0x00;
    }
    int total_bits = message_length * 8;
    int total_7bit_groups = (total_bits + 6) / 7; // Calculate the number of 7-bit groups needed
    printf("total_bits = %d, total_7bit_groups = %d\n", total_bits, total_7bit_groups);
    for (int i = 0; i < total_7bit_groups; i++)
    {
        *buffer = get_7bits(message, i * 7, message_length);
        printf("buffer = 0x%02hhx, i = %d\n", *buffer, i);
        buffer++;
    }  
    return total_7bit_groups;    
}
static int get_7bits(const uint8_t *message, uint8_t start_bit, int message_length) {
    uint8_t value = 0x00;
    uint8_t count = 0x00;
    for (uint8_t i = 0; i < 7; i++)
    {
        uint8_t local_start_bit = (start_bit + i) % 8;
        uint8_t data_index = (start_bit + i) / 8;
        uint8_t value_to_check = message[data_index];
        if (data_index >= message_length)
        {
            printf("data_index = %d is out of bounds for message length = %d. Treat out-of-bounds as 0\n", data_index, message_length);
            // break;
            value_to_check = 0x00; // Treat out-of-bounds as 0
        } else {
            printf("data_index = %d is within bounds for message length = %d\n", data_index, message_length);
        }
        
        uint8_t bit = (value_to_check >> (7 - local_start_bit)) & 1;
        if (bit == 1)
        {
            count++;
        }
        value = (value << 1) | bit;  
        printf("message[%d] = 0x%02hhx, i = %d, value_to_check = 0x%02hhx, count = %d, bit = %d and value = %d start_bit = %d, local_start_bit = %d, data_index = %d\n",data_index, message[data_index], i, value_to_check, count, bit, value, start_bit, local_start_bit, data_index);
    }
    value = (value << 1) | (count % 2);  
    printf("value = 0x%02hhx\n", value);
    return value;
}
