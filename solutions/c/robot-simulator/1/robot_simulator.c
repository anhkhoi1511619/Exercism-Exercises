#include "robot_simulator.h"
robot_status_t robot_create(robot_direction_t direction, int x, int y)
{
    robot_status_t rs;
    rs.direction = direction;
    rs.position.x = x;
    rs.position.y = y;
    return rs;
}
void robot_move(robot_status_t *robot, const char *commands)
{
    if (robot == NULL || *commands == '\0')
    {
        return;
    }
    
    printf("1. robot->direction = %d, command %c\n", robot->direction, *commands);
    switch (*commands)
    {
        case 'R':
            robot->direction++;
            break;
        case 'L':
            robot->direction = (robot->direction == DIRECTION_NORTH) ?
                                    DIRECTION_WEST :
                                    (robot->direction - 1);
            break;                        
        case 'A':
            switch (robot->direction)
            {
                case DIRECTION_NORTH:
                    robot->position.y++;
                    break;
                case DIRECTION_SOUTH:
                    robot->position.y--;
                    break;
                case DIRECTION_EAST:
                    robot->position.x++;
                    break;
                case DIRECTION_WEST:
                    robot->position.x--;
                    break;
                default:
                    break;
            }
            break;            
        default:
            break;
    }
    if (robot->direction >= DIRECTION_MAX || robot->direction < DIRECTION_DEFAULT)
    {
        robot->direction = DIRECTION_NORTH;
    }
    char next_char = *commands++;
    printf("2. robot->direction = %d, next_char = %d, command %c\n", robot->direction, next_char, *commands);
    robot_move(robot, commands);
}
