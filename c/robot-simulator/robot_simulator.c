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
    printf("1. robot->direction = %d\n", robot->direction);
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
        default:
            break;
    }
    if (robot->direction >= DIRECTION_MAX || robot->direction < DIRECTION_DEFAULT)
    {
        robot->direction = DIRECTION_NORTH;
    }
    printf("2. robot->direction = %d\n", robot->direction);
}
