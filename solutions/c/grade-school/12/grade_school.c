#include "grade_school.h"
static bool is_added_same_name(roster_t * r, const char *name);
static void arrange_roster_by_condition(roster_t * r);
static int cmp (const void *v1, const void *v2);
void init_roster(roster_t *r) {
    r->count = 0;
}
bool add_student(roster_t *r, const char *name, uint8_t grade) {
    student_t st;
    st.grade = grade;
    strcpy(st.name, name);
    if (is_added_same_name(r, name)) return false;
    r->students[r->count] = st;
    r->count++;
    arrange_roster_by_condition(r);
    return true;
}

roster_t get_grade(roster_t *r, const uint8_t desired_grade){
    roster_t desired_roster_t;
    init_roster(&desired_roster_t);
    for (size_t i = 0; i < r->count; i++)
    {
        if (r->students[i].grade == desired_grade)
        {
            add_student(&desired_roster_t, r->students[i].name, desired_grade);
        }
    }
    return desired_roster_t;
}


static bool is_added_same_name(roster_t * r, const char *name) {
    for (size_t i = 0; i < r->count; i++)
    {
        if (strcmp(name, r->students[i].name) == 0)
        {
            return true;
        }
    }
    return false;
}

static int cmp (const void *v1, const void *v2) {
    int diff = ((student_t *) v1)->grade - ((student_t *) v2)->grade;
    if (diff == 0)
    {
        return strcmp(((student_t *) v1)->name, ((student_t *) v2)->name);
    }
    return diff;
}

static void arrange_roster_by_condition(roster_t * r) {
    student_t *sts = malloc(sizeof(student_t) * r->count);
    sts = r->students;
    qsort (sts, r->count, sizeof (student_t), cmp);
}
