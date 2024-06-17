#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print the usage/help message
void print_usage(const char *progname) {
    printf("Usage: %s [OPTIONS] [MESSAGE_COUNT]\n", progname);
    printf("Options:\n");
    printf("  -m, --morning  Print a morning welcome message.\n");
    printf("  -e, --evening  Print an evening welcome message.\n");
    printf("  -h, --help     Display this help message.\n");
    printf("[MESSAGE_COUNT] (optional): Number of messages to print (defaults to 1).\n");
}

// Function to print morning messages
void print_morning_message(int count) {
    for (int i = 0; i < count; ++i) {
        printf("Good morning!\n");
    }
}

// Function to print evening messages
void print_evening_message(int count) {
    for (int i = 0; i < count; ++i) {
        printf("Good evening!\n");
    }
}

int main(int argc, char *argv[]) {
    int want_morning = 0, want_evening = 0;
    int morning_count = 1, evening_count = 1;
    int message_count = 1;

    // Process command-line arguments
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-m") == 0 || strcmp(argv[i], "--morning") == 0) {
            want_morning = 1;
            if (i + 1 < argc && sscanf(argv[i + 1], "%d", &message_count) == 1) {
                morning_count = message_count;
                i++; // Skip the count argument
            }
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--evening") == 0) {
            want_evening = 1;
            if (i + 1 < argc && sscanf(argv[i + 1], "%d", &message_count) == 1) {
                evening_count = message_count;
                i++; // Skip the count argument
            }
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage(argv[0]);
            return 0;
        } else {
            fprintf(stderr, "Error: Unknown option '%s'.\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        }
    }

    // Validate and handle errors
    if (!want_morning && !want_evening) {
        fprintf(stderr, "Error: You must specify either morning or evening.\n");
        return 1;
    }

    // Print messages based on choices and count
    if (want_morning) {
        print_morning_message(morning_count);
    }
    if (want_evening) {
        print_evening_message(evening_count);
    }

    return 0;
}
