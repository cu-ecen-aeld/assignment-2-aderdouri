#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char *writefile;
    char *writestr;

    // Initialize syslog with LOG_USER facility
    openlog("writer_utility", LOG_PID | LOG_CONS, LOG_USER);

    if (argc < 3) {
        syslog(LOG_ERR, "Error: Insufficient arguments provided");
        printf("Error: Please provide the writefile and writestr\n");
        return 1; // Exit with error
    }

    writefile = argv[1];
    writestr = argv[2];

    // Log the writing action with LOG_DEBUG level
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error: Could not write to %s", writefile);
        printf("Error: Could not write to %s\n", writefile);
        return 1; // Exit with error
    }

    fprintf(fp, "%s", writestr);
    fclose(fp);

    // Close syslog
    closelog();

    return 0; // Success
}