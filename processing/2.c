#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

//функция для создания процессов
void create_processes(int n, int level) {
    pid_t pids[n]; //массив для хранения PID дочерних процессов
    
    for (int i = 0; i < n; i++) {
        pid_t pid = fork(); //создание нового процесса
        
        if (pid < 0) {
            perror("Fork failed"); 
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            //код выполняется в дочернем процессе
            if (level > 0) {
                create_processes(n - 1, level - 1); //рекурсивное создание дочерних процессов
            }
            //вывод PID текущего процесса и его дочерних процессов
            printf("PID: %d", getpid());
            for (int j = 0; j < n; j++) {
                if (pids[j] != 0) {
                    printf(" %d", pids[j]); // выод PID дочерних процессов
                }
            }
            printf("\n");
            
            //задержка перед завершением процесса
            sleep(10 + (n - level));
            exit(0); //завершение дочернего процесса
        } else {
            //код выполняется в родительском процессе
            pids[i] = pid; //сохранение PID дочернего процесса
        }
    }


  
    //ожидание завершения всех дочерних процессов
    for (int i = 0; i < n; i++) {
        if (pids[i] > 0) {
            waitpid(pids[i], NULL, 0); //ожидание завершения конкретного дочернего процесса
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Использование: %s <N> [имя_выходного_файла]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    int n = atoi(argv[1]); //преобразование аргумента в число
    FILE *output_file = NULL;
    
    //проверяем на наличие имени выходного файла
    if (argc == 3) {
        output_file = fopen(argv[2], "w"); //открытие файла для записи
        if (!output_file) {
            perror("Не удалось открыть выходной файл"); //ошибка при открытии файла
            exit(EXIT_FAILURE);
        }
        dup2(fileno(output_file), STDOUT_FILENO); //перенаправление стандартного вывода в файл
    }
    
    create_processes(n, n); //запуск функции для создания процессов
    
    //вывод приветствия и количества порождённых процессов
    printf("Приветствие от <ФИО>. Количество порождённых процессов: %d\n", n * (n + 1) / 2);
    
    if (output_file) {
        fclose(output_file); //закрытие выходного файла
    }
    
    return 0; //успешное завершение программы
}
