#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static int new_img(char *img_name, char *ram_alloc) {
  char *args[] = {"scripts/new-img.sh", img_name, ram_alloc, NULL};
  execvp(args[0], args);   // Use execvp instead of execv
  perror("execvp failed"); // This only runs if execvp fails
  return -1;
}

static int boot_img(char *img_name, char *ram_alloc) {
  char *args[] = {"scripts/boot-img.sh", img_name, ram_alloc, NULL};
  printf("Attempting to boot %s with %s RAM\n", img_name, ram_alloc);

  execvp(args[0], args);
  perror("execvp failed");
  return -1;
}

static int del_img(char *img_name) {
  char *args[] = {"scripts/boot-img.sh", img_name, NULL};
  printf("Attempting delete %s\n", img_name);

  execvp(args[0], args);
  perror("execvp failed");
  return -1;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: archpass [new|boot|list] [args...]\n");
    return -1;
  }

  if (strcmp(argv[1], "new") == 0) {
    return (argc == 4) ? new_img(argv[2], argv[3]) : -1;
  } else if (strcmp(argv[1], "boot") == 0) {
    return (argc == 4) ? boot_img(argv[2], argv[3]) : -1;
  } else if (strcmp(argv[1], "list") == 0) {
    FILE *file_ptr;
    char buffer[1024];
    char *cmd_ = "ls img";
    file_ptr = popen(cmd_, "r");
    if (file_ptr == NULL) {
      perror("Error in locating the images");
      exit(EXIT_FAILURE);
    }
    printf("\n+===========================================================+\n"
           "                      ARCHPASS LIST                           \n"
           "+===========================================================+\n");
    while (fgets(buffer, sizeof(buffer), file_ptr) != NULL) {
      for (int i = 0; i < strlen(buffer); i++) {
        if (buffer[i] != '.') {
          printf("%c", buffer[i]);
          continue;
        }
        break;
      }
      printf("\n");
    }
    printf("+===========================================================+\n");
    pclose(file_ptr);
  } else {
    printf("archpass: invalid command '%s'\n", argv[1]);
    return -1;
  }
  return 0;
}
