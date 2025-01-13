#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // проверка количества аргументов
    if (argc != 2) {
        fprintf(stderr, "ошибка: укажите количество процессов в качестве аргумента.\n");
        return 1;
    }
    
    // преобразование аргумента к целому числу
    int num_processes = atoi(argv[1]);
    if (num_processes <= 0) {
        fprintf(stderr, "ошибка: количество процессов должно быть положительным числом.\n");
        return 1;
    }

    // фио автора 
    const char *author_name = "гаджиева манаханум заурбековна";

    for (int i = 0; i < num_processes; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            // ошибка при создании процесса
            perror("fork");
            return 1;
        } else if (pid == 0) {
            // это код дочернего процесса
            printf("привет, %s! мой pid: %d\n", author_name, getpid());
            exit(0);  // завершаем дочерний процесс
        }
    }

    // ожидание завершения всех дочерних процессов
    for (int i = 0; i < num_processes; i++) {
        wait(NULL);
    }

    return 0;
}
