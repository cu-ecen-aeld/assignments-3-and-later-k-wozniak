// Original Bash script
// #!/bin/bash
//
// # Check if two arguments are given
// if [ $# -ne 2 ]; then
//     echo "Usage: writer.sh <file> <input_text>"
//     exit 1
// fi
//
// # Remove the file if exists
// if [ -f "$1" ]; then
//     rm "$1"
// fi
//
// # Create the file and directory if not exists
// mkdir -p "$(dirname "$1")"
// echo "$2" > "$1"
// 
// # Check if the file was created
// if ! [ -f "$1" ]; then
//     echo "File was not created"
//     exit 1
// fi

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <syslog.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    openlog("writer", LOG_PID|LOG_CONS, LOG_USER);

    // Check if two arguments are given
    if (argc != 3) {
        syslog(LOG_ERR, "Usage: writer <file> <input_text>\n");
        closelog();
        exit(1);
    }

    // Meet the requirement to write to syslog
    syslog(LOG_INFO, "Writing %s to %s\n", argv[2], argv[1]);

    // Remove the file if exists
    if (access(argv[1], F_OK) == 0) {
        remove(argv[1]);
    }

    // Create the file and directory if not exists
    mkdir(dirname(argv[1]), 0777);
    FILE *fp = fopen(argv[1], "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "File was not created\n");
        closelog();
        exit(1);
    }
    fprintf(fp, "%s", argv[2]);
    fclose(fp);

    return 0;
}
