#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H


#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>


#define MAX_NAME_LENGTH 20
#define MAX_STUDENTS 20

#define NON_EMPTY_DUMMY_ROSTER                                                 \
   {                                                                           \
      1,                                                                       \
      {                                                                        \
         (student_t)                                                           \
         {                                                                     \
            255, "DEADBEEF"                                                    \
         }                                                                     \
      }                                                                        \
   }

typedef struct {
   uint8_t grade;
   char name[MAX_NAME_LENGTH];
} student_t;

typedef struct {
   size_t count;
   student_t students[MAX_STUDENTS];
} roster_t;

void init_roster(roster_t *r);
bool add_student(roster_t *r, const char *name, uint8_t grade);
roster_t get_grade(roster_t *r, const uint8_t desired_grade);


#endif
