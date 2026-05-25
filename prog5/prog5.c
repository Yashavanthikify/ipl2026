#include <stdio.h>

/* Union with bit-fields */
union decision {
    unsigned char flags;

    struct field {
        int your_choice:1;
        int your_mothers_choice:1;
        int your_fathers_choice:1;
        int socially_acceptable:1;
        int financially_viable:1;
        int do_you_aptitude:1;
        int do_you_likeit:1;
        int decision:1;
    } f;
};

/* Function to take input */
union decision input() {
    union decision d;
    d.flags = 0;

    printf("Enter your choice (0/1): ");
    scanf("%d", &d.f.your_choice);

    printf("Mother's choice (0/1): ");
    scanf("%d", &d.f.your_mothers_choice);

    printf("Father's choice (0/1): ");
    scanf("%d", &d.f.your_fathers_choice);

    printf("Socially acceptable (0/1): ");
    scanf("%d", &d.f.socially_acceptable);

    printf("Financially viable (0/1): ");
    scanf("%d", &d.f.financially_viable);

    printf("Do you have aptitude (0/1): ");
    scanf("%d", &d.f.do_you_aptitude);

    printf("Do you like it (0/1): ");
    scanf("%d", &d.f.do_you_likeit);

    return d;
}

/* Decision logic */
void make_decision(union decision *d) {
    d->f.decision =
        d->f.your_choice &&
        d->f.do_you_likeit &&
        d->f.do_you_aptitude &&
        (d->f.financially_viable || d->f.socially_acceptable);
}

/* Print decision */
void print_decision(union decision d) {
    if (d.f.decision)
        printf("\n Final Decision: ACCEPTED\n");
    else
        printf("\n Final Decision: REJECTED\n");
}

/* Print flags interpretation */
void print_conclusion_based_on_flags(union decision d) {
    printf("\nFlags value (decimal): %d\n", d.flags);

    if (d.flags > 5)
        printf("Conclusion: Strong positive decision factors.\n");
    else
        printf("Conclusion: Weak or conflicting decision factors.\n");
}

/* Main function */
int main() {
    union decision d = input();

    make_decision(&d);

    print_decision(d);

    print_conclusion_based_on_flags(d);

    return 0;
}
