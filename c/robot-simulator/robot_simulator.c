#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t rs = {
        .direction = direction,
        .position = {
            .x = x,
            .y = y
        }};
    return rs;
}
void robot_move(robot_status_t *robot, const char *commands)
{
    if (robot == NULL || *commands == '\0')
    {
        return;
    }
    const int incx[] = { 0, 1, 0, -1};
    const int incy[] = { 1, 0, -1, 0};    
    printf("1. robot->direction = %d, command %c\n", robot->direction, *commands);
    switch (*commands)
    {
        case 'R':
            robot->direction = (robot->direction + 1) % 4;
            break;
        case 'L':
            robot->direction = (robot->direction + 3) % 4;
            break; 
        case 'A':
            robot->position = (robot_position_t) {
                .x = robot->position.x +incx[robot->direction],
                .y = robot->position.y + incy[robot->direction]
            };
            break;     
        default:
            break;
    }
    char next_char = *commands++;
    printf("2. robot->direction = %d, next_char = %d, command %c\n", robot->direction, next_char, *commands);
    robot_move(robot, commands);
}
