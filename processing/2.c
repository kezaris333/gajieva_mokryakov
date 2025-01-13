#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void create_processes(int n, int level, FILE* output) {
    // получаем pid текущего процесса
    pid_t pid = getpid();
    // массив для хранения pid дочерних процессов
    pid_t child_pids[100];
    // вычисляем количество дочерних процессов для текущего уровня
    int num_children = n - level;
    
    // если больше не нужно создавать процессы
    if (num_children <= 0) {
        sleep(10);  // последние процессы ждут 10 секунд
        exit(0);
    }

    // создаем дочерние процессы
    for (int i = 0; i < num_children; i++) {
        pid_t child_pid = fork();
        
        if (child_pid == 0) {  // код дочернего процесса
            create_processes(n, level + 1, output);
            exit(0);
        } else {  // код родительского процесса
            child_pids[i] = child_pid;
        }
    }

    // выводим информацию о процессе и его дочерних процессах
    if (output == NULL) {
        printf("PID %d:", pid);
    } else {
        fprintf(output, "PID %d:", pid);
    }
    
    // выводим pid всех дочерних процессов
    for (int i = 0; i < num_children; i++) {
        if (output == NULL) {
            printf(" %d", child_pids[i]);
        } else {
            fprintf(output, " %d", child_pids[i]);
        }
    }
    
    // переход на новую строку
    if (output == NULL) {
        printf("\n");
    } else {
        fprintf(output, "\n");
        fflush(output);
    }

    // ждем завершения дочерних процессов
    sleep(10 + (n - num_children));  // увеличиваем время ожидания для каждого уровня
    
    // ожидаем завершения каждого дочернего процесса
    for (int i = 0; i < num_children; i++) {
        waitpid(child_pids[i], NULL, 0);
    }
}

int main(int argc, char *argv[]) {
    // проверяем количество аргументов
    if (argc < 2) {
        printf("Usage: %s N [output_file]\n", argv[0]);
        return 1;
    }

    // получаем число N из аргументов
    int n = atoi(argv[1]);
    FILE* output = NULL;
    
    // если указан файл для вывода, открываем его
    if (argc > 2) {
        output = fopen(argv[2], "w");
        if (output == NULL) {
            perror("Error opening output file");
            return 1;
        }
    }

    // создаем иерархию процессов
    create_processes(n, 0, output);

    // подсчитываем общее количество созданных процессов
    int total_processes = 0;
    for (int i = 0; i < n; i++) {
        total_processes += (n - i);
    }

    // выводим финальное сообщение
    if (output == NULL) {
        printf("гаджиева минаханум заурбековна\n");
        printf("общее количество созданных процессов: %d\n", total_processes);
    } else {
        fprintf(output, "гаджиева Минаханум Заурбековна\n");
        fprintf(output, "общее количество созданных процессов: %d\n", total_processes);
        fclose(output);
    }

    return 0;
}





//gcc -o hierarchy hierarchy.c
//./hierarchy 3 output.txt  # Для вывода в файл
//# или
//./hierarchy 3  # Для вывода на экран


